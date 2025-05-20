//FormAI DATASET v1.0 Category: File Encyptor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

char* encrypt(char* content, int key)
{
    int i, len = strlen(content);
    char* encrypted = malloc(sizeof(char) * len);
    
    for(i = 0; i < len; i++)
    {
        encrypted[i] = content[i] + key;
    }
    
    return encrypted;
}

char* decrypt(char* content, int key)
{
    int i, len = strlen(content);
    char* decrypted = malloc(sizeof(char) * len);
    
    for(i = 0; i < len; i++)
    {
        decrypted[i] = content[i] - key;
    }
    
    return decrypted;
}

void writeToFile(char* fileName, char* content)
{
    FILE* fp = fopen(fileName, "w");
    fprintf(fp, "%s", content);
    fclose(fp);
}

char* readFromFile(char* fileName)
{
    FILE* fp;
    char* content;
    long fileSize;
    
    fp = fopen(fileName, "r");
    fseek(fp, 0, SEEK_END);
    fileSize = ftell(fp);
    rewind(fp);
    
    content = malloc(sizeof(char) * (fileSize + 1));
    fread(content, sizeof(char), fileSize, fp);

    fclose(fp);
    content[fileSize] = '\0';
    
    return content;
}

void encryptFile(char* fileName, int key)
{
    char* fileContents = readFromFile(fileName);
    char* encrypted = encrypt(fileContents, key);
    writeToFile(fileName, encrypted);
    free(encrypted);
    free(fileContents);
}

void decryptFile(char* fileName, int key)
{
    char* fileContents = readFromFile(fileName);
    char* decrypted = decrypt(fileContents, key);
    writeToFile(fileName, decrypted);
    free(decrypted);
    free(fileContents);
}

int main(int argc, char** argv)
{
    if(argc != 4)
    {
        fprintf(stderr, "Usage: ./encryptor [file] [key] [mode(decrypt/encrypt)]\n");
        exit(1);
    }
    
    char* fileName = argv[1];
    int key = atoi(argv[2]);
    char* mode = argv[3];
    
    if(strcmp(mode, "encrypt") == 0)
    {
        encryptFile(fileName, key);
        printf("File Encrypted successfully\n");
    }
    else if(strcmp(mode, "decrypt") == 0)
    {
        decryptFile(fileName, key);
        printf("File Decrypted successfully\n");
    }
    else
    {
        fprintf(stderr, "Invalid mode selected. Select either encrypt/decrypt\n");
        exit(1);
    }
    
    return 0;
}