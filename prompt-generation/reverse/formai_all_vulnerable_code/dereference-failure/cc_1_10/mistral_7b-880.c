//MISTRAL-7B DATASET v1.0 Category: String manipulation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_INPUT_SIZE 1024
#define BUFFER_SIZE 256

void strReplaceAll(char *str, const char *from, const char *to);

int main() {
    char input[MAX_INPUT_SIZE];
    char from[BUFFER_SIZE];
    char to[BUFFER_SIZE];
    char output[MAX_INPUT_SIZE];

    printf("Enter a string: ");
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character

    printf("Enter the substring to replace: ");
    fgets(from, BUFFER_SIZE, stdin);
    from[strcspn(from, "\n")] = '\0'; // Remove newline character

    printf("Enter the replacement substring: ");
    fgets(to, BUFFER_SIZE, stdin);
    to[strcspn(to, "\n")] = '\0'; // Remove newline character

    // Validate input
    if (strlen(from) > BUFFER_SIZE / 2 || strlen(to) > BUFFER_SIZE / 2) {
        printf("Error: Input strings are too long.\n");
        return 1;
    }

    strReplaceAll(input, from, to);
    strcpy(output, input);

    printf("Original string: %s\n", input);
    printf("Modified string: %s\n", output);

    return 0;
}

void strReplaceAll(char *str, const char *from, const char *to) {
    size_t length = strlen(str);
    size_t from_len = strlen(from);
    size_t to_len = strlen(to);

    char *result = malloc((length + to_len - from_len) * sizeof(char) + 1);

    char *start = str;
    while (*start != '\0') {
        char *current = start;
        size_t remaining = length - (start - str);

        while (remaining >= from_len && strncmp(current, from, from_len) == 0) {
            strncpy(current, to, to_len);
            length += to_len - from_len;
            remaining -= from_len;
            current += to_len;
        }

        start = ++current;
    }

    strcpy(result, str);
    free(str);
    strcpy(str, result);
    free(result);
}