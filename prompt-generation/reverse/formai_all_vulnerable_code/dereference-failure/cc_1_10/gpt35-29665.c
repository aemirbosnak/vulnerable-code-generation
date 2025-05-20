//FormAI DATASET v1.0 Category: Image Editor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME 100
#define MAX_EFFECT_NAME 50

// Function prototypes
void openImage(const char *fileName);
void saveImage(const char *fileName);
void grayscale(); 
void invert();
void blur();
void sharpen();

// Global variables
int width, height, maxColor;
int **red, **green, **blue; // 2D arrays containing pixel intensities

int main() {
    char fileName[MAX_FILE_NAME];
    printf("Enter the name of the file to open: ");
    scanf("%s", fileName);
    openImage(fileName);
    
    char effectName[MAX_EFFECT_NAME];
    while(1) {
        printf("\nEffects available:\n 1. Grayscale\n 2. Invert\n 3. Blur\n 4. Sharpen\n Enter 'quit' to exit.\n");
        printf("Enter the effect name: ");
        scanf("%s", effectName);
        
        if(strcmp(effectName, "quit") == 0) {
            break;
        }
        else if(strcmp(effectName, "Grayscale") == 0) {
            grayscale();
        }
        else if(strcmp(effectName, "Invert") == 0) {
            invert();
        }
        else if(strcmp(effectName, "Blur") == 0) {
            blur();
        }
        else if(strcmp(effectName, "Sharpen") == 0) {
            sharpen();
        }
        else {
            printf("Invalid effect name. Please try again.\n");
        }
    }
    
    printf("\nEnter the name of the file to save: ");
    scanf("%s", fileName);
    saveImage(fileName);
    
    // Free memory
    for(int i = 0; i < height; i++) {
        free(red[i]);
        free(green[i]);
        free(blue[i]);
    }
    free(red);
    free(green);
    free(blue);
    
    return 0;
}

void openImage(const char *fileName) {
    FILE *file = fopen(fileName, "r");
    if(file == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }
    char type[3];
    fscanf(file, "%s", type);
    if(strcmp(type, "P3") != 0) {
        printf("File is not in P3 format.\n");
        exit(1);
    }
    fscanf(file, "%d %d\n%d\n", &width, &height, &maxColor);
    red = (int **) malloc(height * sizeof(int *));
    green = (int **) malloc(height * sizeof(int *));
    blue = (int **) malloc(height * sizeof(int *));
    for(int i = 0; i < height; i++) {
        red[i] = (int *) malloc(width * sizeof(int));
        green[i] = (int *) malloc(width * sizeof(int));
        blue[i] = (int *) malloc(width * sizeof(int));
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fscanf(file, "%d %d %d", &red[i][j], &green[i][j], &blue[i][j]);
        }
    }
    fclose(file);
}

void saveImage(const char *fileName) {
    FILE *file = fopen(fileName, "w");
    fprintf(file, "P3\n");
    fprintf(file, "%d %d\n%d\n", width, height, maxColor);
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(file, "%d %d %d ", red[i][j], green[i][j], blue[i][j]);
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

void grayscale() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int average = (red[i][j] + green[i][j] + blue[i][j]) / 3;
            red[i][j] = average;
            green[i][j] = average;
            blue[i][j] = average;
        }
    }
}

void invert() {
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            red[i][j] = maxColor - red[i][j];
            green[i][j] = maxColor - green[i][j];
            blue[i][j] = maxColor - blue[i][j];
        }
    }
}

void blur() { 
    int **newRed, **newGreen, **newBlue;
    newRed = (int **) malloc(height * sizeof(int *));
    newGreen = (int **) malloc(height * sizeof(int *));
    newBlue = (int **) malloc(height * sizeof(int *));
    for(int i = 0; i < height; i++) {
        newRed[i] = (int *) malloc(width * sizeof(int));
        newGreen[i] = (int *) malloc(width * sizeof(int));
        newBlue[i] = (int *) malloc(width * sizeof(int));
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0, count = 0;
            for(int k = -1; k <= 1; k++) { 
                for(int l = -1; l <= 1; l++) { 
                    int row = i + k;
                    int col = j + l;
                    if(row >= 0 && row < height && col >= 0 && col < width) {
                        sumRed += red[row][col];
                        sumGreen += green[row][col];
                        sumBlue += blue[row][col];
                        count++;
                    }
                }
            }
            newRed[i][j] = sumRed / count;
            newGreen[i][j] = sumGreen / count;
            newBlue[i][j] = sumBlue / count;
        }
    }
    // Update the image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            red[i][j] = newRed[i][j];
            green[i][j] = newGreen[i][j];
            blue[i][j] = newBlue[i][j];
        }
    }
    // Free memory
    for(int i = 0; i < height; i++) {
        free(newRed[i]);
        free(newGreen[i]);
        free(newBlue[i]);
    }
    free(newRed);
    free(newGreen);
    free(newBlue);
}

void sharpen() {
    int **newRed, **newGreen, **newBlue;
    newRed = (int **) malloc(height * sizeof(int *));
    newGreen = (int **) malloc(height * sizeof(int *));
    newBlue = (int **) malloc(height * sizeof(int *));
    for(int i = 0; i < height; i++) {
        newRed[i] = (int *) malloc(width * sizeof(int));
        newGreen[i] = (int *) malloc(width * sizeof(int));
        newBlue[i] = (int *) malloc(width * sizeof(int));
    }
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            int sumRed = 0, sumGreen = 0, sumBlue = 0;
            for(int k = -1; k <= 1; k++) { 
                for(int l = -1; l <= 1; l++) { 
                    int row = i + k;
                    int col = j + l;
                    if(row >= 0 && row < height && col >= 0 && col < width) {
                        if(k == 0 && l == 0) { // center pixel
                            sumRed += 9 * red[row][col];
                            sumGreen += 9 * green[row][col];
                            sumBlue += 9 * blue[row][col];
                        }
                        else {
                            sumRed -= red[row][col];
                            sumGreen -= green[row][col];
                            sumBlue -= blue[row][col];
                        }
                    }
                }
            }
            newRed[i][j] = red[i][j] + sumRed;
            newGreen[i][j] = green[i][j] + sumGreen;
            newBlue[i][j] = blue[i][j] + sumBlue;
            // Ensure that the values stay within 0 to maxColor
            if(newRed[i][j] < 0) {
                newRed[i][j] = 0;
            }
            if(newGreen[i][j] < 0) {
                newGreen[i][j] = 0;
            }
            if(newBlue[i][j] < 0) {
                newBlue[i][j] = 0;
            }
            if(newRed[i][j] > maxColor) {
                newRed[i][j] = maxColor;
            }
            if(newGreen[i][j] > maxColor) {
                newGreen[i][j] = maxColor;
            }
            if(newBlue[i][j] > maxColor) {
                newBlue[i][j] = maxColor;
            }
        }
    }
    // Update the image
    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            red[i][j] = newRed[i][j];
            green[i][j] = newGreen[i][j];
            blue[i][j] = newBlue[i][j];
        }
    }
    // Free memory
    for(int i = 0; i < height; i++) {
        free(newRed[i]);
        free(newGreen[i]);
        free(newBlue[i]);
    }
    free(newRed);
    free(newGreen);
    free(newBlue);
}