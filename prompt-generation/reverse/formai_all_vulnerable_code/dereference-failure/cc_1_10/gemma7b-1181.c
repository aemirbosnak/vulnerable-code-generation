//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Pics 10

typedef struct Picture
{
    char **data;
    int width, height;
} Picture;

void display_picture(Picture *pic)
{
    for (int r = 0; r < pic->height; r++)
    {
        for (int c = 0; c < pic->width; c++)
        {
            printf("%c ", pic->data[r][c]);
        }
        printf("\n");
    }
}

void edit_picture(Picture *pic)
{
    printf("Enter the row and column of the pixel you want to edit, separated by a comma: ");
    char input[100];
    scanf("%s", input);

    int row, col;
    sscanf(input, "%d, %d", &row, &col);

    printf("Enter the new pixel value: ");
    int new_pixel_value;
    scanf("%d", &new_pixel_value);

    pic->data[row][col] = new_pixel_value;
}

int main()
{
    Picture pictures[MAX_Pics];

    for (int i = 0; i < MAX_Pics; i++)
    {
        pictures[i].data = NULL;
        pictures[i].width = 0;
        pictures[i].height = 0;
    }

    pictures[0].width = 5;
    pictures[0].height = 5;
    pictures[0].data = malloc(pictures[0].height * pictures[0].width * sizeof(char));

    pictures[0].data[0][0] = 255;
    pictures[0].data[0][1] = 0;
    pictures[0].data[0][2] = 0;
    pictures[0].data[0][3] = 0;
    pictures[0].data[0][4] = 255;

    pictures[0].data[1][0] = 0;
    pictures[0].data[1][1] = 255;
    pictures[0].data[1][2] = 0;
    pictures[0].data[1][3] = 0;
    pictures[0].data[1][4] = 0;

    pictures[0].data[2][0] = 0;
    pictures[0].data[2][1] = 0;
    pictures[0].data[2][2] = 255;
    pictures[0].data[2][3] = 0;
    pictures[0].data[2][4] = 0;

    pictures[0].data[3][0] = 0;
    pictures[0].data[3][1] = 0;
    pictures[0].data[3][2] = 0;
    pictures[0].data[3][3] = 255;
    pictures[0].data[3][4] = 0;

    pictures[0].data[4][0] = 255;
    pictures[0].data[4][1] = 0;
    pictures[0].data[4][2] = 0;
    pictures[0].data[4][3] = 0;
    pictures[0].data[4][4] = 255;

    display_picture(&pictures[0]);

    edit_picture(&pictures[0]);

    display_picture(&pictures[0]);

    return 0;
}