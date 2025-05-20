//FormAI DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Helper function to get the minimum value
int min(int a, int b) {
    return (a < b) ? a : b;
}

// Function to hide a secret message in an image
void embed_message(char* message, char* image_name) {
    FILE* image_file = fopen(image_name, "rb"); // Open the image file in binary mode
    if (!image_file) {
        printf("Error: Could not open image file!\n");
        return;
    }

    // Get the size of the image file
    fseek(image_file, 0L, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);

    // Allocate memory for the image data
    char* image_data = malloc(sizeof(char) * image_size);
    if (!image_data) {
        printf("Error: Could not allocate memory for image data!\n");
        return;
    }

    // Read the image data into memory
    int bytes_read = fread(image_data, sizeof(char), image_size, image_file);
    if (bytes_read != image_size) {
        printf("Error: Could not read image data properly!\n");
        return;
    }

    fclose(image_file);

    int message_size = strlen(message); // Get the length of the message
    int max_message_length = (image_size / CHAR_BIT) - 1; // Calculate the maximum length of the message that can be hidden in the image

    if (message_size > max_message_length) {
        printf("Error: Message too long to embed in the image!\n");
        return;
    }

    // Embed the message in the image
    int image_index = 0;
    for (int i = 0; i < message_size; i++) {
        char message_byte = message[i];
        for (int j = 0; j < CHAR_BIT; j++) {
            int bit = (message_byte >> j) & 1;
            image_data[image_index] = (image_data[image_index] & (~1)) | bit;
            image_index++;
        }
    }

    // Write the modified image data to a new file
    char* new_image_name = malloc(strlen(image_name) + 5);
    strcpy(new_image_name, image_name);
    strcat(new_image_name, ".new");

    image_file = fopen(new_image_name, "wb"); // Open the new image file in binary mode
    if (!image_file) {
        printf("Error: Could not create new image file!\n");
        return;
    }

    fwrite(image_data, sizeof(char), image_size, image_file); // Write the new image data to the file

    fclose(image_file);
    free(image_data);
    free(new_image_name);
}

// Function to extract a secret message from an image
char* extract_message(char* image_name) {
    FILE* image_file = fopen(image_name, "rb"); // Open the image file in binary mode
    if (!image_file) {
        printf("Error: Could not open image file!\n");
        return NULL;
    }

    // Get the size of the image file
    fseek(image_file, 0L, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);

    // Allocate memory for the image data
    char* image_data = malloc(sizeof(char) * image_size);
    if (!image_data) {
        printf("Error: Could not allocate memory for image data!\n");
        return NULL;
    }

    // Read the image data into memory
    int bytes_read = fread(image_data, sizeof(char), image_size, image_file);
    if (bytes_read != image_size) {
        printf("Error: Could not read image data properly!\n");
        return NULL;
    }

    fclose(image_file);

    char* message = malloc((image_size / CHAR_BIT) + 1); // Allocate memory for the extracted message
    int message_index = 0;

    // Extract the message from the image
    for (int i = 0; i < (image_size / CHAR_BIT); i++) {
        char message_byte = 0;
        for (int j = 0; j < CHAR_BIT; j++) {
            message_byte = message_byte | ((image_data[(i * CHAR_BIT) + j] & 1) << j);
        }
        message[message_index] = message_byte;
        message_index++;

        if (message_byte == '\0') {
            break; // Stop extracting if we reach the end of the message
        }
    }

    free(image_data);
    return message;
}

int main() {
    char* message = "This is a secret message that will be hidden in the image";
    char* image_name = "image.bmp";

    embed_message(message, image_name);

    char* extracted_message = extract_message("image.bmp.new");
    printf("Extracted message: %s\n", extracted_message);

    free(extracted_message);
    return 0;
}