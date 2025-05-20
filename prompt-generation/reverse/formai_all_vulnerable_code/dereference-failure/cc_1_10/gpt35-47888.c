//FormAI DATASET v1.0 Category: Image Steganography ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

void hideMessage(char*, char*);
void decodeMessage(char*);

int main() {
    printf("Welcome to the steganography program!\n");
    printf("Please enter the name of the image file you wish to hide a message in: ");
    
    char fileName[100];
    scanf("%s", fileName);
    
    printf("Please enter your message: ");
    
    char message[1000];
    scanf(" %[^\n]", message);
    
    hideMessage(fileName, message);
    
    printf("Message successfully hidden in %s!\n\n", fileName);
    
    printf("Now, let's decode the message from the image.\n");
    printf("Please enter the name of the image file you wish to decode: ");
    
    char encodedFileName[100];
    scanf("%s", encodedFileName);
    
    decodeMessage(encodedFileName);
    
    return 0;
}

void hideMessage(char* fileName, char* message) {
    FILE* filePtr = fopen(fileName, "rb");
    if(filePtr == NULL) {
        printf("Error: Could not open image file");
        exit(1);
    }
    
    fseek(filePtr, 0, SEEK_END);
    int fileSize = ftell(filePtr);
    rewind(filePtr);
    
    char* imageData = (char*)malloc(sizeof(char)*fileSize);
    
    fread(imageData, sizeof(char), fileSize, filePtr);
    fclose(filePtr);
    
    int i, j;
    int size = 8*sizeof(char)*sizeof(char);
    
    for(i=0; message[i] != '\0'; i++) {
        for(j=0; j<size && message[i] != '\0'; j++) {
            char bit = (message[i] >> j) & 1;
            imageData[i] = (imageData[i] & ~1) | bit;
        }
    }
    
    FILE* newFilePtr = fopen("encodedImage.bin", "wb");
    fwrite(imageData, sizeof(char), fileSize, newFilePtr);
    fclose(newFilePtr);
    free(imageData);
}

void decodeMessage(char* fileName) {
    FILE* filePtr = fopen(fileName, "rb");
    if(filePtr == NULL) {
        printf("Error: Could not open encoded image file");
        exit(1);
    }
    
    fseek(filePtr, 0, SEEK_END);
    int fileSize = ftell(filePtr);
    rewind(filePtr);
    
    char* imageData = (char*)malloc(sizeof(char)*fileSize);
    
    fread(imageData, sizeof(char), fileSize, filePtr);
    fclose(filePtr);
    
    int i, j;
    char message[1000] = {0};
    int k=0;
    
    for(i=0; i<fileSize; i++) {
        for(j=0; j<8; j++) {
            char bit = (imageData[i] >> j) & 1;
            message[k] = (message[k] & ~(1<<j)) | (bit << j);
            if(k>0 && message[k] == '\0')
                break;
        }
        if(k>0 && message[k] == '\0')
            break;
        k++;
    }
    
    printf("The decoded message is: %s\n", message);
    free(imageData);
}