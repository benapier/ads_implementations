//
// Created by Ben Napier on 03/02/2019.
//

#ifndef ADS_IMPLEMENTATIONS_SINGLYLINKEDLIST_H
#define ADS_IMPLEMENTATIONS_SINGLYLINKEDLIST_H


/**
 * Simple node data structure for a singly linked list.
 */
class Node {
public:
    Node *next = nullptr;
    int data = 0;
};

/**
 * Simple data structure for a singly linked list which utilises the node data structure.
 */
class LinkedList {
public:
    Node *head = nullptr;
    int size = 0;

    LinkedList() = default;

    /**
     * Insert a new node with specified data into the head of the linked list.
     * @param data the data to insert into the list.
     */
    void Insert(int data) {
        auto temp = new Node();
        temp->data = data;
        temp->next = head;
        head = temp;
        size++;
    }

    /**
     * Finds the node with specified data in the list.
     * @param data the data to find in the list.
     * @return the index of the node with the data or -1 if not found.
     */
    int Find(int data) {
        Node *temp = head;
        for (int i = 0; i < size; ++i) {
            if (temp->data == data) {
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }

    /**
     * Delete the node with specified data in the list.
     * Will delete the first node that it finds and then terminate.
     * @param data the data to delete from the list.
     */
    void Delete(int data) {
        if (head->data == data) {
            head = head->next;
            size--;
        } else {
            Node *node = head->next;
            Node *prev = head->next;
            for (int i = 1; i < size; ++i) {
                if (node->data == data) {
                    prev->next = node->next;
                    size--;
                    return;
                }
                prev = node;
                node = node->next;
            }
        }
    }
};


#endif //ADS_IMPLEMENTATIONS_SINGLYLINKEDLIST_H
