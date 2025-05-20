//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: curious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //Opening the image file
    FILE *image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Unable to open image file\n");
        return -1;
    }
    //Reading the image header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, image_file);
    //Extracting image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];
    //Calculating image size
    int size = width * height * 3;
    //Allocating memory for the image data
    unsigned char *image_data = (unsigned char*)malloc(size);
    //Reading the image data
    fread(image_data, sizeof(unsigned char), size, image_file);
    fclose(image_file);

    //Flipping the image horizontally
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            //Swapping pixels
            int index1 = (i * width + j) * 3;
            int index2 = (i * width + (width - 1 - j)) * 3;
            unsigned char temp1 = image_data[index1];
            unsigned char temp2 = image_data[index1 + 1];
            unsigned char temp3 = image_data[index1 + 2];
            image_data[index1] = image_data[index2];
            image_data[index1 + 1] = image_data[index2 + 1];
            image_data[index1 + 2] = image_data[index2 + 2];
            image_data[index2] = temp1;
            image_data[index2 + 1] = temp2;
            image_data[index2 + 2] = temp3;
        }
    }

    //Changing brightness and contrast
    float brightness = 0.5;
    float contrast = 1.5;
    for (int i = 0; i < size; i++) {
        float temp = ((float)image_data[i] / 255.0 - 0.5) * contrast + 0.5 + brightness;
        image_data[i] = (unsigned char)(temp * 255.0);
    }

    //Writing the modified image to a new file
    FILE *output_file = fopen("modified_image.bmp", "wb");
    if (output_file == NULL) {
        printf("Unable to create output file\n");
        return -1;
    }
    fwrite(header, sizeof(unsigned char), 54, output_file);
    fwrite(image_data, sizeof(unsigned char), size, output_file);
    fclose(output_file);
    free(image_data);

    printf("Image processing completed successfully!\n");

    return 0;
}