//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red, green, blue;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename);
void save_ppm(const char *filename, Image *img);
void flip_image(Image *img);
void change_brightness(Image *img, int value);
void change_contrast(Image *img, double factor);
void free_image(Image *img);

void display_menu() {
    printf("Select an operation:\n");
    printf("1. Flip Image\n");
    printf("2. Change Brightness\n");
    printf("3. Change Contrast\n");
    printf("4. Exit\n");
}

int main() {
    const char *input_file = "input.ppm";
    const char *output_file = "output.ppm";
    Image *img = load_ppm(input_file);
    
    if (!img) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    int choice;
    while (1) {
        display_menu();
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                flip_image(img);
                printf("Image flipped.\n");
                break;
            case 2: {
                int brightness;
                printf("Enter brightness value (-255 to 255): ");
                scanf("%d", &brightness);
                change_brightness(img, brightness);
                printf("Brightness changed.\n");
                break;
            }
            case 3: {
                double contrast;
                printf("Enter contrast factor (0.0 to 3.0): ");
                scanf("%lf", &contrast);
                change_contrast(img, contrast);
                printf("Contrast changed.\n");
                break;
            }
            case 4:
                free_image(img);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    
    free_image(img);
    return 0;
}

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) return NULL;
    if (buffer[0] != 'P' || buffer[1] != '6') return NULL;

    Image *img = (Image*)malloc(sizeof(Image));
    if (!img) return NULL;

    // Read image size
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxColor;
    fscanf(file, "%d", &maxColor);
    fgetc(file); // skip newline

    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - x - 1;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + opposite_x];
            img->data[y * img->width + opposite_x] = temp;
        }
    }
}

void change_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = (img->data[i].red + value > 255) ? 255 : (img->data[i].red + value < 0) ? 0 : img->data[i].red + value;
        img->data[i].green = (img->data[i].green + value > 255) ? 255 : (img->data[i].green + value < 0) ? 0 : img->data[i].green + value;
        img->data[i].blue = (img->data[i].blue + value > 255) ? 255 : (img->data[i].blue + value < 0) ? 0 : img->data[i].blue + value;
    }
}

void change_contrast(Image *img, double factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = (unsigned char) fmin(fmax((img->data[i].red - 128) * factor + 128, 0), 255);
        img->data[i].green = (unsigned char) fmin(fmax((img->data[i].green - 128) * factor + 128, 0), 255);
        img->data[i].blue = (unsigned char) fmin(fmax((img->data[i].blue - 128) * factor + 128, 0), 255);
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}