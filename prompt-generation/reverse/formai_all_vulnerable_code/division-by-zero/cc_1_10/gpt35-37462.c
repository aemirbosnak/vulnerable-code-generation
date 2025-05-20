//FormAI DATASET v1.0 Category: File Encyptor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* input_file, char* output_file, char* key)
{
    FILE *fp1, *fp2;
    char ch;
    int i = 0, keylen = strlen(key);

    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch ^ key[i], fp2);
        i = (i + 1) % keylen;
    }

    fclose(fp1);
    fclose(fp2);

    printf("Encryption successful!\n");
}

void decrypt(char* input_file, char* output_file, char* key)
{
    FILE *fp1, *fp2;
    char ch;
    int i = 0, keylen = strlen(key);

    fp1 = fopen(input_file, "r");
    fp2 = fopen(output_file, "w");

    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Error in opening file!");
        exit(1);
    }

    while ((ch = fgetc(fp1)) != EOF)
    {
        fputc(ch ^ key[i], fp2);
        i = (i + 1) % keylen;
    }

    fclose(fp1);
    fclose(fp2);

    printf("Decryption successful!\n");
}

int main()
{
    char input_file[100], output_file[100], key[100], choice;

    printf("Enter the filename to be encrypted: ");
    scanf("%s", input_file);

    printf("Enter the filename to store the encrypted data: ");
    scanf("%s", output_file);

    printf("Enter the key for encryption: ");
    scanf("%s", key);

    encrypt(input_file, output_file, key);

    printf("Do you want to decrypt the file? (y/n) ");
    scanf(" %c", &choice);

    if (choice == 'y')
    {
        printf("Enter the filename to be decrypted: ");
        scanf("%s", input_file);

        printf("Enter the filename to store the decrypted data: ");
        scanf("%s", output_file);

        printf("Enter the key for decryption: ");
        scanf("%s", key);

        decrypt(input_file, output_file, key);
    }

    return 0;
}