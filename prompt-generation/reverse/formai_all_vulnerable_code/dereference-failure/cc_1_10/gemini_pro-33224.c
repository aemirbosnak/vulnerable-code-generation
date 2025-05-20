//GEMINI-pro DATASET v1.0 Category: File handling ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum size of the input file
#define MAX_FILE_SIZE 1024

// Define the maximum number of lines in the input file
#define MAX_LINES 100

// Define the maximum length of a line in the input file
#define MAX_LINE_LENGTH 256

// Define the maximum number of characters in a word
#define MAX_WORD_LENGTH 32

// Define the maximum number of words in the input file
#define MAX_WORDS 1000

// Define the structure of a word
typedef struct word {
    char *word;
    int count;
} word;

// Define the structure of the input file
typedef struct input_file {
    char *filename;
    char *data;
    int size;
    int lines;
    int words;
    word *words_array;
} input_file;

// Function to read the input file into a string
char *read_file(const char *filename) {
    // Open the input file
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Get the size of the input file
    fseek(file, 0, SEEK_END);
    int size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory for the input file data
    char *data = malloc(size + 1);
    if (data == NULL) {
        fprintf(stderr, "Error allocating memory for file data\n");
        fclose(file);
        return NULL;
    }

    // Read the input file data into the string
    fread(data, size, 1, file);
    data[size] = '\0';

    // Close the input file
    fclose(file);

    // Return the input file data
    return data;
}

// Function to count the number of lines in a string
int count_lines(const char *data) {
    // Initialize the line count
    int lines = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(data); i++) {
        // Increment the line count if the current character is a newline character
        if (data[i] == '\n') {
            lines++;
        }
    }

    // Return the line count
    return lines;
}

// Function to count the number of words in a string
int count_words(const char *data) {
    // Initialize the word count
    int words = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(data); i++) {
        // Increment the word count if the current character is a space character
        if (data[i] == ' ') {
            words++;
        }
    }

    // Return the word count
    return words;
}

// Function to extract the words from a string
word *extract_words(const char *data, int *words_count) {
    // Allocate memory for the words array
    word *words_array = malloc(sizeof(word) * MAX_WORDS);
    if (words_array == NULL) {
        fprintf(stderr, "Error allocating memory for words array\n");
        return NULL;
    }

    // Initialize the word count
    *words_count = 0;

    // Iterate over the string
    for (int i = 0; i < strlen(data); i++) {
        // Skip space characters
        if (data[i] == ' ') {
            continue;
        }

        // Get the word length
        int word_length = 0;
        while (data[i + word_length] != ' ' && data[i + word_length] != '\0') {
            word_length++;
        }

        // Allocate memory for the word
        words_array[*words_count].word = malloc(word_length + 1);
        if (words_array[*words_count].word == NULL) {
            fprintf(stderr, "Error allocating memory for word\n");
            return NULL;
        }

        // Copy the word to the array
        strncpy(words_array[*words_count].word, data + i, word_length);
        words_array[*words_count].word[word_length] = '\0';

        // Increment the word count
        (*words_count)++;

        // Skip the word
        i += word_length;
    }

    // Return the words array
    return words_array;
}

// Function to count the occurrences of each word in an array
void count_occurrences(word *words_array, int words_count) {
    // Iterate over the words array
    for (int i = 0; i < words_count; i++) {
        // Initialize the occurrence count
        words_array[i].count = 0;

        // Iterate over the words array again
        for (int j = 0; j < words_count; j++) {
            // Increment the occurrence count if the words match
            if (strcmp(words_array[i].word, words_array[j].word) == 0) {
                words_array[i].count++;
            }
        }
    }
}

// Function to print the words and their occurrences
void print_words(word *words_array, int words_count) {
    // Iterate over the words array
    for (int i = 0; i < words_count; i++) {
        // Print the word and its occurrence count
        printf("%s: %d\n", words_array[i].word, words_array[i].count);
    }
}

// Function to free the memory allocated for the input file data and the words array
void free_memory(input_file *input_file) {
    // Free the input file data
    free(input_file->data);

    // Free the words array
    for (int i = 0; i < input_file->words; i++) {
        free(input_file->words_array[i].word);
    }
    free(input_file->words_array);
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the input file was specified
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the input file into a string
    char *data = read_file(argv[1]);
    if (data == NULL) {
        return EXIT_FAILURE;
    }

    // Initialize the input file structure
    input_file input_file;
    input_file.filename = argv[1];
    input_file.data = data;
    input_file.size = strlen(data);
    input_file.lines = count_lines(data);
    input_file.words = count_words(data);
    input_file.words_array = extract_words(data, &input_file.words);
    if (input_file.words_array == NULL) {
        free(data);
        return EXIT_FAILURE;
    }

    // Count the occurrences of each word in the array
    count_occurrences(input_file.words_array, input_file.words);

    // Print the words and their occurrences
    print_words(input_file.words_array, input_file.words);

    // Free the memory allocated for the input file data and the words array
    free_memory(&input_file);

    return EXIT_SUCCESS;
}