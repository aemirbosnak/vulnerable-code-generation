//FormAI DATASET v1.0 Category: Image Steganography ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54

int main(int argc, char* argv[]) {
    FILE* img_file;
    unsigned char* img_data;
    unsigned int img_size;
    int byte_count = 0;
    char* secret_message = "Hello, world!";
    int secret_message_len = strlen(secret_message);

    // Open the input image file
    img_file = fopen("input.bmp", "rb");
    if (!img_file) {
        printf("Error opening input file.\n");
        exit(1);
    }
    
    // Get the size of the input image file
    fseek(img_file, 0L, SEEK_END);
    img_size = ftell(img_file);
    fseek(img_file, 0L, SEEK_SET);
    
    // Allocate memory for the input image data
    img_data = (unsigned char*)malloc(img_size);
    if (!img_data) {
        printf("Error allocating memory for image data.\n");
        exit(1);
    }
    
    // Read the input image data into memory
    if (fread(img_data, 1, img_size, img_file) != img_size) {
        printf("Error reading image data.\n");
        exit(1);
    }
    
    // Hide the secret message in the image data
    for (int i = BMP_HEADER_SIZE; i < img_size && byte_count < secret_message_len; i += 3) {
        img_data[i] &= 0xFC; // Clear the two least significant bits
        img_data[i] |= ((secret_message[byte_count] >> 6) & 0x03); // Set the two most significant bits
        img_data[i+1] &= 0xFC;
        img_data[i+1] |= ((secret_message[byte_count] >> 4) & 0x03);
        img_data[i+2] &= 0xFC;
        img_data[i+2] |= ((secret_message[byte_count] >> 2) & 0x03);
        byte_count++;
    }
    
    // Write the steganographed image data to a new file
    FILE* output_file = fopen("output.bmp", "wb");
    fwrite(img_data, 1, img_size, output_file);
    fclose(output_file);
    
    printf("Secret message hidden successfully.\n");
    
    free(img_data);
    fclose(img_file);
    return 0;
}