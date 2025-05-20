//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to compare two strings (case insensitive)
int compare(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    if (len1!= len2) {
        return 1;
    }

    for (int i = 0; i < len1; i++) {
        if (tolower(str1[i])!= tolower(str2[i])) {
            return 1;
        }
    }

    return 0;
}

// Function to search for a string in an array of strings (case insensitive)
int search(char** arr, int size, char* target) {
    for (int i = 0; i < size; i++) {
        if (compare(arr[i], target) == 0) {
            printf("%s found at index %d\n", target, i);
            return 1;
        }
    }

    printf("%s not found\n", target);
    return 0;
}

int main() {
    char** arr = malloc(5 * sizeof(char*));
    int size = 5;

    // Initialize array
    arr[0] = "apple";
    arr[1] = "banana";
    arr[2] = "cherry";
    arr[3] = "date";
    arr[4] = "elderberry";

    char* target = "banana";

    search(arr, size, target);

    for (int i = 0; i < size; i++) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}