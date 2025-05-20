//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file into a buffer
char *read_file(const char *filename) {
    // Open the file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    // Allocate a buffer to hold the file contents
    char *buffer = malloc(file_size + 1);
    if (buffer == NULL) {
        perror("Error allocating memory for buffer");
        fclose(file);
        return NULL;
    }

    // Read the file into the buffer
    size_t bytes_read = fread(buffer, 1, file_size, file);
    if (bytes_read != file_size) {
        perror("Error reading file");
        free(buffer);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Add a null terminator to the end of the buffer
    buffer[file_size] = '\0';

    // Return the buffer
    return buffer;
}

// Function to write a buffer to a file
int write_file(const char *filename, const char *buffer) {
    // Open the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the buffer to the file
    size_t bytes_written = fwrite(buffer, 1, strlen(buffer), file);
    if (bytes_written != strlen(buffer)) {
        perror("Error writing file");
        fclose(file);
        return -1;
    }

    // Close the file
    fclose(file);

    // Return 0 on success
    return 0;
}

// Function to count the number of words in a string
int count_words(const char *string) {
    // Initialize the word count
    int word_count = 0;

    // Parse the string
    char *token = strtok(string, " ");
    while (token != NULL) {
        // Increment the word count
        word_count++;

        // Get the next token
        token = strtok(NULL, " ");
    }

    // Return the word count
    return word_count;
}

// Function to count the number of lines in a string
int count_lines(const char *string) {
    // Initialize the line count
    int line_count = 0;

    // Parse the string
    char *token = strtok(string, "\n");
    while (token != NULL) {
        // Increment the line count
        line_count++;

        // Get the next token
        token = strtok(NULL, "\n");
    }

    // Return the line count
    return line_count;
}

// Function to count the number of characters in a string
int count_characters(const char *string) {
    // Initialize the character count
    int character_count = 0;

    // Iterate over the string
    for (int i = 0; string[i] != '\0'; i++) {
        // Increment the character count
        character_count++;
    }

    // Return the character count
    return character_count;
}

// Main function
int main() {
    // Read the file into a buffer
    char *buffer = read_file("input.txt");
    if (buffer == NULL) {
        return EXIT_FAILURE;
    }

    // Count the number of words, lines, and characters in the buffer
    int word_count = count_words(buffer);
    int line_count = count_lines(buffer);
    int character_count = count_characters(buffer);

    // Print the results
    printf("Number of words: %d\n", word_count);
    printf("Number of lines: %d\n", line_count);
    printf("Number of characters: %d\n", character_count);

    // Write the buffer to a file
    int write_status = write_file("output.txt", buffer);
    if (write_status != 0) {
        return EXIT_FAILURE;
    }

    // Free the buffer
    free(buffer);

    // Return 0 on success
    return EXIT_SUCCESS;
}