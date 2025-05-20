//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <math.h>
#define WIDTH 64
#define HEIGHT 64
#define BPP 3
#define PIXEL_SIZE (WIDTH * BPP)
typedef struct {
    char name[32];
    unsigned char r, g, b;
} Color;
Color colors[16];
void read_palette(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    int i;
    for (i = 0; i < 16; i++) {
        fgets(colors[i].name, sizeof(colors[i].name), fp);
        fread(&colors[i].r, sizeof(unsigned char), 1, fp);
        fread(&colors[i].g, sizeof(unsigned char), 1, fp);
        fread(&colors[i].b, sizeof(unsigned char), 1, fp);
        fgetc(fp); // skip newline character
    }
    fclose(fp);
}
void generate_pixel_art(const char *output_filename) {
    int x, y, i;
    void *pixels;
    int fd = open(output_filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
    pixels = mmap(NULL, WIDTH * HEIGHT * BPP, PROT_WRITE, MAP_PRIVATE, fd, 0);
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            float hue = (x + y * WIDTH) / (WIDTH * HEIGHT) * 360.0;
            int index = (int)fmod(hue / 30.0, 16);
            Color *color = &colors[index];
            ((unsigned char *)pixels)[y * PIXEL_SIZE + x * BPP] = color->r;
            ((unsigned char *)pixels)[y * PIXEL_SIZE + x * BPP + 1] = color->g;
            ((unsigned char *)pixels)[y * PIXEL_SIZE + x * BPP + 2] = color->b;
        }
    }
    munmap(pixels, WIDTH * HEIGHT * BPP);
    close(fd);
}
int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <input_palette.txt> <output_pixel_art.bmp>\n", argv[0]);
        return 1;
    }
    read_palette(argv[1]);
    generate_pixel_art(argv[2]);
    printf("Pixel art generated successfully!\n");
    return 0;
}