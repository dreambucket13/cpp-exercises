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
        const std::unique_ptr<binary_tree<T>>& left() {
            return leftPtr;
        }

        const std::unique_ptr<binary_tree<T>>& right() {
            return rightPtr;
        }

        T data() {
            return nodeValue;
        }

        void insert(T addedData){

            if (addedData <= data()){

                if (left() == nullptr){
                    leftPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                } else {
                    leftPtr->insert(addedData);
                }

            } else {

                if (right() == nullptr){
                    rightPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                } else {
                    rightPtr->insert(addedData);
                }

            }

        }

        const std::unique_ptr<binary_tree<T>>& min() {
            
            if (left() != nullptr){    
                leftPtr->min();
            } else {
                minPtr = std::unique_ptr<binary_tree<T>> (this);           
                return minPtr;
            }

        }  

        std::vector<T> sort (){

            //if min has a left pointer, set min's rightPtr to parents leftPtr

            sortedList = std::vector<T>();


            return sortedList;
        }

    private:

        T nodeValue;
        std::unique_ptr<binary_tree<T>> leftPtr;
        std::unique_ptr<binary_tree<T>> rightPtr;
        std::unique_ptr<binary_tree<T>> minPtr;        
        std::vector<T> sortedList;
        std::size_t size = 0;      

};

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H