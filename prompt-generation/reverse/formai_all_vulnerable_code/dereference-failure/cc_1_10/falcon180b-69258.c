//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

// Function to convert image to ASCII art
void image_to_ascii(char* filename, int width, int height) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    unsigned char header[54];
    fread(header, 1, 54, fp);

    int bytes_per_pixel = header[28] & 0xFF;
    int image_size = width * height * bytes_per_pixel;

    unsigned char* image_data = malloc(image_size);
    fread(image_data, 1, image_size, fp);
    fclose(fp);

    int max_value = 0;
    for (int i = 0; i < image_size; i++) {
        if (image_data[i] > max_value) {
            max_value = image_data[i];
        }
    }

    printf("P6\n%d %d\n%d\n", width, height, max_value);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int value = image_data[index] * (max_value / 255);

            printf("%c", '@' + value);
        }
        printf("\n");
    }

    free(image_data);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <width> <height>\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    image_to_ascii(argv[1], width, height);

    return 0;
}