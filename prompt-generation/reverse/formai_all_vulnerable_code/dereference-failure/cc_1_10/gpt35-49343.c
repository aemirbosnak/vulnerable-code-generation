//FormAI DATASET v1.0 Category: Image Steganography ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hide_message(char *img_file, char *msg_file, char *stego_file){
    // Open image and message files
    FILE *img = fopen(img_file, "rb");
    FILE *msg = fopen(msg_file, "r");

    // Get size of message file
    fseek(msg, 0, SEEK_END);
    long int msg_size = ftell(msg);
    rewind(msg);

    // Allocate memory to store message
    char *message = (char*) malloc(msg_size * sizeof(char));
    fread(message, sizeof(char), msg_size, msg);

    // Open steganography file for writing
    FILE *stego = fopen(stego_file, "wb");

    // Read and write image file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, img);
    fwrite(header, sizeof(unsigned char), 54, stego);

    // Get size of image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int data_size = width * height * 3;

    // Read image data, and replace LSB with message bits
    unsigned char data[data_size];
    fread(data, sizeof(unsigned char), data_size, img);

    int k = 0;
    for(long int i=0; i<msg_size; i++){
        for(int j=0; j<8; j++){
            if(k >= data_size){
                printf("Message too large to fit in image!");
                exit(0);
            }
            data[k] = (data[k] & 0xFE) | ((message[i] >> j) & 0x01);
            k++;
        }
    }

    // Write steganography data to file
    fwrite(data, sizeof(unsigned char), data_size, stego);

    // Close files
    fclose(img);
    fclose(msg);
    fclose(stego);

    printf("Message hidden successfully!");
}

void retrieve_message(char *stego_file, char *msg_file){
    // Open steganography file and message file for reading and writing respectively
    FILE *stego = fopen(stego_file, "rb");
    FILE *msg = fopen(msg_file, "w");

    // Read image file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, stego);

    // Get size of image data
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int data_size = width * height * 3;

    // Read image data, and extract LSBs to form message
    unsigned char data[data_size];
    fread(data, sizeof(unsigned char), data_size, stego);

    int k = 0;
    char message[10000];
    int i = 0;

    while(k < data_size){
        char byte = 0;
        for(int j=0; j<8; j++){
            byte = (byte << 1) | (data[k] & 0x01);
            k++;
        }
        message[i] = byte;
        i++;
    }

    // Write message to file
    fprintf(msg, "%s", message);

    // Close files
    fclose(stego);
    fclose(msg);

    printf("Message retrieved successfully!");
}

int main(){
    // Hide message in image
    hide_message("image.bmp", "message.txt", "stego_image.bmp");

    // Retrieve message from steganography
    retrieve_message("stego_image.bmp", "retrieved_message.txt");

    return 0;
}