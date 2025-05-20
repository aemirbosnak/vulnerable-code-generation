//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main()
{
    FILE *fpIn, *fpOut;
    char inFileName[64], outFileName[64];
    char key[64];
    unsigned char byte, byteKey, encryptedByte;
    int i = 0, keyLength, success;

    // Get input file name
    printf("Enter the file name to encrypt: ");
    scanf("%s", inFileName);

    // Open input file
    fpIn = fopen(inFileName, "rb");
    if(fpIn == NULL)
    {
        printf("Error opening file!\n");
        return EXIT_FAILURE;
    }

    // Get output file name
    printf("Enter the name of the encrypted file: ");
    scanf("%s", outFileName);

    // Open output file
    fpOut = fopen(outFileName, "wb");
    if(fpOut == NULL)
    {
        printf("Error creating encrypted file!\n");
        return EXIT_FAILURE;
    }

    // Get encryption key
    printf("Enter the encryption key: ");
    scanf("%s", key);
    keyLength = strlen(key);

    // Encrypt file
    while(fread(&byte, sizeof(byte), 1, fpIn))
    {
        byteKey = key[i++ % keyLength];
        encryptedByte = byte ^ byteKey;

        success = fwrite(&encryptedByte, sizeof(encryptedByte), 1, fpOut);
        if(success != 1)
        {
            printf("Error writing to encrypted file!\n");
            return EXIT_FAILURE;
        }
    }

    // Close files
    fclose(fpIn);
    fclose(fpOut);

    printf("File encryption successful.\n");

    return EXIT_SUCCESS;
}