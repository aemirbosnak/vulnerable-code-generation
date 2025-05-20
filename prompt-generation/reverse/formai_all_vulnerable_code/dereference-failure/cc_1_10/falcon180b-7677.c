//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    char *data = malloc(size);
    if (!data) {
        fprintf(stderr, "Error: Could not allocate memory for image data.\n");
        exit(1);
    }

    if (fread(data, 1, size, fp)!= size) {
        fprintf(stderr, "Error: Could not read image data from file.\n");
        exit(1);
    }

    fclose(fp);

    Image img = { data, 0, 0 };
    return img;
}

void print_image(const Image *img, int scale) {
    int width = img->width * scale;
    int height = img->height * scale;

    if (width > MAX_WIDTH) {
        fprintf(stderr, "Error: Image is too wide to display.\n");
        exit(1);
    }

    if (height > MAX_HEIGHT) {
        fprintf(stderr, "Error: Image is too tall to display.\n");
        exit(1);
    }

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * img->width + x) / scale;

            char c = img->data[index];

            if (c == 0) {
                printf(" ");
            } else if (c == 1) {
                printf("#");
            } else {
                printf("%c", c + 33);
            }
        }

        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_file> <scale_factor>\n", argv[0]);
        exit(1);
    }

    Image img = load_image(argv[1]);
    int scale = atoi(argv[2]);

    print_image(&img, scale);

    free(img.data);
    return 0;
}