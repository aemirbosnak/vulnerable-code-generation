//FormAI DATASET v1.0 Category: Image Steganography ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

void hideMessage(char* cover_image_path, char* message_path, char* output_image_path) {
    FILE *cover_image, *message, *output_image;
    unsigned char cover_byte, message_byte;
    
    // Open the cover image and message file
    cover_image = fopen(cover_image_path, "rb");
    message = fopen(message_path, "rb");
    
    if (cover_image == NULL) {
        printf("Unable to open cover image\n");
        exit(EXIT_FAILURE);
    }
    
    if (message == NULL) {
        printf("Unable to open message file\n");
        exit(EXIT_FAILURE);
    }
    
    // Create the output image file
    output_image = fopen(output_image_path, "wb");
    
    // Get cover image size
    fseek(cover_image, 0, SEEK_END);
    int cover_size = ftell(cover_image);
    fseek(cover_image, 0, SEEK_SET);
    
    // Copy cover image bytes to output image
    int i;
    for (i = 0; i < cover_size; i++) {
        cover_byte = fgetc(cover_image);
        fputc(cover_byte, output_image);
    }
    
    // Get message size
    fseek(message, 0, SEEK_END);
    int message_size = ftell(message);
    fseek(message, 0, SEEK_SET);
    
    // Create a byte array to hold the message
    unsigned char message_bytes[MAX_SIZE];
    
    // Read message bytes
    fread(message_bytes, 1, message_size, message);
    
    // Embed message bytes in cover image
    int j;
    for (j = 0; j < message_size; j++) {
        cover_byte = fgetc(cover_image);
        message_byte = message_bytes[j];
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 7) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 6) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 5) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 4) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 3) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 2) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | ((message_byte >> 1) & 0x01);
        fputc(cover_byte, output_image);
        
        cover_byte = fgetc(cover_image);
        cover_byte = (cover_byte & 0xFE) | (message_byte & 0x01);
        fputc(cover_byte, output_image);
    }
    
    // Copy remaining cover bytes
    while (!feof(cover_image)) {
        cover_byte = fgetc(cover_image);
        fputc(cover_byte, output_image);
    }
    
    fclose(cover_image);
    fclose(message);
    fclose(output_image);
    
    printf("Message hidden successfully!\n");
}

void showMessage(char* stego_image_path, char* output_message_path) {
    FILE *stego_image, *output_message;
    unsigned char stego_byte, message_byte = 0;
    
    // Open the stego image file
    stego_image = fopen(stego_image_path, "rb");
    
    if (stego_image == NULL) {
        printf("Unable to open stego image\n");
        exit(EXIT_FAILURE);
    }
    
    // Create message file
    output_message = fopen(output_message_path, "wb");
    
    // Extract message bytes from stego image
    int i;
    for (i = 0; i < MAX_SIZE; i++) {
        stego_byte = fgetc(stego_image);
        message_byte = (message_byte << 1) | (stego_byte & 0x01);
        if ((i + 1) % 8 == 0) {
            if (message_byte == '\0') {
                break;
            } else {
                fputc(message_byte, output_message);
                message_byte = 0;
            }
        }
    }
    
    fclose(stego_image);
    fclose(output_message);
    
    printf("Message retrieved successfully!\n");
}

int main() {
    char* cover_image_path = "cover.bmp";
    char* message_path = "message.txt";
    char* output_image_path = "stego.bmp";
    char* output_message_path = "output_message.txt";
    
    hideMessage(cover_image_path, message_path, output_image_path);
    showMessage(output_image_path, output_message_path);
    
    return 0;
}