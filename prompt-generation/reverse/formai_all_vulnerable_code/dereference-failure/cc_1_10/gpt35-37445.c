//FormAI DATASET v1.0 Category: Spell checking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICTIONARY_FILE "dictionary.txt"

// Define a helper function to read a file into memory
char* read_file(const char* path) {
    FILE* file = fopen(path, "rb");
    if (!file) {
        printf("Error: could not open file %s\n", path);
        return NULL;
    }

    fseek(file, 0, SEEK_END); // Go to the end of the file
    long size = ftell(file); // Get the size in bytes
    rewind(file); // Go back to the beginning of the file

    char* buffer = (char*) malloc(size + 1);
    buffer[size] = '\0';

    if (fread(buffer, 1, size, file) != size) {
        printf("Error: could not read file %s\n", path);
        fclose(file);
        free(buffer);
        return NULL;
    }

    fclose(file);
    return buffer;
}

// Define a helper function to split a string into an array of tokens
char** split_string(char* str, const char* delimiter, int* count) {
    char** result = NULL;
    char* token = strtok(str, delimiter);

    while (token) {
        result = (char**) realloc(result, (*count + 1) * sizeof(char*));
        result[*count] = token;
        (*count)++;
        token = strtok(NULL, delimiter);
    }

    return result;
}

// Define the main function
int main() {
    // Read the dictionary file into memory
    char* dictionary_data = read_file(DICTIONARY_FILE);
    if (!dictionary_data) {
        return 1;
    }

    // Split the dictionary data into an array of strings
    int word_count = 0;
    char** dictionary_words = split_string(dictionary_data, "\n", &word_count);

    printf("Loaded %d words from %s\n", word_count, DICTIONARY_FILE);

    // Prompt the user to enter a sentence
    printf("Enter a sentence: ");

    char input_buffer[512];
    fgets(input_buffer, sizeof(input_buffer), stdin);

    // Split the input sentence into an array of words
    int input_word_count = 0;
    char** input_words = split_string(input_buffer, " \n", &input_word_count);

    printf("Checking %d words...\n", input_word_count);

    // Check each input word against the dictionary
    for (int i = 0; i < input_word_count; i++) {
        int found = 0;

        for (int j = 0; j < word_count; j++) {
            if (strcmp(input_words[i], dictionary_words[j]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Unknown word: %s\n", input_words[i]);
        }
    }

    // Free the memory used by the dictionary and input word arrays
    free(dictionary_words);
    free(input_words);

    return 0;
}