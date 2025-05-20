//LLAMA2-13B DATASET v1.0 Category: Sorting ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// A struct to represent a person's name and age
typedef struct {
    char name[MAX_LEN];
    int age;
} person_t;

// A function to sort an array of persons based on their age
void sort_by_age(person_t *arr, int len) {
    int i, j, min_idx;

    // Find the first element that is not in order
    for (i = 0; i < len - 1; i++) {
        if (arr[i].age > arr[i + 1].age) {
            min_idx = i;
            break;
        }
    }

    // If no elements are found, return
    if (min_idx == len - 1) {
        return;
    }

    // Swap the first and last elements
    person_t temp = arr[min_idx];
    arr[min_idx] = arr[len - 1];
    arr[len - 1] = temp;

    // Recursively sort the remaining elements
    sort_by_age(arr, len - 1);
}

int main() {
    person_t arr[5] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 20},
        {"David", 35},
        {"Eve", 40}
    };
    int len = sizeof(arr) / sizeof(arr[0]);

    // Sort the array based on age
    sort_by_age(arr, len);

    // Print the sorted array
    for (int i = 0; i < len; i++) {
        printf("%s %d\n", arr[i].name, arr[i].age);
    }

    return 0;
}