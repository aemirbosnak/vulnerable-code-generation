//FormAI DATASET v1.0 Category: File Encyptor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to encrypt file
void encrypt(char *fileName)
{
    FILE *file = fopen(fileName, "r+");
    char buffer[100];
    
    while(fgets(buffer, 100, file)) //Reading each line from file
    {
        int length = strlen(buffer);
        for(int i=0; i<length; i++) //Encrypting each character of the line
        {
            buffer[i] += 5;
        }
        fseek(file, -length, SEEK_CUR); //Going back to the start of the line
        fputs(buffer, file); //Writing the encrypted line to file
        fflush(file); //Flush the file stream to save the changes
    }
    fclose(file); //Close the file
}

//Function to decrypt file
void decrypt(char *fileName)
{
    FILE *file = fopen(fileName, "r+");
    char buffer[100];
    
    while(fgets(buffer, 100, file)) //Reading each line from file
    {
        int length = strlen(buffer);
        for(int i=0; i<length; i++) //Decrypting each character of the line
        {
            buffer[i] -= 5;
        }
        fseek(file, -length, SEEK_CUR); //Going back to the start of the line
        fputs(buffer, file); //Writing the decrypted line to file
        fflush(file); //Flush the file stream to save the changes
    }
    fclose(file); //Close the file
}

int main()
{
    char fileName[100];
    int option;
    
    printf("Enter file name: ");
    scanf("%s", fileName);
    
    printf("1. Encrypt\n2. Decrypt\n");
    printf("Enter your option: ");
    scanf("%d", &option);
    
    switch(option)
    {
        case 1:
            encrypt(fileName);
            printf("File encrypted successfully!\n");
            break;
        case 2:
            decrypt(fileName);
            printf("File decrypted successfully!\n");
            break;
        default:
            printf("Invalid option selected!\n");
            break;
    }
    
    return 0;
}