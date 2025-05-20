//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define INDENT_SIZE 4

// Function to remove unnecessary whitespace from the line
void trimWhitespace(char *line) {
    char *end;

    // Trim leading space
    while(isspace((unsigned char)*line)) line++;

    // Trim trailing space
    end = line + strlen(line) - 1;
    while(end > line && isspace((unsigned char)*end)) end--;

    // Null terminate after the last character
    *(end + 1) = '\0';
}

// Function to beautify a line of HTML
void beautifyLine(char *line, int indentLevel, FILE *outFile) {
    // Add indentation before the line
    for(int i = 0; i < indentLevel; i++) {
        fprintf(outFile, "%*s", INDENT_SIZE, "");
    }
    
    // Write the trimmed line to the output file
    fprintf(outFile, "%s\n", line);
}

// Function to check if the line contains an opening or closing tag
int checkTagType(char *line, int *indentLevel) {
    if (strstr(line, "<") && strstr(line, ">")) {
        // Check for closing tag
        if (line[1] == '/') {
            (*indentLevel)--;
            return 1; // Closing tag
        }
        // Check for opening tag
        (*indentLevel)++;
        return 0; // Opening tag
    }
    return -1; // No tag
}

// Function to beautify the HTML content
void beautifyHTML(const char *inputFileName, const char *outputFileName) {
    FILE *inFile = fopen(inputFileName, "r");
    FILE *outFile = fopen(outputFileName, "w");
    
    if (!inFile) {
        perror("Error opening input file");
        exit(EXIT_FAILURE);
    }
    if (!outFile) {
        perror("Error opening output file");
        fclose(inFile);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int indentLevel = 0;

    // Read each line from the input file
    while (fgets(line, sizeof(line), inFile)) {
        trimWhitespace(line);
        
        int tagType = checkTagType(line, &indentLevel);
        
        // Beautify the line
        beautifyLine(line, indentLevel, outFile);
        
        // If it was a closing tag, adjust the indent level after writing
        if (tagType == 1) {
            indentLevel--;
        }
    }

    fclose(inFile);
    fclose(outFile);
}

// Main function to execute the program
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_html_file> <output_html_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    beautifyHTML(argv[1], argv[2]);
    printf("HTML Beautification Complete!\n");
    
    return 0;
}