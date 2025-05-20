//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the image structure
typedef struct {
    unsigned char *data;
    int width;
    int height;
    int max_val;
} Image;

// Function to load a PBM image
Image* load_image(const char *filename) {
    Image *img = (Image *)malloc(sizeof(Image));
    FILE *file = fopen(filename, "rb");
    if(!file) {
        fprintf(stderr, "Error opening file\n");
        return NULL;
    }
    
    // Read PBM header
    char buffer[16];
    fscanf(file, "%s", buffer);
    if (strcmp(buffer, "P5") != 0) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }
    
    // Read image size and max value
    fscanf(file, "%d %d", &img->width, &img->height);
    fscanf(file, "%d", &img->max_val);
    fgetc(file); // Skip the newline character

    // Allocate memory for image data
    img->data = (unsigned char *)malloc(img->width * img->height);
    fread(img->data, 1, img->width * img->height, file);
    fclose(file);
    
    return img;
}

// Function to save a PBM image
void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving file\n");
        return;
    }
    
    // Write PBM header
    fprintf(file, "P5\n%d %d\n%d\n", img->width, img->height, img->max_val);
    fwrite(img->data, 1, img->width * img->height, file);
    fclose(file);
}

// Function to invert the image colors
void invert_colors(Image *img) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i] = img->max_val - img->data[i];
    }
}

// Function to display the image in the console (for small images)
void display_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = img->data[y * img->width + x];
            if (pixel > (img->max_val / 2)) {
                printf("  "); // bright pixel
            } else {
                printf("**"); // dark pixel
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input_image.pbm> <output_image.pbm>\n", argv[0]);
        return 1;
    }

    // Load the image
    Image *img = load_image(argv[1]);
    if (!img) return 1;

    // Display the original image
    printf("Original Image:\n");
    display_image(img);

    // Invert colors
    invert_colors(img);

    // Display the processed image
    printf("\nInverted Image:\n");
    display_image(img);
    
    // Save it to output file
    if (argc > 2) {
        save_image(argv[2], img);
        printf("\nImage saved to %s\n", argv[2]);
    }

    // Free allocated memory
    free(img->data);
    free(img);
    return 0;
}