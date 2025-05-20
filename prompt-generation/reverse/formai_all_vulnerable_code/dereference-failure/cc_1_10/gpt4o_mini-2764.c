//GPT-4o-mini DATASET v1.0 Category: HTML beautifier ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

// Function prototypes
void beautifyHTML(FILE *inputFile, FILE *outputFile);
void indentLine(char *line, int indentLevel, FILE *outputFile);
int isOpeningTag(const char *tag);
int isClosingTag(const char *tag);
void trimWhitespace(char *line);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input.html> <output.html>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *inputFile = fopen(argv[1], "r");
    if (!inputFile) {
        perror("Error opening input file");
        return EXIT_FAILURE;
    }

    FILE *outputFile = fopen(argv[2], "w");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return EXIT_FAILURE;
    }

    beautifyHTML(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);
    return EXIT_SUCCESS;
}

void beautifyHTML(FILE *inputFile, FILE *outputFile) {
    char line[BUFFER_SIZE];
    int indentLevel = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        trimWhitespace(line);
        
        // Check for closing tag
        char *closingTag = strchr(line, '<');
        if (closingTag && closingTag[1] == '/') {
            indentLevel--;
        }

        // Indent and write the line
        indentLine(line, indentLevel, outputFile);

        // Check for opening tag
        char *openingTag = strchr(line, '<');
        if (openingTag && openingTag[1] != '/') {
            indentLevel++;
        }
    }
}

void indentLine(char *line, int indentLevel, FILE *outputFile) {
    fprintf(outputFile, "%*s%s\n", indentLevel * 4, "", line); // 4 spaces per indent
}

int isOpeningTag(const char *tag) {
    return tag[0] != '/' && tag[0] == '<';
}

int isClosingTag(const char *tag) {
    return tag[0] == '/';
}

void trimWhitespace(char *line) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*line)) line++;

    // Trim trailing space
    end = line + strlen(line) - 1;
    while (end > line && isspace((unsigned char)*end)) end--;

    // Null terminate after trimming
    *(end + 1) = '\0';
}