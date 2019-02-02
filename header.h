//
// Created by Ben Napier on 2019-01-28.
//

#ifndef ADS_IMPLEMENTATIONS_HEADER_H
#define ADS_IMPLEMENTATIONS_HEADER_H

#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

// Array sorting algorithms
void BucketSort(int array[], int array_size);
void SelectionSort(int array[], int array_size);
void InsertionSort(int array[], int array_size);
void BubbleSort(int array[], int array_size);
void MergeSort(int array[], int left, int right);
void Merge(int array[], int left, int mid, int right);

#endif //ADS_IMPLEMENTATIONS_HEADER_H
