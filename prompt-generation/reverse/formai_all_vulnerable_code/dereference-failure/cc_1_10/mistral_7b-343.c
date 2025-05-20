//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_SIZE 100

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

int is_space(char c) {
    return (isspace((unsigned char)c) || c == '\n');
}

int main() {
    FILE *input_file, *output_file;
    char input_buffer[WORD_SIZE], output_buffer[WORD_SIZE];
    char *token = malloc(WORD_SIZE);
    char *last_token = malloc(WORD_SIZE);
    size_t len = 0;
    int i = 0;

    input_file = fopen("input.txt", "r");
    output_file = fopen("output.txt", "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening files");
        return 1;
    }

    while (fgets(input_buffer, WORD_SIZE, input_file)) {
        len = strlen(input_buffer);
        int pos = 0;

        for (i = 0; i < len; i++) {
            if (is_space(input_buffer[i])) {
                input_buffer[i] = '\0';
                reverse_word(last_token);
                strncpy(output_buffer, last_token, WORD_SIZE);
                output_buffer[strlen(last_token)] = ' ';
                strcat(output_buffer, input_buffer + pos);
                strcpy(last_token, input_buffer + pos + 1);
                pos = i + 1;
            }
            if (i == len - 1) {
                input_buffer[i] = '\0';
                reverse_word(last_token);
                strncpy(output_buffer + strlen(output_buffer), last_token, WORD_SIZE);
                fputs(output_buffer, output_file);
            }
        }

        free(last_token);
        free(token);
    }

    free(last_token);
    free(token);
    fclose(input_file);
    fclose(output_file);

    printf("The magic of reversed words has been woven into output.txt!\n");
    return 0;
}