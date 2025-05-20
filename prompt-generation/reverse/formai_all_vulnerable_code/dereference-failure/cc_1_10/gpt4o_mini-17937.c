//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to check for HTML tags
int isTag(char *line, int *i) {
    if (line[*i] == '<') {
        return 1; // Found a tag
    }
    return 0; // No tag found
}

// Function to beautify a single line of HTML
void beautifyLine(char *line, FILE *outputFile) {
    int indentLevel = 0;
    char *token = strtok(line, ">");
    while (token != NULL) {
        if (isTag(token, &(int) {0})) {
            // Opening tag detected
            fprintf(outputFile, "%*s%s>\n", indentLevel * 4, "", token);
            // Increase indent for child tags
            if (token[strlen(token) - 1] != '/') {
                indentLevel++;
            }
        } else {
            // Closing tag detected
            if (strstr(token, "/") != NULL) {
                indentLevel--;
            }
            fprintf(outputFile, "%*s%s", indentLevel * 4, "", token);
        }
        token = strtok(NULL, ">");
    }
}

// Function to read, beautify and write to output file
void beautifyHTML(const char *inputFile, const char *outputFile) {
    FILE *inFile = fopen(inputFile, "r");
    FILE *outFile = fopen(outputFile, "w");
    
    if (inFile == NULL || outFile == NULL) {
        printf("Unexpected Error: Unable to open file(s)!\n");
        return;
    }

    char line[1024];
    while (fgets(line, sizeof(line), inFile)) {
        beautifyLine(line, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

// Main function 
int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Whoops! You have to provide input and output file names.\n");
        printf("Usage: %s <input.html> <output.html>\n", argv[0]);
        return 1;
    }

    printf("Whoa! Starting the HTML beautification process!\n");
    beautifyHTML(argv[1], argv[2]);
    printf("Amazing! HTML beautification is complete! Check the output file!\n");

    return 0;
}