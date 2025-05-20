//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Cannot open file");
        return NULL;
    }
    
    char buff[16];
    if (fgets(buff, sizeof(buff), file) == NULL) {
        perror("Error reading PPM file");
        return NULL;
    }

    if (buff[0] != 'P' || buff[1] != '6') {
        fprintf(stderr, "Invalid PPM format\n");
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // Consume the newline character

    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);

    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Cannot open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flipHorizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void adjustBrightnessContrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = fmin(fmax((img->data[i].r - 128) * contrast + 128 + brightness, 0), 255);
        img->data[i].g = fmin(fmax((img->data[i].g - 128) * contrast + 128 + brightness, 0), 255);
        img->data[i].b = fmin(fmax((img->data[i].b - 128) * contrast + 128 + brightness, 0), 255);
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

int main() {
    char inputFile[256], outputFile[256];
    int brightness;
    float contrast;

    printf("Enter the input PPM file name: ");
    scanf("%s", inputFile);
    
    Image *img = loadPPM(inputFile);
    if (!img) {
        return 1;
    }

    printf("Choose an operation:\n1. Flip horizontally\n2. Adjust brightness and contrast\n");
    int choice;
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            flipHorizontal(img);
            printf("Image flipped horizontally.\n");
            break;
        case 2:
            printf("Enter brightness adjustment (-255 to 255): ");
            scanf("%d", &brightness);
            printf("Enter contrast adjustment (e.g. 1.5 for more contrast): ");
            scanf("%f", &contrast);
            adjustBrightnessContrast(img, brightness, contrast);
            printf("Brightness and contrast adjusted.\n");
            break;
        default:
            printf("Invalid choice.\n");
            freeImage(img);
            return 1;
    }
    
    printf("Enter the output PPM file name: ");
    scanf("%s", outputFile);
    savePPM(outputFile, img);
    
    printf("Image processing completed. Saved to %s\n", outputFile);
    
    freeImage(img);
    return 0;
}