//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024

void remove_duplicates(FILE *input, FILE *output) {
    char line[MAX_LINE_LENGTH];
    char *saved_line = NULL;

    while (fgets(line, sizeof(line), input)) {
        size_t length = strlen(line);
        if (saved_line) {
            if (strncmp(line, saved_line, length) == 0) {
                free(line);
                continue;
            }
        }
        fputs(line, output);
        saved_line = strdup(line);
    }

    if (saved_line) {
        free(saved_line);
    }
}

int main(int argc, char *argv[]) {
    FILE *input = NULL;
    FILE *output = NULL;

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    if (!input) {
        perror("Error opening input file");
        return 1;
    }

    output = fopen(argv[2], "w");
    if (!output) {
        perror("Error opening output file");
        fclose(input);
        return 1;
    }

    remove_duplicates(input, output);

    fclose(input);
    fclose(output);

    return 0;
}