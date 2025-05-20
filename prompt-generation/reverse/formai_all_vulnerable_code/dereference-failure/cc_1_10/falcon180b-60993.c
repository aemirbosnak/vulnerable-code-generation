//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

// Function to compare two strings
int compare(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int min_len = len1 < len2? len1 : len2;

    for (int i = 0; i < min_len; i++) {
        if (str1[i]!= str2[i]) {
            return 0;
        }
    }

    return 1;
}

// Function to search for a string in an array of strings
int binary_search(char **arr, int size, char *str) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (compare(arr[mid], str)) {
            return mid;
        } else if (strcmp(arr[mid], str) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    char **names = malloc(SIZE * sizeof(char *));
    int count = 0;

    // Add names to the array
    names[count++] = "Sherlock Holmes";
    names[count++] = "Dr. John Watson";
    names[count++] = "Professor Moriarty";
    names[count++] = "Mycroft Holmes";
    names[count++] = "Irene Adler";

    // Sort the array
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (strcmp(names[j], names[i]) < 0) {
                char *temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }

    // Search for a name
    char *query = "Professor Moriarty";
    int index = binary_search(names, count, query);

    if (index == -1) {
        printf("Name not found.\n");
    } else {
        printf("Name found at index %d.\n", index);
    }

    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    free(names);

    return 0;
}