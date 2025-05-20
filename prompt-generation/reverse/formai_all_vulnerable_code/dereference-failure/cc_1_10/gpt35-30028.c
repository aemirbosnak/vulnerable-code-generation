//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void toAscii(char *imagePath);
char *getAscii(int grayValue);

char *grayValues = " .:-=+*#%@";

int main(int argc, char *argv[]) {
    if(argc != 2){
        printf("Error: Please provide image path as argument.");
        return 1;
    }
    char *imagePath = argv[1];
    toAscii(imagePath);
    return 0;
}

void toAscii(char *imagePath){
    FILE *file = fopen(imagePath, "rb");
    if (file == NULL) {
        perror("Cannot open image file.");
        exit(EXIT_FAILURE);
    }

    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, file);

    int width = *(int*)&info[18];
    int height = *(int*)&info[22];
    int row_padded = (width*3 + 3) & (~3);
    unsigned char* data = malloc(sizeof(unsigned char) * row_padded);

    if(data == NULL){
        perror("Error allocating memory!");
        exit(EXIT_FAILURE);
    }

    for(int i = height-1; i >= 0; i--){
        fread(data, sizeof(unsigned char), row_padded, file);
        for(int j = 0; j < width; j++){
            int pixelIndex = j * 3;
            int red = data[pixelIndex+2];
            int green = data[pixelIndex+1];
            int blue = data[pixelIndex];
            int gray = (red + green + blue) / 3;
            printf("%s", getAscii(gray));
        }
        printf("\n");
    }

    fclose(file);
    free(data);
}

char *getAscii(int grayValue){
    int maxIndex = strlen(grayValues)-1;
    int index = (grayValue * maxIndex) / 255;
    return &grayValues[index];
}