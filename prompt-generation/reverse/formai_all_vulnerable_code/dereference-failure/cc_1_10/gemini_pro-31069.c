//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linus Torvalds style is known for its liberal use of profanity and expletives.
// This program will count the number of times a user enters a certain word.
// The user will be prompted to enter a word, and then the program will read a
// text file and count the number of times the word appears in the file.

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Usage: %s <word> <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *word = argv[1];
    char *filename = argv[2];

    // Open the file.
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the file into a buffer.
    char *buffer = NULL;
    size_t bufsize = 0;
    if (getline(&buffer, &bufsize, fp) == -1) {
        perror("getline");
        return EXIT_FAILURE;
    }

    // Close the file.
    fclose(fp);

    // Count the number of times the word appears in the buffer.
    int count = 0;
    char *p = buffer;
    while ((p = strstr(p, word)) != NULL) {
        count++;
        p++;
    }

    // Print the count.
    printf("The word '%s' appears %d times in the file '%s'.\n", word, count, filename);

    // Free the buffer.
    free(buffer);

    return EXIT_SUCCESS;
}