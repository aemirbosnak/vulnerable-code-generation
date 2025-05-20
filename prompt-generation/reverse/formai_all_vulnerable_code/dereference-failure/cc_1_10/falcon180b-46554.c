//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 25
#define MAX_COLORS 256

typedef struct {
    int r;
    int g;
    int b;
} Color;

Color palette[MAX_COLORS];
int num_colors;

void init_palette() {
    num_colors = 0;
    palette[num_colors++] = (Color){0, 0, 0};
    palette[num_colors++] = (Color){255, 0, 0};
    palette[num_colors++] = (Color){0, 255, 0};
    palette[num_colors++] = (Color){255, 255, 0};
    palette[num_colors++] = (Color){0, 0, 255};
    palette[num_colors++] = (Color){255, 0, 255};
    palette[num_colors++] = (Color){0, 255, 255};
    palette[num_colors++] = (Color){255, 255, 255};
}

void generate_art(char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Error: Could not create file '%s'.\n", filename);
        exit(1);
    }

    srand(time(NULL));
    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int color_index = rand() % num_colors;
            Color color = palette[color_index];
            fprintf(fp, "%c", (char)color.r);
            fprintf(fp, "%c", (char)color.g);
            fprintf(fp, "%c", (char)color.b);
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    printf("Art generated successfully in '%s'.\n", filename);
}

int main(int argc, char** argv) {
    if (argc!= 3) {
        printf("Usage: %s <output_file> <seed>\n", argv[0]);
        return 1;
    }

    int seed = atoi(argv[2]);
    srand(seed);

    init_palette();
    generate_art(argv[1]);

    return 0;
}