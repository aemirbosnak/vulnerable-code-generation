//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_IMAGE_SIZE 1000000
#define MAX_MESSAGE_SIZE 1000

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

typedef struct {
    char *message;
    int length;
} Message;

Image *read_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(fp);
        return NULL;
    }

    fseek(fp, 0, SEEK_END);
    image->data = malloc(ftell(fp));
    if (image->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        free(image);
        return NULL;
    }

    fseek(fp, 0, SEEK_SET);
    fread(image->data, 1, ftell(fp), fp);
    fclose(fp);

    return image;
}

void write_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return;
    }

    fwrite(image->data, 1, image->width * image->height * 3, fp);
    fclose(fp);
}

Message *read_message(Image *image) {
    int i = 0;
    while (image->data[i] != '\0') {
        i++;
    }

    Message *message = malloc(sizeof(Message));
    if (message == NULL) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        return NULL;
    }

    message->message = malloc(i + 1);
    if (message->message == NULL) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        free(message);
        return NULL;
    }

    memcpy(message->message, image->data + i, i);
    message->message[i] = '\0';
    message->length = i;

    return message;
}

void write_message(Image *image, Message *message) {
    int i = 0;
    while (image->data[i] != '\0') {
        i++;
    }

    memcpy(image->data + i, message->message, message->length);
    image->data[i + message->length] = '\0';
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input image> <output image> <message>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return 1;
    }

    Message *message = malloc(sizeof(Message));
    if (message == NULL) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        free(image);
        return 1;
    }

    message->message = argv[3];
    message->length = strlen(argv[3]);

    if (message->length > MAX_MESSAGE_SIZE) {
        fprintf(stderr, "Error: message is too long\n");
        free(image);
        free(message);
        return 1;
    }

    write_message(image, message);
    write_image(image, argv[2]);

    free(image->data);
    free(image);
    free(message->message);
    free(message);

    return 0;
}