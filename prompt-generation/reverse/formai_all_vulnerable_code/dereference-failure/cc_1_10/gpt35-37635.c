//FormAI DATASET v1.0 Category: Image Steganography ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Header {
    unsigned char signature[2];  // signature which is 'BM'
    unsigned int size;           // file size
    unsigned short int reserve1, reserve2;
    unsigned int offset;         // offset of image data
};

struct Image {
    struct Header header;
    unsigned int width, height, size;   
    unsigned char *pixels;      // image pixels
};

// define a helper function to read BMP image from file
struct Image read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Image %s not found!\n", filename);
        exit(1);
    }

    struct Image image;
    fread(&image.header, sizeof(image.header), 1, fp);
    if (image.header.signature[0] != 'B' || image.header.signature[1] != 'M') {
        printf("Image %s is not a BMP file!\n", filename);
        exit(1);
    }

    fread(&image.width, 4, 1, fp);
    fread(&image.height, 4, 1, fp);
    image.size = image.width * image.height * 3;  // 3 bytes per pixel in BMP file

    image.pixels = (unsigned char*) malloc(image.size);
    fseek(fp, image.header.offset, SEEK_SET);
    fread(image.pixels, image.size, 1, fp);
    fclose(fp);

    return image;
}

// define a helper function to write BMP image to file
void write_image(char* filename, struct Image image) { 
    FILE *fp = fopen(filename, "wb");
    fwrite(&image.header, sizeof(image.header), 1, fp);
    fwrite(&image.width, 4, 1, fp);
    fwrite(&image.height, 4, 1, fp);
    fseek(fp, image.header.offset, SEEK_SET);
    fwrite(image.pixels, image.size, 1, fp);
    fclose(fp);
}

// define a function to hide a message in the image
struct Image hide_message(struct Image image, char *message) {
    int len = strlen(message);
    unsigned char *msg = (unsigned char*)message;  // convert the message to unsigned char* for bitwise operation

    // hide message in least significant bit of the blue channel of each pixel
    for (int i = 0; i < image.size; i++) {
        image.pixels[i] = (image.pixels[i] & 0xFE) | ((msg[i % len] >> 7) & 1);
        msg[i % len] <<= 1;
    }

    return image;
}

// define a function to extract the hidden message from the image
char* extract_message(struct Image image, int len) {
    unsigned char *msg = (unsigned char*) malloc(len + 1);  // reserve space for null terminator
    char ch;
    int offset = image.header.offset;

    // extract message from least significant bit of the blue channel of each pixel
    for (int i = 0; i < len; i++) {
        ch = 0;
        for (int j = 0; j < 8; j++) {
            ch |= (image.pixels[offset] & 1) << j;
            offset += 3;  // skip red and green channels
        }
        msg[i] = ch;
    }
    msg[len] = '\0';

    return (char*)msg;
}

int main() {
    char *filename = "beach.bmp";
    char *message = "Hello, this is a secret message!";

    struct Image image = read_image(filename);
    image = hide_message(image, message);
    write_image("hidden.bmp", image);

    struct Image new_image = read_image("hidden.bmp");
    char *extracted_msg = extract_message(new_image, strlen(message));
    printf("%s\n", extracted_msg);

    return 0;
}