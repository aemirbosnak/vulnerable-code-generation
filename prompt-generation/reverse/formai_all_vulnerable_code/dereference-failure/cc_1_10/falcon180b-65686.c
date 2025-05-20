//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARRAY_SIZE 1000

int main() {
    char *arr[MAX_ARRAY_SIZE];
    int size = 0;

    // Prompt user to enter strings
    while (1) {
        char input[100];
        printf("Enter a string (enter 'done' to finish): ");
        scanf("%s", input);

        if (strcmp(input, "done") == 0) {
            break;
        }

        if (size >= MAX_ARRAY_SIZE) {
            printf("Array is full. Please remove some strings.\n");
            continue;
        }

        arr[size] = (char *)malloc(strlen(input) + 1);
        strcpy(arr[size], input);
        size++;
    }

    // Prompt user to enter search string
    char search[100];
    printf("Enter a string to search for: ");
    scanf("%s", search);

    // Perform search
    int found = 0;
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i], search) == 0) {
            printf("String found at index %d.\n", i);
            found = 1;
        }
    }

    if (!found) {
        printf("String not found.\n");
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }

    return 0;
}