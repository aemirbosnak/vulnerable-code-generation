//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// The main function
int main(int argc, char *argv[]) {
    // Check if the user provided a file name
    if (argc < 2) {
        printf("Usage: %s <file_name>\n", argv[0]);
        return 1;
    }

    // Open the file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate memory for the file contents
    char *file_contents = malloc(file_size + 1);
    if (file_contents == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    // Read the file contents into memory
    fread(file_contents, 1, file_size, file);

    // Close the file
    fclose(file);

    // Count the number of words in the file
    int word_count = count_words(file_contents);

    // Print the word count
    printf("Word count: %d\n", word_count);

    // Free the memory allocated for the file contents
    free(file_contents);

    return 0;
}

// Count the number of words in a given string
int count_words(char *string) {
    // Base case: if the string is empty, return 0
    if (*string == '\0') {
        return 0;
    }

    // If the current character is not a space, increment the word count
    int word_count = (*string != ' ') ? 1 : 0;

    // Recursively count the number of words in the rest of the string
    return word_count + count_words(string + 1);
}