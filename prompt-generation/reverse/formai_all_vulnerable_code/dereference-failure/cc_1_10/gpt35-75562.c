//FormAI DATASET v1.0 Category: Image Editor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

#define ROWS 256
#define COLS 256

int *read_image(FILE *file);
void write_image(FILE *file, int *image);

int main()
{
    FILE *input_file, *output_file;
    int *image;

    // Open input file and read image into memory
    input_file = fopen("input_image.txt", "r");
    if (input_file == NULL)
    {
        printf("Error: could not open input file\n");
        return 1;
    }
    image = read_image(input_file);
    fclose(input_file);

    printf("Image read successfully\n");

    // Perform image editing operations here
    // Example: invert image colors
    for (int i = 0; i < ROWS * COLS; i++)
    {
        image[i] = 255 - image[i];
    }

    // Open output file and write edited image to it
    output_file = fopen("output_image.txt", "w");
    if (output_file == NULL)
    {
        printf("Error: could not open output file\n");
        return 1;
    }
    write_image(output_file, image);
    fclose(output_file);

    printf("Image editing completed successfully\n");

    // Free dynamically allocated memory
    free(image);

    return 0;
}

int *read_image(FILE *file)
{
    int *image = malloc(sizeof(int) * ROWS * COLS);
    if (image == NULL)
    {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    int pixel;
    for (int i = 0; i < ROWS * COLS; i++)
    {
        fscanf(file, "%d", &pixel);
        image[i] = pixel;
    }

    return image;
}

void write_image(FILE *file, int *image)
{
    for (int i = 0; i < ROWS * COLS; i++)
    {
        fprintf(file, "%d ", image[i]);
        if ((i + 1) % COLS == 0)
        {
            fprintf(file, "\n");
        }
    }
}