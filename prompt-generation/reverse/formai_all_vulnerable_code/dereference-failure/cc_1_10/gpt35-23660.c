//FormAI DATASET v1.0 Category: Image Editor ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// struct to store image data
struct Image{
    int width;
    int height;
    int *pixels;
};

// function to create a new image
struct Image* create_image(int width, int height){
    struct Image *image = malloc(sizeof(*image));
    if(image == NULL){
        fprintf(stderr, "Error: Unable to allocate memory for image\n");
        return NULL;
    }
    image->width = width;
    image->height = height;
    image->pixels = malloc(width * height * sizeof(int));
    if(image->pixels == NULL){
        fprintf(stderr, "Error: Unable to allocate memory for image pixels\n");
        free(image);
        return NULL;
    }
    return image;
}

// function to get the pixel at a given x and y coordinate
int get_pixel(struct Image *image, int x, int y){
    return image->pixels[x + y * image->width];
}

// function to set the pixel at a given x and y coordinate
void set_pixel(struct Image *image, int x, int y, int value){
    image->pixels[x + y * image->width] = value;
}

// function to invert the colors of an image
void invert_colors(struct Image *image){
    int x, y;
    for(y = 0; y < image->height; y++){
        for(x = 0; x < image->width; x++){
            set_pixel(image, x, y, 255 - get_pixel(image, x, y));
        }
    }
}

// function to write an image to a file
void write_image(struct Image *image, const char *filename){
    FILE *file = fopen(filename, "wb");
    if(file == NULL){
        fprintf(stderr, "Error: Unable to open file for writing\n");
        return;
    }
    fprintf(file, "P5\n%d %d\n255\n", image->width, image->height);
    fwrite(image->pixels, image->width * image->height, 1, file);
    fclose(file);
}

int main(int argc, char *argv[]){
    if(argc != 4){
        fprintf(stderr, "Usage: %s <input file> <output file> <operation>\n", argv[0]);
        fprintf(stderr, "Operations:\n");
        fprintf(stderr, "  invert  - Invert the colors of the image\n");
        fprintf(stderr, "  graysca    - Convert the image to grayscale\n");
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];

    struct Image *image = NULL;

    // read the image from the input file
    FILE *file = fopen(input_filename, "rb");
    if(file == NULL){
        fprintf(stderr, "Error: Unable to open file for reading\n");
        return 1;
    }

    char format[3];
    fscanf(file, "%2s", format);

    if(strcmp(format, "P5") != 0){
        fprintf(stderr, "Error: Invalid file format\n");
        fclose(file);
        return 1;
    }

    int width, height;
    fscanf(file, "%d %d", &width, &height);

    int max_value;
    fscanf(file, "%d", &max_value);

    if(max_value != 255){
        fprintf(stderr, "Error: Maximum value must be 255\n");
        fclose(file);
        return 1;
    }

    image = create_image(width, height);

    fread(image->pixels, width * height, 1, file);
    fclose(file);

    // apply the selected operation
    if(strcmp(operation, "invert") == 0){
        invert_colors(image);
    }
    else if(strcmp(operation, "grayscale") == 0){
        // code to convert the image to grayscale
    }
    else{
        fprintf(stderr, "Error: Invalid operation\n");
        return 1;
    }

    // write the modified image to the output file
    write_image(image, output_filename);

    // free image memory
    free(image->pixels);
    free(image);

    return 0;
}