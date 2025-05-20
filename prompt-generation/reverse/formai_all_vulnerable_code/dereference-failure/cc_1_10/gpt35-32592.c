//FormAI DATASET v1.0 Category: Image Steganography ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Image {
    char* pixels;
    int width;
    int height;
};

void printImage(struct Image* img){
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            printf("%x ", img->pixels[i*img->width+j]);
        }
        printf("\n");
    }
}

void encode(struct Image* img, char* message){
    int msgLen = strlen(message)*8;
    int idx = 0;
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            char pixel = img->pixels[i*img->width+j];
            int bit = pixel < pow(2,7-idx%8) ? 0 : 1;
            int msgBit = (message[idx/8] & (1<<(idx%8))) > 0;
            if(bit == msgBit){
                continue;
            }else{
                if(bit == 0){
                    img->pixels[i*img->width+j] += pow(2,7-idx%8);
                }else{
                    img->pixels[i*img->width+j] -= pow(2,7-idx%8);
                }
            }
            idx++;
        }
        if(idx >= msgLen){
            return;
        }
    }
}

char* decode(struct Image* img, int msgLen){
    char* message = (char*)calloc(msgLen/8+1, sizeof(char));
    int idx = 0;
    for(int i=0; i<img->height; i++){
        for(int j=0; j<img->width; j++){
            char pixel = img->pixels[i*img->width+j];
            int bit = pixel < pow(2,7-idx%8) ? 0 : 1;
            message[idx/8] |= (bit << (idx%8));
            idx++;
            if(idx >= msgLen){
                return message;
            }
        }
    }
    return message;
}

int main(){
    char message[] = "Hello, world!";
    struct Image img = { (char*)calloc(12, sizeof(char)), 4, 3 };
    strncpy(img.pixels, "\xff\xff\xf0\x00\x00\xee\x00\xee\x00\x00\x00\x00", 12);
    printImage(&img);
    encode(&img, message);
    printImage(&img);
    char* decodedMessage = decode(&img, strlen(message)*8);
    printf("Decoded Message: %s\n", decodedMessage);
    free(decodedMessage);
    free(img.pixels);
}