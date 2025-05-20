//FormAI DATASET v1.0 Category: File Encyptor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *text, int key);

int main()
{
    char filename[50];
    int key;

    // Get the filename and key from the user
    printf("Enter the name of the file to encrypt: ");
    scanf("%s", filename);
    printf("Enter the encryption key: ");
    scanf("%d", &key);

    FILE *file = fopen(filename, "r");  // Open the file in read mode

    if (file == NULL)  // Check if the file could not be opened
    {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    // Get the size of the file
    fseek(file, 0, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Allocate memory to store the file contents
    char *file_contents = (char *) malloc(file_size + 1);
    fread(file_contents, file_size, 1, file);
    fclose(file);

    // Encrypt the file contents
    encrypt(file_contents, key);

    // Open a new file to write the encrypted contents
    FILE *new_file = fopen("encrypted.bin", "wb");

    if (new_file == NULL)  // Check if the new file could not be created
    {
        printf("Error: Could not create encrypted file.\n");
        exit(1);
    }

    fwrite(file_contents, file_size, 1, new_file);
    fclose(new_file);

    free(file_contents);

    printf("File encrypted successfully.\n");

    return 0;
}

void encrypt(char *text, int key)
{
    int i;
    char c;

    for (i = 0; text[i] != '\0'; i++)
    {
        c = text[i];

        if (c >= 'a' && c <= 'z')  // Encrypt lowercase letters
        {
            c = c + key;

            if (c > 'z')
            {
                c = c - 'z' + 'a' - 1;
            }

            text[i] = c;
        }
        else if (c >= 'A' && c <= 'Z')  // Encrypt uppercase letters
        {
            c = c + key;

            if (c > 'Z')
            {
                c = c - 'Z' + 'A' - 1;
            }

            text[i] = c;
        }
    }
}