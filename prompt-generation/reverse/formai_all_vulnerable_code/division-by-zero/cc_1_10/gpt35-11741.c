//FormAI DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* This function takes a filename and a passphrase string, reads the content of the file,
   and encrypts it based on the passphrase */
void encrypt_file(const char *filename, const char *passphrase)
{
    FILE *fptr1, *fptr2;
    char ch;
    int i, len;

    // Open the input file in read mode
    fptr1 = fopen(filename, "r");

    // If the input file is not found, show error and exit
    if (fptr1 == NULL)
    {
        printf("Error: Input file \"%s\" not found\n", filename);
        exit(1);
    }

    // Open the output file in write mode
    fptr2 = fopen("encrypted_file.bin", "wb");

    // If the output file cannot be created, show error and exit
    if (fptr2 == NULL)
    {
        printf("Error: Cannot create output file\n");
        fclose(fptr1);
        exit(1);
    }

    // Get the length of the passphrase
    len = strlen(passphrase);

    // Read characters from the input file one by one
    i = 0;
    while ((ch = fgetc(fptr1)) != EOF)
    {
        // Encrypt the character by XORing it with the corresponding character of the passphrase
        ch = ch ^ passphrase[i % len];

        // Write the encrypted character to the output file
        fputc(ch, fptr2);

        // Increment the passphrase index
        i++;
    }

    // Close both files
    fclose(fptr1);
    fclose(fptr2);

    printf("File \"%s\" was encrypted with passphrase \"%s\".\nEncrypted file is \"encrypted_file.bin\"\n", filename, passphrase);
}

int main()
{
    char filename[100], passphrase[100];

    printf("Enter the filename to encrypt: ");
    scanf("%s", filename);

    printf("Enter the passphrase: ");
    scanf("%s", passphrase);

    // Encrypt the input file with the passphrase
    encrypt_file(filename, passphrase);

    return 0;
}