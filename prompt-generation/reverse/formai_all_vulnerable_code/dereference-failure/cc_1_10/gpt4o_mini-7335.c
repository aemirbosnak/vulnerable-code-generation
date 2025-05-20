//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DICT_SIZE 256 // Traditional size of the dictionary
#define MAX_CODE_LENGTH 12 // Code length limit for compressed data
#define BUFFER_SIZE 1024 // Buffer size for reading data
#define WORD_LENGTH 14 // Max length of a word in the input

typedef struct {
    char word[WORD_LENGTH];
    unsigned int code;
} DictionaryEntry;

typedef struct {
    DictionaryEntry entries[DICT_SIZE];
    int size;
} Dictionary;

void initialize_dictionary(Dictionary *dict) {
    for (int i = 0; i < DICT_SIZE; i++) {
        dict->entries[i].code = 0;
        snprintf(dict->entries[i].word, WORD_LENGTH, "%c", (char)i);
    }
    dict->size = 256; // Initialize with ASCII characters
}

unsigned int find_code(Dictionary *dict, const char *word) {
    for (int i = 0; i < dict->size; i++) {
        if (strcmp(dict->entries[i].word, word) == 0) {
            return dict->entries[i].code;
        }
    }
    return (unsigned int)-1; // Return value to indicate not found
}

void add_to_dictionary(Dictionary *dict, const char *word, unsigned int code) {
    if (dict->size < DICT_SIZE) {
        strncpy(dict->entries[dict->size].word, word, WORD_LENGTH - 1);
        dict->entries[dict->size].code = code;
        dict->size++;
    }
}

void compress_data(const char *input, FILE *output) {
    Dictionary dict;
    initialize_dictionary(&dict);
    
    char current_word[WORD_LENGTH] = {0};
    int index = 0;

    for (int i = 0; input[i] != '\0'; i++) {
        current_word[index++] = input[i];

        unsigned int code = find_code(&dict, current_word);
        if (code != (unsigned int)-1) {
            // If the word is already in the dictionary
            continue; 
        } else {
            // If the word is not in the dictionary 
            // Emit the previous word's code
            if (index > 1) {
                fprintf(output, "%u ", find_code(&dict, strncpy(current_word + index - 1, "\0", 1)));
                // Reset current_word to the last character
                current_word[0] = input[i];
                index = 1;
            }

            // Add the new word to the dictionary
            add_to_dictionary(&dict, current_word, dict.size);
        }
    }

    if (index > 0) {
        fprintf(output, "%u ", find_code(&dict, strncpy(current_word + index - 1, "\0", 1)));
    }
}

void decompress_data(FILE *input, FILE *output) {
    Dictionary dict;
    initialize_dictionary(&dict);

    unsigned int code;
    while (fscanf(input, "%u", &code) != EOF) {
        if (code < dict.size) {
            // Output the word corresponding to the code
            fprintf(output, "%s", dict.entries[code].word);
        } else {
            // Handle unrecognized code (could happen if input is corrupted)
            fprintf(output, "[UNKNOWN CODE: %u]", code);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <compress|decompress> <input_file> <output_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if (strcmp(argv[1], "compress") == 0) {
        FILE *input_file = fopen(argv[2], "r");
        FILE *output_file = fopen(argv[3], "w");

        if (input_file == NULL || output_file == NULL) {
            fprintf(stderr, "Error opening files!\n");
            return EXIT_FAILURE;
        }

        char *buffer = (char *)malloc(BUFFER_SIZE);
        while (fgets(buffer, BUFFER_SIZE, input_file) != NULL) {
            compress_data(buffer, output_file);
        }

        free(buffer);
        fclose(input_file);
        fclose(output_file);
        printf("Compression complete. Stay vigilant, survivor.\n");
    } else if (strcmp(argv[1], "decompress") == 0) {
        FILE *input_file = fopen(argv[2], "r");
        FILE *output_file = fopen(argv[3], "w");

        if (input_file == NULL || output_file == NULL) {
            fprintf(stderr, "Error opening files!\n");
            return EXIT_FAILURE;
        }

        decompress_data(input_file, output_file);

        fclose(input_file);
        fclose(output_file);
        printf("Decompression complete. Rebuilding our lost stories...\n");
    } else {
        fprintf(stderr, "Invalid action! Use 'compress' or 'decompress'.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}