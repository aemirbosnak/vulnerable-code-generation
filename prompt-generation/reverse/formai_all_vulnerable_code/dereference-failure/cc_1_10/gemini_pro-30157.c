//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct Image {
    uint8_t *data;
    int width, height;
};

void read_image(char *filename, struct Image *image)
{
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    // Read the header
    fseek(fp, 10, SEEK_SET);
    fread(&image->width, 4, 1, fp);
    fread(&image->height, 4, 1, fp);

    // Read the data
    image->data = malloc(image->width * image->height * 3);
    fread(image->data, image->width * image->height * 3, 1, fp);

    fclose(fp);
}

void write_image(char *filename, struct Image *image)
{
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    // Write the header
    fseek(fp, 10, SEEK_SET);
    fwrite(&image->width, 4, 1, fp);
    fwrite(&image->height, 4, 1, fp);

    // Write the data
    fwrite(image->data, image->width * image->height * 3, 1, fp);

    fclose(fp);
}

void invert_image(struct Image *image)
{
    for (int i = 0; i < image->width * image->height * 3; i++) {
        image->data[i] = ~image->data[i];
    }
}

void main()
{
    struct Image image;

    read_image("lena.bmp", &image);

    invert_image(&image);

    write_image("out.bmp", &image);

    free(image.data);
}