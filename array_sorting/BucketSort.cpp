#include "../header.h"

void BucketSort(int data_array[], int array_size) {
    // First we find the maximum value in the list so we know how much space to allocate.
    int maximum_value = 0;
    for (int i = 0; i < array_size; ++i) {
        if (data_array[i] > maximum_value) {
            maximum_value = data_array[i];
        }
    }
    auto bucket_vector = std::vector<unsigned >(static_cast<unsigned int>(maximum_value + 1));
    // And now we fill our buckets.
    for (int i = 0; i < array_size; ++i) {
        bucket_vector[data_array[i]]++;
    }
    // Now we convert back to our array.
    int count = 0;
    for (int i = 0; i < bucket_vector.capacity(); ++i) {
        for (int j = 0; j < bucket_vector[i]; ++j) {
            data_array[count] = i;
            count++;
        }
    }
}