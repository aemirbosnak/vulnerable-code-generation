//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1024
#define GROW_BY 128

void safe_getline(char **line, size_t *size) {
    char *buf = *line;
    size_t current_size = *size;

    if (current_size <= 0) {
        if (*line) free(*line);
        *line = malloc(MAX_INPUT);
        *size = MAX_INPUT;
        buf = *line;
    }

    if (fgets(buf, current_size, stdin) != NULL) {
        size_t new_size = current_size + GROW_BY;

        while (strchr(buf, '\n') == NULL && fgets(buf + current_size, GROW_BY, stdin) != NULL) {
            new_size += GROW_BY;
        }

        if (new_size > *size) {
            *line = realloc(*line, new_size);
            *size = new_size;
        }
    }

    if (strchr(buf, '\n') == NULL) {
        free(*line);
        *line = NULL;
        *size = 0;
    }
}

int main() {
    char *input = NULL;
    size_t size = 0;

    while (1) {
        safe_getline(&input, &size);
        if (input == NULL) {
            break;
        }

        printf("You entered: %s\n", input);
        free(input);
    }

    return 0;
}