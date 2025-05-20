//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BLOCK_SIZE 64
#define NUM_BLOCKS 3

/* function to embed a message in an image */
void embed(unsigned char *img, int len, unsigned char *message) {
    int i, j;
    unsigned char *p;

    for (i = 0; i < len; i++) {
        for (j = 0; j < NUM_BLOCKS; j++) {
            p = &img[BLOCK_SIZE * j + i * NUM_BLOCKS * BLOCK_SIZE];
            p[0] ^= message[i];
            p[1] ^= message[i];
            p[2] ^= message[i];
            p[3] ^= message[i];
        }
    }
}

/* function to extract a message from an image */
unsigned char *extract(unsigned char *img, int len) {
    int i, j;
    unsigned char *p;

    unsigned char *message = malloc(len);

    for (i = 0; i < len; i++) {
        for (j = 0; j < NUM_BLOCKS; j++) {
            p = &img[BLOCK_SIZE * j + i * NUM_BLOCKS * BLOCK_SIZE];
            message[i] = p[0] ^ p[1] ^ p[2] ^ p[3];
        }
    }

    return message;
}

int main() {
    unsigned char img[4096];
    unsigned char message[256];
    unsigned char *p;

    printf("Enter the message to be embedded: ");
    fgets(message, sizeof(message), stdin);
    p = strtok(message, "\n");
    message[strlen(message) - 1] = '\0';
    printf("Message length: %d\n", strlen(message));

    printf("Enter the image file name: ");
    fgets(p, sizeof(p), stdin);
    p[strlen(p) - 1] = '\0';
    printf("Image file name: %s\n", p);

    FILE *fp = fopen(p, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open image file\n");
        return 1;
    }

    fread(img, 1, sizeof(img), fp);
    fclose(fp);

    embed(img, strlen(message), message);

    fp = fopen(p, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open image file for writing\n");
        return 1;
    }

    fwrite(img, 1, sizeof(img), fp);
    fclose(fp);

    printf("Message embedded successfully!\n");

    fp = fopen(p, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Unable to open image file for reading\n");
        return 1;
    }

    unsigned char *extracted_message = extract(img, strlen(message));

    if (strcmp(extracted_message, message)!= 0) {
        fprintf(stderr, "Error: Message extraction failed!\n");
        return 1;
    }

    fclose(fp);

    printf("Message extraction successful!\n");

    return 0;
}