//LLAMA2-13B DATASET v1.0 Category: Text processing ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024
#define MAX_ARRAY_SIZE 64

void safe_strcpy(char *dest, const char *src) {
    if (dest == NULL || src == NULL) {
        return;
    }
    size_t len = strlen(src);
    if (len >= MAX_LINE_LENGTH) {
        len = MAX_LINE_LENGTH - 1;
    }
    memcpy(dest, src, len + 1);
}

int main() {
    char buffer[MAX_ARRAY_SIZE];
    char *line = NULL;
    size_t line_len = 0;

    // Read input from standard input
    while (fgets(buffer, MAX_ARRAY_SIZE, stdin) != NULL) {
        line = buffer;
        line_len = strlen(line);

        // Trim trailing newline and whitespace
        line[line_len - 1] = '\0';
        while (line_len > 0 && isspace(line[line_len - 1])) {
            line_len--;
        }

        // Check if line is too long
        if (line_len >= MAX_LINE_LENGTH) {
            printf("Line too long, truncating...\n");
            line_len = MAX_LINE_LENGTH - 1;
        }

        // Copy line to safe_strcpy()-allocated memory
        char *safe_line = malloc(line_len + 1);
        safe_strcpy(safe_line, line);

        // Print line with trailing newline
        printf("%s\n", safe_line);

        // Free memory
        free(safe_line);
    }

    return 0;
}