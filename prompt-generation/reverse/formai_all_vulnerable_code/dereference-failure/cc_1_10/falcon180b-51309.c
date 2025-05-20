//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of image

typedef struct {
    char *filename;
    unsigned char *data;
    int size;
} image_t;

void read_image(image_t *img) {
    FILE *fp = fopen(img->filename, "rb");
    fseek(fp, 0, SEEK_END);
    img->size = ftell(fp);
    rewind(fp);
    img->data = malloc(img->size);
    fread(img->data, img->size, 1, fp);
    fclose(fp);
}

void write_image(image_t *img) {
    FILE *fp = fopen(img->filename, "wb");
    fwrite(img->data, img->size, 1, fp);
    fclose(fp);
}

void hide_message(image_t *img, char *message) {
    int message_size = strlen(message);
    int offset = 0;
    while (offset < img->size - message_size) {
        int i;
        for (i = 0; i < message_size; i++) {
            img->data[offset + i] ^= message[i];
        }
        offset += message_size;
    }
}

void reveal_message(image_t *img, char *message) {
    int message_size = strlen(message);
    int offset = 0;
    while (offset < img->size - message_size) {
        int i;
        for (i = 0; i < message_size; i++) {
            img->data[offset + i] ^= message[i];
        }
        offset += message_size;
    }
}

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <image_file> <hide|reveal> <message>\n", argv[0]);
        return 1;
    }

    image_t img;
    img.filename = argv[1];
    read_image(&img);

    char *mode = argv[2];
    if (strcmp(mode, "hide") == 0) {
        char *message = argv[3];
        hide_message(&img, message);
        write_image(&img);
        printf("Message hidden in image.\n");
    } else if (strcmp(mode, "reveal") == 0) {
        char *message = argv[3];
        reveal_message(&img, message);
        write_image(&img);
        printf("Message revealed in image.\n");
    } else {
        printf("Invalid mode.\n");
        return 1;
    }

    free(img.data);
    return 0;
}