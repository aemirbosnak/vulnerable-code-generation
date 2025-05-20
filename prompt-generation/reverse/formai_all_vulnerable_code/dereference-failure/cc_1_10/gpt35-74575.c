//FormAI DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void encode(char* message, char* filename){
    FILE* fp = fopen(filename, "r+b");

    if (fp == NULL){
        printf("Error: Failed to open file \n");
        return;
    }

    int messageLength = strlen(message);

    // Write message length to file
    fwrite(&messageLength, sizeof(int), 1, fp);

    // Encode each character of the message
    for (int i = 0; i < messageLength; i++){
        // Read current pixel
        pixel p;
        fread(&p, sizeof(pixel), 1, fp);

        // Encode character as LSB of each color channel
        p.red = (p.red & 0xFE) | ((message[i] >> 7) & 0x01);
        p.green = (p.green & 0xFE) | ((message[i] >> 6) & 0x01);
        p.blue = (p.blue & 0xFE) | ((message[i] >> 5) & 0x01);

        // Write modified pixel to file
        fseek(fp, -sizeof(pixel), SEEK_CUR);
        fwrite(&p, sizeof(pixel), 1, fp);
    }

    fclose(fp);
    return;
}

char* decode(char* filename){
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL){
        printf("Error: Failed to open file \n");
        return NULL;
    }

    int messageLength = 0;
    fread(&messageLength, sizeof(int), 1, fp);

    char* message = (char*) malloc(sizeof(char) * (messageLength + 1));
    message[messageLength] = '\0';

    // Decode each character of the message
    for (int i = 0; i < messageLength; i++){
        // Read current pixel
        pixel p;
        fread(&p, sizeof(pixel), 1, fp);

        // Extract LSB of each color channel as character
        message[i] = ((p.red & 0x01) << 7) | ((p.green & 0x01) << 6) | ((p.blue & 0x01) << 5);
    }

    fclose(fp);
    return message;
}

int main(){
    char message[100] = "Romeo, Romeo, wherefore art thou Romeo?";
    char filename[100] = "image.bmp";

    // Encode message into image
    encode(message, filename);

    // Decode message from image
    char* decodedMessage = decode(filename);

    printf("%s\n", decodedMessage);

    free(decodedMessage);

    return 0;
}