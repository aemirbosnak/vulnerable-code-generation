//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

int main(int argc, char *argv[])
{
    char image[MAX_HEIGHT][MAX_WIDTH];
    int width, height;

    // read image file
    if (argc != 2)
    {
        fprintf(stderr, "usage: %s FILE\n", argv[0]);
        exit(1);
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL)
    {
        fprintf(stderr, "error: cannot open file '%s'\n", argv[1]);
        exit(1);
    }

    fscanf(fp, "%d %d\n", &width, &height);

    if (width > MAX_WIDTH || height > MAX_HEIGHT)
    {
        fprintf(stderr, "error: image is too large\n");
        exit(1);
    }

    int x, y;
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            fscanf(fp, "%c", &image[y][x]); // read char by char
        }
        fscanf(fp, "\n"); // advance to next line
    }

    fclose(fp);

    // convert image to ASCII art
    for (y = 0; y < height; y++)
    {
        for (x = 0; x < width; x++)
        {
            switch (image[y][x])
            {
                case ' ': printf(" "); break;
                case '.': printf("."); break;
                case ',': printf(","); break;
                case '-': printf("-"); break;
                case '+': printf("+"); break;
                case '*': printf("*"); break;
                case '/': printf("/"); break;
                case '\\': printf("\\"); break;
                case '(': printf("("); break;
                case ')': printf(")"); break;
                case '[': printf("["); break;
                case ']': printf("]"); break;
                case '{': printf("{"); break;
                case '}': printf("}"); break;
                case '|': printf("|"); break;
                case '_': printf("_"); break;
                default: printf(" "); break; // default to white space
            }
        }
        printf("\n");
    }

    return 0;
}