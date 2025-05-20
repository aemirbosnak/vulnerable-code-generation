//GEMINI-pro DATASET v1.0 Category: File handling ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Open a file for reading
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Read the file into a buffer
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(file);
        return EXIT_FAILURE;
    }
    fread(buffer, file_size, 1, file);
    fclose(file);

    // Process the file contents
    int num_lines = 0;
    int num_words = 0;
    int num_chars = 0;
    char *line = strtok(buffer, "\n");
    while (line != NULL) {
        num_lines++;

        char *word = strtok(line, " ");
        while (word != NULL) {
            num_words++;

            int word_length = strlen(word);
            num_chars += word_length;

            word = strtok(NULL, " ");
        }

        line = strtok(NULL, "\n");
    }

    // Print the results
    printf("Number of lines: %d\n", num_lines);
    printf("Number of words: %d\n", num_words);
    printf("Number of characters: %d\n", num_chars);

    // Free the buffer
    free(buffer);

    return EXIT_SUCCESS;
}