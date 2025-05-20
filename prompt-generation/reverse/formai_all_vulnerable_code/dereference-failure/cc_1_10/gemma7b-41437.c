//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int r, c, pixel, max_r, max_c;
    char **img_data;

    // Allocate memory for the image data
    img_data = (char **)malloc(max_r * sizeof(char *) + 1);
    for (r = 0; r < max_r; r++)
    {
        img_data[r] = (char *)malloc(max_c * sizeof(char) + 1);
    }

    // Read the image data
    printf("Enter the number of rows and columns in the image: ");
    scanf("%d %d", &max_r, &max_c);

    printf("Enter the pixel values (separated by commas): ");
    for (r = 0; r < max_r; r++)
    {
        for (c = 0; c < max_c; c++)
        {
            scanf("%d ", &pixel);
            img_data[r][c] = pixel;
        }
    }

    // Convert the image data into ASCII art
    for (r = 0; r < max_r; r++)
    {
        for (c = 0; c < max_c; c++)
        {
            pixel = img_data[r][c];
            switch (pixel)
            {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf(".");
                    break;
                case 2:
                    printf("#");
                    break;
                default:
                    printf("!");
                    break;
            }
        }
        printf("\n");
    }

    // Free the memory allocated for the image data
    for (r = 0; r < max_r; r++)
    {
        free(img_data[r]);
    }
    free(img_data);

    return 0;
}