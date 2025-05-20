//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include<stdio.h>
#include<stdlib.h>

void bitsToChar(unsigned char* buffer, unsigned char* byte, int size){
    int i;
    for(i = 0; i < size; i++){
        unsigned char bit = buffer[i]%2;
        byte[i/8] |= bit << (i%8);
    }
}

void charToBits(unsigned char* buffer, unsigned char* byte, int size){
    int i;
    for(i = 0; i < size; i++){
        buffer[i] = (byte[i/8] >> (i%8)) & 1;
    }
}

void hideBytes(unsigned char* message, int size, unsigned char* image, int imageSize){
    int i;
    for(i = 0; i < size; i++){
        unsigned char* byte = (unsigned char*) malloc(8 * sizeof(unsigned char));
        int j;
        for(j = 0; j < 8; j++){
            byte[j] = (message[i] >> j) & 1;
        }
        int index = i*8;
        if(index + 8 > imageSize*3){
            break;
        }
        bitsToChar(byte, &image[index/3], 8);
        free(byte);
    }
}

void unhideBytes(unsigned char* message, int size, unsigned char* image, int imageSize){
    int i;
    for(i = 0; i < size; i++){
        unsigned char* byte = (unsigned char*) malloc(8 * sizeof(unsigned char));
        int index = i*8;
        if(index + 8 > imageSize*3){
            break;
        }
        charToBits(byte, &image[index/3], 8);
        message[i] = 0;
        int j;
        for(j = 0; j < 8; j++){
            message[i] |= byte[j] << j;
        }
        free(byte);
    }
}

int main(){
    FILE* imageFile = fopen("Original_Image.bmp", "rb");
    if(imageFile == NULL){
        printf("Error opening image file");
        return -1;
    }
    fseek(imageFile, 0, SEEK_END);
    int imageSize = ftell(imageFile)-54;
    rewind(imageFile);
    unsigned char* image = (unsigned char*) malloc(imageSize * sizeof(unsigned char));
    fread(&image[0], sizeof(unsigned char), 54, imageFile);
    fread(&image[54], sizeof(unsigned char), imageSize, imageFile);
    fclose(imageFile);

    FILE* messageFile = fopen("Secret_Message.txt", "r");
    if (messageFile == NULL){
        printf("Error opening message file");
        return -1;
    }
    fseek(messageFile, 0, SEEK_END);
    int messageSize = ftell(messageFile);
    rewind(messageFile);
    unsigned char* message = (unsigned char*)malloc(messageSize * sizeof(unsigned char));
    fread(message, sizeof(unsigned char), messageSize, messageFile);
    fclose(messageFile);

    hideBytes(message, messageSize, image, imageSize);
    printf("Message hidden successfully!\n");

    FILE* outputImageFile = fopen("Steganographed_Image.bmp", "wb");
    if(imageFile == NULL){
        printf("Error opening output image file for writing");
        return -1;
    }
    fwrite(image, sizeof(unsigned char), 54+imageSize, outputImageFile);
    fclose(outputImageFile);
    printf("Steganographed image file created!\n");

    imageFile = fopen("Steganographed_Image.bmp", "rb");
    if(imageFile == NULL){
        printf("Error opening steganographed image file");
        return -1;
    }
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile)-54;
    rewind(imageFile);
    image = (unsigned char*) malloc(imageSize * sizeof(unsigned char));
    fread(&image[0], sizeof(unsigned char), 54, imageFile);
    fread(&image[54], sizeof(unsigned char), imageSize, imageFile);
    fclose(imageFile);

    unsigned char* recoveredMessage = (unsigned char*)malloc(messageSize*sizeof(unsigned char));
    unhideBytes(recoveredMessage, messageSize, image, imageSize);
    printf("Recovered message: %s\n", recoveredMessage);

    free(image);
    free(message);
    free(recoveredMessage);

    return 0;
}