//GPT-4o-mini DATASET v1.0 Category: Compression algorithms ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DICT_SIZE 4096
#define MAX_CODE_SIZE 12

typedef struct {
    unsigned char *code; // The actual code for each string
    int size;            // Size of the code
} DictionaryEntry;

typedef struct {
    DictionaryEntry dict[MAX_DICT_SIZE]; // Dictionary entries for codes
    int dictSize;                         // Current size of the dictionary
} Dictionary;

// Function to initialize the dictionary
void initDictionary(Dictionary *dict) {
    dict->dictSize = 256; // Initialize for 256 ASCII characters
    for (int i = 0; i < 256; i++) {
        dict->dict[i].code = (unsigned char *)malloc(1);
        dict->dict[i].code[0] = (unsigned char)i;
        dict->dict[i].size = 1;
    }
}

// Function to free the dictionary
void freeDictionary(Dictionary *dict) {
    for (int i = 0; i < dict->dictSize; i++) {
        free(dict->dict[i].code);
    }
}

// Function to find or add new entry in the dictionary
int findOrAddEntry(Dictionary *dict, unsigned char *str, int length) {
    for (int i = 0; i < dict->dictSize; i++) {
        if (length == dict->dict[i].size && memcmp(str, dict->dict[i].code, length) == 0) {
            return i; // Found existing entry
        }
    }
    // Add new entry to the dictionary if necessary
    if (dict->dictSize < MAX_DICT_SIZE) {
        dict->dict[dict->dictSize].code = (unsigned char *)malloc(length);
        memcpy(dict->dict[dict->dictSize].code, str, length);
        dict->dict[dict->dictSize].size = length;
        return dict->dictSize++;
    }
    return -1; // Dictionary is full
}

// Compress function using LZW algorithm
void compress(const unsigned char *input, size_t inputLength) {
    Dictionary dict;
    initDictionary(&dict);
    unsigned char curr[MAX_CODE_SIZE];
    int currLength = 0;
    
    for (size_t i = 0; i < inputLength; i++) {
        curr[currLength++] = input[i];
        int codeIndex = findOrAddEntry(&dict, curr, currLength);
        
        if (codeIndex == -1) {
            // Output the code for the previous string
            currLength--; // Step back to previous string
            printf("%d\n", findOrAddEntry(&dict, curr, currLength));
            // Add new entry to the dictionary
            curr[currLength] = input[i]; // Add current character
            findOrAddEntry(&dict, curr, currLength + 1);
            currLength = 1; // Start new current with the latest character
            curr[0] = input[i]; // Reset curr
        }
    }
    if (currLength > 0) {
        printf("%d\n", findOrAddEntry(&dict, curr, currLength));
    }

    freeDictionary(&dict);
}

// A simple helper function to read the input file
unsigned char* readFile(const char* filename, size_t *length) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    *length = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *buffer = (unsigned char *)malloc(*length);
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }
    fread(buffer, 1, *length, file);
    fclose(file);
    return buffer;
}

// Main function to execute the program
int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    size_t length;
    unsigned char* inputData = readFile(argv[1], &length);
    if (!inputData) {
        return EXIT_FAILURE;
    }

    printf("Compressing data from file: %s\n", argv[1]);
    compress(inputData, length);

    free(inputData);
    return EXIT_SUCCESS;
}