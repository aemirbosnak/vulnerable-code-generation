//FormAI DATASET v1.0 Category: File Encyptor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

#define KEY_LEN 16

void encrypt(char *inputFileName, char *outputFileName, char *key);
void decrypt(char *inputFileName, char *outputFileName, char *key);
char *readFileContents(char *fileName);
void writeToFile(char *fileName, char *contents);

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        printf("Usage: %s <input_file> <output_file> <key> <mode>\n", argv[0]);
        printf("Mode: enc - encrypt, dec - decrypt\n");
        return 1;
    }

    char *inputFileName = argv[1];
    char *outputFileName = argv[2];
    char *key = argv[3];
    char *mode = argv[4];

    if (strlen(key) != KEY_LEN)
    {
        printf("Invalid key length. Key must be %d characters long.", KEY_LEN);
        return 1;
    }

    if (*mode == 'e')
    {
        encrypt(inputFileName, outputFileName, key);
        printf("File %s encrypted successfully.\n", inputFileName);
    }
    else if (*mode == 'd')
    {
        decrypt(inputFileName, outputFileName, key);
        printf("File %s decrypted successfully.\n", inputFileName);
    }
    else
    {
        printf("Invalid mode. Mode must be 'enc' or 'dec'.\n");
        return 1;
    }

    return 0;
}

void encrypt(char *inputFileName, char *outputFileName, char *key)
{
    char *inputFileContents = readFileContents(inputFileName);
    char *outputFileContents = malloc(strlen(inputFileContents) + 1);

    int i;
    for (i = 0; i < strlen(inputFileContents); i++)
    {
        outputFileContents[i] = inputFileContents[i] ^ key[i % KEY_LEN];
    }

    outputFileContents[i] = '\0';
    writeToFile(outputFileName, outputFileContents);

    free(inputFileContents);
    free(outputFileContents);
}

void decrypt(char *inputFileName, char *outputFileName, char *key)
{
    encrypt(inputFileName, outputFileName, key);
}

char *readFileContents(char *fileName)
{
    FILE *file = fopen(fileName, "r");
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *fileContents = malloc(fileSize + 1);
    fread(fileContents, fileSize, 1, file);

    fclose(file);

    fileContents[fileSize] = '\0';
    return fileContents;
}

void writeToFile(char *fileName, char *contents)
{
    FILE *file = fopen(fileName, "w");
    fwrite(contents, strlen(contents), 1, file);
    fclose(file);
}