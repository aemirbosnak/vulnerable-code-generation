//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int pixel_size = 1024;
    int **pixel_array = (int**)malloc(pixel_size * sizeof(int*));
    for(int i = 0; i < pixel_size; i++)
    {
        pixel_array[i] = (int*)malloc(pixel_size * sizeof(int));
    }

    // Load pixel data from file
    FILE* file = fopen("image.ppm", "r");
    fscanf(file, "PBM %d %d %d\n", &pixel_size, &pixel_size, &pixel_size);
    for(int y = 0; y < pixel_size; y++)
    {
        for(int x = 0; x < pixel_size; x++)
        {
            fscanf(file, "%d ", &pixel_array[y][x]);
        }
    }
    fclose(file);

    // Modify pixel data
    for(int y = 0; y < pixel_size; y++)
    {
        for(int x = 0; x < pixel_size; x++)
        {
            pixel_array[y][x] = pixel_array[y][x] * 2;
        }
    }

    // Save pixel data to file
    file = fopen("image_edited.ppm", "w");
    fprintf(file, "PBM %d %d %d\n", pixel_size, pixel_size, pixel_size);
    for(int y = 0; y < pixel_size; y++)
    {
        for(int x = 0; x < pixel_size; x++)
        {
            fprintf(file, "%d ", pixel_array[y][x]);
        }
    }
    fclose(file);

    // Free memory
    for(int i = 0; i < pixel_size; i++)
    {
        free(pixel_array[i]);
    }
    free(pixel_array);

    return 0;
}