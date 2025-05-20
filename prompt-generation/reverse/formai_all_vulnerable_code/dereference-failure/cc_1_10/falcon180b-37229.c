//Falcon-180B DATASET v1.0 Category: Memory management ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    char *data;
    int size;
} String;

// Function to initialize a string
void init_string(String *str) {
    str->data = (char *)malloc(MAX_SIZE * sizeof(char));
    str->size = 0;
    str->data[0] = '\0';
}

// Function to append a character to a string
void append_char(String *str, char c) {
    if (str->size >= MAX_SIZE) {
        printf("Error: String is full.\n");
        return;
    }

    str->data[str->size++] = c;
    str->data[str->size] = '\0';
}

// Function to print a string
void print_string(const String *str) {
    printf("%s", str->data);
}

// Function to free memory used by a string
void free_string(String *str) {
    free(str->data);
    str->data = NULL;
    str->size = 0;
}

int main() {
    String str1, str2;

    // Initialize strings
    init_string(&str1);
    init_string(&str2);

    // Append characters to strings
    append_char(&str1, 'H');
    append_char(&str1, 'e');
    append_char(&str1, 'l');
    append_char(&str1, 'l');
    append_char(&str1, 'o');

    append_char(&str2, 'W');
    append_char(&str2, 'o');
    append_char(&str2, 'r');
    append_char(&str2, 'l');
    append_char(&str2, 'd');

    // Print strings
    print_string(&str1);
    print_string(&str2);

    // Free memory used by strings
    free_string(&str1);
    free_string(&str2);

    return 0;
}