//FormAI DATASET v1.0 Category: Image Steganography ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct BMP_Header{
    uint16_t signature;
    uint32_t file_size;
    uint32_t reserved;
    uint32_t data_offset;
    uint32_t header_size;
    uint32_t width;
    uint32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t data_size;
    uint32_t h_res;
    uint32_t v_res;
    uint32_t colors_used;
    uint32_t colors_important;
}BMP_Header;

int encode(const char* bmp_image_path, const char* message, const char* output_image_path);
int decode(const char* bmp_image_path);

int main(int argc, char* argv[]){
    if(argc != 4){
        printf("Usage: <program_name> <bmp_image_path> <secret_message> <output_image_path>");
        exit(EXIT_FAILURE);
    }
    
    const char* bmp_image_path = argv[1];
    const char* message = argv[2];
    const char* output_image_path = argv[3];
    
    int ret_val = encode(bmp_image_path, message, output_image_path);
    
    if(ret_val == EXIT_FAILURE){
        printf("Error! Could not encode the message.\n");
        exit(EXIT_FAILURE);
    }
    
    ret_val = decode(output_image_path);
    
    if(ret_val == EXIT_FAILURE){
        printf("Error! Could not decode the message.\n");
        exit(EXIT_FAILURE);
    }
    
    return 0;
}

int encode(const char* bmp_image_path, const char* message, const char* output_image_path){
    // Open BMP image
    FILE* bmp_file = fopen(bmp_image_path, "rb+");
    
    if(bmp_file == NULL){
        printf("Error! could not open the file.\n");
        return EXIT_FAILURE;
    }
    
    // Read the BMP header
    BMP_Header bmp_header;
    fread(&bmp_header, sizeof(BMP_Header), 1, bmp_file);
    
    // Validate the BMP header
    if(bmp_header.signature != 0x4D42){ // BMP signature
        printf("Error! The input file is not a BMP file.\n");
        return EXIT_FAILURE;
    }
    
    // Validate message length
    size_t message_length = strlen(message);
    size_t total_capacity = bmp_header.width * bmp_header.height * 3;
    if(message_length >= total_capacity){
        printf("Error! Message length too large to encode in this image.\n");
        return EXIT_FAILURE;
    }
    
    // Embed the secret message in the BMP image
    fseek(bmp_file, bmp_header.data_offset, SEEK_SET);
    for(size_t i=0; i<message_length; i++){
        char secret_char = message[i];
        for(int j=0; j<8; j++){
            uint8_t byte;
            fread(&byte, sizeof(uint8_t), 1, bmp_file);
            uint8_t bit = (secret_char >> (7-j)) & 0x01;
            if(bit){
                byte = byte | 0x01;
            }
            else{
                byte = byte & 0xFE;
            }
            fwrite(&byte, sizeof(uint8_t), 1, bmp_file);
        }
    }
    
    fclose(bmp_file);
    return EXIT_SUCCESS;
}

int decode(const char* bmp_image_path){
    // Open BMP image
    FILE* bmp_file = fopen(bmp_image_path, "rb");
    
    if(bmp_file == NULL){
        printf("Error! could not open the file.\n");
        return EXIT_FAILURE;
    }
    
    // Read the BMP header
    BMP_Header bmp_header;
    fread(&bmp_header, sizeof(BMP_Header), 1, bmp_file);
    
    // Validate the BMP header
    if(bmp_header.signature != 0x4D42){ // BMP signature
        printf("Error! The input file is not a BMP file.\n");
        return EXIT_FAILURE;
    }
    
    // Extract the secret message embedded in the BMP image
    fseek(bmp_file, bmp_header.data_offset, SEEK_SET);
    size_t message_length = bmp_header.width * bmp_header.height * 3 / 8;
    char* message = (char*)malloc((message_length + 1) * sizeof(char));
    message[message_length] = '\0';
    for(size_t i=0; i<message_length; i++){
        char secret_char;
        for(int j=0; j<8; j++){
            uint8_t byte;
            fread(&byte, sizeof(uint8_t), 1, bmp_file);
            secret_char = secret_char | ((byte & 0x01) << (7-j));
        }
        message[i] = secret_char;
    }
    
    printf("Secret message: %s\n", message);
    
    fclose(bmp_file);
    return EXIT_SUCCESS;
}