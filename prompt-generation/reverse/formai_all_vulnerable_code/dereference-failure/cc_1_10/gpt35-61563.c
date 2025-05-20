//FormAI DATASET v1.0 Category: Image Steganography ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_SIZE 1000000

unsigned char *read_file(char *filename, long *file_size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Could not open file %s", filename);
        exit(1);
    }

    fseek(file, 0L, SEEK_END);
    *file_size = ftell(file);
    rewind(file);

    if (*file_size > MAX_FILE_SIZE) {
        printf("File size is too large");
        exit(1);
    }

    unsigned char *file_buf = (unsigned char *) malloc(*file_size);
    if (!file_buf) {
        printf("Could not allocate memory for file buffer");
        exit(1);
    }

    fread(file_buf, *file_size, 1, file);
    fclose(file);

    return file_buf;
}

void write_file(unsigned char *file_buf, long file_size, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Could not open file %s for writing", filename);
        exit(1);
    }

    fwrite(file_buf, file_size, 1, file);
    fclose(file);
}

void encode(unsigned char *image_buf, long image_size, unsigned char *msg_buf, long msg_size) {
    int i, j, k;
    unsigned char mask;
    unsigned char pixel;

    for (i = 0, j = 0; i < image_size && j < msg_size; i += 3, j++) {
        // LSB of blue pixel
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i];
            pixel = (msg_buf[j] & mask) ? (pixel | 0x01) : (pixel & 0xFE);
            image_buf[i] = pixel;

            mask <<= 1;
        }

        // LSB of green pixel
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i+1];
            pixel = (msg_buf[j] & mask) ? (pixel | 0x01) : (pixel & 0xFE);
            image_buf[i+1] = pixel;

            mask <<= 1;
        }

        // LSB of red pixel
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i+2];
            pixel = (msg_buf[j] & mask) ? (pixel | 0x01) : (pixel & 0xFE);
            image_buf[i+2] = pixel;

            mask <<= 1;
        }
    }

    // Mark end of message
    if (j >= msg_size) {
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i];
            pixel = (pixel & 0xFE) | mask;
            image_buf[i] = pixel;

            mask <<= 1;
        }
    }
}

unsigned char *decode(unsigned char *image_buf, long image_size, long *msg_size) {
    int i, j, k;
    unsigned char mask;
    unsigned char pixel;
    unsigned char *msg_buf = (unsigned char *) malloc(image_size/3);

    for (i = 0, j = 0; i < image_size; i += 3) {
        // LSB of blue pixel
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i];
            if (pixel & mask) {
                msg_buf[j] |= 0x01;
            }

            j++;

            if (j >= image_size/3) {
                goto exit_loop;
            }

            mask <<= 1;
        }

        // LSB of green pixel
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i+1];
            if (pixel & mask) {
                msg_buf[j] |= 0x01;
            }

            j++;

            if (j >= image_size/3) {
                goto exit_loop;
            }

            mask <<= 1;
        }

        // LSB of red pixel
        mask = 0x01;
        for (k = 0; k < 8; k++) {
            pixel = image_buf[i+2];
            if (pixel & mask) {
                msg_buf[j] |= 0x01;
            }

            j++;

            if (j >= image_size/3) {
                goto exit_loop;
            }

            mask <<= 1;
        }
    }

    // Message end not found
    printf("Could not find end of message");
    exit(1);

exit_loop:
    *msg_size = j;

    return msg_buf;
}

int main() {
    long image_size, msg_size;
    unsigned char *image_buf = read_file("image.bmp", &image_size);
    unsigned char *msg_buf = read_file("message.txt", &msg_size);

    printf("Original message: %s\n", msg_buf);

    encode(image_buf, image_size, msg_buf, msg_size);

    write_file(image_buf, image_size, "encoded_image.bmp");

    unsigned char *decoded_msg_buf = decode(image_buf, image_size, &msg_size);

    printf("Decoded message: %s\n", decoded_msg_buf);

    write_file(decoded_msg_buf, msg_size, "decoded_message.txt");

    free(image_buf);
    free(msg_buf);
    free(decoded_msg_buf);

    return 0;
}