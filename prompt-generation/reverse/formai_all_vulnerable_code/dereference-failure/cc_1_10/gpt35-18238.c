//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100 // Maximum length of a word in the input file
#define MAX_WORD_COUNT 1000 // Maximum number of unique words in the input file
#define MAX_LINE_LENGTH 100000 // Maximum length of a line in the input file

// Function to remove unwanted characters from a word
void clean_word(char *word) {
    char *p = word;
    while (*p) {
        if (*p == '.' || *p == ',' || *p == ';' ||
            *p == ':' || *p == '!' || *p == '?') {
            *p = '\0';
            break;
        }
        p++;
    }
}

// Function to add a word to the word frequency count array
void add_word(char *word, int word_count[], char *words[]) {
    int i;
    for (i = 0; i < MAX_WORD_COUNT; i++) {
        if (words[i] == NULL || strcmp(words[i], word) == 0) {
            break;
        }
    }
    if (words[i] == NULL) {
        words[i] = strdup(word);
    }
    word_count[i]++;
}

int main() {
    char *input_file_name = "input.txt";
    char *output_file_name = "output.txt";
    char *words[MAX_WORD_COUNT];
    int word_count[MAX_WORD_COUNT] = {0};
    char line[MAX_LINE_LENGTH];
    char word[MAX_WORD_LENGTH];
    FILE *input_file, *output_file;

    // Open input and output files
    input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", input_file_name);
        exit(1);
    }
    output_file = fopen(output_file_name, "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", output_file_name);
        exit(1);
    }

    // Loop through each line in the input file
    while (fgets(line, MAX_LINE_LENGTH, input_file) != NULL) {
        // Loop through each word in the line
        char *p = line;
        while (sscanf(p, "%s", word) == 1) {
            p += strlen(word);
            clean_word(word);
            if (strlen(word) > 0) {
                add_word(word, word_count, words);
            }
            while (*p && !isalnum(*p)) {
                p++;
            }
        }
    }

    // Write the word frequencies to the output file
    int i;
    for (i = 0; i < MAX_WORD_COUNT; i++) {
        if (words[i] != NULL) {
            fprintf(output_file, "%s: %d\n", words[i], word_count[i]);
        }
    }

    // Close input and output files
    fclose(input_file);
    fclose(output_file);

    return 0;
}