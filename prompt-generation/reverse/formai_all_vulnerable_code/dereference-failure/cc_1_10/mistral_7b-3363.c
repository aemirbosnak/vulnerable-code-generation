//MISTRAL-7B DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check if a character is alphabetic
int is_alpha(char c) {
    return (isalpha(c) || isupper(c) || islower(c));
}

// Function to count the occurrences of a word in a string
int count_word_occurrences(char *str, char *word) {
    int count = 0;
    char *token;

    // Tokenize the string using strtok
    token = strtok(str, " ");
    while (token != NULL) {
        if (strcmp(token, word) == 0) {
            count++;
        }
        token = strtok(NULL, " ");
    }

    return count;
}

// Function to read a file and print the number of occurrences of the word "C"
void count_word_in_file(char *filename) {
    FILE *file;
    char *buffer;
    size_t buffer_size;
    char word[5] = {"C"};
    int count = 0;

    // Determine the size of the buffer based on the file size
    file = fopen(filename, "r");
    fseek(file, 0, SEEK_END);
    buffer_size = ftell(file) + 1;
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the buffer
    buffer = malloc(buffer_size);
    if (buffer == NULL) {
        printf("Error: Unable to allocate memory for the buffer.\n");
        exit(EXIT_FAILURE);
    }

    // Read the contents of the file into the buffer
    size_t bytes_read = fread(buffer, sizeof(char), buffer_size, file);
    if (bytes_read < buffer_size) {
        printf("Error: Unable to read the entire file.\n");
        free(buffer);
        exit(EXIT_FAILURE);
    }

    // Count the occurrences of the word "C" in the buffer
    char *token = strtok(buffer, ".");
    while (token != NULL) {
        if (is_alpha(token[0]) && strcmp(token, "C") == 0) {
            count++;
        }
        token = strtok(NULL, ".");
    }

    // Print the number of occurrences of the word "C"
    printf("The word 'C' occurs %d times in the file '%s'.\n", count, filename);

    // Free the memory allocated for the buffer
    free(buffer);
    fclose(file);
}

// Main function to call the count_word_in_file function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    count_word_in_file(argv[1]);

    return EXIT_SUCCESS;
}