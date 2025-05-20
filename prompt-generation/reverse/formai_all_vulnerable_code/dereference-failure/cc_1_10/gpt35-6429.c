//FormAI DATASET v1.0 Category: File Encyptor ; Style: Ada Lovelace
/*
 * FILE ENCYPTOR PROGRAM IN ADA LOVELACE STYLE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char filename[100];
    char password[50];
    int choice;
    FILE *fp, *nfp;

    printf("Welcome to the File Encyptor Program in Ada Lovelace Style!\n\n");

    printf("Enter the filename (with extension): ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    if(fp == NULL)
    {
        printf("Error opening file! Make sure you typed the filename correctly.\n");
        exit(1);
    }

    //Get the password for encryption/decryption
    printf("\nEnter the password: ");
    scanf("%s", password);

    printf("\nWhat would you like to do with the file?\n");
    printf("1. Encrypt\n");
    printf("2. Decrypt\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            //Encrypt the file
            nfp = fopen("encrypted.txt", "wb");

            if(nfp == NULL)
            {
                printf("Error creating encrypted file!\n");
                exit(1);
            }

            int c, i = 0, password_len = strlen(password);

            while((c = fgetc(fp)) != EOF)
            {
                c = c ^ password[i];
                fputc(c, nfp);

                i++;

                if(i == password_len)
                {
                    i = 0;
                }
            }

            printf("\nFile encrypted successfully! Encrypted file saved as encrypted.txt\n");

            fclose(nfp);
            break;

        case 2:
            //Decrypt the file
            nfp = fopen("decrypted.txt", "wb");

            if(nfp == NULL)
            {
                printf("Error creating decrypted file!\n");
                exit(1);
            }

            int d, j = 0, password_dlen = strlen(password);

            while((d = fgetc(fp)) != EOF)
            {
                d = d ^ password[j];
                fputc(d, nfp);

                j++;

                if(j == password_dlen)
                {
                    j = 0;
                }
            }

            printf("\nFile decrypted successfully! Decrypted file saved as decrypted.txt\n");

            fclose(nfp);
            break;
    }

    fclose(fp);

    return 0;
}