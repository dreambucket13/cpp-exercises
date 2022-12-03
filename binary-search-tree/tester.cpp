#include "binary_search_tree.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

//g++ -o tester tester.cpp -g -Wall

int main(){

    //build a test tree

    auto test_tree = std::unique_ptr<binary_search_tree::binary_tree<uint32_t>>(new binary_search_tree::binary_tree<uint32_t>(4));
    test_tree->insert(2);
    test_tree->insert(6);
    test_tree->insert(3);
    test_tree->insert(8);
    test_tree->insert(1);
    test_tree->insert(5);
    test_tree->insert(7);

    // auto test_tree = std::unique_ptr<binary_search_tree::binary_tree<string>>(new binary_search_tree::binary_tree<string>("b"));
    // test_tree->insert("a");
    // test_tree->insert("c");

    //test_tree->sort();

    return 0;
}
