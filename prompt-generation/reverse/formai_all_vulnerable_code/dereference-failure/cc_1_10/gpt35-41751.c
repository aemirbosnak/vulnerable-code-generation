//FormAI DATASET v1.0 Category: Image Editor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_COMMAND_LENGTH 10
#define MAX_COLOR_VALUE 255

// structure to hold image data
typedef struct Image {
    int numRows;
    int numCols;
    int maxVal;
    int **pixels;
} Image;

// function to read image data from file
void readImage(FILE *file, Image *image) {
    // read header info
    fscanf(file, "P2 %d %d %d\n", &image->numCols, &image->numRows, &image->maxVal);
    
    // allocate space for pixels
    image->pixels = (int **)malloc(sizeof(int *) * image->numRows);
    for (int i = 0; i < image->numRows; i++) {
        image->pixels[i] = (int *)malloc(sizeof(int) * image->numCols);
    }
    
    // read pixel data
    for (int i = 0; i < image->numRows; i++) {
        for (int j = 0; j < image->numCols; j++) {
            fscanf(file, "%d", &image->pixels[i][j]);
        }
    }
}

// function to write image data to file
void writeImage(FILE *file, Image *image) {
    // write header info
    fprintf(file, "P2\n%d %d\n%d\n", image->numCols, image->numRows, image->maxVal);
    
    // write pixel data
    for (int i = 0; i < image->numRows; i++) {
        for (int j = 0; j < image->numCols; j++) {
            fprintf(file, "%d ", image->pixels[i][j]);
        }
        fprintf(file, "\n");
    }
}

// function to flip image horizontally
void flipHorizontal(Image *image) {
    for (int i = 0; i < image->numRows; i++) {
        for (int j = 0; j < image->numCols / 2; j++) {
            int temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[i][image->numCols - j - 1];
            image->pixels[i][image->numCols - j - 1] = temp;
        }
    }
}

// function to flip image vertically
void flipVertical(Image *image) {
    for (int i = 0; i < image->numRows / 2; i++) {
        for (int j = 0; j < image->numCols; j++) {
            int temp = image->pixels[i][j];
            image->pixels[i][j] = image->pixels[image->numRows - i - 1][j];
            image->pixels[image->numRows - i - 1][j] = temp;
        }
    }
}

// function to rotate image 90 degrees clockwise
void rotate90(Image *image) {
    // allocate space for rotated image
    Image *rotated = (Image *)malloc(sizeof(Image));
    rotated->numRows = image->numCols;
    rotated->numCols = image->numRows;
    rotated->maxVal = image->maxVal;
    rotated->pixels = (int **)malloc(sizeof(int *) * rotated->numRows);
    for (int i = 0; i < rotated->numRows; i++) {
        rotated->pixels[i] = (int *)malloc(sizeof(int) * rotated->numCols);
    }
    
    // rotate pixel data
    for (int i = 0; i < rotated->numRows; i++) {
        for (int j = 0; j < rotated->numCols; j++) {
            rotated->pixels[i][j] = image->pixels[image->numRows - j - 1][i];
        }
    }
    
    // free memory of original image
    for (int i = 0; i < image->numRows; i++) {
        free(image->pixels[i]);
    }
    free(image->pixels);
    
    // assign rotated image to original image
    image->numRows = rotated->numRows;
    image->numCols = rotated->numCols;
    image->maxVal = rotated->maxVal;
    image->pixels = rotated->pixels;
}

// function to adjust image brightness
void adjustBrightness(Image *image, int adjustment) {
    // calculate factor by which to adjust pixel values
    double factor = 1.0 + ((double)adjustment / 255.0);
    
    // adjust pixel values
    for (int i = 0; i < image->numRows; i++) {
        for (int j = 0; j < image->numCols; j++) {
            int newValue = (int)(factor * (double)image->pixels[i][j]);
            if (newValue > MAX_COLOR_VALUE) {
                newValue = MAX_COLOR_VALUE;
            }
            image->pixels[i][j] = newValue;
        }
    }
}

// main function
int main() {
    Image image;
    
    // get input file name
    char inputFilename[MAX_FILENAME_LENGTH];
    printf("Enter input file name: ");
    scanf("%s", inputFilename);
    
    // open input file and read image data
    FILE *inputFile = fopen(inputFilename, "r");
    if (inputFile == NULL) {
        printf("Error: could not open input file\n");
        return 1;
    }
    readImage(inputFile, &image);
    fclose(inputFile);
    
    // loop for processing commands
    char command[MAX_COMMAND_LENGTH];
    do {
        // get command from user
        printf("Enter command: ");
        scanf("%s", command);
        
        // process command
        if (strcmp(command, "horizontal") == 0) {
            flipHorizontal(&image);
        } else if (strcmp(command, "vertical") == 0) {
            flipVertical(&image);
        } else if (strcmp(command, "rotate") == 0) {
            rotate90(&image);
        } else if (strcmp(command, "brightness") == 0) {
            int adjustment;
            printf("Enter brightness adjustment (-255 to 255): ");
            scanf("%d", &adjustment);
            adjustBrightness(&image, adjustment);
        } else if (strcmp(command, "save") == 0) {
            // get output file name
            char outputFilename[MAX_FILENAME_LENGTH];
            printf("Enter output file name: ");
            scanf("%s", outputFilename);
            
            // open output file and write image data
            FILE *outputFile = fopen(outputFilename, "w");
            if (outputFile == NULL) {
                printf("Error: could not open output file\n");
                continue;
            }
            writeImage(outputFile, &image);
            fclose(outputFile);
            
            printf("Image saved to %s\n", outputFilename);
        } else if (strcmp(command, "quit") == 0) {
            break;
        } else {
            printf("Unrecognized command\n");
        }
    } while (1);
    
    // free memory
    for (int i = 0; i < image.numRows; i++) {
        free(image.pixels[i]);
    }
    free(image.pixels);
    
    return 0;
}