//FormAI DATASET v1.0 Category: File Encyptor ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 10000

void encryptFile(char *inputFilename, char *outputFilename, char *key);
void decryptFile(char *inputFilename, char *outputFilename, char *key);
char* generateKey();

int main(){
    char inputFilename[MAX_FILENAME_LENGTH];
    char outputFilename[MAX_FILENAME_LENGTH];
    char key[9];

    printf("Enter name of file to encrypt: ");
    scanf("%s", inputFilename);

    printf("Enter name of output file: ");
    scanf("%s", outputFilename);

    printf("Enter key (must be 8 characters): ");
    scanf("%s", key);

    encryptFile(inputFilename, outputFilename, key);

    printf("%s has been encrypted.\n", inputFilename);
    printf("Encrypted data written to %s.\n", outputFilename);

    strcpy(inputFilename, outputFilename);
    strcpy(outputFilename, "decrypted.dat");

    decryptFile(inputFilename, outputFilename, key);

    printf("%s has been decrypted.\n", inputFilename);
    printf("Decrypted data written to %s.\n", outputFilename);

    return 0;
}

void encryptFile(char *inputFilename, char *outputFilename, char *key){
    FILE *inputFile, *outputFile;
    char *inputData, *outputData;
    int keyIndex = 0;
    int inputSize, outputSize;
    int i;

    inputFile = fopen(inputFilename, "rb");
    if(inputFile == NULL){
        printf("Error: unable to open file %s.\n", inputFilename);
        exit(1);
    }

    fseek(inputFile, 0, SEEK_END);
    inputSize = ftell(inputFile);
    fseek(inputFile, 0, SEEK_SET);

    inputData = (char*) malloc(inputSize + 1);
    fread(inputData, 1, inputSize, inputFile);

    fclose(inputFile);

    inputData[inputSize] = '\0';

    outputSize = inputSize;

    outputData = (char*) malloc(outputSize + 1);

    for(i = 0; i < inputSize; i++){
        outputData[i] = inputData[i] ^ key[keyIndex];
        keyIndex = (keyIndex + 1) % 8;
    }

    outputData[outputSize] = '\0';

    outputFile = fopen(outputFilename, "wb");
    if(outputFile == NULL){
        printf("Error: unable to create file %s.\n", outputFilename);
        exit(1);
    }

    fwrite(outputData, 1, outputSize, outputFile);

    fclose(outputFile);

    free(inputData);
    free(outputData);
}

void decryptFile(char *inputFilename, char *outputFilename, char *key){
    encryptFile(inputFilename, outputFilename, key);
}

char* generateKey(){
    char *key = (char*) malloc(9);
    int i;

    for(i = 0; i < 8; i++){
        key[i] = 'a' + rand() % 26;
    }

    key[8] = '\0';

    return key;
}