//GPT-4o-mini DATASET v1.0 Category: Word Count Tool ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to count words in a string
int count_words(const char *str) {
    int count = 0;
    int in_word = 0;

    while (*str) {
        if (isspace(*str)) {
            in_word = 0; // We're outside a word
        } else {
            if (in_word == 0) {
                in_word = 1; // We're entering a new word
                count++;
            }
        }
        str++;
    }
    return count;
}

// Function to read input file and count words
int count_words_in_file(const char *filename) {
    FILE *file;
    char *buffer;
    long file_size;
    int word_count = 0;

    // Open the file in read mode
    file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return -1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file content
    buffer = (char *)malloc(file_size + 1);
    if (!buffer) {
        perror("Unable to allocate memory");
        fclose(file);
        return -1;
    }

    // Read the file content into buffer
    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0'; // Null terminate the string

    // Count words in the buffer
    word_count = count_words(buffer);

    // Clean up
    free(buffer);
    fclose(file);

    return word_count;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int total_words = count_words_in_file(filename);

    if (total_words >= 0) {
        printf("The file '%s' contains %d words.\n", filename, total_words);
    } else {
        fprintf(stderr, "An error occurred while reading the file.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}