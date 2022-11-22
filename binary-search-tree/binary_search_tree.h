#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_search_tree {
    
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

            std::unique_ptr<binary_tree<T>> currentNodePtr;
            std::unique_ptr<binary_tree<T>> headPtr;

            T nodeValue;
            std::unique_ptr<binary_tree<T>> leftPtr;
            std::unique_ptr<binary_tree<T>> rightPtr;

        public:

            binary_tree(T data) : currentNodePtr(nullptr), leftPtr(nullptr), rightPtr(nullptr)  {
                insert(data);
            }

            std::unique_ptr<binary_tree<T>> left() {
                return leftPtr;
            }

            std::unique_ptr<binary_tree<T>> right() {
                return rightPtr;
            }

            void setRight(std::unique_ptr<binary_tree<T>> ptr){
                rightPtr = ptr;
            }

            void setLeft(std::unique_ptr<binary_tree<T>> ptr){
                leftPtr = ptr;
            }

            T data() {
                return nodeValue;
            }

            std::unique_ptr<binary_tree<T>> insert(T data){

                if (currentNodePtr == nullptr){

                    std::unique_ptr<binary_tree<T>> newNodePtr = new binary_tree<T>(data);
                    
                    currentNodePtr = newNodePtr;

                    if (headPtr == nullptr){
                        headPtr = newNodePtr;
                    }

                    return currentNodePtr;
                }

                if (data > currentNodePtr->data()){
                    currentNodePtr->setRight(insert(data));
                    return currentNodePtr;
                } else if (data <= currentNodePtr->data()){
                    currentNodePtr->setLeft(insert(data));
                    return currentNodePtr;
                }

                //should never get here
                return nullptr;

            }


    };

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H