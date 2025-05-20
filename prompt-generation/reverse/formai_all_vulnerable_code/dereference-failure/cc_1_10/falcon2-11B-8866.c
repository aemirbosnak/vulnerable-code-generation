//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide a message in an image file
void hide_message(char* image_file_name, char* message, int size) {
    FILE* file = fopen(image_file_name, "rb");
    if (file == NULL) {
        printf("Error: Unable to open image file.\n");
        return;
    }

    // Read the image file
    fseek(file, 0, SEEK_END);
    long size_image = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* image_data = (char*)malloc(size_image);
    fread(image_data, size_image, 1, file);
    fclose(file);

    // Convert the image data to an array of unsigned char
    unsigned char* image_data_uchar = (unsigned char*)malloc(size_image);
    for (int i = 0; i < size_image; i++) {
        image_data_uchar[i] = image_data[i];
    }

    // Hide the message in the image data
    for (int i = 0; i < size; i++) {
        image_data_uchar[i] = (image_data_uchar[i] & 0xFE) | ((message[i] & 0x01) << 7);
    }

    // Write the modified image data back to the file
    FILE* file_out = fopen(image_file_name, "wb");
    if (file_out == NULL) {
        printf("Error: Unable to open image file for writing.\n");
        free(image_data_uchar);
        return;
    }

    fwrite(image_data_uchar, size_image, 1, file_out);
    fclose(file_out);
    free(image_data_uchar);
}

// Function to extract a message from an image file
char* extract_message(char* image_file_name, int size) {
    FILE* file = fopen(image_file_name, "rb");
    if (file == NULL) {
        printf("Error: Unable to open image file.\n");
        return NULL;
    }

    // Read the image file
    fseek(file, 0, SEEK_END);
    long size_image = ftell(file);
    fseek(file, 0, SEEK_SET);
    char* image_data = (char*)malloc(size_image);
    fread(image_data, size_image, 1, file);
    fclose(file);

    // Convert the image data to an array of unsigned char
    unsigned char* image_data_uchar = (unsigned char*)malloc(size_image);
    for (int i = 0; i < size_image; i++) {
        image_data_uchar[i] = image_data[i];
    }

    // Extract the message from the image data
    char* message = (char*)malloc(size);
    for (int i = 0; i < size; i++) {
        message[i] = image_data_uchar[i] & 0x01;
    }

    // Free memory
    free(image_data_uchar);
    return message;
}

int main() {
    // Hide a message in an image file
    char* image_file_name = "image.png";
    char* message = "Hello, world!";
    int size = strlen(message);
    hide_message(image_file_name, message, size);

    // Extract the message from the image file
    char* extracted_message = extract_message(image_file_name, size);
    printf("Extracted message: %s\n", extracted_message);

    // Free memory
    free(extracted_message);
    return 0;
}