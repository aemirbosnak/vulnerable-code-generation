//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

void printAscii(int arr[HEIGHT][WIDTH]);

void convertToAscii(char *fileName);

int main()
{
    convertToAscii("image.bmp");

    return 0;
}

void printAscii(int arr[HEIGHT][WIDTH])
{
    for(int i=0; i<HEIGHT; i++)
    {
        for(int j=0; j<WIDTH; j++)
        {
            if(arr[i][j] >= 230)
            {
                printf(" ");
            }
            else if(arr[i][j] >= 200)
            {
                printf(".");
            }
            else if(arr[i][j] >= 175)
            {
                printf(":");
            }
            else if(arr[i][j] >= 150)
            {
                printf("o");
            }
            else if(arr[i][j] >= 125)
            {
                printf("&");
            }
            else if(arr[i][j] >= 100)
            {
                printf("8");
            }
            else if(arr[i][j] >= 75)
            {
                printf("#");
            }
            else if(arr[i][j] >= 50)
            {
                printf("@");
            }
            else
            {
                printf("W");
            }
        }
        printf("\n");
    }
}

void convertToAscii(char *fileName)
{
    FILE *file;
    if(!(file = fopen(fileName, "rb")))
    {
        printf("File not Found!\n");
        return;
    }

    unsigned char bmpHeader[54];

    if(fread(bmpHeader, sizeof(unsigned char), 54, file) != 54)
    {
        printf("Invalid BMP Header!\n");
        return;
    }

    int width = *(int*)&bmpHeader[18];
    int height = *(int*)&bmpHeader[22];

    unsigned char image[height][width][3];

    int paddingSize = (4 - (width*3) % 4) % 4;

    int arr[HEIGHT][WIDTH];

    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            fread(image[i][j], sizeof(unsigned char), 3, file);

            int grayScale = 0.11*image[i][j][0] + 0.59*image[i][j][1] + 0.3*image[i][j][2];

            arr[(int)round((double)i / height * HEIGHT)][(int)round((double)j / width * WIDTH)] = grayScale;
        }

        fseek(file, paddingSize, SEEK_CUR);
    }

    fclose(file);

    printAscii(arr);
}