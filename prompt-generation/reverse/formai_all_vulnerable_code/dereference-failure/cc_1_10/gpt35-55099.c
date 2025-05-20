//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

void convertImageToASCII(FILE* inputFile, FILE* outputFile);

int main(int argc, char* argv[]){
    if(argc != 3){
        printf("Invalid arguments.\nUsage: ./img-to-ascii [input_file] [output_file]\n");
        exit(EXIT_FAILURE);
    }

    FILE* inputFile = fopen(argv[1], "r");
    FILE* outputFile = fopen(argv[2], "w");

    if(inputFile == NULL || outputFile == NULL){
        printf("Error: Unable to open files.\n");
        exit(EXIT_FAILURE);
    }

    convertImageToASCII(inputFile, outputFile);

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

void convertImageToASCII(FILE* inputFile, FILE* outputFile){
    char asciiChars[] = { '.', ',', ':', ';', 'i', '1', 't', 'f', 'L', 'C', 'G', '0', '@' };
    int numChars = strlen(asciiChars);
    int width, height, maxVal;
    char* imageData[MAX_HEIGHT];
    char line[MAX_WIDTH];

    fgets(line, sizeof(line), inputFile);

    // skipping comments
    while(line[0] == '#'){
        fgets(line, sizeof(line), inputFile);
    }

    sscanf(line, "%d %d", &width, &height);
    fprintf(outputFile, "Width: %d, Height: %d\n", width, height);

    // reading max value
    fgets(line, sizeof(line), inputFile);
    sscanf(line, "%d", &maxVal);

    // reading image data
    for(int i = 0; i < height; i++){
        imageData[i] = (char*)malloc(sizeof(char) * width);
        fgets(line, sizeof(line), inputFile);
        for(int j = 0; j < width; j++){
            imageData[i][j] = line[j];
        }
    }

    // converting image data to ASCII
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            int pixelVal = imageData[i][j] * numChars / maxVal;
            fprintf(outputFile, "%c", asciiChars[pixelVal]);
        }
        fprintf(outputFile, "\n");
    }
}