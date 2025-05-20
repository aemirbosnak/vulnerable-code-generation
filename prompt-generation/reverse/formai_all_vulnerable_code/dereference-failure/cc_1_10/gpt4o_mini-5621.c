//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }
  
    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Error reading file");
        return NULL;
    }
    
    if (buffer[0] != 'P' || buffer[1] != '5') {
        fprintf(stderr, "Not a valid PGM file\n");
        return NULL;
    }
  
    Image *img = (Image *)malloc(sizeof(Image));
    fgets(buffer, sizeof(buffer), file);  // Read the next line
    sscanf(buffer, "%d %d", &img->width, &img->height);
  
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file);  // Consume the newline character here
  
    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, sizeof(unsigned char), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
    
    fprintf(file, "P5\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(unsigned char), img->width * img->height, file);
    fclose(file);
}

void blur_image(Image *img) {
    int kernel[3][3] = {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };
    int kernel_sum = 16;  // Sum of kernel elements

    unsigned char *blurred_data = (unsigned char *)malloc(img->width * img->height);
    
    for (int y = 1; y < img->height - 1; y++) {
        for (int x = 1; x < img->width - 1; x++) {
            int sum = 0;
            for (int ky = -1; ky <= 1; ky++) {
                for (int kx = -1; kx <= 1; kx++) {
                    int pixel = img->data[(y + ky) * img->width + (x + kx)];
                    sum += pixel * kernel[ky + 1][kx + 1];
                }
            }
            blurred_data[y * img->width + x] = sum / kernel_sum;
        }
    }

    // Edge handling (copying original pixels at the borders)
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            if (y == 0 || y == img->height - 1 || x == 0 || x == img->width - 1) {
                blurred_data[y * img->width + x] = img->data[y * img->width + x];
            }
        }
    }

    free(img->data);
    img->data = blurred_data;
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <input_image.pgm> <output_image.pgm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    blur_image(img);
    save_image(argv[2], img);
    free_image(img);

    printf("Image processed and saved as %s\n", argv[2]);
    return EXIT_SUCCESS;
}