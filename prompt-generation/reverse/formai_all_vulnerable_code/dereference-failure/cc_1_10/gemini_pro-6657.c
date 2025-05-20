//GEMINI-pro DATASET v1.0 Category: Cat Language Translator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

// Function to translate a line of text from Cat Language to English
char *translate_line(char *line) {
    char *translated_line = malloc(MAX_LINE_LENGTH);
    int i, j;
    for (i = 0, j = 0; line[i] != '\0'; i++) {
        switch (line[i]) {
            case 'm':
                translated_line[j++] = 'n';
                break;
            case 'n':
                translated_line[j++] = 'm';
                break;
            case 'a':
                translated_line[j++] = 'o';
                break;
            case 'o':
                translated_line[j++] = 'a';
                break;
            case 'w':
                translated_line[j++] = 'u';
                break;
            case 'u':
                translated_line[j++] = 'w';
                break;
            default:
                translated_line[j++] = line[i];
                break;
        }
    }
    translated_line[j] = '\0';
    return translated_line;
}

// Function to read a line of text from a file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    int i;
    for (i = 0; i < MAX_LINE_LENGTH - 1 && !feof(file); i++) {
        line[i] = fgetc(file);
        if (line[i] == '\n') {
            line[i] = '\0';
            break;
        }
    }
    return line;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    char *line;
    while ((line = read_line(file)) != NULL) {
        char *translated_line = translate_line(line);
        printf("%s\n", translated_line);
        free(translated_line);
        free(line);
    }

    fclose(file);
    return EXIT_SUCCESS;
}