#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector>
#include <iostream>

namespace binary_search_tree {

template <class T>
class binary_tree {

    private:

        T nodeValue;
        std::unique_ptr<binary_tree<T>> leftPtr;
        std::unique_ptr<binary_tree<T>> rightPtr;
        binary_tree<T>* parent;
        std::vector<T> sortedList;
        std::vector<T> initialList;
        std::size_t size = 0;   

        std::vector<binary_tree<T>*> sortedObjects;
        std::vector<binary_tree<T>*> deadEnds;

        bool isIn(std::vector<binary_tree<T>*> treeVector, binary_tree<T>* key){
            for (auto element : treeVector){
                if (element == key){
                    return true;
                }
            }
            return false;
        }   


    public:

        class Iterator {
            
            Iterator begin(){
                sort();
                return Iterator(sortedList.begin());
            }

            Iterator end(){
                sort();
                return Iterator(sortedList.end());
            }

        };    

        binary_tree(T data) {
            nodeValue = data;
            leftPtr = nullptr;
            rightPtr = nullptr;
            initialList.push_back(nodeValue);
            ++size;
        }

        //& after type returns a reference to the unique ptr without 
        //changing ownership.
        std::unique_ptr<binary_tree<T>>& left() {
            return leftPtr;
        }

        std::unique_ptr<binary_tree<T>>& right() {
            return rightPtr;
        }

        T data() {
            return nodeValue;
        }

        void insert(T addedData){

            initialList.push_back(addedData);
            ++size;

            if (addedData <= data()){

                if (left() == nullptr){
                    leftPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    leftPtr->parent = this;
                } else {
                    leftPtr->insert(addedData);
                }

            } else {

                if (right() == nullptr){
                    rightPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    rightPtr->parent = this;
                } else {
                    rightPtr->insert(addedData);
                }

            }

        }

        binary_tree<T>* min() {
            
            if (left() == nullptr){              
                return this;
            } else {
                return leftPtr->min();
            }

        }


        void sort(){

            //keep a list of dead-end nodes and the sorted objects.  
            //go left unless it is a dead end node, else go right.
            //a node is dead ended if it is min and does not have children.

            binary_tree<T>* root = this;
            binary_tree<T>* index = root;

            sortedObjects = std::vector<binary_tree<T>*>() ;
            deadEnds = std::vector<binary_tree<T>*>();
            sortedList = std::vector<T>();

            while (!isIn(deadEnds, root)){

                if (index->leftPtr.get() == nullptr && !isIn(sortedObjects, index)){

                    sortedObjects.push_back(index);
                    sortedList.push_back(index->nodeValue);

                    if (index->rightPtr.get() == nullptr){
                        deadEnds.push_back(index);
                    }

                    index = root;

                } else if (index->leftPtr != nullptr && !isIn(deadEnds, index->leftPtr.get())){
                    index = index->leftPtr.get();
                } else if (index->rightPtr != nullptr && !isIn(deadEnds, index->rightPtr.get())) {
                    index = index->rightPtr.get();
                } 

            }

            //recursive version
            //base case

            // if (leftPtr == nullptr){

            //     sortedObjects.push_back(this);

            //     if (rightPtr == nullptr){
            //         deadEnds.push_back(this);
            //     }

            //     root->sort();

            // } else if (leftPtr != nullptr && !isIn(deadEnds, leftPtr.get())){
            //     leftPtr->sort();
            // } else if (rightPtr != nullptr && !isIn(deadEnds, rightPtr.get())) {
            //     rightPtr->sort();
            // } 
            
        }
};


}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H