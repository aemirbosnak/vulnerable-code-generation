//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1000000

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

pixel image[MAX_IMAGE_SIZE];
int image_size;

void load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fread(&image_size, sizeof(int), 1, fp);
    fread(image, sizeof(pixel), image_size, fp);

    fclose(fp);
}

void save_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    fwrite(&image_size, sizeof(int), 1, fp);
    fwrite(image, sizeof(pixel), image_size, fp);

    fclose(fp);
}

void hide_message(char *message) {
    int message_length = strlen(message);
    int message_index = 0;

    for (int i = 0; i < image_size; i++) {
        if (message_index >= message_length) {
            break;
        }

        image[i].red &= 0xfe;
        image[i].red |= (message[message_index] >> 7) & 0x01;

        image[i].green &= 0xfe;
        image[i].green |= (message[message_index] >> 6) & 0x01;

        image[i].blue &= 0xfe;
        image[i].blue |= (message[message_index] >> 5) & 0x01;

        message_index++;
    }
}

char *extract_message() {
    int message_length = 0;
    char *message = malloc(1);

    for (int i = 0; i < image_size; i++) {
        message_length++;
        message = realloc(message, message_length + 1);

        message[message_length - 1] = (image[i].red & 0x01) << 7;
        message[message_length - 1] |= (image[i].green & 0x01) << 6;
        message[message_length - 1] |= (image[i].blue & 0x01) << 5;

        if (message[message_length - 1] == '\0') {
            break;
        }
    }

    return message;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <image> <message> <output>\n", argv[0]);
        return 1;
    }

    load_image(argv[1]);
    hide_message(argv[2]);
    save_image(argv[3]);

    return 0;
}