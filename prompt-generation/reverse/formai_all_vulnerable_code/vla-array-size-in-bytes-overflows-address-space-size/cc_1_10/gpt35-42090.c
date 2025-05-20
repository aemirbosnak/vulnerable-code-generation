//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
/********************************************************************
* Filename:        image_steganography.c
* Author:          [Your Name]
* Date created:    [Date]
* Purpose:         A program to hide a secret message within an 
*                  image using steganography.  
*********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HIDDEN_FILE "secret_msg.txt"
#define COVER_IMAGE "cover_image.bmp"
#define STEGO_IMAGE "stego_image.bmp"

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} pixel;

pixel **image, **stego_image;
long int file_length, image_size, secret_msg_size;

void embed_secret_msg_in_image(char secret_msg[], int secret_msg_size);
void read_image_into_array(FILE *image_file);
void write_array_to_image(FILE *image_file, pixel **image);
void write_secret_msg_to_file(char secret_msg[], int secret_msg_size);

int main(int argc, char *argv[]) {

    FILE *image_file, *hidden_file;
    char secret_msg[10000];

    printf("Welcome to Grateful's Image Steganography application\n");

    // Read the contents of the hidden file
    hidden_file = fopen(HIDDEN_FILE, "rb");
    if(hidden_file == NULL) {
        printf("Error: Unable to open hidden file %s.\n", HIDDEN_FILE);
        return 1;
    } else {
        // Calculate the size of the file
        fseek(hidden_file, 0, SEEK_END);
        secret_msg_size = ftell(hidden_file);
        fseek(hidden_file, 0, SEEK_SET);
        fread(secret_msg, 1, secret_msg_size, hidden_file);
        fclose(hidden_file);
        // Add the null terminator to the end of the message 
        secret_msg[secret_msg_size] = '\0';
        printf("Message size: %d bytes\n", secret_msg_size);
    }

    // Read the image file into a 2D array
    image_file = fopen(COVER_IMAGE, "rb");
    if(image_file == NULL) {
        printf("Error: Unable to open image file %s.\n", COVER_IMAGE);
        return 1;
    } else {
        read_image_into_array(image_file);
        fclose(image_file);
    }

    // Embed the secret message in the image
    embed_secret_msg_in_image(secret_msg, secret_msg_size);

    // Write the new stego image to file
    image_file = fopen(STEGO_IMAGE, "wb");
    if(image_file == NULL) {
        printf("Error: Unable to create stego image file %s.\n", STEGO_IMAGE);
        return 1;
    } else {
        write_array_to_image(image_file, stego_image);
        fclose(image_file);
    }

    // Write the secret message to file
    write_secret_msg_to_file(secret_msg, secret_msg_size);

    printf("Secret message hidden in image %s\n", STEGO_IMAGE);

    // Free memory
    for(int i = 0; i < image_size; i++) {
        free(image[i]);
        free(stego_image[i]);
    }
    free(image);
    free(stego_image);

    return 0;
}

void embed_secret_msg_in_image(char secret_msg[], int secret_msg_size) {
    int current_char = 0;

    // Allocate memory for the stego image
    stego_image = (pixel **)malloc(sizeof(pixel *) * image_size);
    for(int i = 0; i < image_size; i++) {
        stego_image[i] = (pixel *)malloc(sizeof(pixel) * image_size);
    }

    // Copy the original image to the stego image
    for(int i = 0; i < image_size; i++) {
        for(int j = 0; j < image_size; j++) {
            stego_image[i][j].blue = image[i][j].blue;
            stego_image[i][j].green = image[i][j].green;
            stego_image[i][j].red = image[i][j].red;
        }
    }

    // Embed the secret message into the stego image 
    for(int i = 0; i < image_size; i++) {
        for(int j = 0; j < image_size; j++) {

            // Check if all the characters have been embedded
            if(current_char == secret_msg_size) {
                return;
            }

            // Embed the characters of the secret message in the LSB of the blue color channel
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xFE) | ((secret_msg[current_char] >> 7) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xFD) | ((secret_msg[current_char] >> 6) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xFB) | ((secret_msg[current_char] >> 5) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xF7) | ((secret_msg[current_char] >> 4) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xEF) | ((secret_msg[current_char] >> 3) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xDF) | ((secret_msg[current_char] >> 2) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0xBF) | ((secret_msg[current_char] >> 1) & 1));
            stego_image[i][j].blue = ((stego_image[i][j].blue & 0x7F) | ((secret_msg[current_char]) & 1));

            current_char++;
        }
    }
}

void read_image_into_array(FILE *image_file) {

    // Get the file length
    fseek(image_file, 0, SEEK_END);
    file_length = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    unsigned char header[54];
    fread(header, 1, 54, image_file);

    // Read the image data
    image_size = *(long int *)&header[0x22];
    unsigned char buffer[image_size][image_size * 3];

    for(int i = 0; i < image_size; i++) {
        fread(buffer[i], 1, image_size * 3, image_file);
    }

    // Allocate memory for the image array
    image = (pixel **)malloc(sizeof(pixel *) * image_size);
    for(int i = 0; i < image_size; i++) {
        image[i] = (pixel *)malloc(sizeof(pixel) * image_size);
    }

    // Load the image array with the pixel data
    for(int i = 0; i < image_size; i++) {
        for(int j = 0; j < image_size; j++) {
            int pos = j * 3;
            image[i][j].blue = buffer[image_size - i - 1][pos];
            image[i][j].green = buffer[image_size - i - 1][pos + 1];
            image[i][j].red = buffer[image_size - i - 1][pos + 2];
        }
    }
}

void write_array_to_image(FILE *image_file, pixel **image) {
    unsigned char header[54];
    fseek(image_file, 0, SEEK_SET);
    fread(header, 1, 54, image_file);
    fwrite(header, 1, 54, image_file);

   // Write the pixel data
    for(int i = 0; i < image_size; i++) {
        for(int j = 0; j < image_size; j++) {
            fputc(stego_image[image_size - i - 1][j].blue, image_file);
            fputc(stego_image[image_size - i - 1][j].green, image_file);
            fputc(stego_image[image_size - i - 1][j].red, image_file);
        }
    }
}

void write_secret_msg_to_file(char secret_msg[], int secret_msg_size) {
    FILE *output_file;
    output_file = fopen("output.txt", "w");

    if(output_file == NULL) {
        printf("Error: Unable to create output file.\n");
    } else {
        fwrite(secret_msg, 1, secret_msg_size, output_file);
        fclose(output_file);
    }
}