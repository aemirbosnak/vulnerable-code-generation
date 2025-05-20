//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    int channels;
    int size;
    unsigned char* data;
} Image;

void flipImage(Image* image) {
    unsigned char* temp = (unsigned char*)malloc(image->size);
    memcpy(temp, image->data, image->size);
    int tempWidth = image->width;
    int tempHeight = image->height;
    int tempChannels = image->channels;
    int tempSize = image->size;
    int i, j;
    for (i = 0; i < tempHeight; i++) {
        for (j = 0; j < tempWidth; j++) {
            unsigned char tempData = temp[j * tempChannels + tempChannels - 1];
            temp[j * tempChannels + tempChannels - 1] = temp[j * tempChannels];
            temp[j * tempChannels] = tempData;
        }
    }
    memcpy(image->data, temp, image->size);
    free(temp);
}

void changeBrightnessContrast(Image* image, double brightness, double contrast) {
    unsigned char* temp = (unsigned char*)malloc(image->size);
    memcpy(temp, image->data, image->size);
    int tempWidth = image->width;
    int tempHeight = image->height;
    int tempChannels = image->channels;
    int tempSize = image->size;
    int i, j;
    for (i = 0; i < tempHeight; i++) {
        for (j = 0; j < tempWidth; j++) {
            unsigned char tempData = temp[j * tempChannels + tempChannels - 1];
            double brightnessValue = tempData * brightness + (255 - tempData) * (1 - brightness);
            brightnessValue = brightnessValue < 0? 0 : brightnessValue > 255? 255 : brightnessValue;
            temp[j * tempChannels + tempChannels - 1] = brightnessValue;
            tempData = temp[j * tempChannels];
            double contrastValue = tempData * contrast + (255 - tempData) * (1 - contrast);
            contrastValue = contrastValue < 0? 0 : contrastValue > 255? 255 : contrastValue;
            temp[j * tempChannels] = contrastValue;
        }
    }
    memcpy(image->data, temp, image->size);
    free(temp);
}

int main() {
    Image image;
    image.width = 500;
    image.height = 500;
    image.channels = 3;
    image.size = image.width * image.height * image.channels;
    image.data = (unsigned char*)malloc(image.size);
    for (int i = 0; i < image.size; i++) {
        image.data[i] = (unsigned char)i % 256;
    }

    flipImage(&image);
    changeBrightnessContrast(&image, 0.5, 1.2);

    printf("Flipped Image:\n");
    for (int i = 0; i < image.size; i++) {
        printf("%d ", image.data[i]);
    }
    printf("\n");

    return 0;
}