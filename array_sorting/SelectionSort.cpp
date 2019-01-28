#include "../header.h"
#include <utility>

void SelectionSort(int array[], int array_size) {
    int element, pos;
    for (int i = 0; i < array_size - 1; ++i) {
        element = array[i];
        pos = i;
        for (int j = i + 1; j < array_size; ++j) {
            if (array[j] < element) {
                element = array[j];
                pos = j;
            }
        }
        std::swap(array[i], array[pos]);
    }
}
