//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mind-bending
#include <stdio.h>
#include <math.h>

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

void flip_horizontal(Image *image){
    int bytes_per_row = image->width * 3;
    unsigned char *row = malloc(bytes_per_row);
    int top = 0, bottom = image->height - 1;
    while (top < bottom) {
        memcpy(row, image->data + top * bytes_per_row, bytes_per_row);
        memcpy(image->data + top * bytes_per_row, image->data + bottom * bytes_per_row, bytes_per_row);
        memcpy(image->data + bottom * bytes_per_row, row, bytes_per_row);
        top++;
        bottom--;
    }
    free(row);
}

void flip_vertical(Image *image){
    int bytes_per_row = image->width * 3;
    unsigned char *row = malloc(bytes_per_row);
    for (int y = 0; y < image->height / 2; y++) {
        unsigned char *row1 = image->data + y * bytes_per_row;
        unsigned char *row2 = image->data + (image->height - y - 1)* bytes_per_row;
        memcpy(row, row1, bytes_per_row);
        memcpy(row1, row2, bytes_per_row);
        memcpy(row2, row, bytes_per_row);
    }
    free(row);
}

void change_brightness(Image *image, float brightness){
    for (int i = 0; i < image->width * image->height * 3; i++) {
        float pixel = image->data[i] + brightness * 255.0;
        image->data[i] = fmax(0, fmin(255, pixel));
    }
}

void change_contrast(Image *image, float contrast){
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));
    for (int i = 0; i < image->width * image->height * 3; i++) {
        float pixel = factor * (image->data[i] - 128.0) + 128.0;
        image->data[i] = fmax(0, fmin(255, pixel));
    }
}

int main(){
    Image image;
    image.width = 100;
    image.height = 100;
    image.data = malloc(image.width * image.height * 3);
    // Initialize image data here
    
    // Flip horizontally
    flip_horizontal(&image);
    
    // Flip vertically
    flip_vertical(&image);
    
    // Change brightness
    change_brightness(&image, 0.5);
    
    // Change contrast
    change_contrast(&image, 0.5);
    
    return 0;
}