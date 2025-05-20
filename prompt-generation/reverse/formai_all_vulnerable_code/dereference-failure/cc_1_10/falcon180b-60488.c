//Falcon-180B DATASET v1.0 Category: Digital Watermarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>

int main()
{
    int width, height, x, y, i, j, k, l, m, n, p, q, r, s, t, u, v, w, x1, y1, x2, y2, x3, y3, x4, y4, count = 0;
    int **image, **watermark;
    char filename[100], watermark_filename[100], message[100];
    FILE *fp, *wfp;

    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");

    fseek(fp, 0, SEEK_END);
    width = ftell(fp) / 3;

    rewind(fp);

    height = ftell(fp) / (3 * width);

    image = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++)
    {
        image[i] = (int *)malloc(width * sizeof(int));
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fread(&image[i][j], sizeof(int), 1, fp);
        }
    }

    fclose(fp);

    printf("Enter the name of the watermark file: ");
    scanf("%s", watermark_filename);

    wfp = fopen(watermark_filename, "r");

    fgets(message, 100, wfp);

    watermark = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++)
    {
        watermark[i] = (int *)malloc(width * sizeof(int));
    }

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            fscanf(wfp, "%d", &watermark[i][j]);
        }
    }

    fclose(wfp);

    for (i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (image[i][j] == watermark[i][j])
            {
                count++;
            }
        }
    }

    printf("Watermark found: %d times\n", count);

    return 0;
}