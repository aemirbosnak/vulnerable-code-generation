//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: inquisitive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to check if a given string is safe to use
int is_safe(char *str) {
    size_t len = strlen(str);
    char *safe_str = mmap(NULL, len + 1, PROT_READ, MAP_PRIVATE, 0, 0);

    if (safe_str == MAP_FAILED) {
        perror("mmap failed");
        return 0;
    }

    int result = 1;
    for (size_t i = 0; i < len; i++) {
        if (safe_str[i] < 33 || safe_str[i] > 126) { // Invalid ASCII characters
            result = 0;
            break;
        }
    }

    munmap(safe_str, len + 1);
    return result;
}

int main() {
    char input[1024];
    printf("Inquisitive User Input Sanitizer\n");
    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    // Remove newline character from fgets() input
    size_t len = strlen(input);
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';
    }

    if (is_safe(input)) {
        printf("Sanitized Input: %s\n", input);
    } else {
        printf("Input contains invalid characters. Please enter a valid string.\n");
    }

    return 0;
}