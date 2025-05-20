//GEMINI-pro DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int value;
    bool swapped;
} Node;

void sort(Node *arr, int len) {
    for (int i = 0; i < len; i++) {
        arr[i].swapped = false;
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1; j++) {
            if (arr[j].value > arr[j + 1].value) {
                Node temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                arr[j].swapped = true;
                arr[j + 1].swapped = true;
            }
        }

        bool allSwapped = true;
        for (int j = 0; j < len; j++) {
            if (arr[j].swapped) {
                allSwapped = false;
                break;
            }
        }

        if (allSwapped) {
            break;
        }
    }
}

int main() {
    int arr[] = {5, 3, 1, 2, 4};
    int len = sizeof(arr) / sizeof(arr[0]);

    sort(arr, len);

    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}