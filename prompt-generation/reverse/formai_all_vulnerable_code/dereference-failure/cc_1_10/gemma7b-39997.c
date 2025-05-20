//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>

#define MAX_IMAGE_SIZE 1024

int main()
{
    int image_width, image_height;
    printf("Enter image width: ");
    scanf("%d", &image_width);

    printf("Enter image height: ");
    scanf("%d", &image_height);

    char **image_data = (char **)malloc(image_height * sizeof(char *) + 1);
    for (int h = 0; h < image_height; h++)
    {
        image_data[h] = (char *)malloc(image_width * sizeof(char) + 1);
    }

    printf("Enter image data (separated by spaces): ");
    char input[MAX_IMAGE_SIZE];
    scanf("%s", input);

    int index = 0;
    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            image_data[h][w] = input[index];
            index++;
        }
    }

    for (int h = 0; h < image_height; h++)
    {
        for (int w = 0; w < image_width; w++)
        {
            switch (image_data[h][w])
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

    free(image_data);
    return 0;
}