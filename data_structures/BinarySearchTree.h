//
// Created by Ben Napier on 2019-02-02.
//

#ifndef ADS_IMPLEMENTATIONS_BINARYSEARCHTREE_H
#define ADS_IMPLEMENTATIONS_BINARYSEARCHTREE_H

#include <iostream>
#include <vector>


struct Node {
    Node *parent = nullptr;
    Node *left = nullptr;
    Node *right = nullptr;
    int data;

    explicit Node(int data) {
        this->data = data;
    }

    Node(int data, Node *parent) {
        this->data = data;
        this->parent = parent;
    }
};

class BinarySearchTree {
private:
    void InOrderPrintRecursive(Node *root);

    std::string GenererateLatexCode(std::string &return_string, Node *subtree_root);

public:
    Node *root = nullptr;

    BinarySearchTree() = default;

    explicit BinarySearchTree(int data) {
        root = new Node(data);
    }

    void Add(int data);

    void Add(std::vector<int> data_vector) {
        for (auto data : data_vector) {
            Add(data);
        }
    }

    void Remove(int data);

    void InOrderPrint() {
        InOrderPrintRecursive(root);
        std::cout << std::endl;
    }

    std::string GetLatexCode() {
        std::string output;
        GenererateLatexCode(output, root);
        return output;
    }
};


#endif //ADS_IMPLEMENTATIONS_BINARYSEARCHTREE_H
