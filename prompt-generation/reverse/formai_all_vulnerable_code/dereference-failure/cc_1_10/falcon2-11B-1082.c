//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to embed a secret message into an image file
void embed_message(char* filename, char* message, int file_size) {
    FILE* image_file = fopen(filename, "rb");
    if (image_file == NULL) {
        fprintf(stderr, "Error opening image file '%s' for reading.\n", filename);
        return;
    }

    FILE* message_file = fopen("message.txt", "rb");
    if (message_file == NULL) {
        fprintf(stderr, "Error opening message file'message.txt' for reading.\n");
        return;
    }

    // Read the image file into memory
    fseek(image_file, 0L, SEEK_END);
    long file_size_bytes = ftell(image_file);
    fseek(image_file, 0L, SEEK_SET);

    char* image_data = (char*)malloc(file_size_bytes);
    fread(image_data, sizeof(char), file_size_bytes, image_file);
    fclose(image_file);

    // Read the message file into memory
    fseek(message_file, 0L, SEEK_END);
    long message_size_bytes = ftell(message_file);
    fseek(message_file, 0L, SEEK_SET);

    char* message_data = (char*)malloc(message_size_bytes);
    fread(message_data, sizeof(char), message_size_bytes, message_file);
    fclose(message_file);

    // Embed the message into the image data
    int message_size = strlen(message);
    int image_size = strlen(image_data);
    int message_index = 0;
    while (message_index < message_size) {
        int offset = 0;
        int found = 0;
        while (offset < image_size) {
            if (image_data[offset] == message_data[message_index]) {
                image_data[offset] = message_data[message_index + message_size];
                found = 1;
                break;
            }
            offset++;
        }
        if (!found) {
            printf("Error embedding message: Unable to find matching character.\n");
            free(image_data);
            free(message_data);
            return;
        }
        message_index++;
    }

    // Write the modified image data back to the file
    FILE* output_file = fopen(filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error opening output image file '%s' for writing.\n", filename);
        free(image_data);
        free(message_data);
        return;
    }

    fwrite(image_data, sizeof(char), file_size_bytes, output_file);
    fclose(output_file);

    // Free memory
    free(image_data);
    free(message_data);
}

int main() {
    // Example usage
    char* message = "Hello, world!";
    char* image = "secret_image.jpg";
    int file_size = 1024; // Size of the image file in bytes

    embed_message(image, message, file_size);

    return 0;
}