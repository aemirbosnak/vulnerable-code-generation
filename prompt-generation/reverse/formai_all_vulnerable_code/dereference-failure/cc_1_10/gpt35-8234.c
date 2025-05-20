//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#define CHAR_WIDTH 8 // width of each character in the ASCII art
#define CHAR_HEIGHT 13 // height of each character in the ASCII art
#define MAX_FILENAME_LENGTH 100 // maximum length of the input file name

// a 13x8 matrix to store the ASCII art of a character
char characters[128][CHAR_HEIGHT][CHAR_WIDTH+1] = {
    // ASCII art of character with value 32 (space)
    {
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        ",
        "        "
    },

    // ASCII art of character with value 33 (!)
    {
        "    __  ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |  | ",
        "   |__| ",
        "        ",
        "        "
    },

    // ASCII art of character with value 34 (")
    {
        "   __ __",
        "  |  |  ",
        "  |  |  ",
        "  |__|__",
        "  / ___/",
        " / /    ",
        "| |     ",
        " \\ \\   ",
        "  \\ \\  ",
        "   \\_\\_",
        "        ",
        "        ",
        "        "
    },

    // ASCII art of character with value 35 (#)
    {
        "         ",
        "   /\\ /\\ ",
        "  /\\_//\\_\\",
        " |    | | ",
        " |____|_|_",
        " /\\   /\\  ",
        "/ /\\ / /\\ ",
        "\\ \\_\\/_/ ",
        " \\_____/ ",
        "         ",
        "         ",
        "         ",
        "         "
    },
    // continue with more ASCII art for other characters
    // ...
};

// function to read the PPM image file and return a 2D matrix of pixel values
int** readPPM(char* filename, int* width, int* height){

    FILE* fp;
    char magic[3];
    int i,j,maxValue;

    fp = fopen(filename, "rb");
    if(fp == NULL){
        printf("Error: cannot open input file.\n");
        exit(1);
    }

    // read the first line of the file to find the magic number
    fgets(magic, 3, fp);

    // make sure it is a P6 PPM file (binary)
    if(strcmp(magic, "P6") != 0){
        printf("Error: not a P6 PPM file.\n");
        exit(1);
    }

    // read the width, height and max pixel value of the image
    fscanf(fp, "%d%d%d", width, height, &maxValue);

    // make sure the max pixel value is 255
    if(maxValue != 255){
        printf("Error: max pixel value not supported.\n");
        exit(1);
    }

    // create a 2D matrix to store the pixel values of the image
    int** pixels = (int**)malloc((*height)*sizeof(int*));
    for(i=0; i<*height; i++){
        pixels[i] = (int*)malloc((*width)*sizeof(int));
    }

    // read the pixel values from the file (must be in binary mode)
    unsigned char pixel[3];
    for(i=0; i<*height; i++){
        for(j=0; j<*width; j++){
            fread(pixel, 1, 3, fp);
            pixels[i][j] = (int)pixel[0]; // ignore other two color channels
        }
    }

    fclose(fp);
    return pixels;
}

// function to convert the 2D matrix of pixel values to ASCII art
void pixel2ASCII(int** pixels, int width, int height){

    int i, j, k, l, p, q;
    int char_value;
    char ascii_char[CHAR_HEIGHT][CHAR_WIDTH+1];

    // for each character row
    for(i=0; i<height/CHAR_HEIGHT; i++){

        // for each character column
        for(j=0; j<width/CHAR_WIDTH; j++){

            // calculate the average value of the pixels in the character region
            int sum = 0;
            for(k=0; k<CHAR_HEIGHT; k++){
                for(l=0; l<CHAR_WIDTH; l++){
                    sum += pixels[i*CHAR_HEIGHT+k][j*CHAR_WIDTH+l];
                }
            }
            int average = sum / (CHAR_HEIGHT*CHAR_WIDTH);

            // choose the ASCII character that resembles the region the most
            char_value = 0;
            int min_diff = 255*CHAR_HEIGHT*CHAR_WIDTH;
            for(p=32; p<128; p++){
                int diff = 0;
                for(k=0; k<CHAR_HEIGHT; k++){
                    for(l=0; l<CHAR_WIDTH; l++){
                        diff += abs(characters[p][k][l] - (average<128?0:255));
                        if(average < characters[p][k][l]) diff += (characters[p][k][l] - average);
                        else diff += (average - characters[p][k][l]);
                    }
                }
                if(diff < min_diff){
                    min_diff = diff;
                    char_value = p;
                }
            }

            // copy the ASCII art of the chosen character to the output buffer
            for(k=0; k<CHAR_HEIGHT; k++){
                for(l=0; l<CHAR_WIDTH; l++){
                    ascii_char[k][l] = characters[char_value][k][l];
                }
                ascii_char[k][CHAR_WIDTH] = '\0';
            }

            // output the ASCII art to console
            for(k=0; k<CHAR_HEIGHT; k++){
                printf("%s\n", ascii_char[k]);
            }
        }

        // insert a new line between rows of characters
        printf("\n");
    }

}

int main(){

    int width, height;
    char filename[MAX_FILENAME_LENGTH];

    // read the input file name from command line argument
    printf("Enter the input file name: ");
    scanf("%s", filename);

    // read the PPM image file and store the pixel values in a 2D matrix
    int** image = readPPM(filename, &width, &height);

    // convert the pixel values to ASCII art and output to console
    pixel2ASCII(image, width, height);

    // free the memory used by the 2D matrix of pixel values
    int i;
    for(i=0; i<height; i++){
        free(image[i]);
    }
    free(image);

    return 0;
}