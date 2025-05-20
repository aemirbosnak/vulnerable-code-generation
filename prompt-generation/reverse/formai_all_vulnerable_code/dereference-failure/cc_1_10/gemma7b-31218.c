//Gemma-7B DATASET v1.0 Category: Image Editor ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_Pics 10

typedef struct Picture
{
    char **pixels;
    int width;
    int height;
} Picture;

Picture *createPicture(int w, int h)
{
    Picture *p = (Picture *)malloc(sizeof(Picture));
    p->pixels = (char **)malloc(h * sizeof(char *));
    for (int i = 0; i < h; i++)
    {
        p->pixels[i] = (char *)malloc(w * sizeof(char));
    }
    p->width = w;
    p->height = h;
    return p;
}

void editPicture(Picture *p)
{
    printf("Enter the coordinates of the pixel you want to edit (x, y): ");
    int x, y;
    scanf("%d %d", &x, &y);

    printf("Enter the new color of the pixel (R, G, B): ");
    int r, g, b;
    scanf("%d %d %d", &r, &g, &b);

    if (x >= 0 && x < p->width && y >= 0 && y < p->height)
    {
        p->pixels[y][x] = rgbToPixel(r, g, b);
    }
    else
    {
        printf("Error: coordinates out of bounds.\n");
    }
}

int rgbToPixel(int r, int g, int b)
{
    return (r << 16) | (g << 8) | b;
}

int main()
{
    Picture *pictures[MAX_Pics];

    pictures[0] = createPicture(512, 512);
    pictures[0]->pixels[256][256] = rgbToPixel(255, 0, 0);
    pictures[0]->pixels[256][256] = rgbToPixel(0, 255, 0);

    editPicture(pictures[0]);

    return 0;
}