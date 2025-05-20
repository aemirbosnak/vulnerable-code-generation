//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_MESSAGE_SIZE 2000
#define MAX_FILE_NAME_SIZE 1000
#define HEADER_SIZE 54

typedef unsigned char BYTE;

// function prototypes
int readMessage(char* message, int maxSize);
int readFile(BYTE** fileData, int* fileSize, char* fileName);
int writeFile(BYTE* fileData, int fileSize, char* fileName);
void hideMessage(BYTE* imageData, int imageSize, char* message, int maxSize);
void extractMessage(BYTE* imageData, int imageSize, char* message, int maxSize);

int main(){

    // get message from user
    char message[MAX_MESSAGE_SIZE];
    int messageSize = readMessage(message, MAX_MESSAGE_SIZE);
    
    // get image data from user
    BYTE* imageData;
    int imageSize;
    char fileName[MAX_FILE_NAME_SIZE];
    printf("Enter name of image file to hide message in: ");
    scanf("%s", fileName);
    int fileResult = readFile(&imageData, &imageSize, fileName);
    if(fileResult == -1){
        printf("Error: File does not exist or could not be opened.\n");
        return 1;
    }
    
    // hide message in image data
    hideMessage(imageData, imageSize, message, messageSize);
    
    // write new image data with hidden message to file
    int writeResult = writeFile(imageData, imageSize, "output.bmp");
    if(writeResult == -1){
        printf("Error: Could not write new image data to file.\n");
        return 1;
    }
    printf("Message hidden successfully!\n");
    
    // free allocated memory
    free(imageData);
    
    // extract message from image data
    BYTE* extractedData;
    int extractedSize;
    fileResult = readFile(&extractedData, &extractedSize, "output.bmp");
    if(fileResult == -1){
        printf("Error: Could not open file to extract message.\n");
        return 1;
    }
    char extractedMessage[MAX_MESSAGE_SIZE];
    extractMessage(extractedData, extractedSize, extractedMessage, MAX_MESSAGE_SIZE);
    printf("Extracted message: %s\n", extractedMessage);
    free(extractedData);
    
    return 0;
}

int readMessage(char* message, int maxSize){
    printf("Enter message to hide (max %d characters):\n", maxSize);
    getchar();
    fgets(message, maxSize, stdin);
    int i;
    for(i = 0; message[i] != '\n' && i < maxSize; i++);
    message[i] = '\0';
    return i;
}

int readFile(BYTE** fileData, int* fileSize, char* fileName){
    FILE* file = fopen(fileName, "rb");
    if(!file){
        return -1;
    }
    fseek(file, 0, SEEK_END);
    *fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    *fileData = (BYTE*) malloc(*fileSize * sizeof(BYTE));
    fread(*fileData, sizeof(BYTE), *fileSize, file);
    fclose(file);
    return 0;
}

int writeFile(BYTE* fileData, int fileSize, char* fileName){
    FILE* file = fopen(fileName, "wb");
    if(!file){
        return -1;
    }
    fwrite(fileData, sizeof(BYTE), fileSize, file);
    fclose(file);
    return 0;
}

void hideMessage(BYTE* imageData, int imageSize, char* message, int maxSize){
    int i, j, index = 0;
    for(i = HEADER_SIZE; i < imageSize && index < maxSize; i += 3){
        for(j = 0; j < 3 && index < maxSize; j++){
            imageData[i + j] = (imageData[i + j] & 0xFC) | ((message[index] >> 6) & 0x03);
            imageData[i + j] = (imageData[i + j] & 0xF8) | ((message[index] >> 3) & 0x07);
            imageData[i + j] = (imageData[i + j] & 0xF8) | (message[index] & 0x07);
            index++;
        }
    }
    imageData[HEADER_SIZE - 1] |= 0x03; // set LSB to 11 to signal message hidden
}

void extractMessage(BYTE* imageData, int imageSize, char* message, int maxSize){
    int i, j, index = 0;
    for(i = HEADER_SIZE; i < imageSize; i += 3){
        char letter = 0;
        for(j = 0; j < 3 && index < maxSize; j++, index++){
            letter |= ((imageData[i + j] & 0x03) << 6);
            letter |= ((imageData[i + j] & 0x07) << 3);
            letter |= (imageData[i + j] & 0x07);
        }
        if(letter == '\0'){ // check if end of message
            break;
        }
        message[index] = letter;
    }
    message[index] = '\0'; // null-terminate string
}