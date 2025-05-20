//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_WIDTH 512
#define IMAGE_HEIGHT 512

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel_t;

typedef struct {
    int width;
    int height;
    pixel_t *data;
} image_t;

image_t *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("Error opening file");
        return NULL;
    }

    image_t *image = malloc(sizeof(image_t));
    if (image == NULL) {
        perror("Error allocating memory for image");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->data = malloc(sizeof(pixel_t) * image->width * image->height);
    if (image->data == NULL) {
        perror("Error allocating memory for image data");
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->data, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void write_image(char *filename, image_t *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->data, sizeof(pixel_t), image->width * image->height, fp);
    fclose(fp);
}

void hide_message(image_t *image, char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        if (message_index >= message_length) {
            break;
        }

        unsigned char c = message[message_index];
        image->data[i].r &= 0xfe;
        image->data[i].r |= c >> 7;
        image->data[i].g &= 0xfe;
        image->data[i].g |= (c >> 6) & 1;
        image->data[i].b &= 0xfe;
        image->data[i].b |= (c >> 5) & 1;
        message_index++;
    }
}

char *extract_message(image_t *image) {
    char *message = malloc(sizeof(char) * (image->width * image->height) / 3);
    if (message == NULL) {
        perror("Error allocating memory for message");
        return NULL;
    }

    int message_index = 0;

    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char c = (image->data[i].r & 1) << 7;
        c |= (image->data[i].g & 1) << 6;
        c |= (image->data[i].b & 1) << 5;
        message[message_index] = c;
        message_index++;
    }

    message[message_index] = '\0';
    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <message> <output_image>\n", argv[0]);
        return 1;
    }

    image_t *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    hide_message(image, argv[2]);

    write_image(argv[3], image);

    free(image->data);
    free(image);

    return 0;
}