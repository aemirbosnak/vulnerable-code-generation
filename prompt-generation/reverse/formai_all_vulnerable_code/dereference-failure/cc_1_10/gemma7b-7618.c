//Gemma-7B DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

void watermark(char **img, int w, int h)
{
    int i, j, k, l;
    char **wm = (char **)malloc(h * w * sizeof(char *));
    for(i = 0; i < h; i++)
    {
        wm[i] = (char *)malloc(w * sizeof(char));
    }

    printf("Enter watermark text: ");
    scanf("%s", wm[0]);

    for(k = 0; wm[0][k] != '\0'; k++)
    {
        for(l = 0; l < w; l++)
        {
            for(i = 0; i < h; i++)
            {
                j = rand() % MAX;
                if(img[i][l] == 0 && j < 10)
                {
                    img[i][l] = wm[0][k] & 0xFF;
                }
            }
        }
    }

    free(wm);
}

int main()
{
    char **img = (char **)malloc(MAX * MAX * sizeof(char *));
    for(int i = 0; i < MAX; i++)
    {
        img[i] = (char *)malloc(MAX * sizeof(char));
    }

    printf("Enter image file name: ");
    char filename[255];
    scanf("%s", filename);

    FILE *fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int w, h;
    fscanf(fp, "%d %d", &w, &h);

    fread(img, w * h * 3, 1, fp);
    fclose(fp);

    watermark(img, w, h);

    fp = fopen(filename, "wb");
    if(fp == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    fwrite(img, w * h * 3, 1, fp);
    fclose(fp);

    printf("Image watermarked.\n");

    free(img);
    return 0;
}