//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TABS 10

void beautifyHTML(FILE *inputFile, FILE *outputFile) {
    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;  // To keep track of current indentation level
    int i, j;
    
    while (fgets(line, sizeof(line), inputFile)) {
        // Trim whitespace from the start and end of the line
        char *start = line;
        char *end = line + strlen(line) - 1;

        while (*start && isspace(*start)) start++;
        while (end > start && isspace(*end)) end--;
        end[1] = '\0'; // Terminate the line

        // Handle opening and closing tags to adjust indentation levels
        if (strstr(line, "</") != NULL) {  // Closing tag detected
            indentLevel--;
        }

        // Print indentation for the current line
        for (j = 0; j < indentLevel; j++)
            fprintf(outputFile, "\t");

        // Output the trimmed line
        fprintf(outputFile, "%s\n", start);

        // Handle opening tags to adjust indentation levels
        if (strstr(line, "<") != NULL && strstr(line, "/") == NULL && strstr(line, "</") == NULL) {
            if (strstr(line, "/>") == NULL) {  // Not a self-closing tag
                indentLevel++;
            }
        }
    }
}

void printUsage(char *programName) {
    printf("Usage: %s <input_file.html> <output_file.html>\n", programName);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printUsage(argv[0]);
        return 1;
    }

    // Open input and output files
    FILE *inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    // Begin the beautification process
    beautifyHTML(inputFile, outputFile);

    // Cleanup: Close files
    fclose(inputFile);
    fclose(outputFile);

    printf("HTML beautification completed. Output written to %s\n", argv[2]);

    return 0;
}