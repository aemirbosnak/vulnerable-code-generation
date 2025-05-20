//Gemma-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoa(int num, char *str)
{
    int i = 0;
    char n[11];
    sprintf(n, "%d", num);
    while (n[i] != '\0')
    {
        str[i] = n[i];
        i++;
    }
    str[i] = '\0';
}

int main()
{
    FILE *fp;
    fp = fopen("image.jpg", "r");
    if (fp == NULL)
    {
        printf("Error opening file\n");
        return 1;
    }

    char *buffer;
    int size = 0;
    buffer = NULL;
    int read_size = 0;
    while ((read_size = fread(buffer, 1, 1024, fp)) > 0)
    {
        size += read_size;
        buffer = (char *)realloc(buffer, size);
    }

    fclose(fp);

    buffer = (char *)realloc(buffer, size);

    int pixel_count = 0;
    for (int i = 0; i < size; i++)
    {
        pixel_count++;
        int r = (buffer[i] & 0xf8) >> 5;
        int g = (buffer[i] & 0x0c) >> 2;
        int b = buffer[i] & 0x03;
        char pixel[4] = {'-', '+', '+', '-'};
        pixel[r] = ' ';
        pixel[g] = ' ';
        pixel[b] = ' ';
        printf("%s", pixel);
    }

    printf("\n");
    return 0;
}