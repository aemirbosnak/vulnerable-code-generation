//FormAI DATASET v1.0 Category: File Encyptor ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* This program demonstrates a simple example of file encryption using XOR encryption method */

#define BUFFER_SIZE 100

int main(int argc, char* argv[]){

    if(argc < 3){
        printf("Error: Insufficient arguments. Usage: inputFile outputFile\n");
        return -1;
    }

    FILE *inFile, *outFile;
    inFile = fopen(argv[1], "r");
    if(inFile == NULL){
        printf("Error: Cannot open input file.\n");
        return -1;
    }

    outFile = fopen(argv[2], "w");
    if(outFile == NULL){
        printf("Error: Cannot create output file.\n");
        return -1;
    }

    int key; // Encryption key
    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    // Read the contents of input file and xor each character with the key and write to output file
    char buffer[BUFFER_SIZE];
    char encrypted[BUFFER_SIZE];
    size_t bytesRead;

    while((bytesRead = fread(buffer, 1, BUFFER_SIZE, inFile)) > 0){
        for(int i = 0; i < bytesRead; i++){
            encrypted[i] = buffer[i] ^ key; // Perform XOR operation
        }
        fwrite(encrypted, 1, bytesRead, outFile); // Write to output file
    }

    // Close both files
    fclose(inFile);
    fclose(outFile);

    printf("Encryption successful!\n");

    return 0;
}