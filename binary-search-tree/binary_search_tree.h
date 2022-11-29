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

            if (addedData <= data()){

                if (left() == nullptr){
                    leftPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    ++size;
                } else {
                    leftPtr->insert(addedData);
                }

            } else {

                if (right() == nullptr){
                    rightPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    ++size;
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


        std::vector<T> sort(){

            binary_tree<T>* root = this;
            binary_tree<T>* index;
            binary_tree<T>* deletedNode = nullptr;

            sortedList = std::vector<T>();

            while (root != nullptr){
                
                index = root;

                //if index->left() == deleted node, set index->right to deleted->left()

                //if deleted node is root, set to null

                deletedNode = min();
                auto sortedData = deletedNode->data();
                sortedList.push_back(sortedData);

            }

            return sortedList;
        }

    private:

        T nodeValue;
        std::unique_ptr<binary_tree<T>> leftPtr;
        std::unique_ptr<binary_tree<T>> rightPtr;
        std::vector<T> sortedList;
        std::size_t size = 0;      

};

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H