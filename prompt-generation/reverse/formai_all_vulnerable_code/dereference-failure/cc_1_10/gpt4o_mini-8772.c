//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024
#define INDENT_SIZE 4

void beautify_html(const char *input) {
    char line[BUFFER_SIZE];
    int indent_level = 0;
    int in_tag = 0;
    int i, j;

    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] == '<') {
            in_tag = 1;
            if (i > 0 && input[i-1] != '\n') {
                printf("\n");
                for (j = 0; j < indent_level * INDENT_SIZE; j++) {
                    putchar(' ');
                }
            }
            // Print the opening tag
            while (input[i] != '>' && input[i] != '\0') {
                putchar(input[i++]);
            }
            putchar(input[i]); // Print '>'
            // Handle indent level for certain tags
            if (strncmp(&input[i - strlen(input + i)], "</", 2) != 0) {
                indent_level++;
            } else {
                indent_level--;
            }
            printf("\n");
            for (j = 0; j < indent_level * INDENT_SIZE; j++) {
                putchar(' ');
            }
        } else {
            if (!in_tag && input[i] != '\n') {
                putchar(input[i]);
            } else if (input[i] == '\n') {
                in_tag = 0;
                putchar('\n');
                for (j = 0; j < indent_level * INDENT_SIZE; j++) {
                    putchar(' ');
                }
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <html_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    char *buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if (!buffer) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        fclose(file);
        return EXIT_FAILURE;
    }

    size_t read_size;
    while ((read_size = fread(buffer, sizeof(char), BUFFER_SIZE, file)) > 0) {
        buffer[read_size] = '\0';
        beautify_html(buffer);
    }

    free(buffer);
    fclose(file);
    return EXIT_SUCCESS;
}