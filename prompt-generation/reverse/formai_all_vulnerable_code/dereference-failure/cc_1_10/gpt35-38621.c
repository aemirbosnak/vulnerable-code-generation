//FormAI DATASET v1.0 Category: File Encyptor ; Style: modular
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//function to encrypt the file
void fileEncrypt(char *fileName, char *key) {
    FILE *fileptr1, *fileptr2;
    char *buffer;
    int fileSize;

    //open the file
    fileptr1 = fopen(fileName, "rb");
    if (fileptr1 == NULL) {
        printf("Error opening the file\n");
        return;
    }

    //find the size of the file
    fseek(fileptr1, 0, SEEK_END);           
    fileSize = ftell(fileptr1);              
    rewind(fileptr1);

    //allocate memory for the buffer    
    buffer = (char*)malloc((fileSize+1)*sizeof(char));  
    fread(buffer, fileSize, 1, fileptr1);  
    fclose(fileptr1);

    //encrypt the file by XOR with key
    for(int i=0;i<fileSize;i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    //open the file to write the encrypted data
    fileptr2 = fopen(strcat(fileName, ".enc"), "wb");   
    fwrite(buffer, fileSize, 1, fileptr2);
    fclose(fileptr2);

    free(buffer);
    printf("File Encrypted Successfully!\n");
}

//function to decrypt the file
void fileDecrypt(char *fileName, char *key) {
    FILE *fileptr1, *fileptr2;
    char *buffer;
    int fileSize;

    //open the file
    fileptr1 = fopen(fileName, "rb");     
    if (fileptr1 == NULL) {
        printf("Error opening the file\n");
        return;
    }

    //find the size of the file
    fseek(fileptr1, 0, SEEK_END);           
    fileSize = ftell(fileptr1);              
    rewind(fileptr1);

    //allocate memory for the buffer    
    buffer = (char*)malloc((fileSize+1)*sizeof(char));  
    fread(buffer, fileSize, 1, fileptr1);  
    fclose(fileptr1);

    //decrypt the file by XOR with key
    for(int i=0;i<fileSize;i++) {
        buffer[i] ^= key[i % strlen(key)];
    }

    //open the file to write the decrypted data
    fileName[strlen(fileName)-4] = '\0'; //remove the ".enc" extension
    fileptr2 = fopen(fileName, "wb");      
    fwrite(buffer, fileSize, 1, fileptr2);
    fclose(fileptr2);

    free(buffer);
    printf("File Decrypted Successfully!\n");
}

//main function
int main() {
    char fileName[50], key[50];
    int choice;

    do {
        printf("\n=============================");
        printf("\n     FILE ENCRYPTOR MENU     ");
        printf("\n=============================");
        printf("\n1. Encrypt file");
        printf("\n2. Decrypt file");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: printf("\nEnter the name of file to encrypt (with extension): ");
                    scanf("%s", fileName);
                    printf("Enter the encryption key: ");
                    scanf("%s", key);
                    fileEncrypt(fileName, key);
                    break;

            case 2: printf("\nEnter the name of file to decrypt (with extension): ");
                    scanf("%s", fileName);
                    printf("Enter the decryption key: ");
                    scanf("%s", key);
                    fileDecrypt(fileName, key);
                    break;

            case 3: printf("\nExiting...");
                    break;

            default: printf("\nInvalid choice. Try again.");
        }   
    } while (choice != 3);

    return 0;
}