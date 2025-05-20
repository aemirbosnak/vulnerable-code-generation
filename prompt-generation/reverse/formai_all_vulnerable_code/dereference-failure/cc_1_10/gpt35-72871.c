//FormAI DATASET v1.0 Category: Image Steganography ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void hide_data(unsigned char *image_buffer, char* data, int data_size){
    int byte_offset = 0;
    int bit_offset = 0;
    int data_offset = 0;
    unsigned char image_byte = image_buffer[byte_offset];
    
    while(data_offset != data_size){
        int current_bit = (data[data_offset] >> bit_offset) & 0x01;
        image_byte &= 0xFE; // Clear the least significant bit
        image_byte |= current_bit; // Set the bit if necessary
        image_buffer[byte_offset] = image_byte; // Store the updated image byte
        bit_offset++;

        // If all bits have been used, move to the next byte
        if(bit_offset == 8){
            bit_offset = 0;
            byte_offset++;
            image_byte = image_buffer[byte_offset];
        }

        data_offset++;
    }
}

char* extract_data(unsigned char *image_buffer, int data_size){
    int byte_offset = 0;
    int bit_offset = 0;
    int data_offset = 0;
    char* extracted_data = (char*)malloc(data_size+1);

    while(data_offset != data_size){
        extracted_data[data_offset] = 0x00; // Initialize bits to 0
        int current_bit = image_buffer[byte_offset] & 0x01; // Extract the LSB
        extracted_data[data_offset] |= current_bit << bit_offset;
        bit_offset++;

        // If all bits have been extracted, move to the next byte
        if(bit_offset == 8){
            bit_offset = 0;
            byte_offset++;
        }

        data_offset++;
    }

    return extracted_data;
}

int main(){
    char* data = "This is a steganography test. This message should be encoded in the image.";
    int data_size = strlen(data);

    // Read the image file
    FILE* image_file = fopen("image.jpg", "rb");
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    rewind(image_file);
    unsigned char* image_buffer = (unsigned char*)malloc(image_size);
    fread(image_buffer, 1, image_size, image_file);
    fclose(image_file);

    hide_data(image_buffer, data, data_size);

    // Write the modified image buffer to a new file
    FILE* modified_file = fopen("modified_image.jpg", "wb");
    fwrite(image_buffer, 1, image_size, modified_file);
    fclose(modified_file);

    // Read the modified image file
    FILE* modified_image_file = fopen("modified_image.jpg", "rb");
    fseek(modified_image_file, 0, SEEK_END);
    int modified_image_size = ftell(modified_image_file);
    rewind(modified_image_file);
    unsigned char* modified_image_buffer = (unsigned char*)malloc(modified_image_size);
    fread(modified_image_buffer, 1, modified_image_size, modified_image_file);
    fclose(modified_image_file);

    char* extracted_data = extract_data(modified_image_buffer, data_size);
    extracted_data[data_size] = '\0';

    printf("Extracted data: %s\n", extracted_data);

    free(image_buffer);
    free(modified_image_buffer);
    free(extracted_data);

    return 0;
}