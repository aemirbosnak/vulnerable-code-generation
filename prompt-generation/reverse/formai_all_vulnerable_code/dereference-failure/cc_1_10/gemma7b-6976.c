//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

void itoa(int n, char *s)
{
    int i = 0;
    s[0] = '\0';
    while (n)
    {
        int digit = n % 10;
        n /= 10;
        s[i++] = digit + '0';
    }
    s[i] = '\0';
}

int main()
{
    int img_width, img_height;
    printf("Enter image width: ");
    scanf("%d", &img_width);

    printf("Enter image height: ");
    scanf("%d", &img_height);

    int **img_data = malloc(img_height * sizeof(int *));
    for (int h = 0; h < img_height; h++)
    {
        img_data[h] = malloc(img_width * sizeof(int));
    }

    printf("Enter image data (separated by commas): ");
    char *data = malloc(img_width * img_height);
    scanf("%s", data);

    char **ascii_art = malloc(img_height * sizeof(char *));
    for (int h = 0; h < img_height; h++)
    {
        ascii_art[h] = malloc(img_width * sizeof(char));
    }

    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            int pixel_value = img_data[h][w];
            itoa(pixel_value, ascii_art[h][w]);
            ascii_art[h][w] = ascii_art[h][w] + '0';
        }
    }

    printf("Your ASCII art:\n");
    for (int h = 0; h < img_height; h++)
    {
        for (int w = 0; w < img_width; w++)
        {
            printf("%c ", ascii_art[h][w]);
        }
        printf("\n");
    }

    free(img_data);
    free(ascii_art);
    free(data);

    return 0;
}