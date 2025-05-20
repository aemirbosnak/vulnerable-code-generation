//FormAI DATASET v1.0 Category: HTML beautifier ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// This function checks for opening tags
int isOpeningTag(char *line, int index) {
    // If the line doesn't have an opening tag
    if (line[index] != '<' || line[index + 1] == '/' || line[index + 1] == ' ' || line[index + 1] == '\n') {
        return 0;
    }
    // Check if there is a closing angle bracket
    int i = index + 1;
    while (line[i] != '>' && line[i] != ' ') {
        i++;
    }
    if (line[i] == '>') {
        return i - index + 1;
    }
    return 0;
}

// This function checks for closing tags
int isClosingTag(char *line, int index) {
    // If the line doesn't have a closing tag
    if (line[index] != '<' || line[index + 1] != '/' || line[index + 2] == ' ' || line[index + 2] == '\n') {
        return 0;
    }
    // Check if there is a closing angle bracket
    int i = index + 2;
    while (line[i] != '>') {
        i++;
    }
    return i - index + 1;
}

int main() {
    // Open the input file
    FILE *inputFile = fopen("input.html", "r");
    if (inputFile == NULL) {
        printf("Failed to open input file.\n");
        exit(1);
    }

    // Open the output file
    FILE *outputFile = fopen("output.html", "w");
    if (outputFile == NULL) {
        printf("Failed to open output file.\n");
        exit(1);
    }

    // Read input file line by line
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int indent = 0;
    while ((read = getline(&line, &len, inputFile)) != -1) {
        // Check for opening and closing tags
        int openTagLength = isOpeningTag(line, 0);
        int closeTagLength = isClosingTag(line, 0);

        // Add appropriate indentation
        if (openTagLength && !closeTagLength) {
            for (int i = 0; i < indent; i++) {
                fprintf(outputFile, "    ");
            }
            indent++;
        } else if (closeTagLength) {
            indent--;
            for (int i = 0; i < indent; i++) {
                fprintf(outputFile, "    ");
            }
        } else {
            for (int i = 0; i < indent; i++) {
                fprintf(outputFile, "    ");
            }
        }

        // Write the line to the output file
        fprintf(outputFile, "%s", line);
    }

    // Free memory and close files
    free(line);
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}