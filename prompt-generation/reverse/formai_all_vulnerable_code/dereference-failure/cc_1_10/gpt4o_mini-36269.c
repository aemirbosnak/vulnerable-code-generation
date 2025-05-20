//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char* filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Unable to open file");
        return NULL;
    }
    
    char buf[16];
    if (!fgets(buf, sizeof(buf), fp)) {
        perror("Error reading file");
        return NULL;
    }
    
    if (buf[0] != 'P' || buf[1] != '6') {
        fprintf(stderr, "Not a PPM file\n");
        return NULL;
    }
    
    // Read image dimensions
    Image *img = malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
  
    int maxval;
    fscanf(fp, "%d", &maxval);
    fgetc(fp); // Consume newline

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    return img;
}

void save_image(const char* filename, Image* img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to open file");
        return;
    }
    
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void flip_image(Image* img) {
    int row_size = img->width * sizeof(Pixel);
    Pixel *temp_row = malloc(row_size);
    
    for (int i = 0; i < img->height / 2; ++i) {
        memcpy(temp_row, &img->data[i * img->width], row_size);
        memcpy(&img->data[i * img->width], &img->data[(img->height - i - 1) * img->width], row_size);
        memcpy(&img->data[(img->height - i - 1) * img->width], temp_row, row_size);
    }
    
    free(temp_row);
}

void adjust_brightness_contrast(Image* img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = clamp((int)(img->data[i].r * contrast + brightness), 0, 255);
        img->data[i].g = clamp((int)(img->data[i].g * contrast + brightness), 0, 255);
        img->data[i].b = clamp((int)(img->data[i].b * contrast + brightness), 0, 255);
    }
}

int clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}

void free_image(Image* img) {
    free(img->data);
    free(img);
}

int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    Image* img = load_image(argv[1]);
    if (!img) return 1;

    flip_image(img);
    
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);
    
    adjust_brightness_contrast(img, brightness, contrast);
    
    save_image(argv[2], img);
    free_image(img);
    
    return 0;
}