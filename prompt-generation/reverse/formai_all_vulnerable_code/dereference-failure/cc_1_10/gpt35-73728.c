//FormAI DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define READ_MODE "rb"
#define WRITE_MODE "wb"

void printBits(unsigned char *buffer, int start, int end){
    for(int i=start; i<=end; i++){
        for(int j=7; j>=0; j--){
            printf("%d", (buffer[i] >> j) & 1);
        }
        printf(" ");
    }
    printf("\n");
}

int main(){
    char *image_name = "original_image.jpg";
    char *steg_image_name = "steg_image.jpg";
    char *secret_message = "Top Secret Message";        // secret message to hide within the image

    // open image file
    FILE *image_file = fopen(image_name, READ_MODE);
    if(image_file == NULL){
        printf("Error: Unable to open %s\n", image_name);
        return 0;
    }

    // get image size
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // allocate memory for image buffer
    unsigned char *image_buffer = malloc(image_size);
    fread(image_buffer, 1, image_size, image_file);
    fclose(image_file);

    // print original image buffer contents
    printf("Original Image Contents:\n");
    printBits(image_buffer, 0, 15);

    // open steg image file for writing
    FILE *steg_image_file = fopen(steg_image_name, WRITE_MODE);
    if(steg_image_file == NULL){
        printf("Error: Unable to open %s\n", steg_image_name);
        free(image_buffer);
        return 0;
    }

    // create secret message buffer
    int message_len = strlen(secret_message);
    unsigned char *message_buffer = malloc(message_len);
    memcpy(message_buffer, secret_message, message_len);

    // encrypt secret message
    for(int i=0; i<message_len; i++){
        message_buffer[i] = message_buffer[i] ^ i;
    }

    // calculate required bytes to store secret message within image
    int message_bits_len = message_len * 8;   // length of secret message in bits
    int required_bytes = message_bits_len / 7;    // 7 bits of secret message should be stored within 1 byte of image
    if(message_bits_len % 7 > 0){
        required_bytes++;
    }   

    // check if there is enough space within image to store secret message
    if(image_size < required_bytes){
        printf("Error: Not enough space within image to store secret message.\n");
        free(image_buffer);
        free(message_buffer);
        fclose(steg_image_file);
        return 0;
    }

    // create steg image buffer
    unsigned char *steg_image_buffer = malloc(image_size);

    // add encrypted secret message to steg image buffer
    int bit_index = 0;
    int byte_index = 0;
    for(int i=0; i<message_bits_len; i++){
        int bit = (message_buffer[byte_index] >> bit_index) & 1;
        steg_image_buffer[i] = (image_buffer[i] & ~1) | bit;      // set least significant bit of image pixel to secret message bit
        bit_index++;
        if(bit_index > 6){      // 7 bits of secret message should be stored within 1 byte of image
            bit_index = 0;
            byte_index++;
        }
    }

    // copy remaining image contents into steg image buffer
    for(int i=message_bits_len; i<image_size; i++){
        steg_image_buffer[i] = image_buffer[i];
    }

    // write steg image buffer contents into steg image file
    fwrite(steg_image_buffer, 1, image_size, steg_image_file);
    fclose(steg_image_file);

    // print steg image buffer contents
    printf("Steg Image Contents:\n");
    printBits(steg_image_buffer, 0, 15);

    // free memory
    free(image_buffer);
    free(message_buffer);
    free(steg_image_buffer);

    return 0;
}