#include "../header.h"

void Merge(int array[], int left, int mid, int right) {
    // Making two temporary arrays to put left and right in
    int left_array_size = mid - left + 1;
    int right_array_size = right - mid;
    int left_array[left_array_size];
    int right_array[right_array_size];
    for (int i = 0; i < left_array_size; ++i) {
        left_array[i] = array[i + left];
    }
    for (int i = 0; i < right_array_size; ++i) {
        right_array[i] = array[mid + i + 1];
    }
    // Now we sort into array
    int left_cursor = 0;
    int right_cursor = 0;
    int new_cursor = left;
    while ((left_cursor < left_array_size) && (right_cursor < right_array_size)) {
        if (left_array[left_cursor] <= right_array[right_cursor]) {
            array[new_cursor] = left_array[left_cursor];
            left_cursor++;
        } else {
            array[new_cursor] = right_array[right_cursor];
            right_cursor++;
        }
        new_cursor++;
    }
    while (left_cursor < left_array_size) {
        array[new_cursor] = left_array[left_cursor];
        left_cursor++;
        new_cursor++;
    }
    while (right_cursor < right_array_size) {
        array[new_cursor] = right_array[right_cursor];
        right_cursor++;
        new_cursor++;
    }
}

void MergeSort(int array[], int left, int right) {
    if (right - left + 1 < 2) return;
    int mid = (left + right) / 2;
    MergeSort(array, left, mid);
    MergeSort(array, mid + 1, right);
    Merge(array, left, mid, right);
}