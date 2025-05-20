//FormAI DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the contents of a file
void encryptFile(char* file_path, char* key)
{
    FILE *fp;
    fp = fopen(file_path, "rb");

    // Check if file exists
    if (fp == NULL)
    {
        printf("Error: File does not exist.\n");
        return;
    }

    // Get size of file
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // Create buffer to hold file contents
    char* file_contents = (char*)malloc(file_size);
    fread(file_contents, 1, file_size, fp);
    fclose(fp);

    // Encrypt contents of file
    for (int i = 0; i < file_size; i++)
    {
        file_contents[i] = file_contents[i] ^ key[i % strlen(key)];
    }

    // Write encrypted contents back to file
    fp = fopen(file_path, "wb");
    fwrite(file_contents, 1, file_size, fp);

    free(file_contents);
    fclose(fp);

    printf("File '%s' has been encrypted with key '%s'\n", file_path, key);
}

int main(int argc, char** argv)
{
    // Check if correct number of arguments have been provided
    if (argc != 3)
    {
        printf("Usage: ./encrypt <file_path> <key>\n");
        return 1;
    }

    char* file_path = argv[1];
    char* key = argv[2];

    // Encrypt file
    encryptFile(file_path, key);

    return 0;
}