//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WATERMARK_SIZE 512
#define WATERMARK_VALUE 42

// Function to generate watermark
void generate_watermark(char *watermark) {
    int i;
    for (i = 0; i < WATERMARK_SIZE; i++) {
        watermark[i] = WATERMARK_VALUE + rand() % 10;
    }
}

// Function to embed watermark in image
void embed_watermark(char *image, char *watermark) {
    FILE *fp_image, *fp_watermark;
    char ch;
    int count = 0;

    fp_image = fopen(image, "rb");
    if (fp_image == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    fp_watermark = fopen("watermark.txt", "wb");
    if (fp_watermark == NULL) {
        printf("Error creating watermark file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp_image))!= EOF) {
        if (count >= WATERMARK_SIZE) {
            break;
        }
        fprintf(fp_watermark, "%c", ch);
        count++;
    }

    fclose(fp_image);
    fclose(fp_watermark);
}

// Function to extract watermark from image
void extract_watermark(char *image, char *watermark) {
    FILE *fp_image, *fp_watermark;
    char ch;
    int count = 0;

    fp_image = fopen(image, "rb");
    if (fp_image == NULL) {
        printf("Error opening image file.\n");
        exit(1);
    }

    fp_watermark = fopen("watermark.txt", "wb");
    if (fp_watermark == NULL) {
        printf("Error creating watermark file.\n");
        exit(1);
    }

    while ((ch = fgetc(fp_image))!= EOF) {
        if (count >= WATERMARK_SIZE) {
            break;
        }
        fprintf(fp_watermark, "%c", ch);
        count++;
    }

    fclose(fp_image);
    fclose(fp_watermark);
}

int main() {
    char image[] = "image.jpg";
    char watermark[] = "watermark.txt";

    generate_watermark(watermark);
    embed_watermark(image, watermark);
    extract_watermark(image, watermark);

    return 0;
}