//FormAI DATASET v1.0 Category: Word Count Tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: incorrect number of arguments. Please provide one argument - the file path of the text file to be analyzed.\n");
        return 1;
    }

    FILE *text_file = fopen(argv[1], "r");
    if (!text_file) {
        printf("Error: could not open file.\n");
        return 1;
    }

    // Determine the size of the file
    fseek(text_file, 0, SEEK_END);
    long text_file_size = ftell(text_file);
    fseek(text_file, 0, SEEK_SET);

    // Allocate memory for the text
    char *text = (char*)malloc(text_file_size + 1);
    if (!text) {
        printf("Error: could not allocate memory.\n");
        return 1;
    }
    memset(text, 0, text_file_size + 1);

    // Read in the text
    fread(text, text_file_size, 1, text_file);

    // Close the file
    fclose(text_file);

    // Remove non-alpha characters (except for spaces)
    int i, j;
    for (i = 0, j = 0; i < text_file_size; i++) {
        if (isalpha(text[i]) || isspace(text[i])) {
            text[j] = tolower(text[i]);
            j++;
        }
    }
    text[j] = '\0';

    // Count the words
    char *word;
    char *saveptr;
    int num_words = 0;
    word = strtok_r(text, " ", &saveptr);
    while (word != NULL) {
        num_words++;
        word = strtok_r(NULL, " ", &saveptr);
    }
    printf("The text file '%s' contains %d words.\n", argv[1], num_words);

    // Free memory
    free(text);
    return 0;
}