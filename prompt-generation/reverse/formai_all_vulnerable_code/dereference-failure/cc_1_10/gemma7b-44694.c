//Gemma-7B DATASET v1.0 Category: File handling ; Style: optimized
#include <stdio.h>
#include <stdlib.h>

#define MAX_FILE_SIZE 1024

typedef struct FileData
{
    char *data;
    int size;
} FileData;

FileData *readFile(char *filename)
{
    FILE *fp;
    FileData *fileData = NULL;
    int fileSize = 0;

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        return NULL;
    }

    // Calculate file size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);

    // Allocate memory for file data
    fileData = malloc(sizeof(FileData));
    fileData->data = malloc(fileSize);

    // Read file data
    rewind(fp);
    fread(fileData->data, fileSize, 1, fp);

    fileData->size = fileSize;

    fclose(fp);

    return fileData;
}

void writeFile(FileData *fileData, char *filename)
{
    FILE *fp;

    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        return;
    }

    fwrite(fileData->data, fileData->size, 1, fp);

    fclose(fp);
}

int main()
{
    char *filename = "my_file.txt";
    FileData *fileData = readFile(filename);

    if (fileData)
    {
        printf("File size: %d\n", fileData->size);
        printf("File data: %s\n", fileData->data);

        writeFile(fileData, filename);
        free(fileData->data);
        free(fileData);
    }

    return 0;
}