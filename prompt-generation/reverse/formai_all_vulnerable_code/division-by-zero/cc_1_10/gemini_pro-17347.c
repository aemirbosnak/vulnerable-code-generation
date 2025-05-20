//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

int main(int argc, char **argv) {
    FILE *fp;
    char *data;
    int i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, y, z;

    if (argc != 3) {
        printf("Usage: %s <image file> <message file>\n", argv[0]);
        exit(1);
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening image file: %s\n", argv[1]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long int size = ftell(fp);
    rewind(fp);

    data = malloc(size);
    if (data == NULL) {
        printf("Error allocating memory for image data.\n");
        exit(1);
    }

    fread(data, 1, size, fp);
    fclose(fp);

    fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        printf("Error opening message file: %s\n", argv[2]);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long int message_size = ftell(fp);
    rewind(fp);

    char *message = malloc(message_size);
    if (message == NULL) {
        printf("Error allocating memory for message.\n");
        exit(1);
    }

    fread(message, 1, message_size, fp);
    fclose(fp);

    if (message_size > size) {
        printf("Message too large for image: %ld bytes > %ld bytes\n", message_size, size);
        exit(1);
    }

    for (i = 0; i < size; i++) {
        for (j = 0; j < 8; j++) {
            x = data[i] >> j;
            y = message[i % message_size] >> j;
            z = (x & 1) ^ (y & 1);
            data[i] &= ~(1 << j);
            data[i] |= (z << j);
        }
    }

    fp = fopen(argv[1], "wb");
    if (fp == NULL) {
        printf("Error opening image file for writing: %s\n", argv[1]);
        exit(1);
    }

    fwrite(data, 1, size, fp);
    fclose(fp);

    printf("Message successfully hidden in image: %s\n", argv[1]);

    return 0;
}