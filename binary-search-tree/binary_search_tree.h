#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>

namespace binary_search_tree {
    
    template <class T>
    class node{
        private:
            T nodeValue;
            node<T>* leftPtr;
            node<T>* rightPtr;

        public:
            node(T insertedValue) : nodeValue(insertedValue), leftPtr(nullptr), rightPtr(nullptr)
            {

            }

            T getValue(){
                return nodeValue;
            }

            node<T>* left(){
                return leftPtr;
            }

            node<T>* right(){
                return rightPtr;
            }

            void setLeft(node<T>* ptr){
                leftPtr = ptr;
            }

            void setRight(node<T>* ptr){
                rightPtr = ptr;
            }

    };

    template <class T>
    class binary_tree {

        private:

            node<T>* currentNodePtr;
            node<T>* headPtr;

        public:

            binary_tree(T data) : currentNodePtr(nullptr), headPtr(nullptr)  {
                insert(data);
            }

            node<T>* left() {
                return currentNodePtr->left();
            }

            node<T>* right() {
                
                return currentNodePtr->right();
            }

            T data() {
                return currentNodePtr->getValue();
            }

            node<T>* insert(T data){

                if (currentNodePtr == nullptr){

                    node<T>* newNodePtr = new node(data);
                    currentNodePtr = newNodePtr;

                    if (headPtr == nullptr){
                        headPtr = newNodePtr;
                    }

                    return currentNodePtr;
                }

                if (data > currentNodePtr->getValue()){
                    currentNodePtr->setRight(insert(data));
                    return currentNodePtr;
                } else if (data <= currentNodePtr->getValue()){
                    currentNodePtr->setLeft(insert(data));
                    return currentNodePtr;
                }

                //should never get here
                return nullptr;

            }


    };

}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H