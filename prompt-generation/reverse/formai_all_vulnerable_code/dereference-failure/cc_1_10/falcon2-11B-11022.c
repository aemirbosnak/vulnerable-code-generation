//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int height;
    int width;
    int depth;
    unsigned char *data;
} Image;

typedef struct {
    unsigned char *watermark;
    int watermark_height;
    int watermark_width;
} Watermark;

void watermark_image(Image *image, Watermark *watermark) {
    // Calculate the dimensions of the watermarked image
    int watermarked_height = image->height + watermark->watermark_height;
    int watermarked_width = image->width + watermark->watermark_width;
    int watermarked_depth = image->depth;

    // Allocate memory for the watermarked image
    unsigned char *watermarked_data = (unsigned char *)malloc(watermarked_height * watermarked_width * watermarked_depth);

    // Copy the original image data into the watermarked image data
    memcpy(watermarked_data, image->data, image->height * image->width * image->depth);

    // Insert the watermark into the watermarked image data
    int watermark_start_x = (image->width + watermark->watermark_width) / 2 - watermark->watermark_width / 2;
    int watermark_start_y = (image->height + watermark->watermark_height) / 2 - watermark->watermark_height / 2;
    int watermark_end_x = watermark_start_x + watermark->watermark_width;
    int watermark_end_y = watermark_start_y + watermark->watermark_height;
    memcpy(watermarked_data + watermark_start_y * watermarked_width * watermarked_depth + watermark_start_x * watermarked_depth, watermark->watermark, watermark->watermark_height * watermark->watermark_width * 3);

    // Free the memory for the original image data
    free(image->data);

    // Assign the watermarked image data to the image structure
    image->data = watermarked_data;
    image->height = watermarked_height;
    image->width = watermarked_width;
    image->depth = watermarked_depth;
}

int main() {
    // Load the original image
    Image image;
    image.height = 200;
    image.width = 200;
    image.depth = 3;
    image.data = (unsigned char *)malloc(image.height * image.width * image.depth);
    memset(image.data, 0, image.height * image.width * image.depth);

    // Load the watermark
    Watermark watermark;
    watermark.watermark = (unsigned char *)malloc(watermark.watermark_height * watermark.watermark_width * 3);
    memset(watermark.watermark, 0, watermark.watermark_height * watermark.watermark_width * 3);

    // Insert the watermark into the image
    watermark_image(&image, &watermark);

    // Save the watermarked image
    FILE *fp = fopen("watermarked.jpg", "wb");
    fwrite(image.data, image.height * image.width * image.depth, 1, fp);
    fclose(fp);

    return 0;
}