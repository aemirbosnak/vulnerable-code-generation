//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef struct {
    uint8_t *data;
    size_t size;
} image_t;

typedef struct {
    char *message;
    size_t size;
} message_t;

image_t *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    uint8_t *data = malloc(size);
    if (!data) {
        fclose(file);
        return NULL;
    }

    fread(data, size, 1, file);
    fclose(file);

    image_t *image = malloc(sizeof(image_t));
    if (!image) {
        free(data);
        return NULL;
    }

    image->data = data;
    image->size = size;

    return image;
}

void free_image(image_t *image) {
    if (!image) {
        return;
    }

    free(image->data);
    free(image);
}

message_t *load_message(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    size_t size = ftell(file);
    rewind(file);

    char *message = malloc(size + 1);
    if (!message) {
        fclose(file);
        return NULL;
    }

    fread(message, size, 1, file);
    fclose(file);

    message[size] = '\0';

    message_t *message_struct = malloc(sizeof(message_t));
    if (!message_struct) {
        free(message);
        return NULL;
    }

    message_struct->message = message;
    message_struct->size = size;

    return message_struct;
}

void free_message(message_t *message) {
    if (!message) {
        return;
    }

    free(message->message);
    free(message);
}

void hide_message(image_t *image, message_t *message) {
    if (!image || !message) {
        return;
    }

    if (message->size > image->size) {
        return;
    }

    for (size_t i = 0; i < message->size; i++) {
        image->data[i] = (image->data[i] & 0xf8) | (message->message[i] & 0x07);
    }
}

message_t *extract_message(image_t *image) {
    if (!image) {
        return NULL;
    }

    size_t size = 0;
    while (size < image->size && (image->data[size] & 0x07) != 0) {
        size++;
    }

    char *message = malloc(size + 1);
    if (!message) {
        return NULL;
    }

    for (size_t i = 0; i < size; i++) {
        message[i] = image->data[i] & 0x07;
    }
    message[size] = '\0';

    message_t *message_struct = malloc(sizeof(message_t));
    if (!message_struct) {
        free(message);
        return NULL;
    }

    message_struct->message = message;
    message_struct->size = size;

    return message_struct;
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input image> <input message> <output image>\n", argv[0]);
        return 1;
    }

    image_t *image = load_image(argv[1]);
    if (!image) {
        printf("Error loading image\n");
        return 1;
    }

    message_t *message = load_message(argv[2]);
    if (!message) {
        printf("Error loading message\n");
        return 1;
    }

    hide_message(image, message);

    FILE *file = fopen(argv[3], "wb");
    if (!file) {
        printf("Error opening output image\n");
        return 1;
    }

    fwrite(image->data, image->size, 1, file);
    fclose(file);

    printf("Message hidden in image\n");

    message_t *extracted_message = extract_message(image);
    if (!extracted_message) {
        printf("Error extracting message\n");
        return 1;
    }

    printf("Extracted message: %s\n", extracted_message->message);

    free_message(extracted_message);
    free_message(message);
    free_image(image);

    return 0;
}