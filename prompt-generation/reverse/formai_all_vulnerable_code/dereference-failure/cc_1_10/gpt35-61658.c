//FormAI DATASET v1.0 Category: File Encyptor ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *str)
{
    int len, i;
    char temp;
    len = strlen(str);

    for (i = 0; i < len / 2; i++)
    {
        temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        printf("Usage: %s [file_to_encrypt] [key]\n", argv[0]);
        exit(0);
    }

    char *file_name = argv[1];
    char *key = argv[2];

    FILE *fp = fopen(file_name, "rb");
    if (fp == NULL)
    {
        printf("Error: could not open file %s\n", file_name);
        exit(1);
    }

    // Get the file size
    fseek(fp, 0L, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    // Read the file into a buffer
    char *buffer = (char*)malloc(size + 1);
    fread(buffer, size, 1, fp);
    fclose(fp);

    // Encrypt the buffer
    for (int i = 0; i < size; i++)
        buffer[i] ^= key[i % strlen(key)];

    // Reverse the buffer
    reverse(buffer);

    // Write the encrypted buffer to a new file
    char *encrypted_file_name = (char*)malloc(strlen(file_name) + strlen(".encrypted") + 1);
    strcpy(encrypted_file_name, file_name);
    strcat(encrypted_file_name, ".encrypted");
    fp = fopen(encrypted_file_name, "wb");
    fwrite(buffer, size, 1, fp);
    fclose(fp);

    printf("File %s encrypted and saved to %s\n", file_name, encrypted_file_name);

    free(buffer);
    free(encrypted_file_name);

    return 0;
}