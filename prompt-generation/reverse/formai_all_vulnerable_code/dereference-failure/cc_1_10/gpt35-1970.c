//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Function to hide secret message in the image
void hide_message(char* image_file, char* secret_message){
    FILE* image_ptr = fopen(image_file, "rb"); // Open image file in binary read mode

    if(image_ptr == NULL){
        printf("Error opening image file!\n");
        return;
    }

    // Determine file size
    fseek(image_ptr, 0, SEEK_END);
    int image_size = ftell(image_ptr);
    rewind(image_ptr); // Reset file pointer to the beginning

    // Allocate memory for image buffer
    unsigned char* image_buffer = (unsigned char*)malloc(image_size * sizeof(unsigned char));
    if(image_buffer == NULL){
        printf("Error allocating memory for image buffer!\n");
        return;
    }

    // Read image data into buffer
    size_t read_size = fread(image_buffer, sizeof(unsigned char), image_size, image_ptr);
    if(read_size != image_size){
        printf("Error reading data from image file!\n");
        return;
    }

    fclose(image_ptr); // Close image file

    int message_length = strlen(secret_message);

    // Check if message can be hidden in the image
    if((message_length * 8) > (image_size - 54)){
        printf("Error: Message is too large to hide in the given image!\n");
        return;
    }

    // Set the least significant bit of each pixel byte to a message bit
    int byte_index = 54; // Start at the 55th byte of the image, after the header
    for(int i=0; i<message_length; i++){
        char current_char = secret_message[i];
        for(int j=0; j<8; j++){
            image_buffer[byte_index] &= 0xFE; // Set least significant bit to 0
            image_buffer[byte_index] |= ((int)current_char >> j) & 0x01; // Set LSB to message bit
            byte_index++;
        }
    }

    // Save the modified image
    char* new_image_file = "secret_image.bmp";
    FILE* new_image_ptr = fopen(new_image_file, "wb"); // Open new image file in binary write mode

    if(new_image_ptr == NULL){
        printf("Error creating new image file!\n");
        return;
    }

    size_t write_size = fwrite(image_buffer, sizeof(unsigned char), image_size, new_image_ptr);
    if(write_size != image_size){
        printf("Error writing data to new image file!\n");
        return;
    }

    fclose(new_image_ptr); // Close new image file

    printf("Message hidden successfully in %s!\n", image_file);
    printf("New image saved as %s.\n", new_image_file);

    free(image_buffer); // Free allocated memory
}

// Function to extract secret message from the image
void extract_message(char* image_file){
    FILE* image_ptr = fopen(image_file, "rb"); // Open image file in binary read mode

    if(image_ptr == NULL){
        printf("Error opening image file!\n");
        return;
    }

    // Determine file size
    fseek(image_ptr, 0, SEEK_END);
    int image_size = ftell(image_ptr);
    rewind(image_ptr); // Reset file pointer to the beginning

    // Allocate memory for image buffer
    unsigned char* image_buffer = (unsigned char*)malloc(image_size * sizeof(unsigned char));
    if(image_buffer == NULL){
        printf("Error allocating memory for image buffer!\n");
        return;
    }

    // Read image data into buffer
    size_t read_size = fread(image_buffer, sizeof(unsigned char), image_size, image_ptr);
    if(read_size != image_size){
        printf("Error reading data from image file!\n");
        return;
    }

    fclose(image_ptr); // Close image file

    // Extract message from the least significant bit of each pixel byte
    int byte_index = 54; // Start at the 55th byte of the image, after the header
    char current_char = 0;
    int message_length = 0;
    for(int i=0; i<(image_size - 54)/8; i++){
        for(int j=0; j<8; j++){
            current_char |= (image_buffer[byte_index] & 0x01) << j; // Extract message bit from LSB
            byte_index++;
        }
        message_length++;
        if(current_char == '\0'){
            break; // End of message
        }
        printf("%c", current_char); // Print character to console
        current_char = 0; // Reset for next character
    }

    free(image_buffer); // Free allocated memory
}

int main(){
    char* image_file = "sample.bmp";
    char* secret_message = "This is a top secret message!";

    hide_message(image_file, secret_message);

    extract_message("secret_image.bmp");

    return 0;
}