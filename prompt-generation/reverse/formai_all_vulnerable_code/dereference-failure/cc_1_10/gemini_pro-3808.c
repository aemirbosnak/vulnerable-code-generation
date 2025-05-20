//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: modular
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    size_t size;
} Image;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    unsigned char *data = malloc(size);
    if (!data) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(file);
        return NULL;
    }

    fread(data, 1, size, file);
    fclose(file);

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        free(data);
        return NULL;
    }

    image->data = data;
    image->size = size;

    return image;
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void hide_message(Image *image, const char *message) {
    size_t message_size = strlen(message);

    if (image->size < message_size) {
        fprintf(stderr, "Error: image is too small to hide message\n");
        return;
    }

    for (size_t i = 0; i < message_size; i++) {
        image->data[i] = image->data[i] & 0b11111110 | (message[i] & 0b00000001);
    }
}

char *extract_message(Image *image) {
    size_t message_size = image->size;

    for (size_t i = 0; i < message_size; i++) {
        if ((image->data[i] & 0b00000001) != 0) {
            message_size = i;
            break;
        }
    }

    char *message = malloc(message_size + 1);
    if (!message) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        return NULL;
    }

    for (size_t i = 0; i < message_size; i++) {
        message[i] = image->data[i] & 0b00000001;
    }

    message[message_size] = '\0';

    return message;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <message>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return EXIT_FAILURE;
    }

    hide_message(image, argv[3]);

    FILE *file = fopen(argv[2], "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", argv[2]);
        free_image(image);
        return EXIT_FAILURE;
    }

    fwrite(image->data, 1, image->size, file);
    fclose(file);

    free_image(image);

    return EXIT_SUCCESS;
}