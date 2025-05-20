//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function to indent the output based on the level
void printIndented(FILE *outputFile, int indentLevel, const char *line) {
    for (int i = 0; i < indentLevel; i++) {
        fprintf(outputFile, "%*s", INDENT_SIZE, "");
    }
    fprintf(outputFile, "%s\n", line);
}

// Function to determine if a tag is a closing tag
int isClosingTag(const char *tag) {
    return tag[0] == '/';
}

// Function to beautify the HTML file
void beautifyHTML(const char *inputFilePath, const char *outputFilePath) {
    FILE *inputFile = fopen(inputFilePath, "r");
    FILE *outputFile = fopen(outputFilePath, "w");
    
    if (!inputFile || !outputFile) {
        fprintf(stderr, "Error: Could not open file(s).\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;
    
    while (fgets(line, sizeof(line), inputFile)) {
        char *pos = strstr(line, "<");
        
        while (pos) {
            char tag[256];
            int tagLength = 0;

            // Extract the tag
            while (*pos != '>' && *pos != '\0') {
                tag[tagLength++] = *pos;
                pos++;
            }
            tag[tagLength++] = *pos; // Include the closing '>'
            tag[tagLength] = '\0';

            // Adjust indent level based on tag type
            if (!isClosingTag(tag)) {
                printIndented(outputFile, indentLevel, tag);
                indentLevel++;
            } else {
                indentLevel--;
                printIndented(outputFile, indentLevel, tag);
            }
            
            pos = strstr(pos + 1, "<"); // Search for the next tag
        }

        // Print line without tags
        if (strlen(line) > 0) {
            printIndented(outputFile, indentLevel, line);
        }
    }
    
    fclose(inputFile);
    fclose(outputFile);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_file.html> <output_file.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    beautifyHTML(argv[1], argv[2]);
    printf("HTML beautification completed. Check the output file: %s\n", argv[2]);
    
    return EXIT_SUCCESS;
}