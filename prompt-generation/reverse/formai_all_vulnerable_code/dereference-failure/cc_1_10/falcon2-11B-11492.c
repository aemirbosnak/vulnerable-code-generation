//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX_MESSAGE_LENGTH 100

typedef struct {
    uint8_t* image;
    int width;
    int height;
} Image;

void read_image(const char* filename, Image* image) {
    FILE* file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    image->image = (uint8_t*)malloc(file_size);
    fread(image->image, file_size, 1, file);

    fclose(file);
    image->width = WIDTH;
    image->height = HEIGHT;
}

void write_image(const char* filename, Image* image) {
    FILE* file = fopen(filename, "wb");
    fwrite(image->image, image->width * image->height, 1, file);
    fclose(file);
}

void hide_message(const char* filename_in, const char* filename_out, const char* message) {
    Image image;
    read_image(filename_in, &image);

    uint8_t* message_bytes = (uint8_t*)malloc(strlen(message) + 1);
    strcpy(message_bytes, message);

    int message_length = strlen(message);
    int message_index = 0;
    for (int i = 0; i < image.width * image.height; i++) {
        uint8_t pixel = image.image[i];
        if (pixel!= 0) {
            pixel = pixel ^ message_bytes[message_index++];
        }
        image.image[i] = pixel;
    }

    write_image(filename_out, &image);
    free(message_bytes);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return 1;
    }

    hide_message(argv[1], argv[2], argv[3]);
    return 0;
}