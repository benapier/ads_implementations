//
// Created by Ben Napier on 03/02/2019.
//

#ifndef ADS_IMPLEMENTATIONS_STACK_H
#define ADS_IMPLEMENTATIONS_STACK_H

#include <iostream>

#define MAX_SIZE 32

/**
 * Implementation of a stack data type using an array.
 */
class Stack {
private:
    int data_array[MAX_SIZE] = {};
    int size = 0;
public:
    Stack() = default;

    /**
     * Inserts a new element to the top of the stack.
     * @param data the data of the new element.
     */
    void Push(int data) {
        if (size == MAX_SIZE) {
            return;
        }
        data_array[size] = data;
        size++;
    }

    /**
     * Removes an element from the top of the stack and returns it.
     * @return the data of the element removed.
     */
    int Pop() {
        if (size == 0) {
            std::cerr << "Stack empty." << std::endl;
            return -1;
        }
        size--;
        return data_array[size];
    }

    /**
     * Returns the top element without removing it.
     * @return the data of the top element.
     */
    int get_top() {
        if (size == 0) {
            std::cerr << "Stack empty." << std::endl;
        }
        return data_array[size - 1];
    }

    /**
     * Returns the size of the list.
     * @return the size of the list.
     */
    int get_size() {
        return size;
    }
};

#endif //ADS_IMPLEMENTATIONS_STACK_H
