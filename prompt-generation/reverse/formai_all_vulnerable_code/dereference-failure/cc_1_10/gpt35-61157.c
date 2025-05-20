//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
/*
 *  C Image to ASCII Art Converter
 *  By [Your Name Here]
 */

#include <stdio.h>
#include <stdlib.h>

#define WIDTH 80
#define HEIGHT 60

void print_art(char *art) {
    // Print out the ASCII art to the console
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

int main() {

    // Read in the image file
    FILE *fp;
    fp = fopen("image.pgm", "r");

    // Allocate memory for the ASCII art
    char *art = malloc(sizeof(char) * WIDTH * HEIGHT);

    if (fp) {

        // Read in the PGM file header
        int w, h, max_val;
        fscanf(fp, "P2 %d %d %d", &w, &h, &max_val);

        // Read in the image data
        int pixel;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                fscanf(fp, "%d", &pixel);

                // Convert pixel to ASCII character
                if (pixel < 51) {
                    art[i * WIDTH + j] = ' ';
                }
                else if (pixel < 102) {
                    art[i * WIDTH + j] = '.';
                }
                else if (pixel < 153) {
                    art[i * WIDTH + j] = '*';
                }
                else if (pixel < 204) {
                    art[i * WIDTH + j] = '+';
                }
                else if (pixel < 255) {
                    art[i * WIDTH + j] = '#';
                }
                else {
                    art[i * WIDTH + j] = '@';
                }
            }
        }

        // Print out the ASCII art
        print_art(art);

        // Free memory
        free(art);

        // Close the file
        fclose(fp);
    }
    else {
        printf("Error opening file.\n");
        return 1;
    }

    return 0;
}