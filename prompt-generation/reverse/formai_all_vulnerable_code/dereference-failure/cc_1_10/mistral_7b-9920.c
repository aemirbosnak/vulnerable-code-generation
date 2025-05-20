//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_PATTERNS 10

// Custom error message function
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to extract patterns from a given text file
void extract_patterns(char *filename, char patterns[MAX_PATTERNS][128]) {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    char pattern[128], *token;
    int pattern_index = 0;

    file = fopen(filename, "r");
    if (!file)
        error("Could not open file");

    while (fgets(line, MAX_LINE_LENGTH, file)) {
        token = strtok(line, " ");
        while (token != NULL) {
            strcpy(pattern, token);
            // Convert pattern to lowercase
            for (int i = 0; pattern[i]; i++)
                pattern[i] = tolower(pattern[i]);

            // Check if pattern matches any of the saved patterns
            for (int j = 0; j < pattern_index; j++) {
                if (strstr(patterns[j], pattern)) {
                    printf("Pattern '%s' found in line: %s\n", pattern, line);
                    break;
                }
            }

            // If pattern not found, save it
            if (pattern_index < MAX_PATTERNS) {
                strcpy(patterns[pattern_index++], pattern);
            }

            token = strtok(NULL, " ");
        }
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text_file> [pattern1 pattern2 ...]\n", argv[0]);
        exit(1);
    }

    char patterns[MAX_PATTERNS][128];
    int pattern_index = 0;

    if (argc > 2) {
        for (int i = 1; i < argc; i++) {
            if (i == 1) {
                strcpy(patterns[pattern_index++], argv[i]);
            } else {
                strcpy(patterns[pattern_index++], argv[i]);
            }
        }
    }

    extract_patterns(argv[1], patterns);

    return 0;
}