//Falcon-180B DATASET v1.0 Category: Data recovery tool ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILE_SIZE 1000000
#define MAX_LINE_SIZE 1000
#define MAX_WORD_SIZE 100

typedef struct {
    char *filename;
    FILE *file;
    int size;
} FileData;

typedef struct {
    char *word;
    int count;
} WordData;

void readFile(FileData *fileData);
void countWords(FileData *fileData, WordData *wordData);
void printWords(WordData *wordData, int numWords);

int main() {
    FileData fileData;
    WordData wordData[MAX_FILE_SIZE];

    printf("Enter filename: ");
    scanf("%s", fileData.filename);

    fileData.file = fopen(fileData.filename, "r");

    if (fileData.file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readFile(&fileData);

    countWords(&fileData, wordData);

    printWords(wordData, fileData.size);

    fclose(fileData.file);

    return 0;
}

void readFile(FileData *fileData) {
    char ch;
    int i = 0;

    while ((ch = fgetc(fileData->file))!= EOF) {
        if (i >= MAX_FILE_SIZE) {
            printf("Error: File is too large.\n");
            exit(1);
        }

        fileData->size++;

        if (isspace(ch)) {
            fileData->filename[i] = '\0';
        } else {
            fileData->filename[i++] = ch;
        }
    }

    fileData->filename[i] = '\0';
}

void countWords(FileData *fileData, WordData *wordData) {
    char *token;
    int i = 0;

    token = strtok(fileData->filename, " ");

    while (token!= NULL) {
        if (i >= MAX_WORD_SIZE) {
            printf("Error: Word is too long.\n");
            exit(1);
        }

        strcpy(wordData[i].word, token);
        wordData[i].count = 1;

        i++;

        token = strtok(NULL, " ");
    }
}

void printWords(WordData *wordData, int numWords) {
    int i;

    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordData[i].word, wordData[i].count);
    }
}