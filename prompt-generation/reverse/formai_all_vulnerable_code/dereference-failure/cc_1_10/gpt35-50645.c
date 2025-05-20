//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

//Function to hide the message into the image
void hideMessage(unsigned char *image, int imageSize, unsigned char *msg, int msgSize) {
    int i, j, k = 0;

    for(i=0; i<imageSize; i+=3) {
        if(k < msgSize) {
            for(j=0; j<3 && k<msgSize; j++, k++) {
                //masking the message in the least significant bit of the image colors
                image[i+j] = (image[i+j] & 0xFE) | ((msg[k]>>7) & 0x01);
                image[i+j] = (image[i+j] & 0xFD) | ((msg[k]>>6) & 0x01);
                image[i+j] = (image[i+j] & 0xFB) | ((msg[k]>>5) & 0x01);
                image[i+j] = (image[i+j] & 0xF7) | ((msg[k]>>4) & 0x01);
                image[i+j] = (image[i+j] & 0xEF) | ((msg[k]>>3) & 0x01);
                image[i+j] = (image[i+j] & 0xDF) | ((msg[k]>>2) & 0x01);
                image[i+j] = (image[i+j] & 0xBF) | ((msg[k]>>1) & 0x01);
                image[i+j] = (image[i+j] & 0x7F) | ((msg[k]>>0) & 0x01);
            }
        }
    }
}

//Function to retrieve the hidden message from the image
void retrieveMessage(unsigned char *image, int imageSize, unsigned char *msg, int msgSize) {
    int i, j, k = 0;

    for(i=0; i<imageSize; i+=3) {
        if(k < msgSize) {
            msg[k] = (image[i+0] & 0x01)<<7 | (image[i+1] & 0x01)<<6 |
                     (image[i+2] & 0x01)<<5 | (image[i+3] & 0x01)<<4 |
                     (image[i+4] & 0x01)<<3 | (image[i+5] & 0x01)<<2 |
                     (image[i+6] & 0x01)<<1 | (image[i+7] & 0x01)<<0;
            k++;
        }
    }
}

int main() {
    FILE *fp;
    unsigned char *image, *msg;
    int imageSize, msgSize;

    //Reads the image file into memory
    fp = fopen("image.png", "rb");
    fseek(fp, 0L, SEEK_END);
    imageSize = ftell(fp);
    rewind(fp);
    image = (unsigned char*)malloc(imageSize);
    fread(image, 1, imageSize, fp);
    fclose(fp);

    //Reads the message file into memory
    fp = fopen("message.txt", "rb");
    fseek(fp, 0L, SEEK_END);
    msgSize = ftell(fp);
    rewind(fp);
    msg = (unsigned char*)malloc(msgSize);
    fread(msg, 1, msgSize, fp);
    fclose(fp);

    //Hides the message in the image
    hideMessage(image, imageSize, msg, msgSize);

    //Saves the steganography image
    fp = fopen("stego.png", "wb");
    fwrite(image, 1, imageSize, fp);
    fclose(fp);

    //Clears the memory used for the image and message
    free(image);
    free(msg);

    //Re-reads the steganography image into memory
    fp = fopen("stego.png", "rb");
    fseek(fp, 0L, SEEK_END);
    imageSize = ftell(fp);
    rewind(fp);
    image = (unsigned char*)malloc(imageSize);
    fread(image, 1, imageSize, fp);
    fclose(fp);

    //Retrieves the message from the steganography image
    msg = (unsigned char*)malloc(msgSize);
    retrieveMessage(image, imageSize, msg, msgSize);

    //Prints the retrieved message
    printf("Retrieved Message: %s\n", msg);

    //Clears the memory used for the steganography image and message
    free(image);
    free(msg);

    return 0;
}