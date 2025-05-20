//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdint.h>

#define MAX_PIXELS 1000000
#define MAX_MESSAGE_LENGTH 1000000
#define BITS_PER_PIXEL 8
#define MAX_IMAGE_SIZE (MAX_PIXELS * BITS_PER_PIXEL)
#define MAX_HIDDEN_MESSAGE_LENGTH (MAX_IMAGE_SIZE - (3 * MAX_PIXELS))

// Function prototypes
void generate_random_message(char *message, int length);
void generate_random_image(char *image, int length);
void embed_message(char *image, int length, char *message, int message_length);
void extract_message(char *image, int length, char *message, int message_length);
void print_image(char *image, int length);

int main(int argc, char *argv[]) {
    char message[MAX_MESSAGE_LENGTH];
    char image[MAX_IMAGE_SIZE];
    int message_length, image_length;

    if (argc!= 3) {
        printf("Usage: %s <message> <image>\n", argv[0]);
        return 1;
    }

    message_length = strlen(argv[1]);
    image_length = strlen(argv[2]);

    if (message_length > MAX_MESSAGE_LENGTH) {
        printf("Message too long!\n");
        return 1;
    }

    if (image_length > MAX_IMAGE_SIZE) {
        printf("Image too long!\n");
        return 1;
    }

    strcpy(message, argv[1]);
    strcpy(image, argv[2]);

    generate_random_message(message, message_length);
    generate_random_image(image, image_length);

    embed_message(image, image_length, message, message_length);

    printf("Embedded message:\n");
    print_image(image, image_length);

    extract_message(image, image_length, message, message_length);

    printf("Extracted message:\n%s\n", message);

    return 0;
}

void generate_random_message(char *message, int length) {
    int i;

    for (i = 0; i < length; i++) {
        message[i] = rand() % 256;
    }
}

void generate_random_image(char *image, int length) {
    int i;

    for (i = 0; i < length; i++) {
        image[i] = rand() % 256;
    }
}

void embed_message(char *image, int length, char *message, int message_length) {
    int i, j, k;

    for (i = 0, j = 0; i < length && j < message_length; i++) {
        if ((i % 3) == 0) {
            message[j] = image[i];
            j++;
        }
    }
}

void extract_message(char *image, int length, char *message, int message_length) {
    int i, j, k;

    for (i = 0, j = 0; i < length && j < message_length; i++) {
        if ((i % 3) == 0) {
            message[j] = image[i];
            j++;
        }
    }
}

void print_image(char *image, int length) {
    int i;

    for (i = 0; i < length; i++) {
        printf("%c", image[i]);
    }
}