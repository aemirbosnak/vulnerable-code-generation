//GPT-4o-mini DATASET v1.0 Category: Performance-Critical Component ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 256    // Character set size for the Boyer-Moore algorithm

// Preprocessing function for the bad character heuristic
void preprocessBadCharacter(const char *pattern, int patternLength, int badChar[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badChar[i] = -1;  // Initialize with -1
    }
    for (int i = 0; i < patternLength; i++) {
        badChar[(unsigned char)pattern[i]] = i;  // Store the last occurrence
    }
}

// Boyer-Moore search function
void boyerMooreSearch(const char *text, const char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);
    
    int badChar[ALPHABET_SIZE];
    preprocessBadCharacter(pattern, patternLength, badChar);

    int s = 0;  // Shift of the pattern with respect to text
    while (s <= textLength - patternLength) {
        int j = patternLength - 1; // Start from the end of the pattern
        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;  // Move backwards in the pattern
        }
        if (j < 0) {
            printf("Pattern found at index %d\n", s);
            s += (s + patternLength < textLength) ? patternLength - badChar[(unsigned char)text[s + patternLength]] : 1;
        } else {
            s += (j - badChar[(unsigned char)text[s + j]] > 1) ? j - badChar[(unsigned char)text[s + j]] : 1;
        }
    }
}

// Utility to read the input text from a file
char* readFileContent(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", fileName);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);

    char *buffer = (char *)malloc(fileSize + 1);
    if (!buffer) {
        fprintf(stderr, "Memory allocation failed\n");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, fileSize, file);
    buffer[fileSize] = '\0';  // Null-terminate the string
    fclose(file);
    return buffer;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <pattern>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *fileName = argv[1];
    const char *pattern = argv[2];

    char *text = readFileContent(fileName);
    if (!text) {
        return EXIT_FAILURE;
    }

    printf("Searching for pattern: %s\n", pattern);
    boyerMooreSearch(text, pattern);

    free(text);  // Cleaning up allocated memory
    return EXIT_SUCCESS;
}