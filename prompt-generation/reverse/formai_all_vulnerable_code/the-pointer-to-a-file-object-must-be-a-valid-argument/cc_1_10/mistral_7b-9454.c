//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <limits.h>
#include <math.h>
#include <ctype.h>

#define WIDTH 51
#define HEIGHT 15
#define MAX_COLOR 3
#define ASCII_CHARS " .:!*oe&#%@"

typedef struct {
    unsigned char r, g, b;
} pixel_t;

pixel_t *map;

void read_ppm(const char *filename, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    char magic_number[3];
    int i;

    fgets(magic_number, sizeof(magic_number), fp);
    if (strncmp(magic_number, "P6", 2) != 0) {
        perror("Invalid PPM file");
        exit(EXIT_FAILURE);
    }

    fscanf(fp, "%d%d", width, height);

    map = mmap(NULL, *width * *height * sizeof(pixel_t), PROT_READ | PROT_WRITE, MAP_PRIVATE, fileno(fp), 0);

    for (i = 0; i < *width * *height; ++i) {
        fscanf(fp, "%hhu%hhu%hhu", &map[i].r, &map[i].g, &map[i].b);
    }

    mprotect(map, *width * *height * sizeof(pixel_t), PROT_READ);
    fclose(fp);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input.ppm>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int width, height;
    read_ppm(argv[1], &width, &height);

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            int index = (y * WIDTH + x) * MAX_COLOR;
            printf("%c%c%c", ASCII_CHARS[(int)(map[y * width + x].r / (255.0 * MAX_COLOR))],
                   ASCII_CHARS[(int)(map[y * width + x].g / (255.0 * MAX_COLOR))],
                   ASCII_CHARS[(int)(map[y * width + x].b / (255.0 * MAX_COLOR))]);
        }
        putchar('\n');
    }

    munmap(map, width * height * sizeof(pixel_t));

    return EXIT_SUCCESS;
}