//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE; // A byte is represented by 8 bits

// A function to flip an image horizontally
void flip_horizontally(BYTE *image, int width, int height) {
    BYTE temp;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width/2; j++) {
            temp = *(image + i*width + j);
            *(image + i*width + j) = *(image + i*width + (width - j - 1));
            *(image + i*width + (width - j - 1)) = temp;
        }
    }
}

// A function to change the brightness of an image
void change_brightness(BYTE *image, int width, int height, int brightness) {
    int new_value;
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            new_value = *(image + i*width + j) + brightness;
            *(image + i*width + j) = new_value > 255 ? 255 : new_value < 0 ? 0 : new_value;
        }
    }
}

// A function to change the contrast of an image
void change_contrast(BYTE *image, int width, int height, int contrast) {
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            *(image + i*width + j) = (BYTE) (factor * (*(image + i*width + j) - 128) + 128);
        }
    }
}

// A function to read an image file and return the pointer to its pixels
BYTE *read_image_file(char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("Could not open file %s\n", filename);
        return NULL;
    }
    
    BYTE header[54];
    fread(header, sizeof(BYTE), 54, fp);
    
    *width = *(int *) (header + 18);
    *height = *(int *) (header + 22);
    
    int padding = (*width*3)%4 != 0 ? 4 - (*width*3)%4 : 0;
    
    BYTE *pixels = (BYTE *) malloc(sizeof(BYTE)*(*width)*(*height));
    BYTE *temp = (BYTE *) malloc(sizeof(BYTE)*(*width)*3);
    for(int i = *height - 1; i >= 0; i--) {
        fread(temp, sizeof(BYTE), (*width)*3, fp);
        for(int j = 0; j < *width; j++) {
            *(pixels + i*(*width) + j) = *(temp + j*3);
        }
        fseek(fp, padding, SEEK_CUR);
    }
    
    fclose(fp);
    free(temp);
    
    return pixels;
}

// A function to write an image file from the pixels array
void write_image_file(char *filename, BYTE *image, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    if(!fp) {
        printf("Could not open file %s\n", filename);
        return;
    }
    
    int padding = (width*3)%4 != 0 ? 4 - (width*3)%4 : 0;
    int size = 54 + (width*3 + padding)*height;
    
    BYTE header[] = {
        'B','M',     // Magic number
        size,0,0,0,  // Size of file
        0,0,0,0,     // Reserved
        54,0,0,0,    // Offset of pixel data
        40,0,0,0,    // Header size
        width,0,0,0, // Width
        height,0,0,0,// Height
        1,0,         // Number of color planes
        24,0,        // Bits per pixel
        0,0,0,0,     // Compression method
        0,0,0,0,     // Image size
        0,0,0,0,     // Horizontal resolution
        0,0,0,0,     // Vertical resolution
        0,0,0,0,     // Number of colors in the palette
        0,0,0,0,     // Number of important colors
    };
    
    fwrite(header, sizeof(BYTE), 54, fp);
    
    BYTE *temp = (BYTE *) calloc((width*3 + padding), sizeof(BYTE));
    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j < width; j++) {
            *(temp + j*3) = *(image + i*width + j);
            *(temp + j*3 + 1) = *(image + i*width + j);
            *(temp + j*3 + 2) = *(image + i*width + j);
        }
        fwrite(temp, sizeof(BYTE), width*3 + padding, fp);
    }
    free(temp);
    
    fclose(fp);
}

int main() {
    char filename[] = "image.bmp";
    int width, height;
    BYTE *image = read_image_file(filename, &width, &height);
    
    printf("Flipping horizontally...\n");
    flip_horizontally(image, width, height);
    
    printf("Increasing brightness...\n");
    change_brightness(image, width, height, 50);
    
    printf("Increasing contrast...\n");
    change_contrast(image, width, height, 100);
    
    char new_filename[] = "new_image.bmp";
    write_image_file(new_filename, image, width, height);
    printf("New image saved to file %s\n", new_filename);
    
    free(image);
    return 0;
}