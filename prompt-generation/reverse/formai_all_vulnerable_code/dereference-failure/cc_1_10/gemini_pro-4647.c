//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    size_t size;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    size_t size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    if (data == NULL) {
        perror("malloc");
        fclose(fp);
        return NULL;
    }

    if (fread(data, 1, size, fp) != size) {
        perror("fread");
        free(data);
        fclose(fp);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        perror("malloc");
        free(data);
        fclose(fp);
        return NULL;
    }

    image->data = data;
    image->size = size;

    fclose(fp);

    return image;
}

void write_image(const char *filename, const Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        return;
    }

    if (fwrite(image->data, 1, image->size, fp) != image->size) {
        perror("fwrite");
        fclose(fp);
        return;
    }

    fclose(fp);
}

Image *hide_message(const Image *image, const char *message) {
    size_t message_size = strlen(message) + 1;
    if (image->size < message_size) {
        fprintf(stderr, "Error: Image size is too small to hide message.\n");
        return NULL;
    }

    Image *new_image = malloc(sizeof(Image));
    if (new_image == NULL) {
        perror("malloc");
        return NULL;
    }

    new_image->data = malloc(image->size);
    if (new_image->data == NULL) {
        perror("malloc");
        free(new_image);
        return NULL;
    }

    memcpy(new_image->data, image->data, image->size);

    for (size_t i = 0; i < message_size; i++) {
        new_image->data[i] |= (message[i] >> 1);
    }

    new_image->size = image->size;

    return new_image;
}

char *extract_message(const Image *image) {
    size_t message_length = 0;
    for (size_t i = 0; i < image->size; i++) {
        if ((image->data[i] & 1) == 0) {
            message_length++;
        } else {
            break;
        }
    }

    char *message = malloc(message_length + 1);
    if (message == NULL) {
        perror("malloc");
        return NULL;
    }

    for (size_t i = 0; i < message_length; i++) {
        message[i] = (image->data[i] >> 1) & 0xff;
    }
    message[message_length] = '\0';

    return message;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <message> <output image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        fprintf(stderr, "Error: Could not read input image.\n");
        return EXIT_FAILURE;
    }

    Image *new_image = hide_message(image, argv[2]);
    if (new_image == NULL) {
        fprintf(stderr, "Error: Could not hide message in image.\n");
        free(image);
        return EXIT_FAILURE;
    }

    write_image(argv[3], new_image);

    free(image);
    free(new_image);

    return EXIT_SUCCESS;
}