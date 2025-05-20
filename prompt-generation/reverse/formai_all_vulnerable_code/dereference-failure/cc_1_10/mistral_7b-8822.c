//MISTRAL-7B DATASET v1.0 Category: Math exercise ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

#define KEYWORD_COUNT 25

typedef struct {
    char name[20];
    int length;
} Keyword;

Keyword keywords[KEYWORD_COUNT] = {
    {"if", 2},
    {"else", 4},
    {"while", 5},
    {"for", 3},
    {"int", 3},
    {"float", 5},
    {"double", 6},
    {"char", 3},
    {"void", 4},
    {"return", 6},
    {"struct", 6},
    {"switch", 6},
    {"case", 4},
    {"default", 7},
    {"sizeof", 5},
    {"typedef", 6},
    {"static", 6},
    {"break", 4},
    {"continue", 6},
    {"goto", 3},
    {"const", 5},
};

void error_handler(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int search_keyword(Keyword keyword, char *line) {
    size_t line_len = strlen(line);
    size_t i;

    for (i = 0; i < line_len; i++) {
        if (line[i] == keyword.name[0] &&
            strncmp(line + i, keyword.name, keyword.length) == 0) {
            return i;
        }
    }

    return -1;
}

int main(int argc, char *argv[]) {
    FILE *file;
    char line[1024];
    char filename[128];
    Keyword current_keyword;
    int keyword_position;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    strcpy(filename, argv[1]);
    file = fopen(filename, "r");

    if (file == NULL) {
        error_handler("Failed to open file");
    }

    while (fgets(line, sizeof(line), file) != NULL) {
        for (int i = 0; i < KEYWORD_COUNT; i++) {
            keyword_position = search_keyword(keywords[i], line);
            if (keyword_position >= 0) {
                strcpy(current_keyword.name, keywords[i].name);
                current_keyword.length = keywords[i].length;
                printf("Found keyword '%s' at position %d in line: %s\n",
                       current_keyword.name, keyword_position, line);
                break;
            }
        }
    }

    fclose(file);

    return EXIT_SUCCESS;
}