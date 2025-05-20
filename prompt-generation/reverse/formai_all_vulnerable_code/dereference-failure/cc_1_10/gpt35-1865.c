//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 512
#define MAX_HEIGHT 512
#define MAX_ASCII_DEPTH 11

char ascii_chars[MAX_ASCII_DEPTH] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@', '?'};

int main(int argc, char **argv) {

    if (argc != 2) {
        printf("Please enter the name of an image file\n");
        return 1;
    }

    char *filename = argv[1];

    // Open input file
    FILE *infile = fopen(filename, "r");
    if (!infile) {
        printf("Could not open file: %s\n", filename);
        return 1;
    }

    // Get PPM header
    char ppm_type[3];
    int width, height, depth;
    fscanf(infile, "%2s\n%d %d\n%d\n", ppm_type, &width, &height, &depth);
    if (strcmp(ppm_type, "P6") != 0 || depth > 255) {
        printf("Invalid PPM file format\n");
        return 1;
    }

    // Read image data
    unsigned char image[MAX_WIDTH][MAX_HEIGHT][3];
    fread(image, sizeof(unsigned char), width * height * 3, infile);
    fclose(infile);

    printf("Converting image to ascii art...\n");

    // Convert image to ascii art
    char art[MAX_WIDTH][MAX_HEIGHT];
    int ascii_depth = MAX_ASCII_DEPTH - 1;
    float ascii_interval = depth / ascii_depth;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (int) image[x][y][0];
            int g = (int) image[x][y][1];
            int b = (int) image[x][y][2];
            int average = (r + g + b) / 3;
            int index = (int) (average / ascii_interval);
            index = index > ascii_depth ? ascii_depth : index;
            art[x][y] = ascii_chars[index];
        }
    }

    // Save ascii art to output file
    char output_file[MAX_WIDTH + 4];
    strncpy(output_file, filename, strlen(filename) - 4);
    output_file[strlen(filename) - 4] = '\0';
    strcat(output_file, "_ascii.txt");
    FILE *outfile = fopen(output_file, "w");
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            fputc(art[x][y], outfile);
        }
        fputc('\n', outfile);
    }
    fclose(outfile);

    printf("Done! ASCII art saved to file: %s\n", output_file);

    return 0;
}