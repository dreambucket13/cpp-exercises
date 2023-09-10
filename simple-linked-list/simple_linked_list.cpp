#include "simple_linked_list.h"

#include <stdexcept>

namespace simple_linked_list {

std::size_t List::size() const {
    return current_size;
}

void List::push(int entry) {
    // TODO: Implement a function that pushes an Element with `entry` as data to
    // the front of the list.

    auto pushed_element = new simple_linked_list::List::Element(entry);

    //head needs to move over 
    pushed_element->next = head;

    head = pushed_element;

    ++current_size;
}

int List::pop() {
    // TODO: Implement a function that returns the data value of the first
    // element in the list then discard that element.

    int popped = head->data;
    auto old_head = head;

    head = head->next;
    --current_size;
    delete old_head;

    return popped;
}

void List::reverse() {
    // TODO: Implement a function to reverse the order of the elements in the
    // list.

    auto reversed = new simple_linked_list::List();

    while (this->head != nullptr){
        reversed->push(this->pop());
    }

    this->head = reversed->head;
    delete reversed;

}

List::~List() {
    // TODO: Ensure that all resources are freed on destruction
}

}  // namespace simple_linked_list
