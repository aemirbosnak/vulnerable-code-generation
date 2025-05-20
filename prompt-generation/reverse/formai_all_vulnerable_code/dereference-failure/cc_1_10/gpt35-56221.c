//FormAI DATASET v1.0 Category: HTML beautifier ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

void indentLine(int level) {
    for (int i = 0; i < level; i++) {
        printf("    "); // four spaces per level of indentation
    }
}

void beautifyLine(char* line, int currentLevel) {
    int i = 0;
    while (line[i] == ' ') {
        i++; // count the number of preceding spaces
    }
    if (line[i] == '<') { // opening tag
        indentLine(currentLevel);
        printf("%s\n", line);
        currentLevel++;
    } else if (line[i] == '/') { // closing tag
        currentLevel--;
        indentLine(currentLevel); // decrease level of indentation
        printf("%s\n", line);
    } else { // inner text
        indentLine(currentLevel); // same level of indentation
        printf("%s\n", line);
    }
}

void beautifyFile(char* filePath) {
    FILE* fp;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen(filePath, "r");
    if (fp == NULL) {
        printf("Error: could not open file!\n");
        exit(EXIT_FAILURE);
    }

    int currentLevel = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        beautifyLine(line, currentLevel);
    }

    fclose(fp);
    if (line != NULL) {
        free(line);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s [file_path]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    beautifyFile(argv[1]);
    return EXIT_SUCCESS;
}