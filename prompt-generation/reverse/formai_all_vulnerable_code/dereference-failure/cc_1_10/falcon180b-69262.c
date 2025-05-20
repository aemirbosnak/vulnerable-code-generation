//Falcon-180B DATASET v1.0 Category: String manipulation ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main() {
    char input_string[MAX_STRING_LENGTH];
    char *original_string = NULL;
    char *modified_string = NULL;
    int string_length;

    // Get input string from user
    printf("Enter a string: ");
    fgets(input_string, MAX_STRING_LENGTH, stdin);
    string_length = strlen(input_string) - 1;

    // Allocate memory for original string
    original_string = malloc(string_length + 1);
    if (original_string == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Copy input string to original string
    strcpy(original_string, input_string);

    // Reverse the original string
    char *start = original_string;
    char *end = original_string + string_length - 1;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }

    // Allocate memory for modified string
    modified_string = malloc(string_length + 1);
    if (modified_string == NULL) {
        printf("Error: Memory allocation failed.\n");
        exit(1);
    }

    // Copy original string to modified string
    strcpy(modified_string, original_string);

    // Remove all vowels from modified string
    char vowels[] = "aeiouAEIOU";
    char *remove_vowels = strtok(modified_string, vowels);
    char *result = remove_vowels;

    // Concatenate the modified string without vowels
    while (result!= NULL) {
        strcat(result, " ");
        result = strtok(NULL, vowels);
    }

    // Print the modified string without vowels
    printf("Modified string without vowels: %s\n", result);

    // Free memory allocated for strings
    free(original_string);
    free(modified_string);

    return 0;
}