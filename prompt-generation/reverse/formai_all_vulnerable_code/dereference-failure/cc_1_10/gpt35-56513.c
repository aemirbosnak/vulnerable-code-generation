//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_PIXEL 1024

char ascii[MAX_PIXEL][MAX_PIXEL * 2]; //Stores the ASCII art.
char grayscale[MAX_PIXEL][MAX_PIXEL]; //Stores the grayscale values.

// Convert grayscale to ASCII art.
void to_ascii(int height, int width, int max_val) {
    char ascii_chars[] = {'@', '#', '&', '%', '*', '+', '=', '-', ':', '.', ' '};
    int range = max_val / (sizeof(ascii_chars) - 1);

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = grayscale[i][j] / range;
            ascii[i][j * 2] = ascii_chars[index];
            ascii[i][j * 2 + 1] = ascii_chars[index];
        }
        ascii[i][width * 2] = '\0';
    }
}

int main() {
    char filename[100];
    FILE *img = NULL;
    int height, width, max_val, c;

    printf("Enter the filename of the image: ");
    scanf("%s", filename);

    img = fopen(filename, "rb");
    if (img == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    // Read in header information.
    fscanf(img, "P%d\n%d %d\n%d\n", &c, &width, &height, &max_val);
    if (c != 5) {
        printf("Invalid file format.\n");
        return -1;
    }

    // Read in pixel data (grayscale values).
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            grayscale[i][j] = fgetc(img);
        }
    }

    // Generate ASCII art.
    to_ascii(height, width, max_val);

    // Print ASCII art to console and save to file.
    FILE *out = NULL;
    out = fopen("ascii_art.txt", "w");
    if (out == NULL) {
        printf("Error creating file.\n");
        return -1;
    }

    printf("\n%s\n", ascii);
    fprintf(out, "%s", ascii);

    fclose(img);
    fclose(out);
    return 0;
}