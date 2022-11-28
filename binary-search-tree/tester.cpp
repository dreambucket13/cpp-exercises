#include "binary_search_tree.h"
#include <vector>
#include <memory>

//g++ -o tester tester.cpp -g

int main(){

    //build a test tree

    auto test_tree = std::unique_ptr<binary_search_tree::binary_tree<int>>(new binary_search_tree::binary_tree<int>(4));
    test_tree->insert(2);
    test_tree->insert(6);
    test_tree->insert(3);

    auto& minPtr = test_tree->min();

    return 0;
}
