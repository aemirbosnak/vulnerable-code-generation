//FormAI DATASET v1.0 Category: File Encyptor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 10000

void printUsage()
{
    printf("Usage: ./fileEncyptor <filename> <key>\n");
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printUsage();
        return 0;
    }

    char *filename = argv[1];
    char *key = argv[2];
    FILE *fp;
    char buffer[MAX_BUFFER_SIZE];
    size_t bytesRead;
    size_t fileSize;

    // Open the file for reading
    fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    fileSize = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // Read the contents of the file into the buffer
    bytesRead = fread(buffer, sizeof(char), fileSize, fp);

    // Close the file
    fclose(fp);

    // Encrypt the contents of the buffer
    for(int i = 0; i < bytesRead; i++)
    {
        buffer[i] = buffer[i] ^ key[i % strlen(key)];
    }

    // Save the encrypted contents back to the file
    fp = fopen(filename, "wb");

    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 0;
    }

    fwrite(buffer, sizeof(char), bytesRead, fp);

    // Close the file
    fclose(fp);

    printf("Encyption complete!\n");

    return 0;
}