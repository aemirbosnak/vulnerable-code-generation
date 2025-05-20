//FormAI DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

#define ROWS 512
#define COLS 512

/* Struct to represent a pixel in the image */
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

/* Function to read in the image file and return a dynamic array of pixels */
Pixel** readImageFile(char* filename) {
    FILE* imgFile = fopen(filename, "rb");
    if (!imgFile) {
        printf("Error: Unable to open image file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, imgFile);

    Pixel** imgData = (Pixel**)malloc(sizeof(Pixel*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        imgData[i] = (Pixel*)malloc(sizeof(Pixel) * COLS);
        for (int j = 0; j < COLS; j++) {
            imgData[i][j].blue = fgetc(imgFile);
            imgData[i][j].green = fgetc(imgFile);
            imgData[i][j].red = fgetc(imgFile);
        }
    }

    fclose(imgFile);
    return imgData;
}

/* Function to write the edited image data to a new file */
void writeImageFile(Pixel** imgData, char* filename) {
    FILE* imgFile = fopen(filename, "wb+");
    if (!imgFile) {
        printf("Error: Unable to create new image file.\n");
        exit(1);
    }

    unsigned char header[54] = {0x42, 0x4d, 0x36, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    fwrite(header, sizeof(unsigned char), 54, imgFile);

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            fputc(imgData[i][j].blue, imgFile);
            fputc(imgData[i][j].green, imgFile);
            fputc(imgData[i][j].red, imgFile);
        }
    }

    fclose(imgFile);
}

int main() {
    printf("Welcome to the Image Editor Program!\n");

    Pixel** imgData = readImageFile("input.bmp");

    /* Apply an effect to the image */
    printf("Applying Sepia Tone Effect...\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int r = imgData[i][j].red;
            int g = imgData[i][j].green;
            int b = imgData[i][j].blue;
            imgData[i][j].red = (r * 0.393) + (g * 0.769) + (b * 0.189);
            imgData[i][j].green = (r * 0.349) + (g * 0.686) + (b * 0.168);
            imgData[i][j].blue = (r * 0.272) + (g * 0.534) + (b * 0.131);
        }
    }

    writeImageFile(imgData, "output.bmp");
    printf("Image successfully edited and saved as output.bmp. Have a nice day!\n");

    /* Free dynamically allocated memory */
    for (int i = 0; i < ROWS; i++) {
        free(imgData[i]);
    }
    free(imgData);

    return 0;
}