//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_RGB_VALUE 255
#define MIN_RGB_VALUE 0

typedef struct{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} RGBpixel;

RGBpixel** readImageFile(FILE *filePointer, int *width, int *height);
void writeImageFile(RGBpixel **image, int width, int height, FILE *filePointer);
void freeImage(RGBpixel **image, int height);
void flipImage(RGBpixel **image, int width, int height);
void adjustBrightness(RGBpixel **image, int width, int height, int brightness);
void adjustContrast(RGBpixel **image, int width, int height, float contrast);

int main()
{
    FILE *inputFile, *outputFile;
    char imageName[100];
    int option, width, height, brightness;
    float contrast;
    RGBpixel **image;

    // Read input image file
    printf("Enter the input image file name: ");
    scanf("%s", imageName);
    inputFile = fopen(imageName, "rb");
    if(inputFile == NULL){
        printf("Error openning the input image file.");
        exit(1);
    }
    image = readImageFile(inputFile, &width, &height);
    fclose(inputFile);

    // Display menu
    printf("Choose an option:\n");
    printf("1. Flip image\n");
    printf("2. Adjust brightness\n");
    printf("3. Adjust contrast\n");
    scanf("%d", &option);

    // Process image based on user input
    switch(option){
        case 1:
            flipImage(image, width, height);
            break;
        case 2:
            printf("Enter the brightness value (-255 to 255): ");
            scanf("%d", &brightness);
            adjustBrightness(image, width, height, brightness);
            break;
        case 3:
            printf("Enter the contrast value (0.0 to 3.0): ");
            scanf("%f", &contrast);
            adjustContrast(image, width, height, contrast);
            break;
        default:
            printf("Invalid option selected.");
            exit(1);
    }

    // Write output image file
    printf("Enter the output image file name: ");
    scanf("%s", imageName);
    outputFile = fopen(imageName, "wb");
    if(outputFile == NULL){
        printf("Error creating the output image file.");
        exit(1);
    }
    writeImageFile(image, width, height, outputFile);
    fclose(outputFile);

    // Free memory
    freeImage(image, height);

    return 0;
}

RGBpixel** readImageFile(FILE *filePointer, int *width, int *height)
{
    char imageType[3];
    int maxRGBvalue;

    // Read image type ("P6")
    fgets(imageType, 3, filePointer);
    if(imageType[0] != 'P' || imageType[1] != '6'){
        printf("Error: not a P6 PPM image file.");
        exit(1);
    }

    // Read image width, height and maximum RGB value
    fscanf(filePointer, "%d %d\n%d\n", width, height, &maxRGBvalue);

    // Allocate memory for image array
    RGBpixel **image = (RGBpixel**) malloc(*height * sizeof(RGBpixel*));
    for(int i = 0; i < *height; i++){
        image[i] = (RGBpixel*) malloc(*width * sizeof(RGBpixel));
    }

    // Read pixel values
    for(int i = 0; i < *height; i++){
        for(int j = 0; j < *width; j++){
            fread(&image[i][j].red, 1, 1, filePointer);
            fread(&image[i][j].green, 1, 1, filePointer);
            fread(&image[i][j].blue, 1, 1, filePointer);
        }
    }

    return image;
}

void writeImageFile(RGBpixel **image, int width, int height, FILE *filePointer)
{
    fprintf(filePointer, "P6\n%d %d\n%d\n", width, height, MAX_RGB_VALUE);

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            fwrite(&image[i][j].red, 1, 1, filePointer);
            fwrite(&image[i][j].green, 1, 1, filePointer);
            fwrite(&image[i][j].blue, 1, 1, filePointer);
        }
    }
}

void freeImage(RGBpixel **image, int height)
{
    for(int i = 0; i < height; i++){
        free(image[i]);
    }
    free(image);
}

void flipImage(RGBpixel **image, int width, int height)
{
    RGBpixel temp;
    for(int i = 0; i < height / 2; i++){
        for(int j = 0; j < width; j++){
            temp = image[i][j];
            image[i][j] = image[height - 1 - i][j];
            image[height - 1 - i][j] = temp;
        }
    }
}

void adjustBrightness(RGBpixel **image, int width, int height, int brightness)
{
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].red += brightness;
            image[i][j].green += brightness;
            image[i][j].blue += brightness;

            // clamp RGB values to [0, 255]
            image[i][j].red = image[i][j].red > MAX_RGB_VALUE ? MAX_RGB_VALUE : (image[i][j].red < MIN_RGB_VALUE ? MIN_RGB_VALUE : image[i][j].red);
            image[i][j].green = image[i][j].green > MAX_RGB_VALUE ? MAX_RGB_VALUE : (image[i][j].green < MIN_RGB_VALUE ? MIN_RGB_VALUE : image[i][j].green);
            image[i][j].blue = image[i][j].blue > MAX_RGB_VALUE ? MAX_RGB_VALUE : (image[i][j].blue < MIN_RGB_VALUE ? MIN_RGB_VALUE : image[i][j].blue);
        }
    }
}

void adjustContrast(RGBpixel **image, int width, int height, float contrast)
{
    float factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            image[i][j].red = factor * (image[i][j].red - 128) + 128;
            image[i][j].green = factor * (image[i][j].green - 128) + 128;
            image[i][j].blue = factor * (image[i][j].blue - 128) + 128;

            // clamp RGB values to [0, 255]
            image[i][j].red = image[i][j].red > MAX_RGB_VALUE ? MAX_RGB_VALUE : (image[i][j].red < MIN_RGB_VALUE ? MIN_RGB_VALUE : image[i][j].red);
            image[i][j].green = image[i][j].green > MAX_RGB_VALUE ? MAX_RGB_VALUE : (image[i][j].green < MIN_RGB_VALUE ? MIN_RGB_VALUE : image[i][j].green);
            image[i][j].blue = image[i][j].blue > MAX_RGB_VALUE ? MAX_RGB_VALUE : (image[i][j].blue < MIN_RGB_VALUE ? MIN_RGB_VALUE : image[i][j].blue);
        }
    }
}