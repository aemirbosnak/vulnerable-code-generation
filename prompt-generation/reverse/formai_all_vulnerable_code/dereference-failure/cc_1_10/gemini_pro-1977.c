//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

image *read_image(char *filename) {
    FILE *fp;
    image *img;

    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    img = malloc(sizeof(image));
    if (!img) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    fread(&img->width, sizeof(int), 1, fp);
    fread(&img->height, sizeof(int), 1, fp);

    img->data = malloc(img->width * img->height * sizeof(pixel));
    if (!img->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        free(img);
        return NULL;
    }

    fread(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void write_image(char *filename, image *img) {
    FILE *fp;

    fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    fwrite(&img->width, sizeof(int), 1, fp);
    fwrite(&img->height, sizeof(int), 1, fp);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void hide_message(image *img, char *message) {
    int i, j, k;
    int message_length = strlen(message);

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < 3; k++) {
                if (i * img->width + j * 3 + k < message_length) {
                    img->data[i * img->width + j * 3 + k].red &= 0xFE;
                    img->data[i * img->width + j * 3 + k].red |= (message[i * img->width + j * 3 + k] & 1);
                }
            }
        }
    }
}

char *extract_message(image *img) {
    int i, j, k;
    int message_length = 0;
    char *message;

    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < 3; k++) {
                message_length += (img->data[i * img->width + j * 3 + k].red & 1);
            }
        }
    }

    message = malloc(message_length + 1);
    if (!message) {
        fprintf(stderr, "Error allocating memory for message\n");
        return NULL;
    }

    for (i = 0, k = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            for (k = 0; k < 3; k++) {
                if (i * img->width + j * 3 + k < message_length) {
                    message[i * img->width + j * 3 + k] = (img->data[i * img->width + j * 3 + k].red & 1);
                }
            }
        }
    }

    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    image *img;
    char *message;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image file> <message> <output file>\n", argv[0]);
        return 1;
    }

    img = read_image(argv[1]);
    if (!img) {
        return 1;
    }

    if (strlen(argv[2]) > img->width * img->height * 3) {
        fprintf(stderr, "Message too long\n");
        free(img);
        return 1;
    }

    hide_message(img, argv[2]);
    write_image(argv[3], img);

    free(img);
    return 0;
}