//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int value;
    char name[20];
} Element;

void print_array(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d %s\n", arr[i].value, arr[i].name);
    }
}

int cinnamon_binary_search(Element arr[], int size, int value, int low, int high) {
    int mid;

    while (low <= high) {
        mid = (low + high) / 2;

        if (arr[mid].value == value) {
            printf("Element found at index %d with the name: %s\n", mid, arr[mid].name);
            return mid;
        }

        if (arr[mid].value < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("Element not found in the array.\n");
    return -1;
}

int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    Element arr[size];

    for (int i = 0; i < size; i++) {
        printf("\nEnter the value and name of element %d: ", i + 1);
        scanf("%d %s", &arr[i].value, arr[i].name);
    }

    print_array(arr, size);

    int value;
    printf("\nEnter the value to search: ");
    scanf("%d", &value);

    int result = cinnamon_binary_search(arr, size, value, 0, size - 1);

    return 0;
}