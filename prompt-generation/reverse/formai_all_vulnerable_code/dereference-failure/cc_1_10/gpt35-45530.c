//FormAI DATASET v1.0 Category: Image Editor ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define ROWS 512
#define COLS 512

void invert_color(unsigned char img[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            img[i][j] = 255 - img[i][j];
        }
    }
}

void flip_vertical(unsigned char img[ROWS][COLS]) {
    unsigned char temp;
    for(int i = 0; i < ROWS/2; i++) {
        for(int j = 0; j < COLS; j++) {
            temp = img[i][j];
            img[i][j] = img[ROWS-i-1][j];
            img[ROWS-i-1][j] = temp;
        }
    }
}

void blur(unsigned char img[ROWS][COLS]) {
    unsigned char temp[ROWS][COLS];
    for(int i = 1; i < ROWS-1; i++) {
        for(int j = 1; j < COLS-1; j++) {
            temp[i][j] = (img[i-1][j-1] + img[i-1][j] + img[i-1][j+1] + img[i][j-1] + img[i][j] + img[i][j+1] + img[i+1][j-1] + img[i+1][j] + img[i+1][j+1])/9;
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            img[i][j] = temp[i][j];
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s [image] [operation]\n", argv[0]);
        return 1;
    }

    // Load image
    FILE *f = fopen(argv[1], "rb");
    if(!f) {
        printf("Error: Could not open file\n");
        return 1;
    }
    unsigned char img[ROWS][COLS];
    fread(img, 1, ROWS*COLS, f);
    fclose(f);

    // Perform requested operation
    if(strcmp(argv[2], "invert") == 0) {
        invert_color(img);
    } else if(strcmp(argv[2], "flip") == 0) {
        flip_vertical(img);
    } else if(strcmp(argv[2], "blur") == 0) {
        blur(img);
    } else {
        printf("Error: Invalid operation\n");
        return 1;
    }

    // Save image
    f = fopen("output.raw", "wb");
    if(!f) {
        printf("Error: Could not open file\n");
        return 1;
    }
    fwrite(img, 1, ROWS*COLS, f);
    fclose(f);

    return 0;
}