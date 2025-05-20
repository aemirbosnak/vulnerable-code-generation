//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include<stdio.h>
#include<string.h>

#define MAX 512

// Function to embed digital watermark in an image
void embedWatermark(char image[], char watermark[])
{   
    // Open the input image file in binary mode
    FILE *inputImage = fopen(image, "rb");
    
    // Open the output image file in binary mode
    FILE *outputImage = fopen("watermarkedImage.bmp", "wb");
    
    // Open the watermark file in binary mode
    FILE *watermarkFile = fopen(watermark, "rb");
    
    // Check if the files were opened successfully
    if(inputImage == NULL || outputImage == NULL || watermarkFile == NULL) {
        printf("Error in opening file\n");
        return;
    }
    
    // Copy the input image header to the output image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, inputImage);
    fwrite(header, sizeof(unsigned char), 54, outputImage);
    
    // Embed the watermark in the last 512 bytes of the image
    unsigned char data[MAX];
    int i = 0;
    while(!feof(watermarkFile)) {
        fread(&data[i], sizeof(unsigned char), 1, watermarkFile);
        i++;
    }
    int data_size = i-1;
    fread(&data[i], sizeof(unsigned char), MAX-i, inputImage);
    fwrite(data, sizeof(unsigned char), data_size+MAX-i, outputImage);
    
    // Close all the files
    fclose(inputImage);
    fclose(outputImage);
    fclose(watermarkFile);
    
    printf("Digital watermark successfully embedded in the image!\n");
}

// Function to extract digital watermark from an image
void extractWatermark(char image[])
{   
    // Open the input image file in binary mode
    FILE *inputImage = fopen(image, "rb");
    
    // Check if the file was opened successfully
    if(inputImage == NULL) {
        printf("Error in opening file\n");
        return;
    }
    
    // Extract the watermark from the last 512 bytes of the image
    unsigned char data[MAX];
    fseek(inputImage, -512, SEEK_END);
    fread(data, sizeof(unsigned char), MAX, inputImage);
    
    // Print the extracted watermark
    printf("Extracted Watermark: %s\n", data);
    
    // Close the file
    fclose(inputImage);
}

int main()
{
    char inputImage[] = "test.bmp";
    char watermark[] = "watermark.txt";
    
    // Embed the watermark in the image
    embedWatermark(inputImage, watermark);
    
    // Extract the watermark from the image
    extractWatermark("watermarkedImage.bmp");
    
    return 0;
}