//FormAI DATASET v1.0 Category: Image Editor ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Image
{
    char* image_name;
    int width;
    int height;
    char* format;
    unsigned char* pixels;
};

void grayscale(struct Image* img)
{
    int i, j;
    int gray_val;
    for(i=0; i<img->height; i++)
    {
        for(j=0; j<img->width; j++)
        {
            int pixel_pos = 3*(i*img->width+j);
            gray_val = 0.21*img->pixels[pixel_pos] + 0.72*img->pixels[pixel_pos+1] + 0.07*img->pixels[pixel_pos+2];
            img->pixels[pixel_pos] = img->pixels[pixel_pos+1] = img->pixels[pixel_pos+2] = gray_val;
        }
    }
}

void rotate(struct Image* img)
{
    int i, j, k;
    unsigned char* new_pixels = (unsigned char*) malloc(sizeof(unsigned char)*img->width*img->height*3);
    for(i=0; i<img->height; i++)
    {
        for(j=0; j<img->width; j++)
        {
            for(k=0; k<3; k++)
            {
                *(new_pixels+(j*img->height+(img->height-i-1))*3+k) = *(img->pixels+(i*img->width+j)*3+k);
            }
        }
    }
    free(img->pixels);
    img->pixels = new_pixels;
    int temp = img->width;
    img->width = img->height;
    img->height = temp;
}

void save_image(struct Image* img, char* output_path)
{
    FILE* output_file = fopen(output_path, "wb");
    fprintf(output_file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(unsigned char), img->width*img->height*3, output_file);
    fclose(output_file);
}

int main()
{
    char* read_path = "./sample_image.ppm";
    char* write_path = "./out_image.ppm";
    struct Image img;

   //read image file
    FILE* file = fopen(read_path, "rb");
    if(!file)
    {
        printf("Error opening file.\n");
        return -1;
    }
    char buffer[100];
    fgets(buffer, 100, file);
    if(buffer[0] != 'P' || buffer[1] != '6')
    {
        printf("Invalid PPM format.\n");
        return -1;
    }
    img.image_name = "sample_image";
    fgets(buffer, 100, file);
    sscanf(buffer, "%d %d", &img.width, &img.height);
    img.format = buffer;
    fgets(buffer, 100, file); // max allowed value, ignored

    //allocate memory for pixel data
    img.pixels = (unsigned char*) malloc(sizeof(unsigned char)*img.width*img.height*3);

    //read pixel data
    fread(img.pixels, sizeof(unsigned char), img.width*img.height*3, file);
    fclose(file);

    // grayscale the image
    grayscale(&img);

    //rotate the image
    rotate(&img); 

    //save the image as a new ppm file
    save_image(&img, write_path);
    printf("Image saved at %s.", write_path);

    free(img.pixels);

    return 0;
}