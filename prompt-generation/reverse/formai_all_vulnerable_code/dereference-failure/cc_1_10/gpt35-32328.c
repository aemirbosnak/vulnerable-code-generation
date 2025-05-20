//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* data;
} Image;

// function to read in PPM image file (P6 format)
Image readPPM(const char* filename) {
    char buff[16];
    Image img;
    FILE* fp;
    int maxValue;

    // open image file
    fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s'\n", filename);
        exit(1);
    }

    // read image header (P6 format)
    if (!fgets(buff, sizeof(buff), fp)) {
        perror(filename);
        exit(1);
    }
    if (buff[0] != 'P' || buff[1] != '6') {
        fprintf(stderr, "Invalid image format (must be P6)\n");
        exit(1);
    }
    if (fscanf(fp, "%d %d\n", &img.width, &img.height) != 2) {
        fprintf(stderr, "Invalid image size (error reading width and/or height)\n");
        exit(1);
    }
    if (fscanf(fp, "%d\n", &maxValue) != 1) {
        fprintf(stderr, "Invalid image format (error reading max value)\n");
        exit(1);
    }
    if (maxValue != 255) {
        fprintf(stderr, "Invalid image format (max value must be 255)\n");
        exit(1);
    }

    // allocate memory for image pixel data and read it in
    img.data = (Pixel*)malloc(img.width * img.height * sizeof(Pixel));
    if (!img.data) {
        fprintf(stderr, "Unable to allocate memory for image\n");
        exit(1);
    }
    if (fread(img.data, 3 * img.width, img.height, fp) != img.height) {
        fprintf(stderr, "Error reading image data\n");
        exit(1);
    }

    // close image file and return image
    fclose(fp);
    return img;
}

// function to write out PPM image file (P6 format)
void writePPM(const char* filename, const Image* img) {
    FILE* fp;

    // open image file for writing
    fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file '%s' for writing\n", filename);
        exit(1);
    }

    // write image header (P6 format)
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "255\n");

    // write image pixel data
    fwrite(img->data, 3 * img->width, img->height, fp);

    // close image file
    fclose(fp);
}

// function to flip an image horizontally
void flipImage(Image* img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int i = y * img->width + x;
            int j = (y + 1) * img->width - (x + 1);
            Pixel tmp = img->data[i];
            img->data[i] = img->data[j];
            img->data[j] = tmp;
        }
    }
}

// function to adjust image brightness and contrast
void adjustBrightnessContrast(Image* img, int brightness, float contrast) {
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    // adjust each pixel in the image
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i].r;
        int g = img->data[i].g;
        int b = img->data[i].b;

        // adjust brightness by adding/subtracting the same value to each channel
        r += brightness;
        g += brightness;
        b += brightness;

        // adjust contrast by scaling each channel's value
        r = (int)(factor * (r - 128) + 128);
        g = (int)(factor * (g - 128) + 128);
        b = (int)(factor * (b - 128) + 128);

        // clamp the channel values to the range [0, 255]
        if (r < 0) r = 0; else if (r > 255) r = 255;
        if (g < 0) g = 0; else if (g > 255) g = 255;
        if (b < 0) b = 0; else if (b > 255) b = 255;

        // update the pixel in the image
        img->data[i].r = (unsigned char)r;
        img->data[i].g = (unsigned char)g;
        img->data[i].b = (unsigned char)b;
    }
}

int main() {
    // read in source image file
    Image src = readPPM("input.ppm");

    // flip image horizontally
    flipImage(&src);

    // adjust image brightness and contrast
    adjustBrightnessContrast(&src, -50, 1.5);

    // write out result image file
    writePPM("output.ppm", &src);

    // free memory for source image
    free(src.data);

    return 0;
}