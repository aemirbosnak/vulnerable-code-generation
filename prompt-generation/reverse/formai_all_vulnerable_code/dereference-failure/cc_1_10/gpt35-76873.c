//FormAI DATASET v1.0 Category: File Encyptor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_FILENAME_SIZE 256
#define MAX_DATA_SIZE 1024

void encrypt(char *data, int key);
void decrypt(char *data, int key);
void printErrorMessage(char *message, int exitCode);

int main(int argc, char *argv[])
{
    char filename[MAX_FILENAME_SIZE];
    int key;

    // Check if filename and key are given as command line arguments
    if(argc != 3)
    {
        printErrorMessage("USAGE: encryptor <filename> <key>", 1);
    }

    // Copy filename and key from command line arguments
    strcpy(filename, argv[1]);
    key = atoi(argv[2]);

    // Open file
    FILE *file;
    file = fopen(filename, "r+");
    if(file == NULL)
    {
        printErrorMessage("Failed to open file.", 2);
    }

    // Read data from file
    char data[MAX_DATA_SIZE];
    fread(data, sizeof(char), MAX_DATA_SIZE, file);
    fclose(file);

    // Encrypt data
    encrypt(data, key);

    // Open file again and overwrite it with encrypted data
    file = fopen(filename, "w");
    fwrite(data, sizeof(char), MAX_DATA_SIZE, file);
    fclose(file);

    printf("File encryption successful.\n");

    return 0;
}

void encrypt(char *data, int key)
{
    int len = strlen(data);
    for(int i = 0; i < len; i++)
    {
        if(isalpha(data[i]))
        {
            if(isupper(data[i]))
            {
                data[i] = ((data[i] - 'A' + key) % 26) + 'A';
            }
            else
            {
                data[i] = ((data[i] - 'a' + key) % 26) + 'a';
            }
        }
    }
}

void decrypt(char *data, int key)
{
    encrypt(data, 26 - key % 26);
}

void printErrorMessage(char *message, int exitCode)
{
    printf("ERROR: %s\n", message);
    exit(exitCode);
}