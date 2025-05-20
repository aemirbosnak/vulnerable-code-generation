//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>

#define WIDTH (80) // Width of ASCII art 
#define HEIGHT (60) // Height of ASCII art

int image[WIDTH][HEIGHT]; // 2D array for holding image data
char ASCII[WIDTH][HEIGHT]; // 2D array for holding ASCII art

// Function to read image from binary file
void read_image(char* filename){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("Error: Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    // Read image dimensions
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Verify image dimensions
    if(width > WIDTH || height > HEIGHT){
        printf("Error: Image dimensions exceed max dimensions\n");
        exit(EXIT_FAILURE);
    }

    // Read image data
    fread(image, sizeof(int), width*height, file);

    fclose(file);
}

// Function to map image values to ASCII characters
char map(int value){
    // ASCII character set sorted by darkness
    static const char* ascii_set = " .,-+*#/0123456789@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int set_size = strlen(ascii_set);
    int val = ((double)(value) / INT_MAX) * (set_size-1);
    return ascii_set[val];
}

// Function to convert image array to ASCII art array
void convert_to_ascii(){
    for(int i=0; i<WIDTH; i++){
        for(int j=0; j<HEIGHT; j++){
            ASCII[i][j] = map(image[i][j]);
        }
    }
}

// Function to print ASCII art to console
void print_ascii(){
    for(int j=0; j<HEIGHT; j++){
        for(int i=0; i<WIDTH; i++){
            putchar(ASCII[i][j]);
        }
        putchar('\n');
    }
}

int main(int argc, char** argv){
    if(argc != 2){
        printf("Usage: %s [image file]\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_image(argv[1]);
    convert_to_ascii();
    print_ascii();

    return EXIT_SUCCESS;
}