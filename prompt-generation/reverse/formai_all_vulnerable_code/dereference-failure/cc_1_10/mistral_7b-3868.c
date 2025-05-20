//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define BUFFER_SIZE 1024

// Function to reverse a string in-place
void reverse_string(char *str) {
    int i = 0, j = strlen(str) - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

// Function to reverse each word in a given string
void reverse_words(char *str) {
    char *word_start = str;
    char *word_end;

    while (*str != '\0') {
        if (*str == ' ') {
            word_end = str - 1;
            while (isspace(*--word_start)) {}
            reverse_string(word_start + 1);
            reverse_string(word_end + 1);
            str++;
        } else {
            str++;
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *input_file, *output_file;
    char input_buffer[BUFFER_SIZE];
    char output_buffer[BUFFER_SIZE];

    if (argc != 3) {
        printf("Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }

    input_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");

    if (input_file == NULL || output_file == NULL) {
        perror("Error opening file");
        return 1;
    }

    while (fgets(input_buffer, BUFFER_SIZE, input_file)) {
        reverse_words(input_buffer);
        strcpy(output_buffer, input_buffer);
        fprintf(output_file, "%s", output_buffer);
    }

    fclose(input_file);
    fclose(output_file);

    printf("Reversed words in the file have been written to %s\n", argv[2]);

    return 0;
}