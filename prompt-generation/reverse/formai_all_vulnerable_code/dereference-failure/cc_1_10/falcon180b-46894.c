//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WATERMARK_SIZE 8
#define WATERMARK_VALUE 0xAB

typedef struct {
    int width;
    int height;
    char* data;
} Image;

void read_image(Image* img, FILE* fp) {
    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    fread(img->data, 1, size, fp);

    img->width = *(int*)img->data;
    img->height = *(int*)(img->data + 4);
}

void write_image(Image* img, FILE* fp) {
    fwrite(img->data, 1, img->width * img->height * 3, fp);
}

void add_watermark(Image* img) {
    int watermark_size = WATERMARK_SIZE;
    int watermark_value = WATERMARK_VALUE;

    int width = img->width;
    int height = img->height;

    for (int y = 0; y < height; y += watermark_size) {
        for (int x = 0; x < width; x += watermark_size) {
            int index = (y * width + x) * 3;

            img->data[index] += watermark_value;
            img->data[index + 1] += watermark_value;
            img->data[index + 2] += watermark_value;
        }
    }
}

int main() {
    Image in_img, out_img;

    FILE* fp_in = fopen("input.bmp", "rb");
    if (fp_in == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    read_image(&in_img, fp_in);
    fclose(fp_in);

    add_watermark(&in_img);

    fp_in = fopen("output.bmp", "wb");
    if (fp_in == NULL) {
        printf("Error: Could not open output file.\n");
        free(in_img.data);
        return 1;
    }

    write_image(&in_img, fp_in);
    fclose(fp_in);

    free(in_img.data);

    return 0;
}