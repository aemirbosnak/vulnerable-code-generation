//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH_LIMIT 7

void filter_words(char *line) {
    char *token = strtok(line, " ");
    char *next_token;
    while (token != NULL) {
        int token_length = strlen(token);
        if (token_length > WORD_LENGTH_LIMIT) {
            for (int i = 0; i < token_length; i++) {
                if (isalpha(token[i])) {
                    token[i] = '_';
                } else {
                    token[i] = ' ';
                }
            }
            next_token = malloc(1);
            strcpy(next_token, " ");
            strcat(line, next_token);
            strcat(line, token);
            free(next_token);
            next_token = strtok(NULL, " ");
            free(token);
        } else {
            next_token = strtok(NULL, " ");
            free(token);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    char *line = NULL;
    size_t line_size = 0;
    ssize_t read_size;

    FILE *output_file = fopen(strcat(argv[1], "_filtered.txt"), "w");
    if (output_file == NULL) {
        perror("Error creating output file");
        fclose(input_file);
        free(line);
        return 1;
    }

    while ((read_size = getline(&line, &line_size, input_file)) != -1) {
        filter_words(line);
        fprintf(output_file, "%s", line);
    }

    free(line);
    fclose(input_file);
    fclose(output_file);

    return 0;
}