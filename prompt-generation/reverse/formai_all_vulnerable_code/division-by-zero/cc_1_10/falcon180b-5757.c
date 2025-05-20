//Falcon-180B DATASET v1.0 Category: File Encyptor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

//Function to encrypt the file
void encrypt(char *filename, char *key)
{
    FILE *fp, *temp;
    char ch, ch_key, temp_name[20];
    int i, j;

    //Open the file in read mode
    fp = fopen(filename, "r");

    //Check if file exists
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        exit(0);
    }

    //Create a temporary file
    sprintf(temp_name, "temp_%s", filename);
    temp = fopen(temp_name, "w");

    //Loop through the file
    while ((ch = fgetc(fp))!= EOF)
    {
        //Encrypt the character
        ch_key = ch ^ key[i % strlen(key)];
        i++;
        fputc(ch_key, temp);
    }

    //Close the files
    fclose(fp);
    fclose(temp);

    //Remove the original file and rename the temporary file
    remove(filename);
    rename(temp_name, filename);
}

//Function to decrypt the file
void decrypt(char *filename, char *key)
{
    FILE *fp, *temp;
    char ch, ch_key, temp_name[20];
    int i, j;

    //Open the file in read mode
    fp = fopen(filename, "r");

    //Check if file exists
    if (fp == NULL)
    {
        printf("File does not exist!\n");
        exit(0);
    }

    //Create a temporary file
    sprintf(temp_name, "temp_%s", filename);
    temp = fopen(temp_name, "w");

    //Loop through the file
    while ((ch = fgetc(fp))!= EOF)
    {
        //Decrypt the character
        ch_key = ch ^ key[i % strlen(key)];
        i++;
        fputc(ch_key, temp);
    }

    //Close the files
    fclose(fp);
    fclose(temp);

    //Remove the original file and rename the temporary file
    remove(filename);
    rename(temp_name, filename);
}

//Function to generate a random key
void generate_key(char *key)
{
    int i;

    //Initialize the key with random characters
    for (i = 0; i < strlen(key); i++)
    {
        key[i] = rand() % 26 + 'a';
    }
}

int main()
{
    char filename[MAX_SIZE], key[MAX_SIZE];

    //Get the filename and key from the user
    printf("Enter the filename: ");
    scanf("%s", filename);
    printf("Enter the key: ");
    scanf("%s", key);

    //Encrypt the file
    encrypt(filename, key);

    //Decrypt the file
    decrypt(filename, key);

    return 0;
}