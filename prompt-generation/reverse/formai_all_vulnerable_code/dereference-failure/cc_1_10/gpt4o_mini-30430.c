//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image *load_image(const char *filename);
void save_image(const char *filename, Image *img);
void free_image(Image *img);
void invert_colors(Image *img);
void greyscale(Image *img);
void resize_image(Image *img, int new_width, int new_height, Image *output);
void print_image_info(Image *img);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    print_image_info(image);
    
    // Invert colors
    invert_colors(image);
    save_image("inverted_output.bmp", image);

    // Convert to greyscale
    greyscale(image);
    save_image("greyscale_output.bmp", image);

    // Resize the image
    Image *resized_image = malloc(sizeof(Image));
    int new_width = image->width / 2;
    int new_height = image->height / 2;
    resize_image(image, new_width, new_height, resized_image);
    save_image("resized_output.bmp", resized_image);

    free_image(image);
    free_image(resized_image);
    return 0;
}

Image *load_image(const char *filename) {
    // This function would ideally load a BMP file; for simplicity,
    // we will indicate a placeholder
    printf("Loading image from %s...\n", filename);
    
    // Placeholder implementation (dummy data), real code will read from a file
    Image *img = malloc(sizeof(Image));
    img->width = 800;
    img->height = 600;
    img->data = malloc(img->width * img->height * sizeof(Pixel));

    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = (unsigned char)(i % 256);
        img->data[i].g = (unsigned char)((i + 85) % 256);
        img->data[i].b = (unsigned char)((i + 170) % 256);
    }
    
    return img;
}

void save_image(const char *filename, Image *img) {
    // This function would ideally save to a BMP file; for now, it's just a placeholder
    printf("Saving image to %s...\n", filename);
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void greyscale(Image *img) {
    for (int i = 0; i < img->width * img->height; ++i) {
        unsigned char grey = (unsigned char)(0.299 * img->data[i].r + 0.587 * img->data[i].g + 0.114 * img->data[i].b);
        img->data[i].r = grey;
        img->data[i].g = grey;
        img->data[i].b = grey;
    }
}

void resize_image(Image *img, int new_width, int new_height, Image *output) {
    output->width = new_width;
    output->height = new_height;
    output->data = malloc(new_width * new_height * sizeof(Pixel));
    
    float x_ratio = (float)img->width / new_width;
    float y_ratio = (float)img->height / new_height;
    
    for (int i = 0; i < new_height; ++i) {
        for (int j = 0; j < new_width; ++j) {
            int src_x = (int)(j * x_ratio);
            int src_y = (int)(i * y_ratio);
            output->data[i * new_width + j] = img->data[src_y * img->width + src_x];
        }
    }
}

void print_image_info(Image *img) {
    printf("Image Width: %d\n", img->width);
    printf("Image Height: %d\n", img->height);
}