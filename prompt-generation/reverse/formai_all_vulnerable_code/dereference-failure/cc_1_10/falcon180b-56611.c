//Falcon-180B DATASET v1.0 Category: File handling ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_SIZE 1000000

typedef struct {
    char *filename;
    FILE *file;
    long filesize;
    char *buffer;
    size_t buffersize;
} File;

int main() {
    File file;
    char line[MAX_LINE_LENGTH];
    char word[MAX_LINE_LENGTH];
    char *delimiters = " \t\n\r\f\v";
    int wordcount = 0;

    file.filename = "example.txt";
    file.file = fopen(file.filename, "r");
    if (file.file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(file.file, 0, SEEK_END);
    file.filesize = ftell(file.file);
    rewind(file.file);

    file.buffer = (char*) malloc(file.filesize + 1);
    if (file.buffer == NULL) {
        printf("Error allocating memory for buffer.\n");
        exit(1);
    }

    fread(file.buffer, file.filesize, 1, file.file);
    file.buffer[file.filesize] = '\0';
    fclose(file.file);

    char *token = strtok(file.buffer, delimiters);
    while (token!= NULL) {
        strcpy(word, token);
        wordcount++;
        token = strtok(NULL, delimiters);
    }

    printf("Number of words in file: %d\n", wordcount);

    free(file.buffer);
    return 0;
}