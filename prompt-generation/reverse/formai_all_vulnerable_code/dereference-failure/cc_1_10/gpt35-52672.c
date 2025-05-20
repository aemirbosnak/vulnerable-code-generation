//FormAI DATASET v1.0 Category: Fractal Generation ; Style: creative
#include <stdio.h>
#include <math.h>

#define WIDTH 800           
#define HEIGHT 800         
#define MAX_ITERATIONS 50   
#define SCALE 2.0           

void set_pixel(unsigned char *data, int x, int y, int value)
{
    int index = (y * WIDTH + x) * 3;
    data[index] = value;
    data[index + 1] = value;
    data[index + 2] = value;
}

void generate_fractal(unsigned char *data,double x_center, double y_center, double zoom)
{
    double xs, ys, zx, zy, zx2, zy2;
    int i, j, iterations;
    for (i = 0; i < WIDTH; i++) {
        for (j = 0; j < HEIGHT; j++) {
            xs = SCALE * (i - WIDTH / 2.0) / (0.5 * zoom * WIDTH) + x_center;
            ys = SCALE * (j - HEIGHT / 2.0) / (0.5 * zoom * HEIGHT) + y_center;
            zx = 0;
            zy = 0;
            zx2 = 0;
            zy2 = 0;
            iterations = 0;
            while (zx2 + zy2 < 4 && iterations < MAX_ITERATIONS) {
                zy = 2 * zx * zy + ys;
                zx = zx2 - zy2 + xs;
                zx2 = zx * zx;
                zy2 = zy * zy;
                iterations++;
            }
            set_pixel(data, i, j, 255 * iterations / MAX_ITERATIONS);
        }
    }
}

int main()
{
    FILE *file;
    unsigned char header[54];
    unsigned char *data;
    int file_size = 54 + 3 * WIDTH * HEIGHT;
    int i, j;
    double x_center = -0.5, y_center = 0, zoom = 1;
    data = (unsigned char*)malloc(3 * WIDTH * HEIGHT);
    for (i = 0; i < 54; i++) {
        header[i] = 0;
    }
    header[0] = 'B';
    header[1] = 'M';
    header[2] = file_size & 0xFF;
    header[3] = (file_size >> 8) & 0xFF;
    header[4] = (file_size >> 16) & 0xFF;
    header[5] = (file_size >> 24) & 0xFF;
    header[10] = 54;
    header[14] = 40;
    header[18] = WIDTH & 0xFF;
    header[19] = (WIDTH >> 8) & 0xFF;
    header[20] = (WIDTH >> 16) & 0xFF;
    header[21] = (WIDTH >> 24) & 0xFF;
    header[22] = HEIGHT & 0xFF;
    header[23] = (HEIGHT >> 8) & 0xFF;
    header[24] = (HEIGHT >> 16) & 0xFF;
    header[25] = (HEIGHT >> 24) & 0xFF;
    header[26] = 1;
    header[28] = 24;
    file = fopen("fractal.bmp", "wb");
    fwrite(header, sizeof(unsigned char), 54, file);
    generate_fractal(data, x_center, y_center, zoom);
    fwrite(data, sizeof(unsigned char), 3 * WIDTH * HEIGHT, file);
    fclose(file);
    return 0;
}