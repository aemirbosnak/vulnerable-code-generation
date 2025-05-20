//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

void itoa(int num, char *str)
{
    int i = 0;
    char temp;

    while (num)
    {
        temp = num % 10;
        num /= 10;
        str[i++] = temp + '0';
    }
    str[i] = '\0';
}

int main()
{
    int img_width, img_height;
    char **img_data;
    char *ascii_art;

    printf("Enter the width of the image: ");
    scanf("%d", &img_width);

    printf("Enter the height of the image: ");
    scanf("%d", &img_height);

    img_data = (char **)malloc(img_height * sizeof(char *) + img_height);
    ascii_art = (char *)malloc(img_width * img_height * sizeof(char));

    printf("Enter the pixel values for each row, separated by commas: ");
    for (int r = 0; r < img_height; r++)
    {
        char *row_data = img_data[r] = (char *)malloc(img_width * sizeof(char));
        scanf("%s", row_data);
    }

    for (int r = 0; r < img_height; r++)
    {
        for (int c = 0; c < img_width; c++)
        {
            int pixel_value = img_data[r][c];
            itoa(pixel_value, ascii_art + c * img_height);
        }
    }

    printf("Your ASCII art:\n");
    printf("%s", ascii_art);

    free(img_data);
    free(ascii_art);

    return 0;
}