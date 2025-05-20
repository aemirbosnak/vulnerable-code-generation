//FormAI DATASET v1.0 Category: Image Editor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 50

void apply_filter(int height, int width, unsigned char *pixels) {
    // paranoid filter that makes random changes to the image
    for (int i = 0; i < height * width * 4; i += 4) {
        if (rand() % 5 == 0) {
            int r = pixels[i];
            int g = pixels[i + 1];
            int b = pixels[i + 2];
            int a = pixels[i + 3];
            r += rand() % 50 - 25;
            g += rand() % 50 - 25;
            b += rand() % 50 - 25;
            a += rand() % 50 - 25;
            pixels[i] = (r > 255 ? 255 : (r < 0 ? 0 : r));
            pixels[i + 1] = (g > 255 ? 255 : (g < 0 ? 0 : g));
            pixels[i + 2] = (b > 255 ? 255 : (b < 0 ? 0 : b));
            pixels[i + 3] = (a > 255 ? 255 : (a < 0 ? 0 : a));
        }
    }
}

int main() {
    char filename[MAX_FILENAME_LEN];
    printf("Enter the filename of the image to edit: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    // remove newline character from fgets input
    filename[strcspn(filename, "\n")] = 0;
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error in opening image file specified\n");
        return 1;
    }
    // read header data
    char header[54];
    fread(header, sizeof(char), 54, fp);
    // read image data
    int width = *(int *) &header[18];
    int height = *(int *) &header[22];
    int img_size = width * height * 4;
    unsigned char *pixels = (unsigned char *) malloc(img_size);
    fread(pixels, sizeof(unsigned char), img_size, fp);
    fclose(fp);
    // apply paranoid filter
    apply_filter(height, width, pixels);
    // save image data to new file
    char new_filename[MAX_FILENAME_LEN];
    printf("Enter the filename to save the edited image: ");
    fgets(new_filename, MAX_FILENAME_LEN, stdin);
    // remove newline character from fgets input
    new_filename[strcspn(new_filename, "\n")] = 0;
    FILE *fp_new = fopen(new_filename, "wb");
    if (fp_new == NULL) {
        printf("Error in creating new image file\n");
        return 1;
    }
    fwrite(header, sizeof(char), 54, fp_new);
    fwrite(pixels, sizeof(unsigned char), img_size, fp_new);
    fclose(fp_new);
    printf("Paranoid filter applied to image and saved to %s\n", new_filename);
    free(pixels);
    return 0;
}