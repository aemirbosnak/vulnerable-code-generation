//FormAI DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int width = 8; // Width of the pixel art
const int height = 8; // Height of the pixel art

// Function to generate random pixel values
int getRandomPixelValue() {
    int randNum = rand() % 2;
    return randNum;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // The pixel art array - 1 represents black and 0 represents white
    int pixelArt[height][width];

    // Generate random pixel values for pixel art
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            pixelArt[i][j] = getRandomPixelValue();
        }
    }

    // Print the pixel art
    printf("Sherlock Holmes Pixel Art Generator\n");
    printf("----------------------------------\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(pixelArt[i][j] == 1) {
                printf("B "); // Print B for black pixel
            } else {
                printf("W "); // Print W for white pixel
            }
        }
        printf("\n");
    }

    // Generate a filename for the pixel art
    char filename[20] = "SherlockPixelArt_";
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char date[16];
    strftime(date, sizeof(date), "%Y%m%d%H%M%S", tm);
    strcat(filename, date);
    strcat(filename, ".txt");

    // Save the pixel art to a file
    FILE *fptr;
    fptr = fopen(filename, "w");
    if(fptr == NULL) {
        printf("Error: Unable to save pixel art to file.\n");
        return 1;
    }
    fprintf(fptr, "Sherlock Holmes Pixel Art Generator\n");
    fprintf(fptr, "----------------------------------\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(pixelArt[i][j] == 1) {
                fprintf(fptr, "B "); // Print B for black pixel
            } else {
                fprintf(fptr, "W "); // Print W for white pixel
            }
        }
        fprintf(fptr, "\n");
    }
    fclose(fptr);

    // Print the filename that the pixel art was saved to
    printf("Pixel art saved to file: %s\n", filename);

    return 0;
}