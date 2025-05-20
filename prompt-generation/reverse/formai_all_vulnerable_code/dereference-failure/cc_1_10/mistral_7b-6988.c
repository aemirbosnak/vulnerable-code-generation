//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS_PER_LINE 10
#define BUFFER_SIZE 1024
#define WORD_SIZE 64

char *word_to_upper(char *word) {
    int i;
    for (i = 0; word[i]; i++) {
        word[i] = toupper((unsigned char)word[i]);
    }
    return word;
}

int main() {
    FILE *input_file = fopen("input.txt", "r");
    FILE *output_file = fopen("output.txt", "w");
    char buffer[BUFFER_SIZE];
    char words[MAX_WORDS_PER_LINE][WORD_SIZE];
    int words_count = 0;
    char *token;

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, BUFFER_SIZE, input_file)) {
        char *line_start = buffer;
        int line_length = strlen(line_start);
        int i = 0;

        while ((token = strsep(&line_start, " \t\r\n,"))) {
            if (words_count >= MAX_WORDS_PER_LINE) {
                fprintf(output_file, "%s\n", words[0]);
                for (int j = 0; j < words_count - 1; j++) {
                    fprintf(output_file, "%s ", words[j]);
                }
                words_count = 0;
            }

            strcpy(words[words_count++], token);
            word_to_upper(words[words_count - 1]);
        }

        if (words_count > 0) {
            for (int j = 0; j < words_count; j++) {
                fprintf(output_file, "%s%s", words[j], (j + 1 < words_count) ? " " : "");
            }
            fprintf(output_file, "\n");
            words_count = 0;
        }
    }

    fclose(input_file);
    fclose(output_file);

    return EXIT_SUCCESS;
}