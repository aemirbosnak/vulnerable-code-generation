//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // max width of ascii art
#define HEIGHT 45 // max height of ascii art

// function to print ascii art
void print_ascii_art(char *art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", art[i*WIDTH + j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *fp;
    char filename[100];
    char *art = NULL;
    int size = 0;

    // get filename from user
    printf("Enter filename: ");
    scanf("%s", filename);

    // open file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // get size of file
    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    // allocate memory for ascii art
    art = (char*) malloc(size);
    if (art == NULL) {
        printf("Error allocating memory.\n");
        exit(1);
    }

    // read file into ascii art
    size = fread(art, 1, size, fp);
    fclose(fp);

    // convert ascii art to upper case
    for (int i = 0; i < size; i++) {
        art[i] = toupper(art[i]);
    }

    // print ascii art
    print_ascii_art(art);

    // free memory
    free(art);

    return 0;
}