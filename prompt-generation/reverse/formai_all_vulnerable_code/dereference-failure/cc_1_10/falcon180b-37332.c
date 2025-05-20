//Falcon-180B DATASET v1.0 Category: Text to ASCII art generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE_LENGTH 80
#define MAX_FILE_SIZE 1000000

// Function to clean up memory and exit program
void cleanup(char **lines) {
    for (int i = 0; lines[i]!= NULL; i++) {
        free(lines[i]);
    }
    free(lines);
    exit(0);
}

// Function to read file into memory and store as array of strings
char **read_file(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        cleanup(NULL);
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    if (file_size > MAX_FILE_SIZE) {
        printf("Error: file '%s' is too large\n", filename);
        cleanup(NULL);
    }

    char **lines = malloc(sizeof(char *) * (file_size / MAX_LINE_LENGTH + 1));
    for (int i = 0; i < file_size / MAX_LINE_LENGTH + 1; i++) {
        lines[i] = malloc(MAX_LINE_LENGTH * sizeof(char));
    }

    int line_number = 0;
    char ch;
    while ((ch = fgetc(file))!= EOF) {
        if (isspace(ch)) {
            lines[line_number][strlen(lines[line_number]) - 1] = '\0';
            line_number++;
        } else {
            strncat(lines[line_number], &ch, 1);
        }
    }

    lines[line_number][strlen(lines[line_number]) - 1] = '\0';

    fclose(file);

    return lines;
}

// Function to generate ASCII art from lines of text
void generate_art(char **lines) {
    int max_width = 0;
    for (int i = 0; lines[i]!= NULL; i++) {
        int width = strlen(lines[i]);
        if (width > max_width) {
            max_width = width;
        }
    }

    for (int i = 0; lines[i]!= NULL; i++) {
        int padding = (max_width - strlen(lines[i])) / 2;
        printf("%*s%s\n", padding, "", lines[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        cleanup(NULL);
    }

    char **lines = read_file(argv[1]);
    if (lines == NULL) {
        return 0;
    }

    generate_art(lines);

    for (int i = 0; lines[i]!= NULL; i++) {
        free(lines[i]);
    }
    free(lines);

    return 0;
}