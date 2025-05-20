//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: relaxed
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanFile(char* filename, char* virusSignature)
{
    FILE* file = fopen(filename, "rb");
    if (file == NULL)
    {
        return;
    }
    int foundVirus = 0;
    int virusSignatureLength = strlen(virusSignature);
    char* buffer = (char*)calloc(virusSignatureLength, sizeof(char));
    fread(buffer, sizeof(char), virusSignatureLength, file);
    while (!feof(file))
    {
        if (strcmp(buffer, virusSignature) == 0)
        {
            foundVirus = 1;
            break;
        }
        memmove(buffer, buffer + 1, virusSignatureLength - 1);
        fread(buffer + virusSignatureLength - 1, sizeof(char), 1, file);
    }
    fclose(file);
    if (foundVirus)
    {
        printf("Potentially malicious file found: %s\n", filename);
        return;
    }
}

int main()
{
    char* virusSignature = "2137923CD70F79C405ECCAFE4BCA99BA"; // sample virus signature
    int fileCount = 0;
    char** files = (char**)malloc(sizeof(char*));
    char* currentFileName = (char*)malloc(100 * sizeof(char));
    printf("Enter file names (one per line), enter \"done\" when finished:\n");
    while (1)
    {
        fgets(currentFileName, 100, stdin);
        if (strcmp(currentFileName, "done\n") == 0)
        {
            break;
        }
        fileCount++;
        files = (char**)realloc(files, fileCount * sizeof(char*));
        files[fileCount - 1] = (char*)malloc(strlen(currentFileName) * sizeof(char));
        strcpy(files[fileCount - 1], currentFileName);
    }
    printf("Scanning for viruses...\n");
    for (int i = 0; i < fileCount; i++)
    {
        scanFile(files[i], virusSignature);
    }
    printf("Scan complete.\n");
    return 0;
}