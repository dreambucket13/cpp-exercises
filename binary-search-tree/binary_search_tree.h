#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector>
#include <iostream>

namespace binary_search_tree {

template <class T>
class binary_tree {

    public:

        class Iterator {
            
            Iterator begin(){
                return Iterator(min());
            }

        };    

        binary_tree(T data) {
            nodeValue = data;
            leftPtr = nullptr;
            rightPtr = nullptr;
            initialList.push_back(nodeValue);
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

                 //if (left()->left() == nullptr){
                    minParent = this;
                 //}

                return leftPtr->min();
            }

        }


        std::vector<T> sort(){

            binary_tree<T>* root = this;
            binary_tree<T>* deletedNode;

            sortedList = std::vector<T>();

            while (root){

                deletedNode = root->min();
                auto sortedData = deletedNode->data(); 
                sortedList.push_back(sortedData);


                if ( root->leftPtr == nullptr && root->rightPtr ==  nullptr) {
                    //if root has no children, null out
                    root = nullptr;

                } else if (deletedNode == root){
                    
                    //move root to the right
                    //root = rightPtr.get();
                    nodeValue = rightPtr->nodeValue;
                    leftPtr = std::move(rightPtr->leftPtr);
                    rightPtr = std::move(rightPtr->rightPtr);

                } else {
                    //set min's parent's left pointer to mins right.
                    //This will also destroy the original min->left pointer.

                    if (deletedNode->rightPtr != nullptr){
                        //when you move a pointer, need to update parent too
                        //3's parent needs to update to 4
                        deletedNode->rightPtr->parent = deletedNode->parent;                        
                        deletedNode->parent->leftPtr = std::move(deletedNode->rightPtr);

                    } else {
                        deletedNode->parent->leftPtr.reset();
                    }


                }

            }

            //once I have the sorted list, rebuild the tree
            //the max value will remain with null left and right pointers
            //reset it with the first insert manually then insert normally

            nodeValue = initialList[0];
            initialList.erase(initialList.begin());

            for (T rebuild : initialList){
                insert(rebuild);
                //insert will insert again...I know I know
                initialList.pop_back();
            }

            return sortedList;

        }

    private:

        T nodeValue;
        std::unique_ptr<binary_tree<T>> leftPtr;
        std::unique_ptr<binary_tree<T>> rightPtr;
        binary_tree<T>* minParent;
        binary_tree<T>* parent;
        std::vector<T> sortedList;
        std::vector<T> initialList;
        std::size_t size = 0;      

};

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H