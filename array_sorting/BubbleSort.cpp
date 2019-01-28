#include "../header.h"

void BubbleSort(int array[], int array_size) {
    int swap_count;
    for (int i = 0; i < array_size - 1; ++i) {
        swap_count = 0;
        for (int j = 1; j < array_size - i; ++j) {
            if (array[j] < array[j - 1]) {
                std::swap(array[j], array[j - 1]);
                swap_count++;
            }
        }
        // If there is no swaps in a given run, then we know it is sorted.
        if (swap_count == 0) {
            return;
        }
    }
}
