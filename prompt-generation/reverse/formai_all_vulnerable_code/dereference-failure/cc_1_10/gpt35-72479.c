//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

unsigned char *read_bmp(char *filename, int *width, int *height);
void write_bmp(char *filename, unsigned char *img, int width, int height);
unsigned char *flip_image(unsigned char *img, int width, int height);
unsigned char *adjust_brightness_contrast(unsigned char *img, int width, int height, float brightness, float contrast);

int main()
{
    int width, height;
    unsigned char *img = read_bmp("input.bmp", &width, &height);
    
    // Flip the image horizontally
    img = flip_image(img, width, height);
    
    // Adjust brightness and contrast
    img = adjust_brightness_contrast(img, width, height, 0.5, 2.0);
    
    write_bmp("output.bmp", img, width, height);
    free(img);
    return 0;
}

unsigned char *read_bmp(char *filename, int *width, int *height)
{
    FILE *fp;
    unsigned char header[54];
    unsigned char *data;
    
    fp = fopen(filename, "rb");
    if(fp == NULL)
    {
        fprintf(stderr, "Error opening file %s", filename);
        exit(1);
    }
    
    fread(header, sizeof(unsigned char), 54, fp);
    *width = *(int*)&header[18];
    *height = *(int*)&header[22];
    int size = (*width) * (*height) * 3;
    
    data = (unsigned char*)malloc(size);
    fread(data, sizeof(unsigned char), size, fp);
    
    fclose(fp);
    
    return data;
}

void write_bmp(char *filename, unsigned char *img, int width, int height)
{
    FILE *fp;
    unsigned char header[54];
    int size = width * height * 3;
    
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + size;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = width;
    *(int*)&header[22] = height;
    *(short*)&header[26] = 1;
    *(short*)&header[28] = 24;
    *(int*)&header[34] = size;
    
    fp = fopen(filename, "wb");
    if(fp == NULL)
    {
        fprintf(stderr, "Error creating file %s", filename);
        exit(1);
    }
    
    fwrite(header, sizeof(unsigned char), 54, fp);
    fwrite(img, sizeof(unsigned char), size, fp);
    
    fclose(fp);
}

unsigned char *flip_image(unsigned char *img, int width, int height)
{
    unsigned char *new_img = (unsigned char*)malloc(width * height * 3);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            new_img[i*width*3 + (width-j-1)*3 + 0] = img[i*width*3 + j*3 + 0];
            new_img[i*width*3 + (width-j-1)*3 + 1] = img[i*width*3 + j*3 + 1];
            new_img[i*width*3 + (width-j-1)*3 + 2] = img[i*width*3 + j*3 + 2];
        }
    }
    free(img);
    return new_img;
}

unsigned char *adjust_brightness_contrast(unsigned char *img, int width, int height, float brightness, float contrast)
{
    unsigned char *new_img = (unsigned char*)malloc(width * height * 3);
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            for(int k=0; k<3; k++)
            {
                int new_val = img[i*width*3 + j*3 + k] * contrast + 255 * brightness;
                new_val = (new_val > 255 ? 255 : (new_val < 0 ? 0 : new_val));
                new_img[i*width*3 + j*3 + k] = (unsigned char)new_val;
            }
        }
    }
    free(img);
    return new_img;
}