//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

void flipImage(pixel* img, int width, int height) {
    pixel temp;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width/2; j++) {
            temp = img[i*width+j];
            img[i*width+j] = img[i*width+width-j-1];
            img[i*width+width-j-1] = temp;
        }
    }
}

void changeBrightness(pixel* img, int width, int height, int brightness) {
    float factor = (float)(brightness+255)/255.0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i*width+j].red = (unsigned char)(factor*img[i*width+j].red);
            img[i*width+j].green = (unsigned char)(factor*img[i*width+j].green);
            img[i*width+j].blue = (unsigned char)(factor*img[i*width+j].blue);
        }
    }
}

void changeContrast(pixel* img, int width, int height, int contrast) {
    float factor = (259.0*(contrast+255.0))/(255.0*(259.0-contrast));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            img[i*width+j].red = (unsigned char)(factor*(img[i*width+j].red-128)+128);
            img[i*width+j].green = (unsigned char)(factor*(img[i*width+j].green-128)+128);
            img[i*width+j].blue = (unsigned char)(factor*(img[i*width+j].blue-128)+128);
        }
    }
}

int main() {
    char filename[100];
    int width, height, brightness, contrast;

    printf("Enter the filename of the image: ");
    fgets(filename, 100, stdin);

    FILE* fp = fopen(filename, "rb");

    if (!fp) {
        printf("Error in opening file.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    pixel* img = malloc(sizeof(pixel)*width*height);

    if (!img) {
        printf("Error in allocating memory.\n");
        exit(1);
    }

    fseek(fp, 54, SEEK_SET);
    fread(img, sizeof(pixel), width*height, fp);

    printf("Enter 1 to flip image horizontally or 2 to flip image vertically: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        flipImage(img, width, height);
    }
    else if (choice == 2) {
        for (int i = 0; i < width/2; i++) {
            for (int j = 0; j < height; j++) {
                pixel temp = img[i*width+j];
                img[i*width+j] = img[(width-i-1)*width+j];
                img[(width-i-1)*width+j] = temp;
            }
        }
    }
    else {
        printf("Invalid choice.\n");
        exit(1);
    }

    printf("Enter the brightness value (between -255 and 255): ");
    scanf("%d", &brightness);
    changeBrightness(img, width, height, brightness);

    printf("Enter the contrast value (between -255 and 255): ");
    scanf("%d", &contrast);
    changeContrast(img, width, height, contrast);

    FILE* out = fopen("output.bmp", "wb");

    if (!out) {
        printf("Error in creating output file.\n");
        exit(1);
    }

    fwrite(&width, sizeof(int), 1, out);
    fwrite(&height, sizeof(int), 1, out);
    fseek(out, 54, SEEK_SET);
    fwrite(img, sizeof(pixel), width*height, out);

    fclose(fp);
    fclose(out);
    free(img);

    printf("Image processing completed successfully.\n");

    return 0;
}