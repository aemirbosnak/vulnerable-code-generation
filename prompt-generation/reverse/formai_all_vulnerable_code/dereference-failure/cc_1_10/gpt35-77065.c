//FormAI DATASET v1.0 Category: Fractal Generation ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

static uint32_t image[HEIGHT][WIDTH];

static void set_pixel(int x, int y, uint32_t color)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;

    image[y][x] = color;
}

static uint32_t get_pixel(int x, int y)
{
    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return 0;

    return image[y][x];
}

static void clear_image()
{
    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            image[y][x] = 0;
        }
    }
}

static void save_image(const char *filename)
{
    FILE *fp = fopen(filename, "wb");

    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            uint32_t color = image[y][x];

            fputc((color >> 16) & 0xff, fp);
            fputc((color >> 8) & 0xff, fp);
            fputc(color & 0xff, fp);
        }
    }

    fclose(fp);
}

static void draw_fractal(int max_iterations)
{
    float cx, cy, zx, zy, zx_new;

    for (int y = 0; y < HEIGHT; y++)
    {
        for (int x = 0; x < WIDTH; x++)
        {
            cx = (float)(x - WIDTH / 2) / (float)(WIDTH / 4);
            cy = (float)(y - HEIGHT / 2) / (float)(HEIGHT / 4);

            zx = 0.0f;
            zy = 0.0f;

            int i;

            for (i = 0; i < max_iterations; i++)
            {
                zx_new = zx * zx - zy * zy + cx;
                zy = 2 * zx * zy + cy;
                zx = zx_new;

                if (zx * zx + zy * zy > 4.0f)
                    break;
            }

            uint32_t color = 0;

            if (i < max_iterations)
            {
                float t = (float)i / (float)max_iterations;
                float r = sinf(t * 3.14159f);
                float g = sinf(t * 4.71239f);
                float b = sinf(t * 6.28318f);
                color = (uint32_t)((r * 255.0f) + 0.5f) << 16 |
                        (uint32_t)((g * 255.0f) + 0.5f) <<  8 |
                        (uint32_t)((b * 255.0f) + 0.5f);
            }

            set_pixel(x, y, color);
        }
    }
}

int main(int argc, char **argv)
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <max_iterations> <output_file_name>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int max_iterations = atoi(argv[1]);
    const char *filename = argv[2];

    if (max_iterations <= 0)
    {
        fprintf(stderr, "Invalid number of max_iterations\n");
        return EXIT_FAILURE;
    }

    clear_image();

    draw_fractal(max_iterations);

    save_image(filename);

    return EXIT_SUCCESS;
}