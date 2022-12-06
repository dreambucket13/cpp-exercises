#if !defined(BINARY_SEARCH_TREE_H)
#define BINARY_SEARCH_TREE_H

#include <memory>
#include <vector>
#include <iostream>

namespace binary_search_tree {

template <class T>
class binary_tree {

using tree_ptr = typename std::unique_ptr<binary_search_tree::binary_tree<T>>;

    private:

        T nodeValue;
        tree_ptr leftPtr;
        tree_ptr rightPtr;
        binary_tree<T>* parent;

    public:

        struct Iterator 
        {

            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = binary_tree<T>;
            using pointer           = binary_tree<T>*;
            using reference         = T&;

            Iterator(pointer ptr) : currentNode(ptr) {}
            Iterator() { currentNode = nullptr; }

            reference operator*() const { return currentNode->nodeValue; }
            pointer operator->() { return currentNode; }
            T& operator++() { currentNode = currentNode->next(); return currentNode->nodeValue; }  
            // Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            friend bool operator== (const Iterator& a, const Iterator& b) { return a.currentNode == b.currentNode; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.currentNode != b.currentNode; };  

        private:
            pointer currentNode;
        };
    

        Iterator begin() { return Iterator(min()); }
        Iterator end()   { return Iterator(); }

        binary_tree(T data) {
            nodeValue = data;
            leftPtr = nullptr;
            rightPtr = nullptr;
            parent = nullptr;

        }

        //& after type returns a reference to the unique ptr without 
        //changing ownership.
        tree_ptr& left() {
            return leftPtr;
        }

        tree_ptr& right() {
            return rightPtr;
        }

        T data() {
            return nodeValue;
        }

        void insert(T addedData){

            if (addedData <= data()){

                if (left() == nullptr){
                    leftPtr = tree_ptr (new binary_tree<T>(addedData));
                    leftPtr->parent = this;
                } else {
                    leftPtr->insert(addedData);
                }

            } else {

                if (right() == nullptr){
                    rightPtr = tree_ptr (new binary_tree<T>(addedData));
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

        //implement a "next" method given a node.  Each node owning it's own sorted list 
        //seems to be problematic.  

        binary_tree<T>* up_tree(){

            if (parent == nullptr){
                return nullptr;
            } else if (parent->nodeValue >= nodeValue) {
                return parent;
            } else {
                return parent->up_tree();    
            }
        }

        binary_tree<T>* next(){

            if (rightPtr != nullptr){
                return rightPtr->min();
            } else {
                return up_tree();
            }

        }

};


}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H