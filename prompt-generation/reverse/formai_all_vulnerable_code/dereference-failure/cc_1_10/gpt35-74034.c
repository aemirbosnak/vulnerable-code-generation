//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <limits.h>

#define WIDTH 60
#define HEIGHT 45
#define THREAD_COUNT 4

char shades[] = " .:-=+*#%@";

char *pixels;
char *ascii;

void *worker_function(void *arg)
{
    int id = *(int *)arg;
    int start = (HEIGHT / THREAD_COUNT) * id;
    int end = (HEIGHT / THREAD_COUNT) * (id + 1);
    if (id == THREAD_COUNT - 1)
    {
        end = HEIGHT;
    }

    for (int y = start; y < end; y++)
    {
        int row_start = y * WIDTH;
        for (int x = 0; x < WIDTH; x++)
        {
            int p = pixels[row_start + x];
            int shade_id = p * strlen(shades) / UCHAR_MAX;
            ascii[row_start + x] = shades[shade_id];
        }
    }

    pthread_exit(NULL);
}

int main()
{
    pixels = malloc(WIDTH * HEIGHT);
    ascii = malloc(WIDTH * HEIGHT);

    FILE *image_file = fopen("image.dat", "rb");
    if (image_file == NULL)
    {
        printf("Could not open image file\n");
        exit(EXIT_FAILURE);
    }

    fread(pixels, 1, WIDTH * HEIGHT, image_file);
    fclose(image_file);

    pthread_t workers[THREAD_COUNT];
    int worker_ids[THREAD_COUNT];

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        worker_ids[i] = i;
        pthread_create(&workers[i], NULL, worker_function, (void *)&worker_ids[i]);
    }

    for (int i = 0; i < THREAD_COUNT; i++)
    {
        pthread_join(workers[i], NULL);
    }

    FILE *ascii_file = fopen("ascii_art.txt", "w");
    if (ascii_file == NULL)
    {
        printf("Could not open output file\n");
        exit(EXIT_FAILURE);
    }

    for (int y = 0; y < HEIGHT; y++)
    {
        int row_start = y * WIDTH;
        fwrite(ascii + row_start, 1, WIDTH, ascii_file);
        fprintf(ascii_file, "\n");
    }

    fclose(ascii_file);
    free(pixels);
    free(ascii);

    printf("Conversion complete!\n");

    exit(EXIT_SUCCESS);
}