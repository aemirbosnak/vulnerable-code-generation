//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STR_LEN 50

// Function to reverse a string
void reverse_str(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to find the first duplicate in a string
int find_dup(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = 1; i < strlen(str); i++, j++) {
        if (str[i] == str[j]) {
            // Found a duplicate, return its index
            return j;
        }
    }

    // No duplicates found, return -1
    return -1;
}

// Function to remove duplicates from a string
void remove_duplicates(char *str) {
    int i, j, k;
    char temp;

    for (i = 0, j = 1; i < strlen(str); i++, j++) {
        if (str[i] == str[j]) {
            // Found a duplicate, skip the next iteration
            continue;
        }

        // Not a duplicate, add to the new string
        temp = str[i];
        str[j] = temp;
    }

    // Remove the last duplicate
    str[j] = '\0';
}

int main() {
    char str[] = "hello world duplicate";

    // Reverse the string
    reverse_str(str);
    printf("Reversed string: %s\n", str);

    // Find the first duplicate in the string
    int dup_idx = find_dup(str);
    printf("First duplicate index: %d\n", dup_idx);

    // Remove duplicates from the string
    remove_duplicates(str);
    printf("String after removing duplicates: %s\n", str);

    return 0;
}