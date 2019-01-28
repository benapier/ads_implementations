void InsertionSort(int array[], int array_size) {
    int element, pos;
    for (int i = 1; i < array_size; ++i) {
        element = array[i];
        pos = i - 1;
        while (pos > -1 && element < array[pos]) {
            array[pos + 1] = array[pos];
            pos--;
        }
        array[pos + 1] = element;
    }
}