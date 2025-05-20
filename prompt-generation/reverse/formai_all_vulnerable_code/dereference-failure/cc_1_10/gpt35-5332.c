//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
/* Welcome to Image Steganography puzzle game! */
/* This program encodes a message inside a chosen image in a cryptic way */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to convert string to binary */
char* convertToBinary(char* msg){
    int len = strlen(msg);
    char* binaryMsg = (char*) malloc(len * 8 * sizeof(char));
    int i, j, k;
    for(i=0,j=0; i<len; i++,j+=8){
        for(k=7; k>=0; k--){
            *(binaryMsg+j+k) = (*(msg+i) & (1 << k)) ? '1' : '0';
        }
    }
    *(binaryMsg+j) = '\0';
    return binaryMsg;
}

/* Function to steganographically hide binary message in image */
void encodeMessage(unsigned char* image, char* binaryMsg){
    int i, j, k, count=0;
    for(i=0; i<256; i++){
        for(j=0; j<256; j++){
            for(k=0; k<3; k++){
                /* bit 0  => least significant bit (rightmost) */
                /* bit 7  => most significant bit (leftmost)  */
                if(count < strlen(binaryMsg)){
                    if(*(binaryMsg+count) == '0' && (*(image+i*256*3+j*3+k) & 1) != 0){
                        *(image+i*256*3+j*3+k) -= 1;
                    }
                    else if(*(binaryMsg+count) == '1' && (*(image+i*256*3+j*3+k) & 1) != 1){
                        *(image+i*256*3+j*3+k) += 1;
                    }
                    count++;
                }
                else{
                    return; /* message encoding complete */
                }
            }
        }
    }
}

int main(){
    char message[256];
    unsigned char image[256*256*3];
    printf("Enter a message to hide in the image: ");
    scanf("%[^\n]s", message);
    FILE *fp;
    fp = fopen("image.bmp", "rb");
    if(fp == NULL){
        printf("File not found!");
        return 0;
    }
    fread(image, sizeof(unsigned char), 256*256*3, fp);
    fclose(fp);
    char* binaryMsg = convertToBinary(message);
    encodeMessage(image, binaryMsg);
    fp = fopen("hidden-image.bmp", "wb");
    fwrite(image, sizeof(unsigned char), 256*256*3, fp);
    fclose(fp);
    printf("Message encoded in image successfully!");
    free(binaryMsg);
    return 0;
}