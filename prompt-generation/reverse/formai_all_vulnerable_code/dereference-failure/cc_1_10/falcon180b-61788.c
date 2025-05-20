//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color* generate_palette(int num_colors) {
    Color* palette = malloc(sizeof(Color) * num_colors);

    for (int i = 0; i < num_colors; i++) {
        palette[i].r = rand() % 256;
        palette[i].g = rand() % 256;
        palette[i].b = rand() % 256;
    }

    return palette;
}

void generate_image(Color* palette, int width, int height, FILE* output) {
    int num_pixels = width * height;
    int* pixels = malloc(sizeof(int) * num_pixels);

    for (int i = 0; i < num_pixels; i++) {
        pixels[i] = rand() % MAX_COLORS;
    }

    fprintf(output, "P6\n%d %d\n%d\n", width, height, MAX_COLORS);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            int color_index = pixels[index];

            fprintf(output, "%d %d %d ",
                palette[color_index].r,
                palette[color_index].g,
                palette[color_index].b);
        }
    }
}

int main() {
    srand(time(0));

    int num_colors = 256;
    Color* palette = generate_palette(num_colors);

    char output_filename[20];
    sprintf(output_filename, "image_%d.png", num_colors);

    FILE* output = fopen(output_filename, "wb");

    if (!output) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    generate_image(palette, WIDTH, HEIGHT, output);

    fclose(output);

    printf("Image generated and saved as %s.\n", output_filename);

    return 0;
}