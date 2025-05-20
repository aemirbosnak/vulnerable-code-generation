//FormAI DATASET v1.0 Category: Fractal Generation ; Style: immersive
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 

// Define the size of image and the number of iterations
#define WIDTH 800 
#define HEIGHT 800 
#define ITERATIONS 1000

// Define the coordinates of the image
#define XMIN -2.5 
#define XMAX 1.5 
#define YMIN -2.0 
#define YMAX 2.0 

// Define color and pixel values
#define BLACK 0 
#define WHITE 255 
#define PIXEL_COLOR_VALUE 204

void fillBitmap(unsigned char* Bitmap, int Index) { 
    int pix_x = Index % WIDTH; 
    int pix_y = Index / WIDTH; 
    double x = XMIN + ((double)pix_x / WIDTH) * (XMAX - XMIN); 
    double y = YMIN + ((double)pix_y / HEIGHT) * (YMAX - YMIN); 

    double zx = 0; 
    double zy = 0; 

    int k = 0; 

    while(k < ITERATIONS) { 
        double xtemp = zx * zx - zy * zy + x; 
        zy = 2 * zx * zy + y; 
        zx = xtemp; 
        k++; 

        if(zx * zx + zy * zy > 4.0) { 
            Bitmap[Index] = PIXEL_COLOR_VALUE; 
            return; 
        } 
    } 

    Bitmap[Index] = BLACK; 
} 

int main(int argc, char* argv[]) { 
    int BitmapSize = WIDTH * HEIGHT * sizeof(char); 
    unsigned char* Bitmap = (unsigned char*)malloc(BitmapSize); 

    for(int i = 0; i < WIDTH * HEIGHT; i++) { 
        fillBitmap(Bitmap, i); 
    } 

    // Output the bitmap 
    printf("P2\n"); 
    printf("%d %d\n", WIDTH, HEIGHT); 
    printf("%d\n", WHITE); 

    for(int i = 0; i < WIDTH * HEIGHT; i++) { 
        printf("%d ", Bitmap[i]); 
    } 

    free(Bitmap); 
    return 0; 
}