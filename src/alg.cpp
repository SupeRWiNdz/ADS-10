// Copyright 2022 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "tree.h"

unsigned int factorial(unsigned int n) {
    unsigned int result = 1;
    while (n > 0) {
        result *= n;
        n--;
    }
    return result;
}

std::vector<char> getPerm(const Tree& tree, int n) {
    if (n > factorial(tree.children.size()))
        return {};
    n -= 1;
    const Tree* ptr = &tree;
    std::vector<char> result;
    for (int i = 0; i < tree.children.size(); i++) {
        int temp = factorial(ptr->children.size() - 1);
        ptr = ptr->children[n / temp];
        result.push_back(ptr->ch);
        n %= temp;
    }
    return result;
}
