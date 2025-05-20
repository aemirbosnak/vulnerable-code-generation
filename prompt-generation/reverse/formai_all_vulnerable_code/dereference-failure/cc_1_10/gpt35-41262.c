//FormAI DATASET v1.0 Category: Image compression ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main(){
    printf("Welcome to the coolest image compression program ever created!\n");
    printf("Please enter the name of the image file you want to compress:\n");

    char filename[100];
    scanf("%s", filename);

    // Open the image file
    FILE *image_file = fopen(filename, "rb");
    if(!image_file) {
        printf("Could not open file %s\n", filename);
        exit(1);
    }
    
    // Get the size of the image
    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    // Allocate memory for the image data
    unsigned char* image_data = (unsigned char*) malloc(image_size * sizeof(unsigned char));
    if(!image_data) {
        printf("Could not allocate memory for image data\n");
        exit(1);
    }

    // Read the image data
    fread(image_data, sizeof(unsigned char), image_size, image_file);
    fclose(image_file);

    // Perform the image compression algorithm
    int compressed_image_size = image_size / 2;
    unsigned char* compressed_image_data = (unsigned char*) malloc(compressed_image_size * sizeof(unsigned char));
    if(!compressed_image_data) {
        printf("Could not allocate memory for compressed image data\n");
        exit(1);
    }
    
    for(int i=0; i<compressed_image_size; i++) {
        compressed_image_data[i] = image_data[2*i];
    }

    // Save the compressed image to file
    char* compressed_filename = "compressed_image.dat";
    FILE *compressed_image_file = fopen(compressed_filename, "wb");
    fwrite(compressed_image_data, sizeof(unsigned char), compressed_image_size, compressed_image_file);
    fclose(compressed_image_file);
    
    printf("Image compression complete! Compressed image saved to %s\n", compressed_filename);

    return 0;
}