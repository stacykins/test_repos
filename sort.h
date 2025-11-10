#ifndef SORT_H
#define SORT_H

#include <cstddef>
#include <cstring>

// swap для покажчиків на рядки
inline void swap(char** a, char** b) {
    char* temp = *a;
    *a = *b;
    *b = temp;
}

// простий quick sort для масиву char* 
inline void quick_sort(char* arr[], size_t length) {
    if (length <= 1) return;

    char* pivot = arr[length / 2];
    size_t i = 0;
    size_t j = length - 1;

    while (i <= j) {
        while (strcmp(arr[i], pivot) < 0) i++;
        while (strcmp(arr[j], pivot) > 0) j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            if (j > 0) j--;
        }
    }
    if (j > 0) quick_sort(arr, j + 1);
    if (i < length) quick_sort(arr + i, length - i);
}

#endif // SORT_H
