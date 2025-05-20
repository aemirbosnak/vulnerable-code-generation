//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Custom Error Structure
typedef struct Error {
    char *message;
    int errorCode;
} Error;

// Function to allocate memory and check for errors
void *my_malloc(size_t size) {
    void *ptr = malloc(size);
    if (ptr == NULL) {
        Error err = {.message = "Memory Allocation Failed!", .errorCode = 1};
        fprintf(stderr, "%s\n", err.message);
        exit(err.errorCode);
    }
    return ptr;
}

// Function to read a string from user input with error handling
char *get_string(char *prompt) {
    char *input = NULL;
    size_t len = 0;
    ssize_t bytesRead;

    printf("%s", prompt);
    input = my_malloc(MAX_LEN + 1);

    if (getline(&input, &len, stdin) < 0) {
        Error err = {.message = "Error reading input", .errorCode = 2};
        fprintf(stderr, "%s\n", err.message);
        free(input);
        exit(err.errorCode);
    }

    if (strchr(input, '\n') != NULL) {
        size_t index = strlen(input) - 1;
        if (input[index] == '\n') {
            input[index] = '\0';
        }
    }

    return input;
}

int main(void) {
    char *str1, *str2;

    str1 = get_string("Enter first string: ");
    str2 = get_string("Enter second string: ");

    // Function to compare two strings with error handling
    int result = my_strcmp(str1, str2);

    if (result != 0) {
        printf("Strings are not equal.\n");
    } else {
        printf("Strings are equal.\n");
    }

    free(str1);
    free(str2);

    return 0;
}

// Custom strcmp function with error handling
int my_strcmp(char *str1, char *str2) {
    int ret = strcmp(str1, str2);

    if (ret != 0) {
        return ret;
    }

    Error err = {.message = "Strings are identical!", .errorCode = 3};
    fprintf(stderr, "%s\n", err.message);
    exit(err.errorCode);
}