//FormAI DATASET v1.0 Category: Image Steganography ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hide_message_in_image(char* message, char* image_path, char* output_path) {
    FILE *image, *output;
    image = fopen(image_path, "rb");
    output = fopen(output_path, "wb");

    if (image == NULL || output == NULL) {
        printf("Error opening files!");
        exit(1);
    }

    long int message_length = strlen(message);
    fseek(image, 0, SEEK_END);
    long int image_size = ftell(image);
    rewind(image);

    char data[image_size];
    fread(data, image_size, 1, image);

    for (long int i = 0; i < message_length; i++) {
        long int pos = (i * 8) + 54;
        char ch = message[i];
        for (int j = 0; j < 8; j++) {
            char bit = (ch >> j) & 1;
            if (bit == 1 && (data[pos] & 1) == 0) {
                data[pos] |= 1;
            } else if (bit == 0 && (data[pos] & 1) == 1) {
                data[pos] &= ~1;
            }
            pos += 3;
        }
    }

    fwrite(data, image_size, 1, output);
    fclose(image);
    fclose(output);
}

char* reveal_message_in_image(char* image_path) {
    FILE *image;
    image = fopen(image_path, "rb");

    if (image == NULL) {
        printf("Error opening file!");
        exit(1);
    }

    fseek(image, 0, SEEK_END);
    long int image_size = ftell(image);
    rewind(image);

    char data[image_size];
    fread(data, image_size, 1, image);

    char* message = (char*) malloc(image_size/8);

    long int pos = 54;
    long int bit_pos = 0;

    while (1) {
        if (bit_pos == 8) {
            bit_pos = 0;
            pos += 3;
        }
        if (pos > image_size) {
            break;
        }
        if ((data[pos] & 1) == 1) {
            message[pos/8] |= (1 << bit_pos);
        } else {
            message[pos/8] &= ~(1 << bit_pos);
        }
        bit_pos++;
    }

    return message;
}

int main() {
    char message[] = "hello world";
    char image_path[] = "image.bmp";
    char output_path[] = "output.bmp";

    printf("Hiding message: %s\n", message);
    hide_message_in_image(message, image_path, output_path);

    printf("Revealing message...\n");
    char* revealed_message = reveal_message_in_image(output_path);
    printf("Message revealed: %s\n", revealed_message);

    return 0;
}