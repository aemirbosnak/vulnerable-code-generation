//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define SIZE 100

//Function for encrypting the file
void encrypt(FILE *file, char *key)
{
    char ch;
    int key_index = 0;
    while((ch = fgetc(file))!= EOF)
    {
        if(isalpha(ch))
        {
            ch = toupper(ch);
            ch = ch + key_index;
            if(ch > 'Z')
            {
                ch = ch - 26;
            }
            else if(ch < 'A')
            {
                ch = ch + 26;
            }
        }
        else if(isdigit(ch))
        {
            ch = ch + key_index;
            if(ch > '9')
            {
                ch = ch - 10;
            }
        }
        else
        {
            ch = ch;
        }
        fputc(ch, stdout);
        key_index = (key_index + 1) % strlen(key);
    }
}

//Function for decrypting the file
void decrypt(FILE *file, char *key)
{
    char ch;
    int key_index = 0;
    while((ch = fgetc(file))!= EOF)
    {
        if(isalpha(ch))
        {
            ch = toupper(ch);
            ch = ch - key_index;
            if(ch < 'A')
            {
                ch = ch + 26;
            }
            else if(ch > 'Z')
            {
                ch = ch - 26;
            }
        }
        else if(isdigit(ch))
        {
            ch = ch - key_index;
            if(ch < '0')
            {
                ch = ch + 10;
            }
        }
        else
        {
            ch = ch;
        }
        fputc(ch, stdout);
        key_index = (key_index + 1) % strlen(key);
    }
}

//Function for generating a random key
void generate_key(char *key)
{
    int i;
    for(i = 0; i < strlen(key); i++)
    {
        key[i] = rand() % 26 + 'A';
    }
    key[strlen(key)] = '\0';
}

int main()
{
    char filename[SIZE];
    char key[SIZE];
    FILE *file;
    int choice;
    do
    {
        printf("Enter the name of the file to be encrypted:\n");
        scanf("%s", filename);
        file = fopen(filename, "r+");
        if(file == NULL)
        {
            printf("Error opening file\n");
        }
        else
        {
            printf("Enter the key for encryption:\n");
            scanf("%s", key);
            generate_key(key);
            printf("Do you want to encrypt or decrypt the file? (E/D)\n");
            scanf(" %c", &choice);
            if(choice == 'E' || choice == 'e')
            {
                encrypt(file, key);
            }
            else if(choice == 'D' || choice == 'd')
            {
                decrypt(file, key);
            }
            else
            {
                printf("Invalid choice\n");
            }
            fclose(file);
        }
    }
    while(1);
    return 0;
}