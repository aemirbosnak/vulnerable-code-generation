//Gemma-7B DATASET v1.0 Category: File handling ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct FileHandle
{
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    size_t readPos;
    size_t writePos;
} FileHandle;

FileHandle *openFile(char *filename)
{
    FileHandle *fh = malloc(sizeof(FileHandle));
    fh->fp = fopen(filename, "r");
    if (fh->fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
    fh->readPos = 0;
    fh->writePos = 0;
    return fh;
}

void closeFile(FileHandle *fh)
{
    fclose(fh->fp);
    free(fh);
}

int readFromFile(FileHandle *fh, char *buffer, size_t size)
{
    size_t bytesRead = fread(buffer, 1, size, fh->fp);
    fh->readPos += bytesRead;
    return bytesRead;
}

int writeToFile(FileHandle *fh, char *buffer, size_t size)
{
    size_t bytesWritten = fwrite(buffer, 1, size, fh->fp);
    fh->writePos += bytesWritten;
    return bytesWritten;
}

int main()
{
    FileHandle *fh = openFile("my_file.txt");
    char buffer[MAX_BUFFER_SIZE];

    readFromFile(fh, buffer, MAX_BUFFER_SIZE);
    printf("%s", buffer);

    writeToFile(fh, buffer, MAX_BUFFER_SIZE);
    printf("Data written successfully");

    closeFile(fh);

    return 0;
}