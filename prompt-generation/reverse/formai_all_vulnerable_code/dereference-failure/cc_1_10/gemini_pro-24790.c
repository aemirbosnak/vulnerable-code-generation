//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <text file>\n", argv[0]);
        return 1;
    }

    // Read the text file into a string.
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *text = malloc(file_size + 1);
    if (text == NULL) {
        printf("Error allocating memory for text\n");
        fclose(file);
        return 1;
    }

    fread(text, file_size, 1, file);
    fclose(file);

    text[file_size] = '\0';

    // Process the text.

    // Count the number of words in the text.
    int word_count = 0;
    char *word = strtok(text, " ");
    while (word != NULL) {
        word_count++;
        word = strtok(NULL, " ");
    }

    // Count the number of lines in the text.
    int line_count = 0;
    char *line = strtok(text, "\n");
    while (line != NULL) {
        line_count++;
        line = strtok(NULL, "\n");
    }

    // Count the number of characters in the text.
    int char_count = strlen(text);

    // Print the results.
    printf("Word count: %d\n", word_count);
    printf("Line count: %d\n", line_count);
    printf("Character count: %d\n", char_count);

    // Free the memory that was allocated for the text.
    free(text);

    return 0;
}