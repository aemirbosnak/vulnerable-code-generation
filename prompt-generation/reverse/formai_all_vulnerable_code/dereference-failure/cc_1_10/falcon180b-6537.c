//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random color
void generateColor(int *r, int *g, int *b) {
    *r = rand() % 256;
    *g = rand() % 256;
    *b = rand() % 256;
}

int main() {
    srand(time(NULL));

    // Set the size of the image
    int width = 800;
    int height = 600;

    // Allocate memory for the image
    int **image = (int **)malloc(height * sizeof(int *));
    for (int i = 0; i < height; i++) {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    // Initialize the image with random colors
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int r, g, b;
            generateColor(&r, &g, &b);
            image[i][j] = (r << 16) | (g << 8) | b;
        }
    }

    // Save the image as a PNG file
    FILE *fp = fopen("image.png", "wb");
    if (!fp) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fprintf(fp, "<?xml version=\"1.0\" standalone=\"no\"?>\n");
    fprintf(fp, "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\"\n");
    fprintf(fp, "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">\n");
    fprintf(fp, "<svg width=\"%d\" height=\"%d\">\n", width, height);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fprintf(fp, "<rect x=\"%d\" y=\"%d\" width=\"1\" height=\"1\" fill=\"#%06x\"/>\n", j, i, image[i][j]);
        }
    }

    fprintf(fp, "</svg>");
    fclose(fp);

    for (int i = 0; i < height; i++) {
        free(image[i]);
    }
    free(image);

    return 0;
}