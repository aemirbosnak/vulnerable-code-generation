//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 1000
#define WORD_DELIMITER " \t\n\r,"

void reverse_string(char *str, int length) {
    int i = 0, j = length - 1;
    char temp;

    while (i < length / 2) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

void reverse_words(char *line) {
    char *token, *start = line;
    int length = strlen(line);

    while (*line != '\0') {
        token = strchr(start, *line);
        if (token != NULL) {
            *token = '\0';
            int word_length = (int) (token - start);
            reverse_string(start, word_length);
            start += word_length + 1;
            line++;
        } else {
            line++;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_filename[MAX_LENGTH], output_filename[MAX_LENGTH];

    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    strcpy(input_filename, argv[1]);
    strcpy(output_filename, argv[2]);

    input_file = fopen(input_filename, "r");
    output_file = fopen(output_filename, "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file(s)");
        fclose(input_file);
        fclose(output_file);
        return 1;
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, input_file) != NULL) {
        reverse_words(line);
        fputs(line, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Text reversed successfully!\n");
    return 0;
}