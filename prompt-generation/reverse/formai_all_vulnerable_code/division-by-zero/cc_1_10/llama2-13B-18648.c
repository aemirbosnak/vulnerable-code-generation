//LLAMA2-13B DATASET v1.0 Category: Error handling ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to print an error message and exit the program
void oopsie(const char *message) {
    fprintf(stderr, "%s\n", message);
    exit(EXIT_FAILURE);
}

int main() {
    // Try to divide by zero! 😱
    int result = 10 / 0;

    // Handle the error gracefully
    if (result == -1) {
        printf("Whoops! Division by zero is not allowed.\n");
        return 0;
    }

    // Try to access an invalid array index! 😲
    char arr[5] = "hello";
    printf("%c\n", arr[6]);

    // Handle the error gracefully
    if (arr[6] == '\0') {
        printf("Oops! Array index out of bounds.\n");
        return 0;
    }

    // Try to allocate an invalid memory! 😳
    int *ptr = malloc(10 * sizeof(int));

    // Handle the error gracefully
    if (ptr == NULL) {
        printf("Uh-oh! Memory allocation failed.\n");
        return 0;
    }

    // Try to read an invalid file! 😟
    FILE *file = fopen("non_existent_file.txt", "r");

    // Handle the error gracefully
    if (file == NULL) {
        printf("Oops! File not found.\n");
        return 0;
    }

    // Try to execute an invalid system call! 😨
    system("non_existent_command");

    // Handle the error gracefully
    if (system("non_existent_command") == -1) {
        printf("Whoops! System call failed.\n");
        return 0;
    }

    return 1;
}