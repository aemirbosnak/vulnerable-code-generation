//MISTRAL-7B DATASET v1.0 Category: Searching algorithm ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int key;
    char name[20];
} Element;

int curious_search(Element arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    int middle;
    int moves = 0;

    while (left <= right) {
        // Add some randomness to the search
        srand(time(NULL));
        middle = (left + rand() % (right - left + 1) + left) / 2;

        if (arr[middle].key == key) {
            printf("The curious one found the key in position %d!\n", middle + 1);
            return middle;
        }

        if (arr[middle].key < key) {
            left = middle + 1;
        } else {
            right = middle - 1;
        }

        moves++;
    }

    printf("The curious one could not find the key. Total moves: %d\n", moves);
    return -1;
}

void print_elements(Element arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("Element %d: Key = %d, Name = %s\n", i + 1, arr[i].key, arr[i].name);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    Element arr[n];

    for (int i = 0; i < n; i++) {
        printf("Enter the key and name for Element %d: ", i + 1);
        scanf("%d %s", &arr[i].key, arr[i].name);
    }

    int target_key;
    printf("Enter the key to search for: ");
    scanf("%d", &target_key);

    curious_search(arr, n, target_key);
    print_elements(arr, n);

    return 0;
}