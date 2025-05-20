//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024
#define MAX_WORDS 1000

// Function to read a file into a buffer
char *read_file(char *filename) {
    FILE *fp;
    char *buffer;
    long length;

    // Open the file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    // Get the length of the file
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);

    // Allocate a buffer to hold the file
    buffer = malloc(length + 1);
    if (buffer == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    // Read the file into the buffer
    fseek(fp, 0, SEEK_SET);
    fread(buffer, 1, length, fp);
    buffer[length] = '\0';

    // Close the file
    fclose(fp);

    return buffer;
}

// Function to split a string into words
char **split_words(char *str) {
    char **words;
    char *word;
    int num_words = 0;

    // Allocate an array to hold the words
    words = malloc(MAX_WORDS * sizeof(char *));
    if (words == NULL) {
        perror("malloc");
        return NULL;
    }

    // Split the string into words
    while ((word = strtok(str, " \t\n")) != NULL) {
        words[num_words++] = word;
        str = NULL;
    }

    return words;
}

// Function to count the number of words in a file
int count_words(char *filename) {
    char *buffer;
    char **words;
    int num_words = 0;

    // Read the file into a buffer
    buffer = read_file(filename);
    if (buffer == NULL) {
        return -1;
    }

    // Split the buffer into words
    words = split_words(buffer);
    if (words == NULL) {
        free(buffer);
        return -1;
    }

    // Count the number of words
    while (words[num_words] != NULL) {
        num_words++;
    }

    // Free the memory allocated for the words
    free(words);

    // Free the memory allocated for the buffer
    free(buffer);

    return num_words;
}

int main(int argc, char *argv[]) {
    int num_words;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    num_words = count_words(argv[1]);
    if (num_words == -1) {
        perror("count_words");
        return EXIT_FAILURE;
    }

    printf("The file \"%s\" contains %d words.\n", argv[1], num_words);

    return EXIT_SUCCESS;
}