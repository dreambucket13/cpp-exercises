#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_search_tree {
    
    //commented out - implementation doesn't seem to include separate node class...each leaf is of type tree_ptr<T>?

    // template <class T>
    // class node{
    //     private:
    //         T nodeValue;
    //         node<T>* leftPtr;
    //         node<T>* rightPtr;

    //     public:
    //         node(T insertedValue) : nodeValue(insertedValue), leftPtr(nullptr), rightPtr(nullptr)
    //         {

    //         }

    //         T getValue(){
    //             return nodeValue;
    //         }

    //         node<T>* left(){
    //             return leftPtr;
    //         }

    //         node<T>* right(){
    //             return rightPtr;
    //         }

    //         void setLeft(node<T>* ptr){
    //             leftPtr = ptr;
    //         }

    //         void setRight(node<T>* ptr){
    //             rightPtr = ptr;
    //         }

    // };

    template <class T>
    class binary_tree {

        private:

            T nodeValue;
            std::unique_ptr<binary_tree<T>> leftPtr;
            std::unique_ptr<binary_tree<T>> rightPtr;
            static std::unique_ptr<binary_tree<T>> rootPtr;

        public:
            // auto tree = tree_ptr<T>(new binary_search_tree::binary_tree<T>(*data_iter));
            binary_tree(T data) {
                nodeValue = data;
                leftPtr = nullptr;
                rightPtr = nullptr;

            }

            std::unique_ptr<binary_tree<T>> left() {
                return std::move(leftPtr);
            }

            std::unique_ptr<binary_tree<T>> right() {
                return std::move(rightPtr);
            }

            T data() {
                return nodeValue;
            }

            std::unique_ptr<binary_tree<T>> insert(T addedData){
                //my old java implementation
                // current.left = insert_value(v,current.left);
                // return current;
                if (addedData <= data()){

                    if (leftPtr == nullptr){
                        leftPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    }

                    return std::move(leftPtr);

                } else if (addedData > data()){

                    if (rightPtr == nullptr){
                        rightPtr = std::unique_ptr<binary_tree<T>> (new binary_tree<T>(addedData));
                    } 

                    return std::move(rightPtr);
                }

                return nullptr;

            }


    };

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H