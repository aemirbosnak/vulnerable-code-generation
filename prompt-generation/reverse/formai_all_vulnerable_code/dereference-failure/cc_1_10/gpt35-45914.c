//FormAI DATASET v1.0 Category: HTML beautifier ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAB_SIZE 4 // number of spaces per tab

void beautify(char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s filename.html\n", argv[0]);
        return 1;
    }
    beautify(argv[1]);
    return 0;
}

void beautify(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Cannot open file: %s\n", filename);
        return;
    }

    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t linelen;
    int indent_level = 0;

    while ((linelen = getline(&buffer, &bufsize, file)) != -1) {
        // Remove trailing whitespace
        while (linelen > 0 && (buffer[linelen - 1] == ' ' || buffer[linelen - 1] == '\t')) {
            linelen--;
            buffer[linelen] = '\0';
        }

        // Determine the indent level
        int i;
        for (i = 0; i < linelen && (buffer[i] == ' ' || buffer[i] == '\t'); i++) {
            if (buffer[i] == '\t') {
                indent_level++;
            } else {
                indent_level += TAB_SIZE;
            }
        }

        // Output the line with the appropriate indentation
        int j;
        printf("%*s", indent_level, "");
        for (j = i; j < linelen; j++) {
            putchar(buffer[j]);
        }
        putchar('\n');

        // Handle opening and closing tags on separate lines
        if (strstr(buffer, "</") != NULL) {
            indent_level--;
        }
        if (strstr(buffer, "<") != NULL && strstr(buffer, "</") == NULL) {
            indent_level++;
        }
    }

    free(buffer);
    fclose(file);
}