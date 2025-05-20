//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Function to compare two strings
int compare(char *str1, char *str2) {
    int result = 0;
    int i = 0;
    while (str1[i]!= '\0' && str2[i]!= '\0' && result == 0) {
        if (str1[i]!= str2[i]) {
            result = 1;
        }
        i++;
    }
    return result;
}

// Function to search for a string in an array of strings
int search(char **array, int size, char *str) {
    int result = -1;
    int i = 0;
    while (i < size && result == -1) {
        if (compare(array[i], str) == 0) {
            result = i;
        }
        i++;
    }
    return result;
}

// Function to sort an array of strings
void sort(char **array, int size) {
    int i, j;
    char *temp;
    for (i = 0; i < size - 1; i++) {
        for (j = i + 1; j < size; j++) {
            if (compare(array[i], array[j]) > 0) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main() {
    char **array;
    int size = 0;
    char input[MAX_SIZE];

    // Read input strings
    printf("Enter strings (enter 'done' when finished):\n");
    while (fgets(input, MAX_SIZE, stdin)!= NULL) {
        if (strcmp(input, "done") == 0) {
            break;
        }
        array = realloc(array, sizeof(char *) * ++size);
        array[size - 1] = strdup(input);
    }

    // Sort the array
    sort(array, size);

    // Search for a string
    char search_str[MAX_SIZE];
    printf("Enter a string to search for:\n");
    fgets(search_str, MAX_SIZE, stdin);
    int index = search(array, size, search_str);
    if (index == -1) {
        printf("String not found.\n");
    } else {
        printf("Found at index %d.\n", index);
    }

    // Free memory
    for (int i = 0; i < size; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}