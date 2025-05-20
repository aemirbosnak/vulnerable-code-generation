//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel *data;
    int width, height;
} Image;

Image* load_image(const char* filename);
void save_image(const char* filename, Image* img);
void flip_image(Image* img);
void change_brightness(Image* img, int brightness);
void change_contrast(Image* img, float factor);
void free_image(Image* img);
void print_usage();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_usage();
        return 1;
    }
    
    Image* img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Failed to load image: %s\n", argv[1]);
        return 1;
    }
    
    printf("Welcome to the Neon Image Processor!\n");
    printf("1: Flip Image\n");
    printf("2: Change Brightness\n");
    printf("3: Change Contrast\n");
    printf("Please select an operation: ");
    
    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            flip_image(img);
            printf("Image flipped! Saving as 'flipped_image.bmp'\n");
            save_image("flipped_image.bmp", img);
            break;
        case 2:
            {
                int brightness;
                printf("Enter brightness adjustment (-255 to 255): ");
                scanf("%d", &brightness);
                change_brightness(img, brightness);
                printf("Brightness adjusted! Saving as 'bright_image.bmp'\n");
                save_image("bright_image.bmp", img);
            }
            break;
        case 3:
            {
                float factor;
                printf("Enter contrast factor (0.0 to 3.0): ");
                scanf("%f", &factor);
                change_contrast(img, factor);
                printf("Contrast adjusted! Saving as 'contrast_image.bmp'\n");
                save_image("contrast_image.bmp", img);
            }
            break;
        default:
            fprintf(stderr, "Invalid choice!\n");
            break;
    }

    free_image(img);
    return 0;
}

Image* load_image(const char* filename) {
    // Dummy load function, real implementation would involve reading BMP format
    Image* img = (Image*)malloc(sizeof(Image));
    img->width = 640;  // Example width
    img->height = 480; // Example height
    img->data = (Pixel*)malloc(sizeof(Pixel) * img->width * img->height);
    memset(img->data, 255, sizeof(Pixel) * img->width * img->height); // White image
    return img;
}

void save_image(const char* filename, Image* img) {
    // Dummy save function, real implementation would involve writing to BMP format
    printf("Saving image... Done!\n");
}

void flip_image(Image* img) {
    int width = img->width;
    int height = img->height;
    Pixel* new_data = (Pixel*)malloc(sizeof(Pixel) * width * height);
    
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            new_data[(height - 1 - y) * width + x] = img->data[y * width + x];
        }
    }

    free(img->data);
    img->data = new_data;
}

void change_brightness(Image* img, int brightness) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->data[i].r + brightness;
        int g = img->data[i].g + brightness;
        int b = img->data[i].b + brightness;

        img->data[i].r = r < 0 ? 0 : (r > 255 ? 255 : r);
        img->data[i].g = g < 0 ? 0 : (g > 255 ? 255 : g);
        img->data[i].b = b < 0 ? 0 : (b > 255 ? 255 : b);
    }
}

void change_contrast(Image* img, float factor) {
    // A simple contrast adjustment formula
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (int)((((img->data[i].r / 255.0) - 0.5) * factor + 0.5) * 255);
        img->data[i].g = (int)((((img->data[i].g / 255.0) - 0.5) * factor + 0.5) * 255);
        img->data[i].b = (int)((((img->data[i].b / 255.0) - 0.5) * factor + 0.5) * 255);
        
        // Clamping
        img->data[i].r = img->data[i].r < 0 ? 0 : (img->data[i].r > 255 ? 255 : img->data[i].r);
        img->data[i].g = img->data[i].g < 0 ? 0 : (img->data[i].g > 255 ? 255 : img->data[i].g);
        img->data[i].b = img->data[i].b < 0 ? 0 : (img->data[i].b > 255 ? 255 : img->data[i].b);
    }
}

void free_image(Image* img) {
    free(img->data);
    free(img);
}

void print_usage() {
    printf("Usage: ./cyberpunk_image_processor <image_file>\n");
}