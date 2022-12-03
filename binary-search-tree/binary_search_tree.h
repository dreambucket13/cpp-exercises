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

            //using tree_ptr<T> = std::unique_ptr<binary_search_tree::binary_tree<T>> 
            //the iterator is looking for unique_ptrs to trees....
            using iterator_category = std::forward_iterator_tag;
            using difference_type   = std::ptrdiff_t;
            using value_type        = binary_tree<T>;
            using pointer           = binary_tree<T>*;
            using reference         = binary_tree<T>&;

            Iterator(pointer ptr) : m_ptr(ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() { return m_ptr; }
            Iterator& operator++() { m_ptr++; return *this; }  
            Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
            friend bool operator== (const Iterator& a, const Iterator& b) { return a.m_ptr == b.m_ptr; };
            friend bool operator!= (const Iterator& a, const Iterator& b) { return a.m_ptr != b.m_ptr; };  

        private:
            pointer m_ptr;
        };

        Iterator begin() { return Iterator(&sortedObjects[0]); }
        Iterator end()   { return Iterator(&sortedObjects.back()); }

        binary_tree(T data) {
            nodeValue = data;
            leftPtr = nullptr;
            rightPtr = nullptr;
            initialList.push_back(nodeValue);
            ++size;
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

            initialList.push_back(addedData);
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

        std::vector<binary_tree<T>*> sort(){

            //keep a list of dead-end nodes and the sorted objects.  
            //go left unless it is a dead end node, else go right.
            //a node is dead ended if it is min and does not have non-dead end children.

            binary_tree<T>* root = this;
            binary_tree<T>* index = root;

            sortedObjects = std::vector<binary_tree<T>*>() ;
            deadEnds = std::vector<binary_tree<T>*>();
            sortedList = std::vector<T>();

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

            return sortedObjects;
            
        }
};


}  // namespace binary_search_tree

#endif // BINARY_SEARCH_TREE_H