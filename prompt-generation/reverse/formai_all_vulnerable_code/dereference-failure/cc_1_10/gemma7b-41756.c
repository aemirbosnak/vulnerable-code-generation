//Gemma-7B DATASET v1.0 Category: File Encyptor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

void encrypt_file(char *filename)
{
    FILE *fp = fopen(filename, "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char buffer[1024];
    int bytes_read;

    FILE *fp_enc = fopen("encrypted.txt", "w");
    if (fp_enc == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    while ((bytes_read = fread(buffer, 1, 1024, fp)) > 0)
    {
        for (int i = 0; i < bytes_read; i++)
        {
            buffer[i] ^= 0x12;
        }

        fwrite(buffer, 1, bytes_read, fp_enc);
    }

    fclose(fp);
    fclose(fp_enc);
}

int main()
{
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    encrypt_file(filename);

    printf("File encrypted successfully!\n");

    return 0;
}