//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct image {
    int width;
    int height;
    char* pixels;
};

void encode_pixel(char* pixel, char message) {
    *pixel = (*pixel & 0xFE) | ((message >> 7) & 1);
    *pixel = (*pixel & 0xFD) | ((message >> 6) & 1);
    *pixel = (*pixel & 0xFB) | ((message >> 5) & 1);
    *pixel = (*pixel & 0xF7) | ((message >> 4) & 1);
    *pixel = (*pixel & 0xEF) | ((message >> 3) & 1);
    *pixel = (*pixel & 0xDF) | ((message >> 2) & 1);
    *pixel = (*pixel & 0xBF) | ((message >> 1) & 1);
    *pixel = (*pixel & 0x7F) | ((message     ) & 1);
}

char decode_pixel(char pixel) {
    char message = 0;
    message |= ((pixel     ) & 1) << 7;
    message |= ((pixel >> 1) & 1) << 6;
    message |= ((pixel >> 2) & 1) << 5;
    message |= ((pixel >> 3) & 1) << 4;
    message |= ((pixel >> 4) & 1) << 3;
    message |= ((pixel >> 5) & 1) << 2;
    message |= ((pixel >> 6) & 1) << 1;
    message |= ((pixel >> 7) & 1);
    return message;
}

char* read_file(char* filename) {
    char* buffer = NULL;
    long length;
    FILE* f = fopen (filename, "rb");
    if (f) {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer) {
            fread (buffer, 1, length, f);
        }
        fclose (f);
    }
    return buffer;
}

void write_file(char* filename, char* buffer, int length) {
    FILE* f = fopen (filename, "wb");
    if (f) {
        fwrite (buffer, 1, length, f);
        fclose (f);
    }
}

void encode_message(struct image* image, char* message) {
    int pixel_index = 0;
    int message_index = 0;
    while (message[message_index] != '\0') {
        if (pixel_index % 4 == 3) {
            pixel_index++;
        }
        if (pixel_index >= image->width * image->height * 3) {
            printf("Error: Image is too small for the message.\n");
            exit(1);
        }
        char* pixel = &(image->pixels[pixel_index]);
        encode_pixel(pixel, message[message_index]);
        pixel_index++;
        message_index++;
    }
    if (pixel_index % 4 != 0) {
        pixel_index += 4 - (pixel_index % 4);
    }
    if (pixel_index >= image->width * image->height * 3) {
        printf("Error: Image is too small for the message.\n");
        exit(1);
    }
    char* pixel = &(image->pixels[pixel_index]);
    encode_pixel(pixel, '\0');
}

char* decode_message(struct image* image) {
    int pixel_index = 0;
    int message_index = 0;
    char* message = malloc(1024);
    while (pixel_index < image->width * image->height * 3) {
        if (pixel_index % 4 == 3) {
            pixel_index++;
        }
        if (pixel_index >= image->width * image->height * 3) {
            printf("Error: Image is too small for the message.\n");
            exit(1);
        }
        char* pixel = &(image->pixels[pixel_index]);
        char c = decode_pixel(*pixel);
        pixel_index++;
        if (c == '\0') {
            break;
        }
        message[message_index] = c;
        message_index++;
        if (message_index >= 1024) {
            printf("Error: Message is too long.\n");
            exit(1);
        }
    }
    message[message_index] = '\0';
    return message;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: steganography encode <input file> <output file> <message>\n");
        printf("Usage: steganography decode <input file>\n");
        exit(1);
    }
    if (strcmp(argv[1], "encode") == 0) {
        char* image_data = read_file(argv[2]);
        if (image_data == NULL) {
            printf("Error: Could not open input file.\n");
            exit(1);
        }
        struct image image;
        image.width = 640;
        image.height = 480;
        image.pixels = image_data;
        encode_message(&image, argv[3]);
        write_file(argv[2], image.pixels, image.width * image.height * 3);
    } else if (strcmp(argv[1], "decode") == 0) {
        char* image_data = read_file(argv[2]);
        if (image_data == NULL) {
            printf("Error: Could not open input file.\n");
            exit(1);
        }
        struct image image;
        image.width = 640;
        image.height = 480;
        image.pixels = image_data;
        char* message = decode_message(&image);
        printf("%s\n", message);
    } else {
        printf("Usage: steganography encode <input file> <output file> <message>\n");
        printf("Usage: steganography decode <input file>\n");
        exit(1);
    }
    return 0;
}