//GEMINI-pro DATASET v1.0 Category: Text processing ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read a file into a string
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

    // Allocate memory for the string
    char *string = malloc(file_size + 1);
    if (string == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    // Read the file into the string
    fread(string, file_size, 1, file);
    fclose(file);

    // Null-terminate the string
    string[file_size] = '\0';

    // Return the string
    return string;
}

// Function to write a string to a file
int write_file(const char *filename, const char *string) {
    // Open the file
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    // Write the string to the file
    fwrite(string, strlen(string), 1, file);
    fclose(file);

    // Return 0 on success
    return 0;
}

// Function to count the number of words in a string
int count_words(const char *string) {
    int count = 0;
    int in_word = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isspace(string[i])) {
            in_word = 0;
        } else if (!in_word) {
            in_word = 1;
            count++;
        }
    }

    return count;
}

// Function to count the number of lines in a string
int count_lines(const char *string) {
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == '\n') {
            count++;
        }
    }

    return count;
}

// Function to count the number of characters in a string
int count_characters(const char *string) {
    int count = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        count++;
    }

    return count;
}

// Main function
int main() {
    // Read a file into a string
    char *string = read_file("input.txt");
    if (string == NULL) {
        return -1;
    }

    // Count the number of words, lines, and characters in the string
    int word_count = count_words(string);
    int line_count = count_lines(string);
    int character_count = count_characters(string);

    // Print the results
    printf("Word count: %d\n", word_count);
    printf("Line count: %d\n", line_count);
    printf("Character count: %d\n", character_count);

    // Write the string to a file
    if (write_file("output.txt", string) != 0) {
        return -1;
    }

    // Free the memory allocated for the string
    free(string);

    return 0;
}