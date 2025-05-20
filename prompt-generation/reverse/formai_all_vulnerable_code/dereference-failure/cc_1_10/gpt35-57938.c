//FormAI DATASET v1.0 Category: File Encyptor ; Style: random
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

int main()
{
    char password[MAX_LENGTH], filename[MAX_LENGTH], buffer[MAX_LENGTH];
    FILE *inputFile, *outputFile;
    int key, byte;

    printf("Enter the password: ");
    fgets(password, MAX_LENGTH, stdin);

    printf("Enter the input filename: ");
    fgets(filename, MAX_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = 0;

    inputFile = fopen(filename, "rb");
    outputFile = fopen("encrypted.dat", "wb");

    if (inputFile == NULL)
    {
        printf("Error: File not found!\n");
        return 1;
    }

    printf("\nEncrypting file...\n");

    key = 0;
    int index = 0;
    while (fgets(buffer, MAX_LENGTH, inputFile))
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            byte = (int) buffer[i];

            if (index >= strlen(password)) index = 0;
            key = (int) password[index];
            index++;

            byte = byte ^ key;

            fputc(byte, outputFile);
        }
    }

    printf("Encryption complete!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}