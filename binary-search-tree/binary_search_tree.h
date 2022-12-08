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

        //prefer default values to doing work within the constructor
        T nodeValue;
        tree_ptr leftPtr = nullptr;
        tree_ptr rightPtr = nullptr;
        binary_tree<T>* parent = nullptr;

    public:
        //use classes when there is an invariant; structs when each member can vary independently
        class Iterator 
        {
        public:
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = T;
            using pointer           = T*;
            using reference         = T&;

            explicit Iterator(binary_tree<T>* ptr) : currentNode(ptr) {}
            Iterator() {} 

            reference operator*() const { return currentNode->nodeValue; }
            pointer operator->() { return &currentNode->nodeValue; }
            T& operator++() { currentNode = currentNode->next(); return currentNode->nodeValue; }  
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            friend bool operator== (const Iterator& a, const Iterator& b) { return a.currentNode == b.currentNode; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.currentNode != b.currentNode; };  

        private:
            binary_tree<T>* currentNode = nullptr;
            T currentValue;
        };
    

        const Iterator begin() { return Iterator(min()); }
        const Iterator end()   { return Iterator(); }

        explicit binary_tree(const T& data) {
            nodeValue = data;
        }

        //& after type returns a reference to the unique ptr without 
        //changing ownership.
        const tree_ptr& left() const {
            return leftPtr;
        }

        const tree_ptr& right() const {
            return rightPtr;
        }

        const T& data() const {
            return nodeValue;
        }

        //taking in value by const reference avoids copying
        void insert(const T& addedData){

            if (addedData <= data()){

                if (!leftPtr){
                    leftPtr = tree_ptr (new binary_tree<T>(addedData));
                    leftPtr->parent = this;
                } else {
                    leftPtr->insert(addedData);
                }

            } else {

                if (!rightPtr){
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