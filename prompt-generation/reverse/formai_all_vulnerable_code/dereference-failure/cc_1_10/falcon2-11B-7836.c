//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} image_t;

void show_image(image_t image) {
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            printf("%c", image.data[y * image.width + x]);
        }
        printf("\n");
    }
}

void show_text(char *text) {
    printf("Text: %s\n", text);
}

int main() {
    image_t image = {800, 600, (char*)malloc(800 * 600 * 3)};

    // Create the image data
    for (int y = 0; y < image.height; y++) {
        for (int x = 0; x < image.width; x++) {
            image.data[y * image.width + x] = '.';
        }
    }

    // Hide the text in the image
    char text[256] = "This is a secret message.";
    int text_length = strlen(text);
    for (int i = 0; i < text_length; i++) {
        char c = text[i];
        int row = (i / image.width) + 1;
        int col = i % image.width;
        image.data[row * image.width + col] = c;
    }

    // Show the original image
    show_image(image);
    printf("Original Image:\n");

    // Show the hidden text
    show_text(text);
    printf("Hidden Text:\n");

    // Free the memory
    free(image.data);

    return 0;
}