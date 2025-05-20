//FormAI DATASET v1.0 Category: File Encyptor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

void encrypt(char *input_filename, char *output_filename)
{
    char ch;
    FILE *fptr1, *fptr2;
    fptr1 = fopen(input_filename, "r");
    if (fptr1 == NULL)
    {
        printf("Error opening input file");
        return;
    }
    fptr2 = fopen(output_filename, "w");
    if (fptr2 == NULL)
    {
        printf("Error opening output file");
        return;
    }
    while (ch != EOF)
    {
        ch = fgetc(fptr1);
        ch = ch + 100;
        fputc(ch, fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
    printf("\nFile encrypted successfully!");
}

void decrypt(char *input_filename, char *output_filename)
{
    char ch;
    int key = 100;
    FILE *fptr1, *fptr2;
    fptr1 = fopen(input_filename, "r");
    if (fptr1 == NULL)
    {
        printf("Error opening input file");
        return;
    }
    fptr2 = fopen(output_filename, "w");
    if (fptr2 == NULL)
    {
        printf("Error opening output file");
        return;
    }
    while (ch != EOF)
    {
        ch = fgetc(fptr1);
        ch = ch - key;
        fputc(ch, fptr2);
    }
    fclose(fptr1);
    fclose(fptr2);
    printf("\nFile decrypted successfully!");
}

int main()
{
    char input_filename[MAX_SIZE];
    char output_filename[MAX_SIZE];
    int choice;
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("Enter the name of input file: ");
    scanf("%s", input_filename);
    printf("Enter the name of output file: ");
    scanf("%s", output_filename);
    switch (choice)
    {
    case 1:
        encrypt(input_filename, output_filename);
        break;
    case 2:
        decrypt(input_filename, output_filename);
        break;
    default:
        printf("Invalid choice");
    }
    return 0;
}