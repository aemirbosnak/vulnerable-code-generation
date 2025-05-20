//FormAI DATASET v1.0 Category: File Encyptor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printError(const char* message)
{
    fprintf(stderr, "Error: %s\n", message);
}

void encryptFile(char* filePath)
{
    FILE* file = fopen(filePath, "rb");
    if(!file)
    {
        printError("File could not be opened!");
        return;
    }

    fseek(file, 0L, SEEK_END);
    size_t fileSize = ftell(file);

    char* fileBytes = (char*) malloc(sizeof(char) * fileSize);
    fseek(file, 0L, SEEK_SET);
    fread(fileBytes, sizeof(char), fileSize, file);
    fclose(file);

    for(int i = 0; i < fileSize; i++)
    {
        fileBytes[i] ^= 0xA5;
    }

    char* newFilePath = (char*) malloc(sizeof(char) * (strlen(filePath) + 5));
    strcpy(newFilePath, filePath);
    strcat(newFilePath, ".enc");

    FILE* newFile = fopen(newFilePath, "wb");
    if(!newFile)
    {
        printError("Could not create encrypted file!");
        return;
    }

    fwrite(fileBytes, sizeof(char), fileSize, newFile);
    fclose(newFile);

    printf("Encryption successful! Encrypted file saved as %s\n", newFilePath);

    free(fileBytes);
    free(newFilePath);
}

int main(int argc, char** argv)
{
    if(argc < 2)
    {
        printError("Please pass a file path as argument!");
        return 1;
    }

    encryptFile(argv[1]);

    return 0;
}