//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// function to convert image to ASCII art
void convertToAsciiArt(char *imageFilename, char* outputFilename);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: ./converter <input_image_filename> <output_file_name>\n");
        exit(1);
    }

    // get input image filename
    char *imageFilename = argv[1];
    // get output filename
    char *outputFilename = argv[2];

    // call function to convert image to ascii art
    convertToAsciiArt(imageFilename, outputFilename);

    return 0;
}

void convertToAsciiArt(char *imageFilename, char* outputFilename) {
    FILE *imageFile = fopen(imageFilename, "r");
    FILE *outputFile = fopen(outputFilename, "w");

    if(imageFile == NULL || outputFile == NULL) {
        printf("Could not open files.\n");
        exit(1);
    }

    char asciiChars[] = {' ','.',':','-','=','+','*','#','%','@'};

    char image[MAX_SIZE][MAX_SIZE];
    int row = 0, col = 0;
    char c;
    while((c = fgetc(imageFile)) != EOF) {
        if(c == '\n') {
            col = 0;
            row++;
        } else {
            image[row][col] = c;
            col++;
        }
    }

    int imageWidth = strlen(image[0]);
    int imageHeight = row;

    for(int i = 0; i < imageHeight; i++) {
        for(int j = 0; j < imageWidth; j++) {
            int grayScale = ((int) image[i][j]) * 10 / 255;
            char asciiChar = asciiChars[grayScale];
            fputc(asciiChar, outputFile);
        }
        fputc('\n', outputFile);
    }

    fclose(imageFile);
    fclose(outputFile);
}