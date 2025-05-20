//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>

// Function to embed a message into an image
void embedMessage(char *image, char *message, int length) {
    int imageSize = 0;
    int i, j, k;
    
    // Get the size of the image
    FILE *image_file = fopen(image, "rb");
    fseek(image_file, 0, SEEK_END);
    imageSize = ftell(image_file);
    fclose(image_file);
    
    // Check if the message is too long to fit in the image
    if (length > imageSize) {
        printf("Error: Message is too long to fit in the image.\n");
        return;
    }
    
    // Open the image file for writing
    image_file = fopen(image, "wb");
    
    // Write the message into the image
    for (i = 0; i < length; i++) {
        for (j = 7; j >= 0; j--) {
            // Get the j-th bit of the message
            int bit = (message[i] >> j) & 1;
            
            // Set the corresponding bit in the image
            fseek(image_file, i + j / 8, SEEK_SET);
            int byte = fgetc(image_file);
            byte = (byte & ~(1 << (j % 8))) | (bit << (j % 8));
            fseek(image_file, i + j / 8, SEEK_SET);
            fputc(byte, image_file);
        }
    }
    
    // Close the image file
    fclose(image_file);
}

// Function to extract a message from an image
char *extractMessage(char *image, int length) {
    int imageSize = 0;
    int i, j, k;
    char *message;
    
    // Get the size of the image
    FILE *image_file = fopen(image, "rb");
    fseek(image_file, 0, SEEK_END);
    imageSize = ftell(image_file);
    fclose(image_file);
    
    // Allocate memory for the message
    message = malloc(length + 1);
    
    // Open the image file for reading
    image_file = fopen(image, "rb");
    
    // Extract the message from the image
    for (i = 0; i < length; i++) {
        char byte = 0;
        for (j = 7; j >= 0; j--) {
            // Get the j-th bit from the image
            fseek(image_file, i + j / 8, SEEK_SET);
            byte |= (fgetc(image_file) & (1 << (j % 8))) >> (j % 8);
        }
        
        // Set the corresponding bit in the message
        message[i] = byte;
    }
    
    // Close the image file
    fclose(image_file);
    
    // Terminate the message with a null byte
    message[length] = '\0';
    
    // Return the message
    return message;
}

// Main function
int main() {
    // Embed a message into an image
    embedMessage("image.png", "Hello world!", 12);
    
    // Extract the message from the image
    char *message = extractMessage("image.png", 12);
    
    // Print the message
    printf("%s\n", message);
    
    // Free the memory allocated for the message
    free(message);
    
    return 0;
}