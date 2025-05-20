//FormAI DATASET v1.0 Category: Image Steganography ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//cyberpunk-style image steganography
//based on LSB (Least Significant Bit) algorithm

typedef struct Image{
    int height;
    int width;
    char *pixels;
} Image;

void encode(Image *image, char *message){
    int message_length = strlen(message);

    //checking message can fit in the image
    if(message_length * 8 > image->height * image->width){
        printf("Error: message is too long for this image.\n");
        return;
    }

    //iterating through message and encoding each bit in the image pixels
    for(int i=0; i<message_length; i++){
        char byte = message[i];
        for(int j=0; j<8; j++){
            int bit = (byte >> j) & 1;
            int pixel_index = i * 8 + j;
            image->pixels[pixel_index] = (image->pixels[pixel_index] & 0xFE) | bit;
        }
    }

    //adding null terminator to end of message
    for(int i=message_length*8; i<(image->height * image->width); i++){
        int pixel_index = i;
        image->pixels[pixel_index] = (image->pixels[pixel_index] & 0xFE) | 0;
    }

    printf("Message encoded successfully!\n");
}

void decode(Image *image){
    int message_length = image->height * image->width / 8;

    //checking if message length is valid
    if((image->pixels[(message_length-1)*8+7] & 1) == 0){
        printf("Error: image does not contain a valid encoded message.\n");
        return;
    }

    char *message = malloc(message_length+1); //allocating memory for message
    int byte_index = 0;

    //iterating through each byte in message and decoding it from the image pixels
    for(int i=0; i<message_length*8; i+=8){
        char byte = 0;
        for(int j=0; j<8; j++){
            int bit = image->pixels[i+j] & 1;
            byte |= bit << j;
        }
        message[byte_index++] = byte;
    }
    message[byte_index] = '\0';

    printf("Decoded message: %s\n", message);
}

int main(){
    Image image;
    image.height = 10;
    image.width = 10;
    image.pixels = malloc(image.height * image.width);

    //setting all pixels to black (0)
    for(int i=0; i<image.height * image.width; i++){
        image.pixels[i] = 0;
    }

    char message[] = "The revolution will not be televised.";

    encode(&image, message);

    decode(&image);

    free(image.pixels);
    return 0;
}