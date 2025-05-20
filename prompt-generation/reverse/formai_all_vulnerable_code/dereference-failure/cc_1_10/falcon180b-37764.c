//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert image to ASCII art
void imageToASCII(char* image, char* ascii) {
    int width, height, i, j, k;
    FILE* fp = fopen(image, "rb");
    if (!fp) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }
    fseek(fp, 18, SEEK_SET); // Skip header
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fclose(fp);

    int size = width * height;
    unsigned char* data = malloc(size * 3);
    if (!data) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    fp = fopen(image, "rb");
    if (!fp) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }
    fseek(fp, 18, SEEK_SET); // Skip header
    fread(data, 3, size, fp);
    fclose(fp);

    ascii[0] = '\0';
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            int r = data[(i * width + j) * 3];
            int g = data[(i * width + j) * 3 + 1];
            int b = data[(i * width + j) * 3 + 2];
            int gray = (r + g + b) / 3;

            if (gray < 63) {
                ascii[k] = '@';
            } else if (gray < 127) {
                ascii[k] = '#';
            } else if (gray < 191) {
                ascii[k] = '%';
            } else if (gray < 255) {
                ascii[k] = '*';
            }
            k++;
        }
        ascii[k] = '\n';
        k++;
    }
    ascii[k] = '\0';
}

int main() {
    char image[100] = "image.bmp";
    char ascii[100000] = "";

    imageToASCII(image, ascii);

    printf("ASCII art:\n%s", ascii);

    return 0;
}