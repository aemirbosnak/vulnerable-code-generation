//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *file_name)
{
    FILE *fp;
    int c;

    fp = fopen(file_name, "r+");
    if(fp == NULL)
    {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }

    while((c = fgetc(fp)) != EOF)
    {
        fputc(c^123, fp);
    }
    fclose(fp);
}

void decrypt(char *file_name)
{
    FILE *fp;
    int c;

    fp = fopen(file_name, "r+");
    if(fp == NULL)
    {
        printf("Error: Could not open file %s\n", file_name);
        exit(1);
    }

    while((c = fgetc(fp)) != EOF)
    {
        fputc(c^123, fp);
    }
    fclose(fp);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <e/d> <file_name>\n", argv[0]);
        return 1;
    }

    char *choice = argv[1];
    char *file_name = argv[2];

    if(strcmp(choice, "e") == 0)
    {
        printf("Encrypting %s\n", file_name);
        encrypt(file_name);
        printf("Done!\n");
    }
    else if(strcmp(choice, "d") == 0)
    {
        printf("Decrypting %s\n", file_name);
        decrypt(file_name);
        printf("Done!\n");
    }
    else
    {
        printf("Invalid command %s\n", choice);
    }

    return 0;
}