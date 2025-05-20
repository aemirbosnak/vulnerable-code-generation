//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

void reverse_string(char *str, int start, int end);
int string_length(char *str);

int main(void) {
    char *str;
    int len;

    // Allocate memory for a C string
    str = (char *) malloc(MAX_SIZE * sizeof(char));

    // Read a string from the user and store it in the allocated memory
    printf("Enter a string: ");
    gets(str);

    // Reverse the string in-place using a recursive function
    reverse_string(str, 0, string_length(str) - 1);

    // Calculate the length of the reversed string and allocate memory for a new C string
    len = string_length(str);
    char *reversed_str = (char *) malloc((len + 1) * sizeof(char));

    // Copy the reversed string into the new allocated memory
    strcpy(reversed_str, str);

    // Free the memory allocated for the original string
    free(str);

    // Print the reversed string
    printf("Reversed string: %s\n", reversed_str);

    // Free the memory allocated for the reversed string
    free(reversed_str);

    return 0;
}

void reverse_string(char *str, int start, int end) {
    if (start >= end)
        return;

    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;

    reverse_string(str, start + 1, end - 1);
}

int string_length(char *str) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }

    return len;
}