//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

//define the dimensions of the image and the ASCII art
#define WIDTH 40
#define HEIGHT 25
#define ASCII_WIDTH 80
#define ASCII_HEIGHT 50

char ASCII[ASCII_HEIGHT][ASCII_WIDTH]; //array to hold the ASCII art


//function to convert the image to ASCII art
void convertToASCII(unsigned char* imageData) {
    int avg, pixel;
    int asciiPixelWidth = WIDTH / ASCII_WIDTH;
    int asciiPixelHeight = HEIGHT / ASCII_HEIGHT;
    for (int y = 0; y < ASCII_HEIGHT; y++) {
        for (int x = 0; x < ASCII_WIDTH; x++) {
            //calculate the average brightness of the block of pixels
            avg = 0;
            for (int iy = 0; iy < asciiPixelHeight; iy++) {
                for (int ix = 0; ix < asciiPixelWidth; ix++) {
                    int py = y * asciiPixelHeight + iy;
                    int px = x * asciiPixelWidth + ix;
                    pixel = imageData[py * WIDTH + px];
                    avg += pixel;
                }
            }
            avg /= asciiPixelWidth * asciiPixelHeight;

            //map the brightness to a character in the ASCII table based on its intensity
            if (avg < 25) {
                ASCII[y][x] = '@';
            }
            else if (avg < 50) {
                ASCII[y][x] = '#';
            }
            else if (avg < 75) {
                ASCII[y][x] = '*';
            }
            else if (avg < 100) {
                ASCII[y][x] = '+';
            }
            else if (avg < 125) {
                ASCII[y][x] = '=';
            }
            else if (avg < 150) {
                ASCII[y][x] = '-';
            }
            else if (avg < 175) {
                ASCII[y][x] = ':';
            }
            else if (avg < 200) {
                ASCII[y][x] = '.';
            }
            else {
                ASCII[y][x] = ' ';
            }
        }
    }
}


int main() {
    FILE* file;
    unsigned char* imageData = malloc(WIDTH * HEIGHT);

    //open the image file
    file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error: could not open image file\n");
        return 1;
    }

    //read the image data into memory
    fseek(file, 54, SEEK_SET);
    fread(imageData, WIDTH * HEIGHT, 1, file);
    fclose(file);

    //convert the image data to ASCII art
    convertToASCII(imageData);
    free(imageData);

    //print the ASCII art to the console
    for (int y = 0; y < ASCII_HEIGHT; y++) {
        for (int x = 0; x < ASCII_WIDTH; x++) {
            printf("%c", ASCII[y][x]);
        }
        printf("\n");
    }

    return 0;
}