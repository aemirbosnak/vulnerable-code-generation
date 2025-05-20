//MISTRAL-7B DATASET v1.0 Category: Palindrome Checker ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <errno.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 1024

// Function to check if a character is alphanumeric
int is_alphanumeric(char c) {
    return (isalpha(c) || isdigit(c));
}

// Function to check if a string is a palindrome using stack
int is_palindrome(char *str) {
    int top = -1;
    size_t len = strlen(str);

    if (len > MAX_INPUT_SIZE) {
        fprintf(stderr, "Error: Input string is too long\n");
        return 0;
    }

    char *input = mmap(NULL, len + 1, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (input == MAP_FAILED) {
        perror("Error: Failed to allocate memory for input string");
        return 0;
    }

    memcpy(input, str, len + 1);

    char stack[len + 1];
    int i = 0;

    for (; i < len / 2; i++) {
        // Push characters to stack
        while (top >= 0 && stack[top] != input[i]) {
            top--;
        }
        top++;
        stack[top] = input[i];

        // Check if last character matches with the current character
        if (input[i] != input[len - i - 1]) {
            munmap(input, len + 1);
            return 0;
        }
    }

    // Check for odd length palindrome
    if (len % 2 == 1) {
        if (top == -1 || stack[top] != input[len / 2]) {
            munmap(input, len + 1);
            return 0;
        }
    }

    munmap(input, len + 1);
    return 1;
}

int main() {
    char str[MAX_INPUT_SIZE];

    printf("Enter a string: ");
    fgets(str, MAX_INPUT_SIZE, stdin);

    // Remove newline character from input
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }

    if (is_alphanumeric(str[0]) == 0) {
        fprintf(stderr, "Error: Input string should start with an alphanumeric character\n");
        return 1;
    }

    int result = is_palindrome(str);

    if (result) {
        printf("The given string is a palindrome\n");
    } else {
        printf("The given string is not a palindrome\n");
    }

    return 0;
}