//FormAI DATASET v1.0 Category: Compression algorithms ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD_LENGTH 1000
#define MAX_DICT_SIZE 1000

int dictSize = 0;

// Define data structure for dictionary entry
typedef struct {
    char* word;
    int code;
} DictionaryEntry;

// Declare and initialize dictionary array
DictionaryEntry* dictionary[MAX_DICT_SIZE] = {0};

// Function to add a new entry to the dictionary
void addEntry(char* word, int code) {
    DictionaryEntry* entry = (DictionaryEntry*)malloc(sizeof(DictionaryEntry));
    entry->word = word;
    entry->code = code;
    
    dictionary[dictSize] = entry;
    dictSize++;
}

// Function to compress a file using LZW algorithm
void compressFile(char* inputFile, char* outputFile) {
    // Open input file for reading
    FILE* inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        printf("Error: Could not open input file for reading.\n");
        exit(1);
    }
    
    // Open output file for writing
    FILE* outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Error: Could not open output file for writing.\n");
        exit(1);
    }
    
    // Initialize dictionary with single-character words
    for (int i = 0; i < 256; i++) {
        char* word = (char*)malloc(2);
        word[0] = (char)i;
        word[1] = '\0';
        addEntry(word, i);
    }
    
    // Read input file character by character and compress using LZW algorithm
    int nextCode = 256;
    char currentChar = fgetc(inFile);
    char* currentWord = (char*)malloc(2);
    currentWord[0] = currentChar;
    currentWord[1] = '\0';
    
    while (currentChar != EOF) {
        // Check if current word is in the dictionary
        int i;
        for (i = 0; i < dictSize; i++) {
            if (strcmp(currentWord, dictionary[i]->word) == 0) {
                break;
            }
        }
        
        if (i < dictSize) {
            // Current word is in dictionary, update current word
            free(currentWord);
            currentWord = (char*)malloc(MAX_WORD_LENGTH);
            currentChar = fgetc(inFile);
            
            if (currentChar != EOF) {
                strcat(currentWord, currentChar);
            }
        } else {
            // Current word is not in dictionary, add current word to dictionary and output code
            addEntry(currentWord, nextCode);
            nextCode++;
            fputc(dictionary[i-1]->code, outFile);
            
            // Reset current word to new character
            free(currentWord);
            currentWord = (char*)malloc(2);
            currentWord[0] = currentChar;
            currentWord[1] = '\0';
            currentChar = fgetc(inFile);
        }
    }
    
    // Output code for final current word
    int i;
    for (i = 0; i < dictSize; i++) {
        if (strcmp(currentWord, dictionary[i]->word) == 0) {
            break;
        }
    }
    fputc(dictionary[i]->code, outFile);
    
    // Close input and output files
    fclose(inFile);
    fclose(outFile);
}

// Function to decompress a file compressed using LZW algorithm
void decompressFile(char* inputFile, char* outputFile) {
    // Open input file for reading
    FILE* inFile = fopen(inputFile, "r");
    if (inFile == NULL) {
        printf("Error: Could not open input file for reading.\n");
        exit(1);
    }
    
    // Open output file for writing
    FILE* outFile = fopen(outputFile, "w");
    if (outFile == NULL) {
        printf("Error: Could not open output file for writing.\n");
        exit(1);
    }
    
    // Initialize dictionary with single-character words
    for (int i = 0; i < 256; i++) {
        char* word = (char*)malloc(2);
        word[0] = (char)i;
        word[1] = '\0';
        addEntry(word, i);
    }
    
    // Read input file code by code and decompress using LZW algorithm
    int nextCode = 256;
    int currentCode = fgetc(inFile);
    char* currentWord = (char*)malloc(MAX_WORD_LENGTH);
    strcpy(currentWord, dictionary[currentCode]->word);
    
    while ((currentCode = fgetc(inFile)) != EOF) {
        char* nextWord;
        if (currentCode < dictSize) {
            nextWord = dictionary[currentCode]->word;
        } else if (currentCode == dictSize) {
            nextWord = (char*)malloc(strlen(currentWord)+1);
            strcpy(nextWord, currentWord);
            strcat(nextWord, currentWord[0]);
        } else {
            printf("Error: Invalid code found in input file.\n");
            exit(1);
        }
        
        fwrite(currentWord, strlen(currentWord), 1, outFile);
        
        if (nextCode < MAX_DICT_SIZE) {
            char* newWord = (char*)malloc(strlen(currentWord)+2);
            strcpy(newWord, currentWord);
            strcat(newWord, nextWord[0]);
            addEntry(newWord, nextCode);
            nextCode++;
        }
        
        free(currentWord);
        currentWord = nextWord;
    }
    
    // Write final word to output file
    fwrite(currentWord, strlen(currentWord), 1, outFile);
    
    // Close input and output files
    fclose(inFile);
    fclose(outFile);
}

int main() {
    // Compress file
    compressFile("input.txt", "compressed.lzw");
    
    // Decompress file
    decompressFile("compressed.lzw", "output.txt");
    
    return 0;
}