//MISTRAL-7B DATASET v1.0 Category: Error handling ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_NUM_LINES 10

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main() {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int lines_read = 0;
    char *token;

    if ((file = fopen("input.txt", "r")) == NULL) {
        die("Could not open file");
    }

    while (fgets(line, sizeof(line), file) != NULL && lines_read < MAX_NUM_LINES) {
        size_t len = strlen(line);
        if (len > 0 && line[len - 1] == '\n') { // remove trailing newline
            line[len - 1] = '\0';
        }

        token = strtok(line, " ");
        if (token == NULL) {
            fprintf(stderr, "Invalid line format: %s\n", line);
            continue;
        }

        int num = atoi(token);
        if (errno == ERANGE) {
            fprintf(stderr, "Number too large: %s\n", line);
            continue;
        }

        if (num < 0) {
            fprintf(stderr, "Invalid number: %s\n", line);
            continue;
        }

        lines_read++;
        printf("Line %d: %s\n", lines_read, line);
    }

    if (feof(file)) {
        fprintf(stderr, "End of file reached\n");
    } else {
        die("Unexpected error reading file");
    }

    fclose(file);
    return EXIT_SUCCESS;
}