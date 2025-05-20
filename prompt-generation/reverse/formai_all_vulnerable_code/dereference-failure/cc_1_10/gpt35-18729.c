//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: ephemeral
#include<stdio.h>

int main()
{
    printf("Welcome to Simple Image Processing\n");

    //Reading the image file
    FILE *imageFile;
    imageFile = fopen("image.bmp", "rb");

    printf("Reading the image file...\n");

    //Checking if the image file opened successfully
    if(imageFile == NULL)
    {
        printf("Error opening the image file\n");
        return 1;
    }

    //Getting the image height and width
    int imageWidth, imageHeight;
    fseek(imageFile, 18, SEEK_SET);
    fread(&imageWidth, sizeof(int), 1, imageFile);
    fread(&imageHeight, sizeof(int), 1, imageFile);

    //Getting the image offset
    int imageOffset;
    fseek(imageFile, 10, SEEK_SET);
    fread(&imageOffset, sizeof(int), 1, imageFile);

    //Setting the brightness and contrast values
    float brightness = 50;
    float contrast = 1.25;

    printf("Image Details:\n");
    printf("Width: %d\n", imageWidth);
    printf("Height: %d\n", imageHeight);

    //Creating a buffer to read the pixels from the image
    unsigned char buffer[imageHeight][imageWidth][3];
    fseek(imageFile, imageOffset, SEEK_SET);

    printf("Reading the pixel values...\n");

    int x, y;
    for (y = 0; y < imageHeight; y++)
    {
        for (x = 0; x < imageWidth; x++)
        {
            //Reading the pixel values
            fread(buffer[y][x], sizeof(unsigned char), 3, imageFile);

            //Adjusting the brightness and contrast
            buffer[y][x][0] = (unsigned char)(brightness + (buffer[y][x][0] - 128) * contrast + 128);
            buffer[y][x][1] = (unsigned char)(brightness + (buffer[y][x][1] - 128) * contrast + 128);
            buffer[y][x][2] = (unsigned char)(brightness + (buffer[y][x][2] - 128) * contrast + 128);
        }
    }

    //Closing the image file
    fclose(imageFile);

    //Creating a new image file to write the processed image
    FILE *newImageFile;
    newImageFile = fopen("new_image.bmp", "wb");

    printf("Writing the processed image...\n");

    //Writing the image header
    fseek(newImageFile, 0, SEEK_SET);
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fopen("image.bmp", "rb"));
    fwrite(header, sizeof(unsigned char), 54, newImageFile);

    //Writing the new pixel values to the new image file
    for (y = 0; y < imageHeight; y++)
    {
        for (x = 0; x < imageWidth; x++)
        {
            fwrite(buffer[y][x], sizeof(unsigned char), 3, newImageFile);
        }
    }

    //Closing the new image file
    fclose(newImageFile);

    printf("Image processing completed successfully!\n");

    return 0;
}