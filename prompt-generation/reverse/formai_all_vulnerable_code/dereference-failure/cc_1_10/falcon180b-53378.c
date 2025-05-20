//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to compare two strings
int compare(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = (len1 < len2)? len1 : len2;

    for (int i = 0; i < min_len; i++) {
        if (str1[i]!= str2[i]) {
            return str1[i] - str2[i];
        }
    }

    return 0;
}

// Function to search for a string in an array of strings
int search(char** arr, int size, char* str) {
    int result = -1;

    for (int i = 0; i < size; i++) {
        if (compare(arr[i], str) == 0) {
            result = i;
            break;
        }
    }

    return result;
}

// Function to sort an array of strings
void sort(char** arr, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (compare(arr[i], arr[j]) > 0) {
                char* temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// Function to print an array of strings
void print_array(char** arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%s\n", arr[i]);
    }
}

int main() {
    char** arr = (char**)malloc(MAX_SIZE * sizeof(char*));
    int size = 0;

    // Add strings to array
    arr[size++] = "apple";
    arr[size++] = "banana";
    arr[size++] = "cherry";
    arr[size++] = "date";
    arr[size++] = "elderberry";

    // Sort array
    sort(arr, size);

    // Print sorted array
    printf("Sorted array:\n");
    print_array(arr, size);

    // Search for a string
    char* search_str = "banana";
    int index = search(arr, size, search_str);

    if (index == -1) {
        printf("String not found\n");
    } else {
        printf("String found at index %d\n", index);
    }

    free(arr);

    return 0;
}