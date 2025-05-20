//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is a word separator
bool is_word_separator(char c) {
    return (isspace(c) || c == '\n');
}

// Function to count words in a given string
int count_words(const char *str) {
    int count = 0;
    if (*str) {
        bool in_word = false;
        do {
            if (is_word_separator(*str)) {
                in_word = false;
                count++;
            } else {
                in_word = true;
            }
        } while (*++str);

        if (in_word)
            count++;
    }

    return count;
}

// Function to read the contents of a file
size_t file_size(FILE *fp) {
    size_t size = 0;
    char c;

    while ((c = fgetc(fp)) != EOF) {
        size++;
    }

    return size;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");

    if (!fp) {
        perror("Error opening file");
        exit(1);
    }

    char *buffer = malloc(file_size(fp) + 1);
    fread(buffer, 1, file_size(fp), fp);
    fclose(fp);

    int num_words = count_words(buffer);
    int num_lines = 1;
    int num_chars = file_size(fp);

    free(buffer);

    printf("File: %s\n", argv[1]);
    printf("Number of words: %d\n", num_words);
    printf("Number of lines: %d\n", num_lines);
    printf("Number of characters: %d\n", num_chars);

    return 0;
}