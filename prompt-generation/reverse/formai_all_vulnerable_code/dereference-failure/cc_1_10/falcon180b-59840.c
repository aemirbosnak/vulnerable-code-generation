//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 50

// Function to count words in a line
int countWords(char *line) {
    int count = 0;
    char *word = strtok(line, ",.?!;:");
    while (word!= NULL) {
        count++;
        word = strtok(NULL, ",.?!;:");
    }
    return count;
}

// Function to read file into memory
char *readFile(char *filename) {
    FILE *file;
    char *buffer = NULL;
    long fileSize;

    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    fileSize = ftell(file);
    rewind(file);

    buffer = (char *) malloc(fileSize + 1);
    if (buffer == NULL) {
        printf("Error allocating memory for file %s\n", filename);
        exit(1);
    }

    fread(buffer, fileSize, 1, file);
    buffer[fileSize] = '\0';

    fclose(file);

    return buffer;
}

// Function to print usage instructions
void printUsage() {
    printf("Usage: wordcount <filename>\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printUsage();
        exit(1);
    }

    char *filename = argv[1];
    char *buffer = readFile(filename);
    int totalWords = 0;
    int lineWords = 0;
    int maxWords = 0;
    int minWords = MAX_WORD_LENGTH;

    char *line = strtok(buffer, "\n");
    while (line!= NULL) {
        int words = countWords(line);
        totalWords += words;
        if (words > maxWords) {
            maxWords = words;
        }
        if (words < minWords) {
            minWords = words;
        }
        lineWords += words;
        line = strtok(NULL, "\n");
    }

    printf("Total words: %d\n", totalWords);
    printf("Average words per line: %.2f\n", (float) totalWords / lineWords);
    printf("Max words per line: %d\n", maxWords);
    printf("Min words per line: %d\n", minWords);

    free(buffer);

    return 0;
}