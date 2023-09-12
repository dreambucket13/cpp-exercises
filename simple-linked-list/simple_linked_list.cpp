#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {

    auto pushed_element = new Element(entry);

    //head needs to move over 
    pushed_element->next = head;

    head = pushed_element;

    ++current_size;
}

int List::pop() {

    if (head == nullptr){
        return 0;
    }

    int popped_data = head->data;
    Element* popped_element = head;
    head = head->next;
    --current_size;

    delete popped_element;

    return popped_data;
}

void List::reverse() {

    Element* previous = nullptr;
    Element* node = head;

    while (node != nullptr){
        Element* temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }

    head = previous;

}

List::~List() {

    while (head != nullptr){
        pop();
    }
    
}

}  // namespace simple_linked_list
