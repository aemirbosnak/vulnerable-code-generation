//FormAI DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
//—-Claude Shannon Style C Image Editor—-

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//—-Image struct—-
typedef struct {
    char magicNum[3]; //file type
    int width; //image width
    int height; //image height
    int maxVal; //maximum pixel value
    int** pixels; //2D array of pixels
} Image;

//—-Function to create Image struct—-
Image* createImage(char* filename) {
    Image* img = malloc(sizeof(Image));
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }
    //read header
    fscanf(fp, "%s", img->magicNum);
    fscanf(fp, "%d", &img->width);
    fscanf(fp, "%d", &img->height);
    fscanf(fp, "%d", &img->maxVal);
    //allocate memory for pixels
    img->pixels = malloc(img->height * sizeof(int*));
    for (int i = 0; i < img->height; i++) {
        img->pixels[i] = malloc(img->width * sizeof(int));
        for (int j = 0; j < img->width; j++) {
            fscanf(fp, "%d", &img->pixels[i][j]);
        }
    }
    fclose(fp);
    printf("Image created from file %s\n", filename);
    return img;
}

//—-Function to save Image struct to file—-
void saveImage(Image* img, char* filename) {
    FILE* fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error creating file %s\n", filename);
        exit(1);
    }
    //write header
    fprintf(fp, "%s\n", img->magicNum);
    fprintf(fp, "%d %d\n", img->width, img->height);
    fprintf(fp, "%d\n", img->maxVal);
    //write pixels
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fprintf(fp, "%d ", img->pixels[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Image saved to file %s\n", filename);
}

//—-Function to invert colors—-
void invertColors(Image* img) {
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = img->maxVal - img->pixels[i][j];
        }
    }
}

//—-Function to blur image—-
void blur(Image* img, int radius) {
    int** temp = malloc(img->height * sizeof(int*));
    for (int i = 0; i < img->height; i++) {
        temp[i] = malloc(img->width * sizeof(int));
        for (int j = 0; j < img->width; j++) {
            int sum = 0;
            int count = 0;
            for (int k = i - radius; k <= i + radius; k++) {
                for (int l = j - radius; l <= j + radius; l++) {
                    if (k >= 0 && k < img->height && l >= 0 && l < img->width) {
                        sum += img->pixels[k][l];
                        count++;
                    }
                }
            }
            temp[i][j] = sum / count;
        }
    }
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            img->pixels[i][j] = temp[i][j];
        }
        free(temp[i]);
    }
    free(temp);
}

int main() {
    Image* img = createImage("input.pgm");
    invertColors(img);
    saveImage(img, "inverted.pgm");
    blur(img, 3);
    saveImage(img, "blurred.pgm");
    //free memory
    for (int i = 0; i < img->height; i++) {
        free(img->pixels[i]);
    }
    free(img->pixels);
    free(img);
    return 0;
}