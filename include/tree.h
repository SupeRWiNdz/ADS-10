// Copyright 2022 NNTU-CS
#include <vector>
#include <iostream>
#ifndef INCLUDE_TREE_H_
#define INCLUDE_TREE_H_

class Tree {
 private:
    void addChild(Tree *root, std::vector<char> values) {
        for (int i = 0; i < size(values); i++) {
            Tree* child = new Tree(values[i]);
            children.push_back(child);
            std::vector<char> temp = values;
            temp.erase(temp.begin() + i);
            child->addChild(child, temp);
        }
    }
    explicit Tree(char x) {
        ch = x;
    }
 public:
    explicit Tree(std::vector<char> values) {
        Tree* root = new Tree('*');
       addChild(root, values);
    }
    char ch = ' ';
    std::vector<Tree*> children;
};

#endif  // INCLUDE_TREE_H_
