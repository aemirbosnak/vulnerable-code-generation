//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
// Medieval Image Editor Example Program
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    FILE *file_in, *file_out;
    char file_name[50];
    int height, width, i, j;

    // Get input file name
    printf("Enter the name of the input file: ");
    scanf("%s", file_name);

    // Open input file
    file_in = fopen(file_name, "rb");
    if(file_in == NULL)
    {
        printf("Error: Unable to open file.");
        exit(1);
    }

    // Get image dimensions
    fscanf(file_in, "P6\n%d %d\n255\n", &width, &height);

    // Allocate memory for image data
    unsigned char *image_data = (unsigned char*)malloc(height * width * 3);

    // Read image data from file
    fread(image_data, sizeof(unsigned char), height * width * 3, file_in);

    // Close input file
    fclose(file_in);

    // Modify the image data in a medieval style
    for(i = 0; i < height; i++)
    {
        for(j = 0; j < width * 3; j += 3)
        {
            if(image_data[i*width*3+j] < 100 && image_data[i*width*3+j+1] < 100 && image_data[i*width*3+j+2] > 100)
            {
                image_data[i*width*3+j] = 255;
                image_data[i*width*3+j+1] = 0;
                image_data[i*width*3+j+2] = 0;
            }
        }
    }

    // Get output file name
    printf("Enter the name of the output file: ");
    scanf("%s", file_name);

    // Open output file
    file_out = fopen(file_name, "wb");
    if(file_out == NULL)
    {
        printf("Error: Unable to open file.");
        exit(1);
    }

    // Write image data to file
    fprintf(file_out, "P6\n%d %d\n255\n", width, height);
    fwrite(image_data, sizeof(unsigned char), height * width * 3, file_out);

    // Close output file
    fclose(file_out);

    // Free allocated memory
    free(image_data);

    printf("Image saved successfully.");

    return 0;
}