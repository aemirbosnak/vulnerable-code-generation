//FormAI DATASET v1.0 Category: HTML beautifier ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 2000
#define INDENTATION_SPACES 2

void print_help_menu() {
    printf("usage: html-beautifier [filename]\n");
}

void parse_line(char* line, int* indentation_level) {
    bool closing_tag = false;
    if (line[0] == '<') {
        if (line[1] == '/') {
            *indentation_level = *indentation_level - 1;
            closing_tag = true;
        } else {
            *indentation_level = *indentation_level + 1;
        }
    }
    for (int i = 0; i < *indentation_level * INDENTATION_SPACES; i++) {
        printf(" ");
    }
    printf("%s\n", line);
    if (closing_tag && *indentation_level == 0) {
        printf("\n");
    }
}

void beautify_file(char* filename) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int indentation_level = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, fp)) != -1) {
        parse_line(line, &indentation_level);
    }

    fclose(fp);
    if (line) {
        free(line);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        print_help_menu();
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    beautify_file(filename);

    return 0;
}