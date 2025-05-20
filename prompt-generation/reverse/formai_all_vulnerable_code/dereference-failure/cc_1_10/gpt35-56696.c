//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: systematic
#include<stdio.h>
#include<stdlib.h>

int main(){

    // Opening the image file
    FILE *fileptr;
    char *filename = "image.raw";
    unsigned char *imageData;
    int height = 512;
    int width = 512;
    int pixel_size = 3;

    // Allocate memory for image data or pixels
    imageData = (unsigned char*)malloc(height * width * pixel_size * sizeof(unsigned char));

    // Reading the image data 
    fileptr = fopen(filename, "rb");
    fread(imageData, sizeof(unsigned char), height * width * pixel_size, fileptr);
    fclose(fileptr);

    //First task : Flipping the image
    unsigned char *flippedData;
    flippedData = (unsigned char*)malloc(height * width * pixel_size * sizeof(unsigned char));
    int flippedHeight = height - 1;
    int flippedWidth = width - 1;
    int count = 0;

    // Logic for flipping the image
    for(int i = flippedHeight; i >= 0; i--){
        for(int j = 0; j <= flippedWidth; j++){
            flippedData[count] = imageData[(i * width + j) * pixel_size];
            flippedData[count+1] = imageData[(i * width + j) * pixel_size + 1];
            flippedData[count+2] = imageData[(i * width + j) * pixel_size + 2];
            count += 3;
        }
    }

    // Second Task : Adjusting the brightness and contrast of image
    float brightness = 0.5;
    float contrast = 1.5;

    unsigned char *processedData;
    processedData = (unsigned char*)malloc(height * width * pixel_size * sizeof(unsigned char));

    // Logic for changing the brightness and contrast of image
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            for(int k = 0; k < pixel_size; k++){
                int index = (i * width + j) * pixel_size + k;
                float val = (flippedData[index] * contrast + brightness * 255) > 255 ? 255 : (flippedData[index] * contrast + brightness * 255);
                processedData[index] = (unsigned char)val;
            }
        }
    }

    // Writing the processed data or pixels to a new file
    FILE *output_file;
    unsigned char *output_data;
    char *output_filename = "processed_output_file.raw";
    output_data = (unsigned char*)malloc(height * width * pixel_size * sizeof(unsigned char));
    output_file = fopen(output_filename, "wb");

    // Writing the processed data to the output file
    fwrite(processedData, sizeof(unsigned char), height * width * pixel_size, output_file);
    fclose(output_file);

    // Deallocating and freeing the memory allocated above
    free(imageData);
    free(flippedData);
    free(processedData);
    free(output_data);

    return 0;
}