//Falcon-180B DATASET v1.0 Category: File handling ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char *filename;
    FILE *file;
} FileHandler;

FileHandler *openFile(char *filename) {
    FileHandler *handler = (FileHandler *)malloc(sizeof(FileHandler));
    handler->filename = strdup(filename);
    handler->file = fopen(filename, "r");
    return handler;
}

void closeFile(FileHandler *handler) {
    fclose(handler->file);
    free(handler->filename);
    free(handler);
}

char *readLine(FileHandler *handler) {
    char *line = NULL;
    size_t capacity = 0;
    int c;
    while ((c = fgetc(handler->file))!= EOF) {
        if (c == '\n') {
            break;
        }
        if (capacity == MAX_LINE_LENGTH) {
            printf("Error: Line too long\n");
            exit(1);
        }
        char *newLine = realloc(line, capacity + 2);
        if (newLine == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(1);
        }
        line = newLine;
        line[capacity++] = c;
    }
    if (c == EOF) {
        if (capacity == 0) {
            line = NULL;
        } else {
            line[capacity - 1] = '\0';
        }
    }
    return line;
}

int main() {
    char filename[MAX_FILE_NAME_LENGTH];
    printf("Enter file name: ");
    scanf("%s", filename);
    FileHandler *handler = openFile(filename);
    if (handler == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    char *line;
    while ((line = readLine(handler))!= NULL) {
        printf("%s", line);
    }
    closeFile(handler);
    return 0;
}