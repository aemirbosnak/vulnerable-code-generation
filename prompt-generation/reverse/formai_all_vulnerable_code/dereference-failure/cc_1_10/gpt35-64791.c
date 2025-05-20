//FormAI DATASET v1.0 Category: Image Steganography ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Definition of the maximum message size */
#define MAX_MSG_SIZE 10000

/* Definition of the functions to read and write messages */
void read_message(char *message, int *message_size);
void write_message(char *message, int message_size);

/* Definition of the function to hide a message in an image */
void hide_message_in_image(char *image_name, char *message, int message_size);

/* Definition of the function to extract a message from an image */
void extract_message_from_image(char *image_name, char *message, int *message_size);

/* Definition of the main function */
int main(int argc, char* argv[]) {
    /* Check that the correct number of arguments was provided */
    if(argc != 4) {
        printf("Usage: %s <hide|extract> <image_name> <message_file>\n", argv[0]);
        return 1;
    }
    
    /* Read the operation, image name, and message file name from the command line arguments */
    char *operation = argv[1];
    char *image_name = argv[2];
    char *message_file = argv[3];
    
    /* Allocate memory for the message */
    char *message = malloc(MAX_MSG_SIZE*sizeof(char));
    int message_size;
    
    /* Read the message from the message file */
    read_message(message, &message_size);
    
    /* Perform the requested operation */
    if(strcmp(operation, "hide") == 0) {
        hide_message_in_image(image_name, message, message_size);
    } else if(strcmp(operation, "extract") == 0) {
        extract_message_from_image(image_name, message, &message_size);
        /* Write the extracted message to the console */
        printf("Extracted message: %s\n", message);
    } else {
        printf("Invalid operation: %s\n", operation);
        return 1;
    }
    
    /* Free the message memory */
    free(message);
    
    return 0;
}

/* Implementation of the function to read a message from a file */
void read_message(char *message, int *message_size) {
    /* Open the message file */
    FILE *fp = fopen("message_file.txt", "r");
    /* Check that the file was opened successfully */
    if(fp == NULL) {
        printf("Failed to open message file\n");
        exit(1);
    }
    /* Read the message from the file */
    *message_size = 0;
    int c = fgetc(fp);
    while(c != EOF && *message_size < MAX_MSG_SIZE) {
        message[*message_size] = c;
        *message_size += 1;
        c = fgetc(fp);
    }
    /* Close the file */
    fclose(fp);
}

/* Implementation of the function to write a message to a file */
void write_message(char *message, int message_size) {
    /* Open the message file */
    FILE *fp = fopen("message_file.txt", "w");
    /* Check that the file was opened successfully */
    if(fp == NULL) {
        printf("Failed to open message file\n");
        exit(1);
    }
    /* Write the message to the file */
    for(int i=0; i<message_size; i++) {
        fputc(message[i], fp);
    }
    /* Close the file */
    fclose(fp);
}

/* Implementation of the function to hide a message in an image */
void hide_message_in_image(char *image_name, char *message, int message_size) {
    /* Open the image file */
    FILE *fp = fopen(image_name, "rb");
    /* Check that the file was opened successfully */
    if(fp == NULL) {
        printf("Failed to open image file\n");
        exit(1);
    }
    /* Read the image header */
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    /* Calculate the number of pixels in the image */
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;
    int num_pixels = width * height;
    /* Calculate the number of bytes needed to represent the message */
    int num_bytes = message_size * 8;
    /* Check that the message can fit in the image */
    if(num_bytes > num_pixels) {
        printf("Message too large to hide in image\n");
        exit(1);
    }
    /* Loop over each pixel in the image and modify the least significant bit of each color channel */
    unsigned char pixel[3];
    int bit_index = 0;
    int message_index = 0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            /* Read the pixel */
            fread(pixel, sizeof(unsigned char), 3, fp);
            /* Modify the least significant bit of each color channel */
            for(int k=0; k<3; k++) {
                if(bit_index < num_bytes) {
                    int bit = (message[message_index] >> (7 - bit_index % 8)) & 1;
                    pixel[k] = (pixel[k] & 0xFE) | bit;
                    bit_index++;
                    if(bit_index % 8 == 0) {
                        message_index++;
                    }
                }
            }
            /* Write the modified pixel */
            fwrite(pixel, sizeof(unsigned char), 3, fp);
        }
        /* Skip over the padding at the end of each row */
        fseek(fp, padding, SEEK_CUR);
    }
    /* Close the file */
    fclose(fp);
}

/* Implementation of the function to extract a message from an image */
void extract_message_from_image(char *image_name, char *message, int *message_size) {
    /* Open the image file */
    FILE *fp = fopen(image_name, "rb");
    /* Check that the file was opened successfully */
    if(fp == NULL) {
        printf("Failed to open image file\n");
        exit(1);
    }
    /* Read the image header */
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);
    /* Calculate the number of pixels in the image */
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    int padding = (4 - (width * 3) % 4) % 4;
    int num_pixels = width * height;
    /* Allocate memory for the extracted message */
    *message_size = num_pixels / 8;
    memset(message, 0, *message_size);
    /* Loop over each pixel in the image and extract the least significant bit of each color channel */
    unsigned char pixel[3];
    int bit_index = 0;
    int message_index = 0;
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            /* Read the pixel */
            fread(pixel, sizeof(unsigned char), 3, fp);
            /* Extract the least significant bit of each color channel */
            for(int k=0; k<3; k++) {
                if(bit_index < *message_size * 8) {
                    int bit = pixel[k] & 1;
                    message[message_index] |= bit << (7 - bit_index % 8);
                    bit_index++;
                    if(bit_index % 8 == 0) {
                        message_index++;
                    }
                }
            }
        }
        /* Skip over the padding at the end of each row */
        fseek(fp, padding, SEEK_CUR);
    }
    /* Close the file */
    fclose(fp);
    /* Write the extracted message to the message file */
    write_message(message, *message_size);
}