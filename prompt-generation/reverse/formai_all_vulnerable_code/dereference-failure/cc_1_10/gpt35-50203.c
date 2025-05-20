//FormAI DATASET v1.0 Category: Image Steganography ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

#define BMP_HEADER_SIZE 54

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
    unsigned char alpha;
} pixel;

typedef struct {
    unsigned int width;
    unsigned int height;
    pixel *data;
} image;

void write_image(image im, char* filename) {
    FILE *fp;
    if((fp = fopen(filename, "wb")) == NULL) {
        perror("Error opening file");
        exit(1);
    }
    unsigned char bmp_header[BMP_HEADER_SIZE] = {
        0x42, 0x4D, // BM
        0x36, 0x00, 0x0C, 0x00, // Size of BMP file
        0x00, 0x00, // Reserved
        0x00, 0x00, // Reserved
        0x36, 0x00, 0x00, 0x00, // Pixel data offset
        0x28, 0x00, 0x00, 0x00, // Header size
        0x00, 0x00, 0x02, 0x00, // Width
        0x00, 0x00, 0x02, 0x00, // Height
        0x01, 0x00, // Number of color planes
        0x20, 0x00, // Bits per pixel (RGB)
        0x00, 0x00, 0x00, 0x10, // Compression (not compressed)
        0x00, 0x00, 0x00, 0x00, // Size of pixel data
        0x00, 0x00, 0x00, 0x00, // Horizontal resolution
        0x00, 0x00, 0x00, 0x00, // Vertical resolution
        0x00, 0x00, 0x00, 0x00, // Number of colors in color pallette
        0x00, 0x00, 0x00, 0x00 // Number of important colors
    };
    unsigned int padded_row_size = (im.width * 3 + 3) & (~3);
    unsigned int bmp_file_size = BMP_HEADER_SIZE + padded_row_size * im.height;
    bmp_header[2] = (unsigned char) bmp_file_size;
    bmp_header[3] = (unsigned char) (bmp_file_size >> 8);
    bmp_header[4] = (unsigned char) (bmp_file_size >> 16);
    fwrite(bmp_header, sizeof(unsigned char), BMP_HEADER_SIZE, fp);
    unsigned char padding[3] = {0, 0, 0};
    for(unsigned int y = 0; y < im.height; y++) {
        for(unsigned int x = 0; x < im.width; x++) {
            pixel p = im.data[y * im.width + x];
            fwrite(&p.blue, sizeof(unsigned char), 1, fp);
            fwrite(&p.green, sizeof(unsigned char), 1, fp);
            fwrite(&p.red, sizeof(unsigned char), 1, fp);
        }
        fwrite(padding, sizeof(unsigned char), padded_row_size - im.width * 3, fp);
    }
    fclose(fp);
}

image read_image(char* filename) {
    FILE *fp;
    if((fp = fopen(filename, "rb")) == NULL) {
        perror("Error opening file");
        exit(1);
    }
    unsigned char bmp_header[BMP_HEADER_SIZE];
    if(fread(bmp_header, sizeof(unsigned char), BMP_HEADER_SIZE, fp) < BMP_HEADER_SIZE) { // BMP header is 54 bytes
        perror("Error reading BMP header");
        exit(1);
    }
    unsigned int width = *((unsigned int*)&(bmp_header[18]));
    unsigned int height = *((unsigned int*)&(bmp_header[22]));
    pixel *data = (pixel*) malloc(width * height * sizeof(pixel));
    unsigned int padded_row_size = (width * 3 + 3) & (~3);
    unsigned char padding[3];
    for(unsigned int y = 0; y < height; y++) {
        for(unsigned int x = 0; x < width; x++) {
            fread(&data[y * width + x], sizeof(pixel), 1, fp);
        }
        fread(padding, sizeof(unsigned char), padded_row_size - width * 3, fp);
    }
    image im = {width, height, data};
    fclose(fp);
    return im;
}

void hide_message(image *im, char* message) {
    unsigned int message_length = strlen(message);
    unsigned int bit_index = 0;
    for(unsigned int i = 0; i < message_length; i++) {
        char c = message[i]; // Read the next character in the message
        for(int j = 0; j < 8; j++) {
            if(bit_index >= im->width * im->height * 3) return; // Make sure the image is large enough to hold the entire message
            pixel p = im->data[bit_index / 3];
            switch(bit_index % 3) {
                case 0:
                    p.blue = (p.blue & 0xFE) | ((c >> j) & 1); // Mask off last bit, then set it to next bit in the message
                    break;
                case 1:
                    p.green = (p.green & 0xFE) | ((c >> j) & 1);
                    break;
                case 2:
                    p.red = (p.red & 0xFE) | ((c >> j) & 1);
                    break;
            }
            im->data[bit_index / 3] = p;
            bit_index++;
        }
    }
}

void reveal_message(image im) {
    unsigned int bit_index = 0;
    char message[256] = {0};
    char current_byte = 0;
    int bits_seen = 0;
    while(1) {
        if(bit_index >= im.width * im.height * 3) return;
        pixel p = im.data[bit_index / 3];
        switch(bit_index % 3) {
            case 0:
                current_byte |= (p.blue & 1) << bits_seen; // Add the last bit to the current byte
                break;
            case 1:
                current_byte |= (p.green & 1) << bits_seen;
                break;
            case 2:
                current_byte |= (p.red & 1) << bits_seen;
                break;
        }
        bits_seen++;
        if(bits_seen == 8) { // If we've seen 8 bits, we've grabbed a whole byte
            bits_seen = 0;
            message[strlen(message)] = current_byte;
            if(current_byte == '\0') { // If the current byte is null, we've reached the end of the message
                printf("The message is: %s\n", message);
                return;
            }
            current_byte = 0; // Zero the current byte for the next 8 bits
        }
        bit_index++;
    }
}

int main() {
    image im = read_image("test.bmp");
    char message[] = "This is a secret message!";
    hide_message(&im, message);
    write_image(im, "hidden.bmp");
    image hidden_im = read_image("hidden.bmp");
    reveal_message(hidden_im);
    return 0;
}