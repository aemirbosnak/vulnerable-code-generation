//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

// Function to convert image to ASCII art
void image_to_ascii(int width, int height, char *filename) {
    FILE *fp;
    int i, j, k, l, m, n, count;
    char ch;
    unsigned char *data;

    // Open the image file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    // Allocate memory for the image data
    data = (unsigned char *) malloc(width * height * 3);
    if (data == NULL) {
        printf("Error: Could not allocate memory.\n");
        exit(1);
    }

    // Read the image data from the file
    fread(data, width * height * 3, 1, fp);

    // Close the image file
    fclose(fp);

    // Convert the image data to ASCII art
    printf("P6\n%d %d\n255\n", width, height);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            count = 0;
            for (k = 0; k < 3; k++) {
                m = i * width * 3 + j * 3 + k;
                n = 255 - data[m];
                while (n >= 0 && n < 6) {
                    ch = "@%#*+=-:. "[n];
                    printf("%c", ch);
                    count++;
                    n--;
                }
            }
            while (count < 6) {
                printf(" ");
                count++;
            }
        }
        printf("\n");
    }

    // Free the memory for the image data
    free(data);
}

int main(int argc, char *argv[]) {
    int width, height;

    // Check if the correct number of arguments were provided
    if (argc!= 4) {
        printf("Usage: %s <width> <height> <filename>\n", argv[0]);
        exit(1);
    }

    // Convert command line arguments to integers
    width = atoi(argv[1]);
    height = atoi(argv[2]);

    // Convert image to ASCII art
    image_to_ascii(width, height, argv[3]);

    return 0;
}