//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

// Function to read a PPM image
Image *readPPM(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("File opening failed");
        return NULL;
    }

    char buf[16];
    if (!fgets(buf, sizeof(buf), fp)) { return NULL; }
    if (buf[0] != 'P' || buf[1] != '6') { return NULL; }

    Image *img = (Image *)malloc(sizeof(Image));
    if (!img) { fclose(fp); return NULL; }

    fscanf(fp, "%d %d", &img->width, &img->height);
    int max_color;
    fscanf(fp, "%d", &max_color);
    fgetc(fp); // consume newline

    img->pixels = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    return img;
}

// Function to write a PPM image
void writePPM(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("File opening failed");
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

// Function to embed watermark into the image
void embedWatermark(Image *img, const char *watermark) {
    int watermark_len = strlen(watermark);
    for (int i = 0; i < watermark_len; i++) {
        // Modify the LSB of each pixel color to store watermark bits
        for (int j = 0; j < 8; j++) {
            if (i * 8 + j < img->width * img->height * 3) {
                Pixel *p = &img->pixels[(i * 8 + j) / 3];
                if ((watermark[i] >> (7 - j)) & 1) {
                    p->r |= 1; // Set LSB to 1
                } else {
                    p->r &= ~1; // Set LSB to 0
                }
            }
        }
    }
}

// Function to extract watermark from the image
void extractWatermark(Image *img, char *watermark, int watermark_size) {
    for (int i = 0; i < watermark_size; i++) {
        watermark[i] = 0;
        for (int j = 0; j < 8; j++) {
            if (i * 8 + j < img->width * img->height * 3) {
                Pixel *p = &img->pixels[(i * 8 + j) / 3];
                watermark[i] |= (p->r & 1) << (7 - j); // Extract LSB
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image.ppm> <output_image.ppm> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_image = argv[1];
    const char *output_image = argv[2];
    const char *watermark = argv[3];

    Image *img = readPPM(input_image);
    if (!img) {
        return EXIT_FAILURE;
    }

    embedWatermark(img, watermark);
    writePPM(output_image, img);

    // Now extract the watermark to verify
    char extracted[100] = {0};
    extractWatermark(img, extracted, strlen(watermark));
    printf("Extracted Watermark: %s\n", extracted);

    free(img->pixels);
    free(img);
    return EXIT_SUCCESS;
}