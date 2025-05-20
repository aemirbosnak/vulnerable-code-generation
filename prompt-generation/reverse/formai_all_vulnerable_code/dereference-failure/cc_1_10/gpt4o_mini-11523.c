//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
void apply_grayscale(Image *image);
void free_image(Image *image);

int main() {
    char input_file[256], output_file[256];
    
    // Load image
    printf("Enter the input PPM file name: ");
    scanf("%s", input_file);
    Image *image = load_image(input_file);
    if (!image) {
        fprintf(stderr, "Error loading image.\n");
        return EXIT_FAILURE;
    }
    
    // Apply grayscale filter
    apply_grayscale(image);
    
    // Save edited image
    printf("Enter the output PPM file name: ");
    scanf("%s", output_file);
    save_image(output_file, image);
    
    // Cleanup
    free_image(image);
    printf("Image has been processed and saved to %s\n", output_file);
    
    return EXIT_SUCCESS;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for reading\n", filename);
        return NULL;
    }
    
    char header[3];
    fscanf(file, "%s\n", header);
    if (header[0] != 'P' || (header[1] != '3' && header[1] != '6')) {
        fprintf(stderr, "Unsupported file format\n");
        fclose(file);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (header[1] == '3') {
        fscanf(file, "%d %d\n", &image->width, &image->height);
    } else {
        // For binary PPM (P6)
        fscanf(file, "%d %d\n255\n", &image->width, &image->height);
    }

    image->data = malloc(image->width * image->height * sizeof(Pixel));

    if (header[1] == '3') {
        for (int i = 0; i < image->width * image->height; i++) {
            fscanf(file, "%hhu %hhu %hhu", &image->data[i].r, &image->data[i].g, &image->data[i].b);
        }
    } else {
        fread(image->data, sizeof(Pixel), image->width * image->height, file);
    }

    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void apply_grayscale(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (unsigned char)(0.299 * image->data[i].r + 
                                             0.587 * image->data[i].g + 
                                             0.114 * image->data[i].b);
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}