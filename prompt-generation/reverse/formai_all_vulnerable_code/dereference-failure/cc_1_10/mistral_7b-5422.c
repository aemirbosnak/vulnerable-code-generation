//MISTRAL-7B DATASET v1.0 Category: File Synchronizer ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 512

typedef struct {
    char name[MAX_FILE_NAME_LENGTH];
    char *content;
    size_t size;
} File;

File readFile(const char *fileName);
void printDiff(const char *oldContent, const char *newContent);
void writeOutput(const char *outputFileName, const char *content);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <oldFile> <newFile> <outputFile>\n", argv[0]);
        exit(1);
    }

    File oldFile = readFile(argv[1]);
    File newFile = readFile(argv[2]);

    if (oldFile.size != newFile.size) {
        printDiff(oldFile.content, newFile.content);
        writeOutput(argv[3], newFile.content);
    } else {
        for (size_t i = 0; i < oldFile.size; ++i) {
            if (oldFile.content[i] != newFile.content[i]) {
                printDiff(&oldFile.content[i], &newFile.content[i]);
                break;
            }
        }
    }

    free(oldFile.content);
    free(newFile.content);

    return 0;
}

File readFile(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if (!file) {
        perror("Error opening file");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    size_t fileSize = ftell(file);
    rewind(file);

    char *content = malloc(fileSize + 1);
    size_t bytesRead = fread(content, 1, fileSize, file);
    if (bytesRead != fileSize) {
        perror("Error reading file");
        exit(1);
    }

    content[fileSize] = '\0';

    File fileData = { .name = fileName, .content = content, .size = fileSize };
    return fileData;
}

void printDiff(const char *oldContent, const char *newContent) {
    printf("Difference found at line %ld:\n", (long) (strcspn(oldContent, "\n") / sizeof(char) + 1));
    printf("Old content: %s\n", oldContent);
    printf("New content: %s\n", newContent);
}

void writeOutput(const char *outputFileName, const char *content) {
    FILE *outputFile = fopen(outputFileName, "w");
    if (!outputFile) {
        perror("Error opening output file");
        exit(1);
    }

    fwrite(content, 1, strlen(content), outputFile);

    fclose(outputFile);
}