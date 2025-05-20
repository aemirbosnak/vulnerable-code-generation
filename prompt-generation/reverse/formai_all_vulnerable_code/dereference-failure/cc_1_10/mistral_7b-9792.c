//MISTRAL-7B DATASET v1.0 Category: File handling ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LINE_LENGTH 1024
#define WORD_DELIMITER " \t\r\n\f,"

void reverse_word(char *word) {
    int i = 0, j = strlen(word) - 1;
    char temp;

    while (i < j) {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
        i++;
        j--;
    }
}

bool is_delimiter(char c) {
    char delimiters[] = WORD_DELIMITER;

    for (int i = 0; delimiters[i]; i++) {
        if (delimiters[i] == c) {
            return true;
        }
    }

    return false;
}

size_t read_line(FILE *input, char *line, size_t max_size) {
    size_t current_size = 0;
    char c;

    while ((c = fgetc(input)) != EOF && current_size < max_size - 1) {
        line[current_size++] = c;

        if (c == '\n') {
            line[current_size++] = '\0';
            return current_size;
        }
    }

    line[current_size] = '\0';
    return current_size;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s input.txt output.txt\n", argv[0]);
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    if (!input || !output) {
        perror("Error opening file(s).");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char *token = NULL;
    size_t line_size;

    while ((line_size = read_line(input, line, MAX_LINE_LENGTH))) {
        char *saved_token = line;

        token = strtok(saved_token, WORD_DELIMITER);

        while (token != NULL) {
            reverse_word(token);
            fprintf(output, "%s%s", token, (token + strlen(token) < line + line_size) ? " " : "\n");
            saved_token = NULL;
            token = strtok(NULL, WORD_DELIMITER);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}