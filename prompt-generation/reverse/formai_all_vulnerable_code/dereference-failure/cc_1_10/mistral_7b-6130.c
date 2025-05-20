//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define MAX_INPUT_SIZE 1024
#define BUF_SIZE 1024

void sanitize_input(char *input, size_t *len) {
    size_t i;
    for (i = 0; i < *len; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            *len = i;
            break;
        }
        if (input[i] >= ' ' && input[i] <= '~') {
            // keep only printable ASCII characters
        } else if (input[i] == '\t') {
            // replace tab characters with spaces
            input[i] = ' ';
        } else {
            // replace all other characters with null characters
            input[i] = '\0';
            *len = i;
            printf("Error: invalid character encountered.\n");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    char input[MAX_INPUT_SIZE];
    size_t len = 0;
    char *sanitized;

    printf("Please enter some input: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    len = strlen(input);
    sanitized = mmap(NULL, BUF_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
    strncpy(sanitized, input, len);

    sanitize_input(sanitized, &len);

    printf("Sanitized input: %s\n", sanitized);

    munmap(sanitized, BUF_SIZE);

    return 0;
}