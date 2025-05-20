//Falcon-180B DATASET v1.0 Category: Memory management ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to read a line from standard input
char* read_line() {
    char* line = (char*) malloc(MAX_LINE_LENGTH * sizeof(char));
    fgets(line, MAX_LINE_LENGTH, stdin);
    return line;
}

// Function to reverse a string
void reverse_string(char* str) {
    int length = strlen(str);
    char* reversed = (char*) malloc((length + 1) * sizeof(char));
    for (int i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }
    reversed[length] = '\0';
    strcpy(str, reversed);
    free(reversed);
}

// Function to remove leading and trailing whitespace from a string
void trim_string(char* str) {
    int length = strlen(str);
    int start = 0;
    while (isspace(str[start])) {
        start++;
    }
    int end = length - 1;
    while (isspace(str[end])) {
        end--;
    }
    int new_length = end - start + 1;
    char* trimmed = (char*) malloc(new_length * sizeof(char));
    strncpy(trimmed, str + start, new_length);
    trimmed[new_length - 1] = '\0';
    strcpy(str, trimmed);
    free(trimmed);
}

// Function to remove duplicate characters from a string
void remove_duplicates(char* str) {
    int length = strlen(str);
    int new_length = 0;
    char* new_str = (char*) malloc(length * sizeof(char));
    new_str[new_length++] = str[0];
    for (int i = 1; i < length; i++) {
        if (str[i]!= str[i - 1]) {
            new_str[new_length++] = str[i];
        }
    }
    strcpy(str, new_str);
    free(new_str);
}

// Function to remove all vowels from a string
void remove_vowels(char* str) {
    int length = strlen(str);
    int new_length = 0;
    char* new_str = (char*) malloc(length * sizeof(char));
    for (int i = 0; i < length; i++) {
        if (str[i]!= 'a' && str[i]!= 'e' && str[i]!= 'i' && str[i]!= 'o' && str[i]!= 'u' && str[i]!= 'A' && str[i]!= 'E' && str[i]!= 'I' && str[i]!= 'O' && str[i]!= 'U') {
            new_str[new_length++] = str[i];
        }
    }
    strcpy(str, new_str);
    free(new_str);
}

int main() {
    char* input_str = read_line();
    trim_string(input_str);
    reverse_string(input_str);
    remove_duplicates(input_str);
    remove_vowels(input_str);
    printf("Modified string: %s\n", input_str);
    return 0;
}