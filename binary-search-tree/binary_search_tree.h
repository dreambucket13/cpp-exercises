#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_search_tree {

    template <class T>
    class binary_tree {

        private:

            T nodeValue;
            std::unique_ptr<binary_tree<T>> leftPtr;
            std::unique_ptr<binary_tree<T>> rightPtr;

        public:
            // auto tree = tree_ptr<T>(new binary_search_tree::binary_tree<T>(*data_iter));
            binary_tree(T data) {
                nodeValue = data;
                leftPtr = nullptr;
                rightPtr = nullptr;
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
                //my old java implementation
                // current.left = insert_value(v,current.left);
                // return current;

                if (addedData <= data()){

                    if (left() == nullptr){
                        leftPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    } else {
                        leftPtr->insert(addedData);
                    }

                } else if (addedData > data()){

                    if (right() == nullptr){
                        rightPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    } else {
                        rightPtr->insert(addedData);
                    }

                }

            }


    };

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H