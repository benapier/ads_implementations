//
// Created by Ben Napier on 2019-02-02.
//

#include "BinarySearchTree.h"

void BinarySearchTree::InOrderPrintRecursive(Node *root) {
    if (root->left != nullptr) {
        InOrderPrintRecursive(root->left);
    }
    std::cout << root->data << ", ";
    if (root->right != nullptr) {
        InOrderPrintRecursive(root->right);
    }
}

std::string BinarySearchTree::GenererateLatexCode(std::string &return_string, Node *subtree_root) {
    return_string += "[$" + std::to_string(subtree_root->data) + "$";
    if (subtree_root->left == nullptr) {
        if (subtree_root->right != nullptr) { // one right node
            return_string += "[,phantom]";
            GenererateLatexCode(return_string, subtree_root->right);
        }
    } else {
        GenererateLatexCode(return_string, subtree_root->left);
        if (subtree_root->right == nullptr) { // one left node
            return_string += "[,phantom]";
        } else { // two notes
            GenererateLatexCode(return_string, subtree_root->right);
        }
    }
    return_string += "]";
    return return_string;
}

void BinarySearchTree::Add(int data) {
    if (root == nullptr) {
        root = new Node(data);
        return;
    }
    Node *temp = root;
    bool node_placed = false;
    if (root == nullptr) {
        root = new Node(data);
    }
    while (!node_placed) {
        if (data <= temp->data) {
            if (temp->left == nullptr) {
                temp->left = new Node(data, temp);
                node_placed = true;
            } else {
                temp = temp->left;
            }
        } else {
            if (temp->right == nullptr) {
                temp->right = new Node(data, temp);
                node_placed = true;
            } else {
                temp = temp->right;
            }
        }
    }
}

void BinarySearchTree::Remove(int data) {
    Node *temp = root;
    // find the node
    while (temp->data != data) {
        if (data <= temp->data) {
            if (temp->left == nullptr) {
                return;
            }
            temp = temp->left;
        } else {
            if (temp->right == nullptr) {
                return;
            }
            temp = temp->right;
        }
    }
    // delete it
    bool is_temp_left_child = false;
    if (temp->parent != nullptr) {
        is_temp_left_child = temp->parent->left == temp;
    }
    if (temp->left == nullptr) {
        if (temp->right == nullptr) { // no children
            if (temp->parent == nullptr) {
                std::cerr << "Cannot remove nodes from an empty tree.\n";
            } else {
                if (is_temp_left_child) {
                    temp->parent->left = nullptr;
                } else {
                    temp->parent->right = nullptr;
                }
            }
        } else { // one right child
            if (temp->parent == nullptr) {
                temp->right->parent = nullptr;
                root = temp->right;
            } else {
                temp->right->parent = temp->parent;
                if (is_temp_left_child) {
                    temp->parent->left = temp->right;
                } else {
                    temp->parent->right = temp->right;
                }
            }
        }
    } else {
        if (temp->right == nullptr) { // one left child
            if (temp->parent == nullptr) {
                temp->left->parent = nullptr;
                root = temp->left;
            } else {
                temp->left->parent = temp->parent;
                if (is_temp_left_child) {
                    temp->parent->left = temp->left;
                } else {
                    temp->parent->right = temp->right;
                }
            }
        } else { // two children
            if (temp->right->left == nullptr) {
                temp->left->parent = temp->right;
                temp->right->left = temp->left;
                if (temp->parent == nullptr) {
                    root = temp->right;
                } else {
                    if (is_temp_left_child) {
                        temp->parent->left = temp->right;
                    } else {
                        temp->parent->right = temp->right;
                    }
                }
            } else {
                auto replacement_node = temp->right->left;
                while (replacement_node->left != nullptr) {
                    replacement_node = replacement_node->left;
                }
                replacement_node->parent->left = nullptr;
                replacement_node->parent = temp->parent;
                replacement_node->left = temp->left;
                if (is_temp_left_child) {
                    temp->parent->left = replacement_node;
                } else {
                    temp->parent->right = replacement_node;
                }
            }
        }
    }
}