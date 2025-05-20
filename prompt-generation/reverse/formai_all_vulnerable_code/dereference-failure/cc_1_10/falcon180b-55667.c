//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

//Function to generate random message
void generate_message(char *message, int size) {
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < size; i++) {
        message[i] = charset[rand() % strlen(charset)];
    }
    message[size] = '\0';
}

//Function to embed watermark in image
void embed_watermark(char *image, char *watermark, int image_size, int watermark_size) {
    for (int i = 0; i < image_size; i++) {
        if (image[i] == '\0') {
            break;
        }
        if (i % watermark_size == 0) {
            image[i] = watermark[0];
        }
    }
}

//Function to extract watermark from image
char *extract_watermark(char *image, int image_size, int watermark_size) {
    char *watermark = (char *) malloc(watermark_size + 1);
    memset(watermark, 0, watermark_size + 1);
    int j = 0;
    for (int i = 0; i < image_size; i++) {
        if (image[i] == '\0') {
            break;
        }
        if (i % watermark_size == 0) {
            watermark[j++] = image[i];
        }
    }
    return watermark;
}

int main() {
    char message[MAX_SIZE];
    char watermark[MAX_SIZE];
    generate_message(message, rand() % MAX_SIZE);
    generate_message(watermark, rand() % MAX_SIZE);

    printf("Original message: %s\n", message);
    printf("Watermark: %s\n", watermark);

    char *image = (char *) malloc(strlen(message) + strlen(watermark) + 1);
    strcpy(image, message);
    embed_watermark(image, watermark, strlen(message), strlen(watermark));

    printf("Embedded image: %s\n", image);

    char *extracted_watermark = extract_watermark(image, strlen(image), strlen(watermark));

    printf("Extracted watermark: %s\n", extracted_watermark);

    free(image);
    free(extracted_watermark);

    return 0;
}