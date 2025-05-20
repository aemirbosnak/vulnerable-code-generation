//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100

void replaceWord(char *line, const char *target, const char *replacement) {
    char buffer[MAX_LINE_LENGTH];
    char *pos;
    int targetLen = strlen(target);
    int replacementLen = strlen(replacement);
    
    // This will act as an empty buffer for the new line after replacement
    buffer[0] = '\0';

    // Loop through each line
    while ((pos = strstr(line, target)) != NULL) {
        // Append part before the found word
        strncat(buffer, line, pos - line);
        // Append the replacement word
        strcat(buffer, replacement);
        // Move the line pointer ahead
        line = pos + targetLen;
    }
    // Append any remaining part of the line
    strcat(buffer, line);
    // Copy the new line back
    strcpy(line, buffer);
}

void processFile(const char *inputFile, const char *outputFile, const char *targetWord, const char *replacementWord) {
    FILE *source = fopen(inputFile, "r");
    FILE *dest = fopen(outputFile, "w");
    
    if (source == NULL) {
        fprintf(stderr, "Could not open the input file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }
    if (dest == NULL) {
        fprintf(stderr, "Could not open the output file %s\n", outputFile);
        fclose(source);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    
    // Read each line from the source file
    while (fgets(line, sizeof(line), source) != NULL) {
        replaceWord(line, targetWord, replacementWord);
        fputs(line, dest);
    }

    fclose(source);
    fclose(dest);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input file> <output file> <target word> <replacement word>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *inputFile = argv[1];
    const char *outputFile = argv[2];
    const char *targetWord = argv[3];
    const char *replacementWord = argv[4];

    processFile(inputFile, outputFile, targetWord, replacementWord);

    printf("Replacement completed. '%s' replaced with '%s'\n", targetWord, replacementWord);
    return EXIT_SUCCESS;
}