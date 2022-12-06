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

            ++size;

            sortedObjects = std::vector<binary_tree<T>*>() ;
            deadEnds = std::vector<binary_tree<T>*>();
            sortedList = std::vector<T>();

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

            ++size;

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

        //idea - implement a "next" method given a node.  Each node owning it's own sorted list 
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

        std::vector<T>& sort(){

            //keep a list of dead-end nodes and the sorted objects.  
            //go left unless it is a dead end node, else go right.
            //a node is dead ended if it is min and does not have non-dead end children.

            binary_tree<T>* root = this;
            binary_tree<T>* index = root;

            sortedObjects.clear();
            deadEnds.clear();
            sortedList.clear();

            while (!isIn(deadEnds, root)){
                
                binary_tree<T>* rawLeft = index->leftPtr.get();
                binary_tree<T>* rawRight = index->rightPtr.get();
                bool leftIsDeadEnd = isIn(deadEnds, rawLeft);
                bool rightIsDeadEnd = isIn(deadEnds, rawRight);
                bool objectIsSorted = isIn(sortedObjects, index);

                if (leftIsDeadEnd && rightIsDeadEnd){
                    deadEnds.push_back(index);
                    index = root;
                } 
                
                if ( (rawLeft == nullptr || leftIsDeadEnd) && !objectIsSorted){

                    sortedObjects.push_back(index);
                    sortedList.push_back(index->nodeValue);

                    if (rawRight == nullptr || rightIsDeadEnd){
                        deadEnds.push_back(index);
                    }

                    index = root;

                } else if (rawLeft != nullptr && !leftIsDeadEnd){
                    index = rawLeft;
                } else if (rawRight != nullptr && !rightIsDeadEnd) {
                    index = rawRight;
                } 

            }

            return sortedList;
            
        }
};


}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H