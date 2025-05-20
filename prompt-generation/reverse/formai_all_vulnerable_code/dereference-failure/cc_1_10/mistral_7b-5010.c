//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 256
#define MAX_WORDS_PER_LINE 50
#define WORD_DELIMITER " \t\n\r,\\;:!?()[]{}\"'<>()\n"

void process_line(char *line, char *output) {
    int i = 0, j = 0, word_count = 0;
    char *token = strtok(line, WORD_DELIMITER);

    while (token != NULL) {
        for (int k = 0; token[k] != '\0'; k++) {
            token[k] = toupper(token[k]);
        }
        strncat(output, token, MAX_WORDS_PER_LINE - j - 1);
        strcat(output, " ");
        j += strlen(token) + 1;
        word_count++;

        token = strtok(NULL, WORD_DELIMITER);
    }

    if (word_count > 0) {
        output[strlen(output) - 1] = '\n';
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char line[MAX_LINE_LENGTH], output[MAX_WORDS_PER_LINE * MAX_LINE_LENGTH];

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    input_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        process_line(line, output);
        fputs(output, output_file);
        memset(output, 0, MAX_WORDS_PER_LINE * MAX_LINE_LENGTH);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}