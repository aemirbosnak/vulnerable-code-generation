//FormAI DATASET v1.0 Category: File Encyptor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the C File Encryptor!\n");
    printf("Please enter the name of the file you wish to encrypt: ");

    char filename[50];
    scanf("%s", filename);

    FILE *fileptr;
    fileptr = fopen(filename, "rb");
    if(fileptr == NULL)
    {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    fseek(fileptr, 0, SEEK_END); // Move to end of file to get file size
    long size = ftell(fileptr);
    fseek(fileptr, 0, SEEK_SET); // Move back to beginning of file

    // Allocate memory for buffer and read contents of file into it
    char *buffer = malloc(size);
    fread(buffer, size, 1, fileptr);
    fclose(fileptr);

    printf("Please enter the encryption key: ");
    char key[50];
    scanf("%s", key);

    int i;
    for(i = 0; i < size; i++)
    {
        buffer[i] ^= key[i % strlen(key)]; // XOR operation with key
    }

    // Write encrypted contents to a new file with "_encrypted" appended to file name
    char encrypted_filename[100];
    strcpy(encrypted_filename, filename);
    strcat(encrypted_filename, "_encrypted");
    fileptr = fopen(encrypted_filename, "wb");
    fwrite(buffer, size, 1, fileptr);
    fclose(fileptr);

    printf("File encrypted successfully!\n");

    free(buffer);

    return 0;
}