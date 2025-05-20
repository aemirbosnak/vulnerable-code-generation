//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t byte;

void embed(char *filename, char *message) {
    FILE *image = fopen(filename, "rb+");
    if (image == NULL) {
        perror("fopen");
        return;
    }

    fseek(image, 0, SEEK_END);
    long length = ftell(image);
    rewind(image);

    byte *data = malloc(length);
    if (data == NULL) {
        perror("malloc");
        fclose(image);
        return;
    }

    fread(data, 1, length, image);

    int messageLength = strlen(message);
    if (length < messageLength + 1) {
        fprintf(stderr, "Error: Image too small to embed message.\n");
        free(data);
        fclose(image);
        return;
    }

    for (int i = 0; i < messageLength; i++) {
        data[i] |= (message[i] & 1);
    }

    fseek(image, 0, SEEK_SET);
    fwrite(data, 1, length, image);

    free(data);
    fclose(image);
}

void extract(char *filename) {
    FILE *image = fopen(filename, "rb");
    if (image == NULL) {
        perror("fopen");
        return;
    }

    fseek(image, 0, SEEK_END);
    long length = ftell(image);
    rewind(image);

    byte *data = malloc(length);
    if (data == NULL) {
        perror("malloc");
        fclose(image);
        return;
    }

    fread(data, 1, length, image);

    char *message = malloc(length / 2 + 1);
    if (message == NULL) {
        perror("malloc");
        free(data);
        fclose(image);
        return;
    }

    int j = 0;
    for (int i = 0; i < length; i++) {
        if (i % 2 == 0) {
            message[j++] = (data[i] & 1) + '0';
        }
    }

    message[j] = '\0';

    printf("%s\n", message);

    free(message);
    free(data);
    fclose(image);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s embed/extract image message\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "embed") == 0) {
        embed(argv[2], argv[3]);
    } else if (strcmp(argv[1], "extract") == 0) {
        extract(argv[2]);
    } else {
        fprintf(stderr, "Error: Invalid command.\n");
        return 1;
    }

    return 0;
}