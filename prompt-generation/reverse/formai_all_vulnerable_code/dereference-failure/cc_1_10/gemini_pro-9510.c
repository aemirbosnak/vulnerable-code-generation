//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define MAX_MSG_SIZE 10000

typedef struct {
    uint8_t *data;
    size_t size;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    rewind(fp);

    uint8_t *data = malloc(size);
    if (!data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        fclose(fp);
        return NULL;
    }

    fread(data, 1, size, fp);
    fclose(fp);

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error allocating memory for image struct\n");
        free(data);
        return NULL;
    }

    image->data = data;
    image->size = size;

    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    fwrite(image->data, 1, image->size, fp);
    fclose(fp);
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

bool embed_message(Image *image, const char *msg) {
    if (strlen(msg) > MAX_MSG_SIZE) {
        fprintf(stderr, "Message too long: %d bytes (max: %d bytes)\n", strlen(msg), MAX_MSG_SIZE);
        return false;
    }

    size_t msg_size = strlen(msg);
    uint8_t *msg_data = (uint8_t *)msg;

    for (size_t i = 0; i < msg_size; i++) {
        for (size_t j = 0; j < 8; j++) {
            uint8_t bit = (msg_data[i] >> j) & 1;
            image->data[i * 8 + j] = (image->data[i * 8 + j] & ~1) | bit;
        }
    }

    return true;
}

char *extract_message(Image *image) {
    size_t msg_size = 0;
    for (size_t i = 0; i < image->size; i++) {
        if (image->data[i] & 1) {
            msg_size++;
        }
    }

    char *msg = malloc(msg_size + 1);
    if (!msg) {
        fprintf(stderr, "Error allocating memory for message\n");
        return NULL;
    }

    uint8_t *msg_data = (uint8_t *)msg;
    for (size_t i = 0, j = 0; i < image->size; i++) {
        if (image->data[i] & 1) {
            msg_data[j++] = (msg_data[j] << 1) | 1;
        } else {
            msg_data[j++] = msg_data[j] << 1;
        }
    }
    msg[msg_size] = '\0';

    return msg;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <input image> <message> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    if (embed_message(image, argv[2])) {
        write_image(argv[3], image);
        printf("Message embedded successfully\n");
    } else {
        printf("Error embedding message\n");
    }

    free_image(image);

    return 0;
}