//LLAMA2-13B DATASET v1.0 Category: File handling ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define MAX_FILES 10
#define MAX_LINE_LENGTH 1024

// Global variables
int numFiles = 0;
char** fileNames = NULL;
char** fileContents = NULL;

// Function prototypes
void generateFiles(void);
void readFiles(void);
void writeFiles(void);
void deleteFiles(void);

int main(void)
{
    // Initialize global variables
    numFiles = 0;
    fileNames = malloc(MAX_FILES * sizeof(char*));
    fileContents = malloc(MAX_FILES * sizeof(char*));

    // Generate random files
    generateFiles();

    // Read files
    readFiles();

    // Write new contents to files
    writeFiles();

    // Delete files
    deleteFiles();

    return 0;
}

// Generate random files
void generateFiles(void)
{
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        char filename[50];
        sprintf(filename, "file%d.txt", i);
        FILE* file = fopen(filename, "w");
        if (file == NULL) {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }
        char* contents = malloc(MAX_LINE_LENGTH * sizeof(char));
        for (int j = 0; j < MAX_LINE_LENGTH; j++) {
            contents[j] = 'A' + (rand() % 26);
        }
        fprintf(file, "%s", contents);
        fclose(file);
        fileNames[i] = filename;
        fileContents[i] = contents;
    }
}

// Read files
void readFiles(void)
{
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        char* contents = malloc(MAX_LINE_LENGTH * sizeof(char));
        FILE* file = fopen(fileNames[i], "r");
        if (file == NULL) {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }
        fread(contents, 1, MAX_LINE_LENGTH, file);
        fclose(file);
        printf("%s\n", contents);
    }
}

// Write new contents to files
void writeFiles(void)
{
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        char* newContents = malloc(MAX_LINE_LENGTH * sizeof(char));
        newContents[rand() % MAX_LINE_LENGTH] = 'A' + (rand() % 26);
        FILE* file = fopen(fileNames[i], "w");
        if (file == NULL) {
            perror("Failed to open file");
            exit(EXIT_FAILURE);
        }
        fprintf(file, "%s", newContents);
        fclose(file);
    }
}

// Delete files
void deleteFiles(void)
{
    int i;
    for (i = 0; i < MAX_FILES; i++) {
        unlink(fileNames[i]);
    }
}