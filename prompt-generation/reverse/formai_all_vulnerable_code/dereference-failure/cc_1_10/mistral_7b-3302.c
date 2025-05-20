//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define WORD_LENGTH 50

void remove_word(char *line, char *word) {
    size_t start = 0, end = 0;
    char *token = strtok(line, " ");

    while (token != NULL) {
        if (strncmp(token, word, strlen(word)) == 0) {
            if (start > 0) {
                size_t len = end - start;
                memmove(line + start - len, line + start, strlen(line + start) - (end - start));
                memset(line + strlen(line) - (end - start), ' ', len);
            }
            start = end = strlen(line) - strlen(token);
        }

        token = strtok(NULL, " ");
        end += strlen(token) + 1;
    }

    if (start > 0 && end < strlen(line)) {
        size_t len = end - start;
        memmove(line + start, line + end, strlen(line + end) - (strlen(line) - end));
        memset(line + strlen(line) - len, ' ', len);
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH];
    char word[WORD_LENGTH];

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <word_to_remove>\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        return 1;
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        fputs(line, output_file);
        sscanf(line, "%s", word);
        remove_word(line, argv[3]);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}