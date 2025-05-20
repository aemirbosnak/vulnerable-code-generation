//FormAI DATASET v1.0 Category: Image Editor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define BYTE_SIZE 255

typedef struct {
    int red;
    int green;
    int blue;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel** pixels;
} Image;

int main() {
    int option = 0;
    Image image;
    char filename[50];

    // Prompt user to enter image dimensions
    printf("Enter image width: ");
    scanf("%d", &image.width);
    printf("Enter image height: ");
    scanf("%d", &image.height);

    // Allocate memory for image pixels
    image.pixels = calloc(image.height, sizeof(Pixel*));
    for(int i = 0; i < image.height; i++) {
        image.pixels[i] = calloc(image.width, sizeof(Pixel));
    }

    // Prompt user to enter image pixels
    for(int i = 0; i < image.height; i++) {
        for(int j = 0; j < image.width; j++) {
            printf("Enter pixel values for (%d, %d): ", i, j);
            scanf("%d%d%d", &image.pixels[i][j].red, &image.pixels[i][j].green, &image.pixels[i][j].blue);
        }
    }

    while(option != 6) {
        printf("\nMain Menu:\n");
        printf("1. Grayscale\n");
        printf("2. Invert colors\n");
        printf("3. Brightness adjustment\n");
        printf("4. Contrast adjustment\n");
        printf("5. Write to file\n");
        printf("6. Exit\n\n");
        printf("Enter an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1: {
                // Convert image to grayscale
                for(int i = 0; i < image.height; i++) {
                    for(int j = 0; j < image.width; j++) {
                        int gray = (image.pixels[i][j].red + image.pixels[i][j].green + image.pixels[i][j].blue) / 3;
                        image.pixels[i][j].red = gray;
                        image.pixels[i][j].green = gray;
                        image.pixels[i][j].blue = gray;
                    }
                }
                break;
            }
            case 2: {
                // Invert image colors
                for(int i = 0; i < image.height; i++) {
                    for(int j = 0; j < image.width; j++) {
                        image.pixels[i][j].red = BYTE_SIZE - image.pixels[i][j].red;
                        image.pixels[i][j].green = BYTE_SIZE - image.pixels[i][j].green;
                        image.pixels[i][j].blue = BYTE_SIZE - image.pixels[i][j].blue;
                    }
                }
                break;
            }
            case 3: {
                // Adjust image brightness
                int brightness;
                printf("Enter brightness value (-255 to 255): ");
                scanf("%d", &brightness);

                for(int i = 0; i < image.height; i++) {
                    for(int j = 0; j < image.width; j++) {
                        image.pixels[i][j].red += brightness;
                        image.pixels[i][j].green += brightness;
                        image.pixels[i][j].blue += brightness;

                        // Limit pixel values to valid range
                        if(image.pixels[i][j].red < 0) image.pixels[i][j].red = 0;
                        if(image.pixels[i][j].red > BYTE_SIZE) image.pixels[i][j].red = BYTE_SIZE;
                        if(image.pixels[i][j].green < 0) image.pixels[i][j].green = 0;
                        if(image.pixels[i][j].green > BYTE_SIZE) image.pixels[i][j].green = BYTE_SIZE;
                        if(image.pixels[i][j].blue < 0) image.pixels[i][j].blue = 0;
                        if(image.pixels[i][j].blue > BYTE_SIZE) image.pixels[i][j].blue = BYTE_SIZE;
                    }
                }
                break;
            }
            case 4: {
                // Adjust image contrast
                float contrast;
                printf("Enter contrast value (0.0 to 10.0): ");
                scanf("%f", &contrast);

                float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
                for(int i = 0; i < image.height; i++) {
                    for(int j = 0; j < image.width; j++) {
                        image.pixels[i][j].red = (int)(factor * (image.pixels[i][j].red - 128) + 128);
                        image.pixels[i][j].green = (int)(factor * (image.pixels[i][j].green - 128) + 128);
                        image.pixels[i][j].blue = (int)(factor * (image.pixels[i][j].blue - 128) + 128);

                        // Limit pixel values to valid range
                        if(image.pixels[i][j].red < 0) image.pixels[i][j].red = 0;
                        if(image.pixels[i][j].red > BYTE_SIZE) image.pixels[i][j].red = BYTE_SIZE;
                        if(image.pixels[i][j].green < 0) image.pixels[i][j].green = 0;
                        if(image.pixels[i][j].green > BYTE_SIZE) image.pixels[i][j].green = BYTE_SIZE;
                        if(image.pixels[i][j].blue < 0) image.pixels[i][j].blue = 0;
                        if(image.pixels[i][j].blue > BYTE_SIZE) image.pixels[i][j].blue = BYTE_SIZE;
                    }
                }
                break;
            }
            case 5: {
                // Write image to file in PPM format
                printf("Enter filename: ");
                scanf("%s", filename);

                FILE* file = fopen(filename, "w");
                fprintf(file, "P3\n%d %d\n%d\n", image.width, image.height, BYTE_SIZE);

                for(int i = 0; i < image.height; i++) {
                    for(int j = 0; j < image.width; j++) {
                        fprintf(file, "%d %d %d ", image.pixels[i][j].red, image.pixels[i][j].green, image.pixels[i][j].blue);
                    }
                    fprintf(file, "\n");
                }

                fclose(file);
                printf("Image saved to %s\n", filename);
                break;
            }
            case 6: {
                // Exit program
                break;
            }
            default: {
                // Invalid option
                printf("Invalid option. Please try again.\n");
                break;
            }
        }
    }

    // Free memory allocated for image pixels
    for(int i = 0; i < image.height; i++) {
        free(image.pixels[i]);
    }
    free(image.pixels);

    return 0;
}