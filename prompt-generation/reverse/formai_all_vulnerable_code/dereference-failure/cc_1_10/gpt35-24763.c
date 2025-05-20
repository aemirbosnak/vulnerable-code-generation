//FormAI DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char* filename)
{
    FILE* file = fopen(filename, "rb");
    if(file == NULL) 
    {
        printf("Error opening file.\n");
        exit(1);
    }
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    char* buffer = (char*) malloc (file_size + 1);
    fread(buffer, file_size, 1, file);
    fclose(file);
    for(int i = 0; i < file_size; i++) 
    {
        buffer[i] ^= 0x5A;
    }
    FILE* encrypted_file = fopen(strcat(filename, ".enc"), "wb");
    if(encrypted_file == NULL) 
    {
        printf("Error opening encrypted file.\n");
        exit(1);
    }
    fwrite(buffer, file_size, 1, encrypted_file);
    fclose(encrypted_file);
    free(buffer);
}

void decrypt(char* filename)
{
    FILE* encrypted_file = fopen(filename, "rb");
    if(encrypted_file == NULL) 
    {
        printf("Error opening file.\n");
        exit(1);
    }
    fseek(encrypted_file, 0, SEEK_END);
    long file_size = ftell(encrypted_file);
    rewind(encrypted_file);
    char* buffer = (char*) malloc (file_size + 1);
    fread(buffer, file_size, 1, encrypted_file);
    fclose(encrypted_file);
    for(int i = 0; i < file_size; i++) 
    {
        buffer[i] ^= 0x5A;
    }
    filename[strlen(filename)-4] = '\0';
    FILE* decrypted_file = fopen(filename, "wb");
    if(decrypted_file == NULL) 
    {
        printf("Error opening decrypted file.\n");
        exit(1);
    }
    fwrite(buffer, file_size, 1, decrypted_file);
    fclose(decrypted_file);
    free(buffer);
}

int main(int argc, char* argv[]) 
{
    if(argc < 2) 
    {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    char* filename = argv[1];
    printf("Encrypting file %s...\n", filename);
    encrypt(filename);
    printf("File encrypted.\n");
    printf("Decrypting file %s.enc...\n", filename);
    decrypt(strcat(filename, ".enc"));
    printf("File decrypted.\n");
    return 0;
}