//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORDS_PER_LINE 64
#define MAX_FILE_NAME_LENGTH 256

void process_line(char *line, char *output) {
    char *token = strtok(line, " ");
    int i = 0;
    while (token != NULL) {
        for (i = 0; token[i] != '\0'; i++) {
            token[i] = toupper(token[i]);
        }
        strcat(output, token);
        strcat(output, " ");
        token = strtok(NULL, " ");
    }
    // remove trailing space
    if (strlen(output) > 0 && output[strlen(output) - 1] == ' ') {
        output[strlen(output) - 1] = '\0';
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_FILE_NAME_LENGTH], output_filename[MAX_FILE_NAME_LENGTH];
    char line[MAX_LINE_LENGTH], output_line[MAX_LINE_LENGTH * MAX_WORDS_PER_LINE];

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("Error opening input file");
        return 1;
    }

    output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(input_file);
        return 1;
    }

    while (fgets(line, sizeof(line), input_file) != NULL) {
        char *output = output_line;
        process_line(line, output);
        fputs(output, output_file);
        fputc('\n', output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return 0;
}