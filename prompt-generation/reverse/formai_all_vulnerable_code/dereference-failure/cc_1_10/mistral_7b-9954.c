//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHARS_PER_LINE 81
#define UPPER_BIT 6

void processFile(FILE *srcFile, FILE *destFile);
int isFileValid(const char *fileName);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <sourceFile> <destinationFile>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (!isFileValid(argv[1])) {
        perror("Error opening source file.");
        exit(EXIT_FAILURE);
    }

    FILE *srcFile = fopen(argv[1], "r");
    FILE *destFile = fopen(argv[2], "w");

    if (!srcFile || !destFile) {
        perror("Error opening files.");
        exit(EXIT_FAILURE);
    }

    processFile(srcFile, destFile);
    fclose(srcFile);
    fclose(destFile);

    printf("File processing completed successfully!\n");
    exit(EXIT_SUCCESS);
}

void processFile(FILE *srcFile, FILE *destFile) {
    char buffer[CHARS_PER_LINE];
    char *ptr;

    while (fgets(buffer, CHARS_PER_LINE, srcFile)) {
        ptr = buffer;

        while (*ptr != '\0') {
            if ((*ptr & 3) == 0) { // Check if it's the fourth character
                *ptr = (*ptr & ~UPPER_BIT) | ((*(ptr + 1) & UPPER_BIT) >> UPPER_BIT);
                if (*ptr > 'z') {
                    *ptr -= 32;
                }
            }
            ptr++;
        }

        fwrite(buffer, sizeof(char), strlen(buffer), destFile);
    }
}

int isFileValid(const char *fileName) {
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        return 0;
    }

    fclose(file);
    return 1;
}