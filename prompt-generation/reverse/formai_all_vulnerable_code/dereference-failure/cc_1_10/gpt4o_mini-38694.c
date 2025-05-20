//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a buffer size
#define BUF_SIZE 1024

// Function prototypes
void beautifyHTML(const char *inFile, const char *outFile);
void indent(int level, char *output);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }
    beautifyHTML(argv[1], argv[2]);
    return EXIT_SUCCESS;
}

void beautifyHTML(const char *inFile, const char *outFile) {
    FILE *input = fopen(inFile, "r");
    FILE *output = fopen(outFile, "w");
    if (!input || !output) {
        perror("File open error");
        exit(EXIT_FAILURE);
    }

    char buffer[BUF_SIZE];
    int level = 0;
    int i;

    while (fgets(buffer, BUF_SIZE, input)) {
        for (i = 0; buffer[i] != '\0'; i++) {
            if (buffer[i] == '<') {
                // Check for closing tags
                if (buffer[i + 1] == '/') {
                    level--;
                    indent(level, buffer);
                } else {
                    indent(level, buffer);
                    level++;
                }
            }
            putc(buffer[i], output);
        }
    }

    fclose(input);
    fclose(output);
}

void indent(int level, char *output) {
    if (level < 0) level = 0; // Prevent negative indent levels
    // Add indentation spaces
    for (int j = 0; j < level; j++) {
        fputs("    ", stdout); // Four space indentation
    }
}