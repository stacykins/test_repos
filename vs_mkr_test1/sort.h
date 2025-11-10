#pragma once

// Ваш код, наприклад, сортування бульбашкою з покажчиками
void pointerSort(int* arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            // Використовуємо покажчики для доступу та порівняння
            if (*(arr + j) > *(arr + j + 1)) {
                // Міняємо місцями, також використовуючи покажчики або стандартну swap
                int temp = *(arr + j);
                *(arr + j) = *(arr + j + 1);
                *(arr + j + 1) = temp;
            }
        }
    }
}