//FormAI DATASET v1.0 Category: File Encyptor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

void encryptFile(FILE* inputFile, FILE* outputFile, char* key){
    unsigned char buffer[BUF_SIZE];
    int keyIndex = 0;
    int bytesRead = 0;
    int keyLength = strlen(key);

    while( (bytesRead = fread(buffer, 1, BUF_SIZE, inputFile)) != 0){
        for(int i = 0; i < bytesRead; i++){

            buffer[i] ^= key[keyIndex];
            keyIndex++;
            if(keyIndex == keyLength){
                keyIndex = 0;
            }

        }
        fwrite(buffer, 1, bytesRead, outputFile);
    }

}

void decryptFile(FILE* inputFile, FILE* outputFile, char* key){
    encryptFile(inputFile, outputFile, key);
}

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage: %s <encode/decode> <input_file> <output_file>\n", argv[0]);
        exit(EXIT_FAILURE);     
    }

    FILE* inputFile = fopen(argv[2], "rb");
    if(inputFile == NULL){
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }

    FILE* outputFile = fopen(argv[3], "wb");
    if(outputFile == NULL){
        printf("Error opening output file.\n");
        exit(EXIT_FAILURE);
    }

    char* key = "my_secret_key"; // feel free to change this
    if(strcmp(argv[1], "encode") == 0){
        encryptFile(inputFile, outputFile, key);
    } else if(strcmp(argv[1], "decode") == 0){
        decryptFile(inputFile, outputFile, key);
    } else {
        printf("Unknown command.\n");
        exit(EXIT_FAILURE);
    }

    printf("%s complete.\n", argv[1]);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}