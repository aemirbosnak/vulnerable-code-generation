//FormAI DATASET v1.0 Category: File Encyptor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define ENCRYPTION_KEY 0xAA

void encryptFile(char* filename);

int main(int argc, char** argv) {
    char filename[MAX_FILENAME_LENGTH];
    
    printf("Enter the filename to be encrypted: ");
    scanf("%s", filename);
    
    encryptFile(filename);
    
    printf("File encrypted successfully!\n");
    
    return 0;
}

void encryptFile(char* filename) {
    FILE* fp;
    fp = fopen(filename, "rb+");
    
    if(fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    long int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char* buffer = (char*) malloc(file_size);
    
    if(buffer == NULL) {
        printf("Error allocating memory for file buffer\n");
        exit(1);
    }
    
    fread(buffer, file_size, 1, fp);
    
    for(int i = 0; i < file_size; i++) {
        buffer[i] ^= ENCRYPTION_KEY;
    }
    
    fseek(fp, 0, SEEK_SET);
    
    fwrite(buffer, file_size, 1, fp);
    
    free(buffer);
    fclose(fp);
}