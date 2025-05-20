//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style: no curly braces for single-line if-else statements
#define ifelse(cond, a, b) ((cond) ? (a) : (b))

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Open the file
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Allocate memory for the file contents
    char *contents = malloc(1024);
    if (contents == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    // Read the file contents into memory
    size_t size = fread(contents, 1, 1024, fp);
    if (size == 0) {
        fprintf(stderr, "Error reading file\n");
        return EXIT_FAILURE;
    }

    // Close the file
    fclose(fp);

    // Initialize word count
    int word_count = 0;

    // Iterate over the file contents and count the words
    char *word = strtok(contents, " ");
    while (word != NULL) {
        word_count++;
        word = strtok(NULL, " ");
    }

    // Print the word count
    printf("Word count: %d\n", word_count);

    // Free the memory allocated for the file contents
    free(contents);

    return EXIT_SUCCESS;
}