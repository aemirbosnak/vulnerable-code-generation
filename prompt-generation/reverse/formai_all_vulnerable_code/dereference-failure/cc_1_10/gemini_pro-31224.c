//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_LEN 10000
#define MAX_IMAGE_SIZE 1000000

unsigned char *image;
int image_size;

void load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    fseek(fp, 0, SEEK_END);
    image_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    image = malloc(image_size);
    if (image == NULL) {
        perror("malloc");
        exit(1);
    }
    fread(image, 1, image_size, fp);
    fclose(fp);
}

void save_image(char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }
    fwrite(image, 1, image_size, fp);
    fclose(fp);
}

void encode_message(char *message) {
    int message_len = strlen(message);
    if (message_len > MAX_MESSAGE_LEN) {
        fprintf(stderr, "Message is too long\n");
        exit(1);
    }
    for (int i = 0; i < message_len; i++) {
        int bit_index = i * 8;
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> j) & 1;
            image[bit_index + j] = (image[bit_index + j] & ~1) | bit;
        }
    }
}

char *decode_message() {
    int message_len = 0;
    while (message_len < MAX_MESSAGE_LEN && image[message_len * 8] != '\0') {
        message_len++;
    }
    char *message = malloc(message_len + 1);
    if (message == NULL) {
        perror("malloc");
        exit(1);
    }
    for (int i = 0; i < message_len; i++) {
        int bit_index = i * 8;
        char byte = 0;
        for (int j = 0; j < 8; j++) {
            byte |= (image[bit_index + j] & 1) << j;
        }
        message[i] = byte;
    }
    message[message_len] = '\0';
    return message;
}

void print_usage() {
    printf("Usage: steganography {-e|-d} <filename> <message>\n");
    printf("-e: encode message into image\n");
    printf("-d: decode message from image\n");
}

int main(int argc, char **argv) {
    if (argc < 4) {
        print_usage();
        return 1;
    }
    char *filename = argv[2];
    char *message = argv[3];
    if (strcmp(argv[1], "-e") == 0) {
        load_image(filename);
        encode_message(message);
        save_image(filename);
        printf("Message encoded successfully\n");
    } else if (strcmp(argv[1], "-d") == 0) {
        load_image(filename);
        char *decoded_message = decode_message();
        printf("Message decoded successfully: %s\n", decoded_message);
        free(decoded_message);
    } else {
        print_usage();
        return 1;
    }
    return 0;
}