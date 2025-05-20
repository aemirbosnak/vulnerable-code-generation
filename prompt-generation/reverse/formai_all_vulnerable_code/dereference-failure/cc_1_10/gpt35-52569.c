//FormAI DATASET v1.0 Category: Image Steganography ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define BMP_HEADER_SIZE 54
#define MAX_SIZE 1000000

uint8_t* read_bmp(char* file_name, uint32_t* width, uint32_t* height) {
    FILE* f = fopen(file_name, "rb");
    if(f == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", file_name);
        return NULL;
    }

    uint8_t header[BMP_HEADER_SIZE];
    if(fread(header, 1, BMP_HEADER_SIZE, f) != BMP_HEADER_SIZE) {
        fprintf(stderr, "Error: could not read header from file %s\n", file_name);
        fclose(f);
        return NULL;
    }

    if(header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file %s is not a BMP file\n", file_name);
        fclose(f);
        return NULL;
    }

    uint32_t data_start = *(uint32_t*)(&header[10]);
    *width = *(uint32_t*)(&header[18]);
    *height = *(uint32_t*)(&header[22]);

    uint8_t* data = (uint8_t*)malloc(MAX_SIZE * sizeof(uint8_t));
    uint32_t size = (*width) * (*height) * 3;
    if(fread(data, 1, size, f) != size) {
        fprintf(stderr, "Error: could not read data from file %s\n", file_name);
        fclose(f);
        free(data);
        return NULL;
    }

    fclose(f);
    return data;
}

int write_bmp(char* file_name, uint8_t* data, uint32_t width, uint32_t height) {
    FILE* f = fopen(file_name, "wb");
    if(f == NULL) {
        fprintf(stderr, "Error: could not open file %s\n", file_name);
        return -1;
    }

    uint8_t header[BMP_HEADER_SIZE];
    memset(header, 0, BMP_HEADER_SIZE);
    header[0] = 'B';
    header[1] = 'M';
    *(uint32_t*)(&header[2]) = BMP_HEADER_SIZE + width * height * 3;
    *(uint32_t*)(&header[10]) = BMP_HEADER_SIZE;
    *(uint32_t*)(&header[14]) = BMP_HEADER_SIZE - 14;
    *(uint32_t*)(&header[18]) = width;
    *(uint32_t*)(&header[22]) = height;
    *(uint16_t*)(&header[26]) = 1;
    *(uint16_t*)(&header[28]) = 24;
    if(fwrite(header, 1, BMP_HEADER_SIZE, f) != BMP_HEADER_SIZE) {
        fprintf(stderr, "Error: could not write header to file %s\n", file_name);
        fclose(f);
        return -1;
    }
    
    uint32_t size = width * height * 3;
    if(fwrite(data, 1, size, f) != size) {
        fprintf(stderr, "Error: could not write data to file %s\n", file_name);
        fclose(f);
        return -1;
    }

    fclose(f);
    return 0;
}

void encode(char* file_name, char* message) {
    uint32_t width, height;
    uint8_t* data = read_bmp(file_name, &width, &height);

    uint32_t offset = BMP_HEADER_SIZE;
    uint32_t size = width * height * 3;
    uint32_t message_size = strlen(message);
    if(message_size * 8 > size) {
        fprintf(stderr, "Error: message is too large to encode in image %s\n", file_name);
        free(data);
        return;
    }

    for(int i = 0; i < message_size; i++) {
        for(int j = 0; j < 8; j++) {
            uint8_t bit = (message[i] >> j) & 1;
            data[offset] = (data[offset] & 0xFE) | bit;
            offset++;
        }
    }

    write_bmp("encoded.bmp", data, width, height);
    free(data);
    printf("Message encoded successfully!\n");
}

void decode(char* file_name) {
    uint32_t width, height;
    uint8_t* data = read_bmp(file_name, &width, &height);

    uint32_t offset = BMP_HEADER_SIZE;
    uint8_t message[MAX_SIZE];
    memset(message, 0, MAX_SIZE);
    int message_size = 0;

    while(offset < width * height * 3 + BMP_HEADER_SIZE) {
        uint8_t byte = 0;
        for(int j = 0; j < 8; j++) {
            byte |= (data[offset] & 1) << j;
            offset++;
        }
        if(byte == 0) break;
        message[message_size++] = byte;
    }

    printf("Decoded message: %s\n", message);
    free(data);
}

int main(int argc, char* argv[]) {
    if(argc < 2) {
        fprintf(stderr, "Usage: %s <encode|decode> [file] [message]\n", argv[0]);
        return 1;
    }

    if(strcmp(argv[1], "encode") == 0) {
        if(argc < 4) {
            fprintf(stderr, "Usage: %s encode <file> <message>\n", argv[0]);
            return 1;
        }
        encode(argv[2], argv[3]);
    } else if(strcmp(argv[1], "decode") == 0) {
        if(argc < 3) {
            fprintf(stderr, "Usage: %s decode <file>\n", argv[0]);
            return 1;
        }
        decode(argv[2]);
    } else {
        fprintf(stderr, "Unknown operation: %s\n", argv[1]);
        return 1;
    }

    return 0;
}