//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: lively
// Plunge into the depths of Digital Watermarking, where secrets dance beneath the surface like playful dolphins!

#include <stdio.h>
#include <stdlib.h>

// Our Canvas: An Image to Embellish
typedef struct Image {
    int width, height;
    int **pixels;
} Image;

// Our Watermark: A Hidden Message
char *watermark;

// Our Brush: Embedding the Watermark
void embedWatermark(Image *img) {
    int i, j, k = 0;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            img->pixels[i][j] += (watermark[k++ % strlen(watermark)] - 'a') % 2;
        }
    }
}

// Our Decoder: Unveiling the Hidden Message
void decodeWatermark(Image *img) {
    int i, j, k = 0;
    char decoded[strlen(watermark)];
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            decoded[k++] = img->pixels[i][j] % 2 + 'a';
        }
    }
    printf("Ta-da! The hidden message is: %s\n", decoded);
}

// Our Portal: Creating and Displaying an Image
Image *createImage(int w, int h) {
    Image *img = malloc(sizeof(Image));
    img->width = w;
    img->height = h;
    int **pixels = malloc(h * sizeof(int *));
    for (int i = 0; i < h; i++) {
        pixels[i] = malloc(w * sizeof(int));
        for (int j = 0; j < w; j++) {
            pixels[i][j] = 0;
        }
    }
    img->pixels = pixels;
    return img;
}

// Our Lighthouse: Freeing the Image from Memory
void freeImage(Image *img) {
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
}

int main() {
    // Set Sail: Initialize Our Canvas and Watermark
    printf("Ahoy there! Let's create an image and hide a secret message!\n");
    int width, height;
    printf("Enter the width and height of your canvas: ");
    scanf("%d %d", &width, &height);
    Image *img = createImage(width, height);
    printf("Now, what's your secret message, matey? (Keep it short): ");
    watermark = malloc(100);
    scanf("%s", watermark);

    // Dive In: Embed the Watermark
    embedWatermark(img);
    printf("Watermarked image ready! Hang on while I display it...\n");

    // Unveil the Treasure: Decode the Watermark
    decodeWatermark(img);

    // Cast Off: Release Our Resources
    freeImage(img);
    free(watermark);

    printf("\nYo ho ho! We've sailed through the adventure of digital watermarking. Hope you enjoyed the ride!\n");
    return 0;
}