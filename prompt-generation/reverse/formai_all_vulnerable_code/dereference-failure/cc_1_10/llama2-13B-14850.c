//LLAMA2-13B DATASET v1.0 Category: String manipulation ; Style: active
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 100

// Function to reverse a string
void reverse_string(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to find the first duplicate character in a string
int find_duplicate(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = 1; i < strlen(str); i++, j++) {
        if (str[i] == str[j]) {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            return j;
        }
    }

    return -1;
}

// Function to remove duplicates from a string
void remove_duplicates(char *str) {
    int i, j;
    char temp;

    for (i = 0, j = 1; i < strlen(str); i++, j++) {
        if (str[i] != str[j]) {
            str[j] = str[i];
        }
    }
}

int main() {
    char str[] = "hello world banana apple orange";

    // Reverse the string
    reverse_string(str);
    printf("Reversed string: %s\n", str);

    // Find the first duplicate character in the string
    int idx = find_duplicate(str);
    printf("First duplicate character index: %d\n", idx);

    // Remove duplicates from the string
    remove_duplicates(str);
    printf("String after removing duplicates: %s\n", str);

    return 0;
}