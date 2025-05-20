//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

#define IMG_WIDTH 640
#define IMG_HEIGHT 480
#define MARK_WIDTH 32
#define MARK_HEIGHT 32

byte img[IMG_WIDTH * IMG_HEIGHT];
byte mark[MARK_WIDTH * MARK_HEIGHT];

int main() {
    FILE *fp_img, *fp_mark;

    // Load the image and the watermark
    fp_img = fopen("image.pgm", "rb");
    fp_mark = fopen("watermark.pgm", "rb");
    if (fp_img == NULL || fp_mark == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return EXIT_FAILURE;
    }

    fread(img, sizeof(byte), IMG_WIDTH * IMG_HEIGHT, fp_img);
    fread(mark, sizeof(byte), MARK_WIDTH * MARK_HEIGHT, fp_mark);

    fclose(fp_img);
    fclose(fp_mark);

    // Embed the watermark in the image
    for (int y = 0; y < IMG_HEIGHT; y++) {
        for (int x = 0; x < IMG_WIDTH; x++) {
            int mark_x = x % MARK_WIDTH;
            int mark_y = y % MARK_HEIGHT;
            double mark_val = ((double)mark[mark_y * MARK_WIDTH + mark_x]) / 255.0;
            double img_val = ((double)img[y * IMG_WIDTH + x]) / 255.0;
            img[y * IMG_WIDTH + x] = (byte)((img_val + (mark_val - 0.5) * 0.2) * 255.0);
        }
    }

    // Save the watermarked image
    fp_img = fopen("watermarked.pgm", "wb");
    if (fp_img == NULL) {
        fprintf(stderr, "Error: Could not open file.\n");
        return EXIT_FAILURE;
    }

    fwrite(img, sizeof(byte), IMG_WIDTH * IMG_HEIGHT, fp_img);
    fclose(fp_img);

    return EXIT_SUCCESS;
}