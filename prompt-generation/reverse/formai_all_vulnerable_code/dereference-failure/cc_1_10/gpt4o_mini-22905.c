//GPT-4o-mini DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(push, 1) 
typedef struct {
    unsigned short bfType; 
    unsigned int bfSize; 
    unsigned short bfReserved1; 
    unsigned short bfReserved2; 
    unsigned int bfOffBits; 
} BMPHeader;

typedef struct {
    unsigned int biSize; 
    int biWidth; 
    int biHeight; 
    unsigned short biPlanes; 
    unsigned short biBitCount; 
    unsigned int biCompression; 
    unsigned int biSizeImage; 
    int biXPelsPerMeter; 
    int biYPelsPerMeter; 
    unsigned int biClrUsed; 
    unsigned int biClrImportant; 
} BMPInfoHeader;

#pragma pack(pop) 

void encodeMessage(char *message, FILE *image) {
    fseek(image, sizeof(BMPHeader) + sizeof(BMPInfoHeader), SEEK_SET);
    
    unsigned char pixel[3];
    for (int i = 0; message[i] != '\0'; i++) {
        fread(pixel, sizeof(unsigned char), 3, image);
        pixel[0] = (pixel[0] & 0xFE) | ((message[i] >> 7) & 0x01); 
        pixel[1] = (pixel[1] & 0xFE) | ((message[i] >> 6) & 0x01); 
        pixel[2] = (pixel[2] & 0xFE) | ((message[i] >> 5) & 0x01); 
        fseek(image, -3, SEEK_CUR); 
        fwrite(pixel, sizeof(unsigned char), 3, image);
    }
    // Indicate end of message
    fread(pixel, sizeof(unsigned char), 3, image);
    pixel[0] = (pixel[0] & 0xFE) | 0x00; 
    fseek(image, -3, SEEK_CUR);
    fwrite(pixel, sizeof(unsigned char), 3, image);
}

void decodeMessage(FILE *image) {
    fseek(image, sizeof(BMPHeader) + sizeof(BMPInfoHeader), SEEK_SET);
    
    unsigned char pixel[3];
    char message[256];
    int index = 0, ch = 0;

    while (1) {
        fread(pixel, sizeof(unsigned char), 3, image);
        if (feof(image)) break;
        ch = (ch << 1) | (pixel[0] & 0x01);
        if (index % 8 == 7) {
            if (ch == 0) break; 
            message[index / 8] = ch;
            index++;
            ch = 0;
        }
        index++;
    }
    message[index / 8] = '\0'; 
    printf("Decoded message: %s\n", message);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <encode/decode> <image.bmp> <message (if encoding)>\n", argv[0]);
        return 1;
    }

    FILE *image = fopen(argv[2], "r+b");
    if (!image) {
        perror("Unable to open image file");
        return 1;
    }
    
    if (strcmp(argv[1], "encode") == 0) {
        encodeMessage(argv[3], image);
        printf("Message encoded successfully!\n");
    } else if (strcmp(argv[1], "decode") == 0) {
        decodeMessage(image);
    } else {
        printf("Invalid mode. Use 'encode' or 'decode'.\n");
    }

    fclose(image);
    return 0;
}