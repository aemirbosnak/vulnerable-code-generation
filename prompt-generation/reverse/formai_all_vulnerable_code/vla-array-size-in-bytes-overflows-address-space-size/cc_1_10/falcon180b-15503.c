//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Define a structure for each item in the array
typedef struct {
    int id;
    char name[20];
} Item;

// Function to compare two items based on their IDs
int compare(const void *a, const void *b) {
    return (*(Item*)a).id - (*(Item*)b).id;
}

// Function to search for an item in the array
int search(Item arr[], int size, int target_id) {
    qsort(arr, size, sizeof(Item), compare); // Sort the array by ID
    for (int i = 0; i < size; i++) {
        if (arr[i].id == target_id) {
            printf("Item found with ID %d and name %s\n", arr[i].id, arr[i].name);
            return 1;
        }
    }
    printf("Item not found\n");
    return 0;
}

int main() {
    int size;
    printf("Enter the number of items in the array: ");
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Array size too large\n");
        return 1;
    }

    Item arr[size];

    printf("Enter the items:\n");
    for (int i = 0; i < size; i++) {
        printf("ID for item %d: ", i+1);
        scanf("%d", &arr[i].id);
        printf("Name for item %d: ", i+1);
        scanf("%s", arr[i].name);
    }

    int target_id;
    printf("Enter the ID of the item to search for: ");
    scanf("%d", &target_id);

    search(arr, size, target_id);

    return 0;
}