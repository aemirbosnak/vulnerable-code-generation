//FormAI DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define OFFSET 54 // BMP file header size

void hide_message(unsigned char* image_buffer, char* message) {
    int message_index = 0;
    int bit_index = 0;
    char bit_mask = 1;
    
    while (message[message_index] != '\0') {
        char character = message[message_index];
        
        for (int i = 0; i < 8; i++) {
            unsigned char current_byte = image_buffer[OFFSET + (bit_index / 8)];
            
            if ((character >> i) & bit_mask) {
                current_byte |= (1 << (bit_index % 8));
            } else {
                current_byte &= ~(1 << (bit_index % 8));
            }
            
            image_buffer[OFFSET + (bit_index / 8)] = current_byte;
            
            bit_index++;
        }
        
        message_index++;
    }
}

char* extract_message(unsigned char* image_buffer) {
    char* message = malloc(sizeof(char));
    int message_index = 0;
    int bit_index = 0;
    
    while (1) {
        unsigned char current_byte = image_buffer[OFFSET + (bit_index / 8)];
        
        if ((current_byte >> (bit_index % 8)) & 1) {
            message[message_index] |= (1 << (bit_index % 8));
        } else {
            message[message_index] &= ~(1 << (bit_index % 8));
        }
        
        bit_index++;
        
        if (bit_index % 8 == 0) {
            message = realloc(message, sizeof(char) * (message_index + 2));
            
            if (message == NULL) {
                printf("Error allocating memory.\n");
                exit(1);
            }
            
            if (message[message_index] == '\0') {
                break;
            }
            
            message_index++;
        }
    }
    
    return message;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: ./image_steganography <image_file> <message_file>\n");
        exit(1);
    }
    
    char* image_file_name = argv[1];
    char* message_file_name = argv[2];
    
    FILE* image_file = fopen(image_file_name, "rb+");
    FILE* message_file = fopen(message_file_name, "r");
    
    if (image_file == NULL || message_file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);
    
    unsigned char* image_buffer = malloc(sizeof(unsigned char) * image_size);
    size_t bytes_read = fread(image_buffer, sizeof(unsigned char), image_size, image_file);
    
    if (bytes_read != image_size) {
        printf("Error reading image file.\n");
        exit(1);
    }
    
    char message[1000];
    fgets(message, sizeof(message), message_file);
    hide_message(image_buffer, message);
    
    FILE* output_file = fopen("output.bmp", "wb");
    
    if (output_file == NULL) {
        printf("Error opening output file.\n");
        exit(1);
    }
    
    fwrite(image_buffer, sizeof(unsigned char), image_size, output_file);
    fclose(output_file);
    
    fseek(image_file, 0, SEEK_SET);
    bytes_read = fread(image_buffer, sizeof(unsigned char), image_size, image_file);
    
    if (bytes_read != image_size) {
        printf("Error reading image file.\n");
        exit(1);
    }
    
    char* extracted_message = extract_message(image_buffer);
    printf("Extracted message: %s\n", extracted_message);
    
    free(image_buffer);
    fclose(image_file);
    fclose(message_file);
    return 0;
}