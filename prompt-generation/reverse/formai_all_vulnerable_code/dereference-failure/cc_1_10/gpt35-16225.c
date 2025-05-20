//FormAI DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_KEY_LENGTH 32

void encryptFile(FILE* inputFile, FILE* outputFile, char* key) {
    char buffer;
    int keyLength = strlen(key);
    int i = 0;
    
    while(fread(&buffer, sizeof(buffer), 1, inputFile) == 1) {
        buffer ^= key[i++ % keyLength];
        fwrite(&buffer, sizeof(buffer), 1, outputFile);
    }
}

void decryptFile(FILE* inputFile, FILE* outputFile, char* key) {
    encryptFile(inputFile, outputFile, key);
}

int main() {
    char inputFilename[MAX_FILENAME_LENGTH];
    char outputFilename[MAX_FILENAME_LENGTH];
    char key[MAX_KEY_LENGTH];
    int mode;
    
    printf("Enter the name of the input file: ");
    scanf("%s", inputFilename);
    
    FILE* inputFile = fopen(inputFilename, "rb");
    if(inputFile == NULL) {
        printf("Error: Cannot open file '%s'\n", inputFilename);
        return 1;
    }
    
    printf("Enter the name of the output file: ");
    scanf("%s", outputFilename);
    
    FILE* outputFile = fopen(outputFilename, "wb");
    if(outputFile == NULL) {
        printf("Error: Cannot create file '%s'\n", outputFilename);
        return 1;
    }
    
    printf("Enter the encryption/decryption key: ");
    scanf("%s", key);
    
    printf("Enter mode (encrypt = 0, decrypt = 1): ");
    scanf("%d", &mode);
    
    if(mode == 0) {
        encryptFile(inputFile, outputFile, key);
        printf("Encryption complete.\n");
    } else {
        decryptFile(inputFile, outputFile, key);
        printf("Decryption complete.\n");
    }
    
    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}