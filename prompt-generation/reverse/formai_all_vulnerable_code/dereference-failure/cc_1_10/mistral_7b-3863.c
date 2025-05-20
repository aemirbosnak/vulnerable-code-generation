//MISTRAL-7B DATASET v1.0 Category: User Input Sanitizer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 1024
#define MAX_FILENAME_SIZE 256

char *filename;
char *file_buffer;
size_t file_buffer_size;

void sanitize_input(char *input) {
    // Custom sanitization function goes here
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] < ' ' || input[i] > '~') {
            input[i] = '*';
        }
    }
}

int main() {
    int ch;
    size_t line_size;
    char input[MAX_LINE_SIZE];
    FILE *fp;

    printf("Enter the filename: ");
    getline(&input, sizeof(input), stdin);
    sanitize_input(input);

    filename = malloc(strlen(input) + 1);
    strcpy(filename, input);

    file_buffer_size = 1024;
    file_buffer = malloc(file_buffer_size);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        free(filename);
        free(file_buffer);
        return 1;
    }

    while ((ch = getline(&input, sizeof(input), fp)) != EOF) {
        size_t input_len = strlen(input);
        for (int i = 0; i < input_len; i++) {
            if (input[i] == '<' || input[i] == '>') {
                input[i] = '[SANITIZED]';
            }
        }
        strcat(file_buffer, input);
        strcat(file_buffer, "\n");
    }

    fclose(fp);
    free(filename);
    free(file_buffer);

    printf("%s", file_buffer);

    return 0;
}