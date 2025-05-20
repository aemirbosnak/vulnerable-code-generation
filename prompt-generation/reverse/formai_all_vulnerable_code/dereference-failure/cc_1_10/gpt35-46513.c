//FormAI DATASET v1.0 Category: Image Editor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

// function prototypes
void grayscale(int height, int width, int image[height][width]);
void histogram_equalization(int height, int width, int image[height][width]);
void print_image(int height, int width, int image[height][width]);

int main() {
    // image dimensions
    int height = 5;
    int width = 5;
    
    // example image
    int image[5][5] = {
        {200, 100, 50, 150, 75},
        {120, 180, 210, 90, 30},
        {50, 100, 150, 200, 250},
        {80, 120, 160, 200, 240},
        {40, 80, 120, 160, 200}
    };
    
    // grayscale the image
    grayscale(height, width, image);
    
    // perform histogram equalization
    histogram_equalization(height, width, image);
    
    // print the final image
    print_image(height, width, image);
    
    return 0;
}

// convert the image to grayscale
void grayscale(int height, int width, int image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int red = (image[i][j] >> 16) & 0xff;
            int green = (image[i][j] >> 8) & 0xff;
            int blue = image[i][j] & 0xff;
            int gray = 0.2126 * red + 0.7152 * green + 0.0722 * blue;
            image[i][j] = gray << 16 | gray << 8 | gray;
        }
    }
}

// perform histogram equalization on the image
void histogram_equalization(int height, int width, int image[height][width]) {
    // calculate image histogram
    int histogram[256] = {0};
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray = (image[i][j] >> 16) & 0xff;
            histogram[gray]++;
        }
    }
    
    // calculate histogram equalization function
    int cumulative_histogram[256] = {0};
    cumulative_histogram[0] = histogram[0];
    for (int i = 1; i < 256; i++) {
        cumulative_histogram[i] = cumulative_histogram[i-1] + histogram[i];
    }
    
    // perform histogram equalization
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int gray = (image[i][j] >> 16) & 0xff;
            int new_gray = (cumulative_histogram[gray] * 255) / (height * width);
            image[i][j] = new_gray << 16 | new_gray << 8 | new_gray;
        }
    }
}

// print the image to the console
void print_image(int height, int width, int image[height][width]) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("%d ", (image[i][j] >> 16) & 0xff);
        }
        printf("\n");
    }
}