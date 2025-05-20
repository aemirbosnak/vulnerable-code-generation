//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 200 // Maximum length of user input

// This function removes leading and trailing whitespaces from a string
char* trim(char* str) {
    char* end;
    while (isspace((unsigned char)*str)) str++;
    if (*str == 0) return str;
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;
    *(end + 1) = 0;
    return str;
}

// This function replaces any instance of '<' or '>' with their respective HTML entities
char* sanitize(char* str) {
    char* out = (char*)malloc(MAX_INPUT_LENGTH * sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == '<') {
            out[j++] = '&';
            out[j++] = 'l';
            out[j++] = 't';
            out[j++] = ';';
        }
        else if (str[i] == '>') {
            out[j++] = '&';
            out[j++] = 'g';
            out[j++] = 't';
            out[j++] = ';';
        }
        else {
            out[j++] = str[i];
        }
    }
    out[j] = '\0';
    return out;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter some text: ");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline from fgets input

    char* sanitized_input = sanitize(trim(input));
    printf("Sanitized input: %s\n", sanitized_input);
    free(sanitized_input); // Free dynamically allocated memory

    return 0;
}