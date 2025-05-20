//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to hide a message in an image
void hide_message(const char* image_file, const char* message, char* secret_message) {
    FILE* image_file_ptr = fopen(image_file, "r");
    if (image_file_ptr == NULL) {
        printf("Error opening image file\n");
        return;
    }

    FILE* secret_file_ptr = fopen("secret.txt", "w");
    if (secret_file_ptr == NULL) {
        printf("Error creating secret file\n");
        return;
    }

    int num_pixels = 0;
    unsigned char* image_pixels = NULL;
    int image_pixels_size = 0;
    int num_bytes_per_pixel = 3;

    fseek(image_file_ptr, 0, SEEK_END);
    num_pixels = ftell(image_file_ptr) / num_bytes_per_pixel;
    rewind(image_file_ptr);

    image_pixels = (unsigned char*)malloc(num_pixels * num_bytes_per_pixel);
    fread(image_pixels, num_bytes_per_pixel, num_pixels, image_file_ptr);
    fclose(image_file_ptr);

    for (int i = 0; i < num_pixels; i++) {
        unsigned char* pixel = &image_pixels[i * num_bytes_per_pixel];
        int message_index = (pixel[2] & 0x0F) * 16 + (pixel[1] & 0x0F);
        if (message_index < strlen(message)) {
            secret_file_ptr = fopen("secret.txt", "a");
            if (secret_file_ptr == NULL) {
                printf("Error opening secret file\n");
                return;
            }

            secret_file_ptr = fputc(message[message_index], secret_file_ptr);
            fclose(secret_file_ptr);
        }
    }

    fseek(secret_file_ptr, 0, SEEK_END);
    fwrite(secret_message, 1, strlen(secret_message), secret_file_ptr);
    fclose(secret_file_ptr);

    free(image_pixels);
}

// Function to extract the hidden message from an image
void extract_message(const char* image_file, char* secret_message) {
    FILE* image_file_ptr = fopen(image_file, "r");
    if (image_file_ptr == NULL) {
        printf("Error opening image file\n");
        return;
    }

    FILE* secret_file_ptr = fopen("secret.txt", "r");
    if (secret_file_ptr == NULL) {
        printf("Error opening secret file\n");
        return;
    }

    int num_pixels = 0;
    unsigned char* image_pixels = NULL;
    int image_pixels_size = 0;
    int num_bytes_per_pixel = 3;

    fseek(image_file_ptr, 0, SEEK_END);
    num_pixels = ftell(image_file_ptr) / num_bytes_per_pixel;
    rewind(image_file_ptr);

    image_pixels = (unsigned char*)malloc(num_pixels * num_bytes_per_pixel);
    fread(image_pixels, num_bytes_per_pixel, num_pixels, image_file_ptr);
    fclose(image_file_ptr);

    char* secret_message_ptr = secret_message;
    for (int i = 0; i < num_pixels; i++) {
        unsigned char* pixel = &image_pixels[i * num_bytes_per_pixel];
        int message_index = (pixel[2] & 0x0F) * 16 + (pixel[1] & 0x0F);
        if (message_index < strlen(secret_message_ptr)) {
            *secret_message_ptr = secret_message_ptr[message_index];
            secret_message_ptr++;
        }
    }

    fseek(secret_file_ptr, 0, SEEK_END);
    fwrite(secret_message_ptr, 1, strlen(secret_message_ptr), secret_file_ptr);
    fclose(secret_file_ptr);
}

int main() {
    char secret_message[100];
    char image_file[] = "image.jpg";
    char message[] = "This is a secret message";

    hide_message(image_file, message, secret_message);
    printf("Hidden message: %s\n", secret_message);

    extract_message(image_file, secret_message);
    printf("Extracted message: %s\n", secret_message);

    return 0;
}