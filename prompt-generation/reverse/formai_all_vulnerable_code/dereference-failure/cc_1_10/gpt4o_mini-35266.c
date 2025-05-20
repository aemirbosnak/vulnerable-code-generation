//GPT-4o-mini DATASET v1.0 Category: Sorting ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 100

// Function to compare two strings for qsort
int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

// Function to sort an array of strings
void sortStrings(char *arr[], int n) {
    qsort(arr, n, sizeof(char *), compareStrings);
}

// Function to read strings from the user
int readStrings(char *arr[], int maxElements) {
    int count = 0;
    char buffer[100];
    
    printf("Enter up to %d strings (type 'exit' to stop):\n", maxElements);
    
    while (count < maxElements) {
        printf("String %d: ", count + 1);
        fgets(buffer, 100, stdin);
        buffer[strcspn(buffer, "\n")] = 0; // Remove newline character

        if (strcmp(buffer, "exit") == 0) {
            break;
        }

        arr[count] = malloc(strlen(buffer) + 1); // Allocate memory
        if (arr[count] == NULL) {
            perror("Unable to allocate memory");
            exit(EXIT_FAILURE);
        }

        strcpy(arr[count], buffer);
        count++;
    }
    
    return count;
}

// Function to free the allocated memory for strings
void freeStrings(char *arr[], int n) {
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
}

// Function to display sorted strings
void displayStrings(char *arr[], int n) {
    printf("\nSorted Strings:\n");
    for (int i = 0; i < n; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    char *strings[MAX_ELEMENTS];
    int n = readStrings(strings, MAX_ELEMENTS);
    
    if (n == 0) {
        printf("No strings entered. Exiting program.\n");
        return EXIT_SUCCESS;
    }

    printf("\nYou entered %d strings, now sorting...\n", n);
    sortStrings(strings, n);
    
    displayStrings(strings, n);
    freeStrings(strings, n);

    return EXIT_SUCCESS;
}