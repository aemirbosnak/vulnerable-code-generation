//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: real-life
// This program converts a given image file to ASCII art

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

#define MAX_PIXEL_VALUE 255
#define ROWS_PER_CHAR 8
#define COLS_PER_CHAR 6

// function to get the ASCII character given the pixel intensity
char getCharacter(int intensity) {
    char characters[] = {' ','.','\'','^','\"',':','~','<','>','/','\\','|','(',')','{}','[]','?','-','_','+','=','*', '#','%','@','X','$'};
    int numChars = sizeof(characters) / sizeof(char);
    int intensityRange = ceil(MAX_PIXEL_VALUE / numChars);
    int charIndex = floor(intensity / intensityRange);
    return characters[charIndex];
}

int main(int argc, char **argv) {

    // check for correct number of arguments
    if(argc != 3) {
        fprintf(stderr, "Usage: %s input_file output_file\n", argv[0]);
        return 1;
    }
  
    // try to open the input file and check for errors
    FILE *inFile = fopen(argv[1], "rb");
    if(!inFile) {
        fprintf(stderr, "Error opening input file: %s. %s\n", argv[1], strerror(errno));
        return 1;
    }

    // try to open the output file and check for errors
    FILE *outFile = fopen(argv[2], "w");
    if(!outFile) {
        fprintf(stderr, "Error opening output file: %s. %s\n", argv[2], strerror(errno));
        fclose(inFile);
        return 1;
    }

    // get the file size
    fseek(inFile, 0, SEEK_END);
    long fileSize = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    // calculate number of characters per line and number of lines
    int numCols = ceil(sqrt(fileSize / 3));
    int numRows = ceil(fileSize / (numCols * 3));

    // read in the image data
    unsigned char *data = malloc(fileSize * sizeof(unsigned char));
    int bytesRead = fread(data, sizeof(unsigned char), fileSize, inFile);

    // convert the image data to ASCII art and write to output file
    for(int row = 0; row < numRows; row++) {
        for(int col = 0; col < numCols; col++) {

            // calculate the average pixel intensity for this character
            int totalIntensity = 0;
            for(int i = row * ROWS_PER_CHAR; i < (row + 1) * ROWS_PER_CHAR; i++) {
                for(int j = col * COLS_PER_CHAR * 3; j < (col + 1) * COLS_PER_CHAR * 3; j += 3) {
                    if(i < numRows && j < fileSize) {
                        int r = data[i * numCols * 3 + j];
                        int g = data[i * numCols * 3 + j + 1];
                        int b = data[i * numCols * 3 + j + 2];
                        totalIntensity += (r + g + b) / 3;
                    }
                }
            }
            int avgIntensity = totalIntensity / (ROWS_PER_CHAR * COLS_PER_CHAR);

            // get the ASCII character that corresponds to this intensity and write to output file
            char c = getCharacter(avgIntensity);
            fprintf(outFile, "%c", c);
        }
        fprintf(outFile, "\n");
    }

    // free memory and close files
    free(data);
    fclose(inFile);
    fclose(outFile);

    return 0;
}