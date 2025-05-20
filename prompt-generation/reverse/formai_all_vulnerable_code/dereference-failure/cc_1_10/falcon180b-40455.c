//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512
#define IMAGE_SIZE (IMAGE_WIDTH * IMAGE_HEIGHT)
#define MAX_MESSAGE_SIZE (IMAGE_SIZE / 8)

typedef struct {
    char* filename;
    unsigned char* data;
    int width;
    int height;
} Image;

void read_image(Image* image) {
    FILE* fp = fopen(image->filename, "rb");
    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    image->data = (unsigned char*)malloc(filesize);
    fread(image->data, filesize, 1, fp);

    fclose(fp);

    image->width = IMAGE_WIDTH;
    image->height = IMAGE_HEIGHT;
}

void write_image(Image* image) {
    FILE* fp = fopen(image->filename, "wb");
    fwrite(image->data, IMAGE_SIZE, 1, fp);
    fclose(fp);
}

void hide_message(Image* image, char* message) {
    int message_size = strlen(message);

    if (message_size > MAX_MESSAGE_SIZE) {
        printf("Message is too long.\n");
        return;
    }

    int index = 0;
    int row = 0;
    int col = 0;

    while (index < message_size) {
        row = (int)floor(index / IMAGE_WIDTH);
        col = index % IMAGE_WIDTH;

        int pixel_value = image->data[(row * IMAGE_WIDTH + col) * 3];
        int message_bit = message[index] - 'A';

        if (message_bit == 1) {
            pixel_value += 5;
        }

        image->data[(row * IMAGE_WIDTH + col) * 3] = pixel_value;

        index++;
    }
}

void reveal_message(Image* image) {
    int row = 0;
    int col = 0;
    int index = 0;

    while (index < MAX_MESSAGE_SIZE) {
        row = (int)floor(index / IMAGE_WIDTH);
        col = index % IMAGE_WIDTH;

        int pixel_value = image->data[(row * IMAGE_WIDTH + col) * 3];

        if (pixel_value >= 5) {
            printf("%c", 'A' + index % 26);
        }

        index++;
    }
}

int main() {
    srand(time(0));

    Image image;
    image.filename = "test.bmp";
    read_image(&image);

    char* message = "Hello, World!";
    hide_message(&image, message);

    write_image(&image);

    reveal_message(&image);

    free(image.data);

    return 0;
}