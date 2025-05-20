//FormAI DATASET v1.0 Category: Image Steganography ; Style: Donald Knuth
/*
* Program: Donald Knuth Style Unique C Image Steganography Example
* Author: Chatbot
* Purpose: This program hides a message within an image using steganography.
* Language: C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MESSAGE_FILE "message.txt"
#define IMAGE_FILE "image.bmp"
#define ENCODED_IMAGE_FILE "encoded_image.bmp"
#define MAX_MESSAGE_LENGTH 1000

// Function to read message from file
char* read_message_from_file(char message_file[]) {
    FILE* fp = fopen(message_file, "r");

    if (fp == NULL) {
        printf("Error: Could not open message file\n");
        exit(1);
    }

    char* message = (char*) malloc(sizeof(char) * MAX_MESSAGE_LENGTH);
    fgets(message, MAX_MESSAGE_LENGTH, fp);

    fclose(fp);

    return message;
}

// Function to write message to file
void write_message_to_file(char message[], char message_file[]) {
    FILE* fp = fopen(message_file, "w");

    if (fp == NULL) {
        printf("Error: Could not open message file\n");
        exit(1);
    }

    fprintf(fp, "%s", message);
    fclose(fp);
}

// Function to get image dimensions
void get_image_dimensions(char image_file[], int* width, int* height) {
    FILE* fp = fopen(image_file, "rb");

    if (fp == NULL) {
        printf("Error: Could not open image file\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(width, 4, 1, fp);
    fread(height, 4, 1, fp);

    fclose(fp);
}

// Function to hide message in image
void hide_message_in_image(char message[], char image_file[], char encoded_image_file[]) {
    int width, height;
    FILE* image_fp = fopen(image_file, "rb");
    FILE* encoded_fp = fopen(encoded_image_file, "wb");

    if (image_fp == NULL || encoded_fp == NULL) {
        printf("Error: Could not open image files\n");
        exit(1);
    }

    fseek(image_fp, 0, SEEK_SET);
    fseek(encoded_fp, 0, SEEK_SET);

    while (!feof(image_fp)) {
        char buffer;
        fread(&buffer, 1, 1, image_fp);
        fwrite(&buffer, 1, 1, encoded_fp);
    }

    fseek(encoded_fp, 54, SEEK_SET);

    for (int i=0; i<strlen(message); i++) {
        char message_character = message[i];

        for (int j=0; j<8; j++) {
            int bit_position = 7-j;
            int mask = 1 << bit_position;
            int image_byte;

            fread(&image_byte, 1, 1, encoded_fp);

            int image_bit = (image_byte & mask) >> bit_position;
            int message_bit = (message_character & mask) >> bit_position;

            if (image_bit != message_bit) {
                if (message_bit == 1) {
                    image_byte = image_byte | mask;
                } else {
                    image_byte = image_byte & (~mask);
                }

                fseek(encoded_fp, -1, SEEK_CUR);
                fwrite(&image_byte, 1, 1, encoded_fp);
            }

            if (feof(encoded_fp)) {
                printf("Error: Image file too small\n");
                exit(1);
            }
        }
    }

    fclose(image_fp);
    fclose(encoded_fp);
}

// Function to retrieve message from image
char* retrieve_message_from_image(char encoded_image_file[]) {
    int width, height;
    FILE* encoded_fp = fopen(encoded_image_file, "rb");

    if (encoded_fp == NULL) {
        printf("Error: Could not open image file\n");
        exit(1);
    }

    fseek(encoded_fp, 0, SEEK_SET);
    fseek(encoded_fp, 18, SEEK_SET);
    fread(&width, 4, 1, encoded_fp);
    fread(&height, 4, 1, encoded_fp);

    if (width*height < strlen(MESSAGE_FILE)*8) {
        printf("Error: Could not retrieve message from image\n");
        exit(1);
    }

    char* message = (char*) malloc(sizeof(char) * MAX_MESSAGE_LENGTH);
    int message_index = 0;
    char message_character = 0;

    fseek(encoded_fp, 54, SEEK_SET);

    for (int i=0; i<strlen(MESSAGE_FILE)*8; i++) {
        int bit_position = 7 - (i % 8);
        int mask = 1 << bit_position;
        int image_byte;

        fread(&image_byte, 1, 1, encoded_fp);

        int image_bit = (image_byte & mask) >> bit_position;

        message_character = message_character | (image_bit << bit_position);
        
        if ((i+1) % 8 == 0) {
            message[message_index++] = message_character;
            message_character = 0;
        }
        
        if (feof(encoded_fp)) {
            printf("Error: Image file too small\n");
            exit(1);
        }
    }

    fclose(encoded_fp);

    return message;
}

int main() {
    char* message = read_message_from_file(MESSAGE_FILE);

    printf("Message to hide: %s\n", message);

    int width = 0;
    int height = 0;
    get_image_dimensions(IMAGE_FILE, &width, &height);

    printf("Image dimensions: %dx%d\n", width, height);

    hide_message_in_image(message, IMAGE_FILE, ENCODED_IMAGE_FILE);

    char* hidden_message = retrieve_message_from_image(ENCODED_IMAGE_FILE);

    printf("Hidden message: %s\n", hidden_message);

    write_message_to_file(hidden_message, "retrieved_message.txt");

    return 0;
}