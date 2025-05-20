//MISTRAL-7B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX_DIGITS 10
#define MAX_ELEMENTS 10000

typedef struct Element {
    int key;
    char value[20];
} Element;

void radix_sort(Element arr[], int n) {
    int exp = 1;
    int i, digit;
    bool flag;

    for (i = 0; i < n && exp <= MAX_DIGITS; i++) {
        flag = true;
        for (int j = 0; j < n - 1; j++) {
            if (arr[j].key / exp > arr[j + 1].key / exp) {
                Element temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                strcpy(temp.value, arr[j].value);
                strcpy(arr[j].value, arr[j + 1].value);
                strcpy(arr[j + 1].value, temp.value);

                flag = false;
            }
        }

        if (flag) break;
        exp *= 10;
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Element arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the key and value for the %dth element: ", i + 1);
        scanf("%d %s", &arr[i].key, arr[i].value);
    }

    printf("\nBefore sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Key: %d, Value: %s\n", arr[i].key, arr[i].value);
    }

    radix_sort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("Key: %d, Value: %s\n", arr[i].key, arr[i].value);
    }

    return 0;
}