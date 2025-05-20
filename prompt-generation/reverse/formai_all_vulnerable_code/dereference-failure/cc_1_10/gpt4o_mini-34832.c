//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
void displayArt();
void processText(const char *inputFile, const char *outputFile);
void toUpperCase(char *text);
void toLowerCase(char *text);
void reverseText(char *text);

int main(int argc, char *argv[]) {
    // Display artistic header
    displayArt();

    // Check for arguments
    if (argc != 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    // Process text from the input file and write to the output file
    processText(argv[1], argv[2]);

    return 0;
}

void displayArt() {
    printf("******************************************\n");
    printf("*        TEXT PROCESSING ARTIST          *\n");
    printf("*              By Your Name              *\n");
    printf("******************************************\n");
    printf("        Transforming words with style     \n");
    printf("******************************************\n\n");
}

void processText(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    char text[1024];

    if (inFile == NULL) {
        fprintf(stderr, "Could not open input file %s\n", inputFile);
        exit(EXIT_FAILURE);
    }
    if (outFile == NULL) {
        fprintf(stderr, "Could not open output file %s\n", outputFile);
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    // Read each line from the input file and process it
    while (fgets(text, sizeof(text), inFile) != NULL) {
        // Transformations
        toUpperCase(text);    // Convert to uppercase
        reverseText(text);    // Reverse the text
        // Write transformed text to output file
        fprintf(outFile, "%s", text);
    }

    fclose(inFile);
    fclose(outFile);
    printf("Text processed and written to %s\n", outputFile);
}

void toUpperCase(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = text[i] - 'a' + 'A';
        }
    }
}

void toLowerCase(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = text[i] - 'A' + 'a';
        }
    }
}

void reverseText(char *text) {
    int start = 0;
    int end = strlen(text) - 1;
    char temp;

    while (start < end) {
        // Swap characters
        temp = text[start];
        text[start] = text[end];
        text[end] = temp;
        start++;
        end--;
    }
}