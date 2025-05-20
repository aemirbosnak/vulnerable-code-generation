//Gemma-7B DATASET v1.0 Category: File handling ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store file information
typedef struct FileInfo
{
    char *filename;
    int size;
    FILE *fp;
} FileInfo;

// Function to open a file
void openFile(FileInfo *file, char *filename, int size)
{
    file->filename = strdup(filename);
    file->size = size;

    file->fp = fopen(filename, "r");
    if (file->fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }
}

// Function to read data from a file
void readData(FileInfo *file, char *buffer, int bytes)
{
    int readBytes = fread(buffer, 1, bytes, file->fp);
    if (readBytes != bytes)
    {
        perror("Error reading data");
        exit(1);
    }
}

// Function to close a file
void closeFile(FileInfo *file)
{
    fclose(file->fp);
    free(file->filename);
}

int main()
{
    // Create a file information structure
    FileInfo file;

    // Open a file
    openFile(&file, "my-file.txt", 1024);

    // Read data from the file
    char buffer[1024];
    readData(&file, buffer, 512);

    // Close the file
    closeFile(&file);

    // Print the data
    printf("%s", buffer);

    return 0;
}