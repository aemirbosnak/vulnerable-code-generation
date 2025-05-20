//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 256
#define IMAGE_HEIGHT 256

// Function to hide data in image
void hide_data(char* image_path, char* data) {
    FILE* image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);

    char* image_data = (char*)malloc(image_size);
    fread(image_data, image_size, 1, image_file);
    fclose(image_file);

    int data_size = strlen(data);
    int image_data_size = image_size - data_size;

    char* new_image_data = (char*)malloc(image_size);
    memcpy(new_image_data, image_data, image_data_size);
    memcpy(new_image_data + image_data_size, data, data_size);

    FILE* new_image_file = fopen(image_path, "wb");
    if (new_image_file == NULL) {
        printf("Error creating new image file.\n");
        exit(1);
    }

    fwrite(new_image_data, image_size, 1, new_image_file);
    fclose(new_image_file);

    free(image_data);
    free(new_image_data);
}

// Function to extract data from image
char* extract_data(char* image_path) {
    FILE* image_file = fopen(image_path, "rb");
    if (image_file == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    fseek(image_file, 0, SEEK_END);
    long image_size = ftell(image_file);
    rewind(image_file);

    char* image_data = (char*)malloc(image_size);
    fread(image_data, image_size, 1, image_file);
    fclose(image_file);

    int data_size = strlen(image_data) - IMAGE_WIDTH * IMAGE_HEIGHT;
    char* data = (char*)malloc(data_size + 1);
    memcpy(data, image_data + IMAGE_WIDTH * IMAGE_HEIGHT, data_size);
    data[data_size] = '\0';

    return data;
}

int main() {
    char* image_path = "image.bmp";
    char* data = "This is a secret message.";

    hide_data(image_path, data);

    char* extracted_data = extract_data(image_path);
    printf("Extracted data: %s\n", extracted_data);

    free(extracted_data);

    return 0;
}