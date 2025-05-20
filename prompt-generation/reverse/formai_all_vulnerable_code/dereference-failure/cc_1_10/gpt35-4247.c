//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to create and add digital watermark to the image
void digitalWatermark(char* image, char* watermark){
    FILE *fp_image, *fp_watermark, *fp_watermarked;   // File pointers
    
    char ch;
    int i, j = 0;

    // Open image file
    fp_image = fopen(image, "r+");
    if(fp_image == NULL){
        perror("Error while opening the image file.\n");
        exit(EXIT_FAILURE);
    }

    // Open watermark file
    fp_watermark = fopen(watermark, "r");
    if(fp_watermark == NULL){
        perror("Error while opening the watermark file.\n");
        exit(EXIT_FAILURE);
    }
  
    // Open new file for watermarked image
    fp_watermarked = fopen("watermarked_image.pgm", "w+");
    if(fp_watermarked == NULL){
        perror("Error while creating new image file.\n");
        exit(EXIT_FAILURE);
    }

    // Read and write headers of image file
    char header[50];
    while(1){
        fgets(header, sizeof(header), fp_image);
        if(strncmp(header, "#", 1) != 0 && strncmp(header, "P5", 2) != 0){     
            fprintf(fp_watermarked, "%s", header);
            break;
        }
    }

    // Process the watermark data and add to image data
    while((ch = fgetc(fp_image)) != EOF){
        int bit = fgetc(fp_watermark);
        if(bit == EOF){
            break;
        }
        for(i = 7; i >= 0; i--){
            unsigned char data = (unsigned char) ch;
            unsigned char mask = 0x01 << i;
            int watermark_bit = (int)(bit & mask);
            int modified_bit = (int)(data & ~mask);
            modified_bit |= watermark_bit;
            char modified_data = (char)(modified_bit & 0xff);
            fwrite(&modified_data, 1, 1, fp_watermarked);
        }
    }

    // Write the remaining image data
    while((ch = fgetc(fp_image)) != EOF){
        fwrite(&ch, 1, 1, fp_watermarked);
    }

    // Close all the file pointers
    fclose(fp_image);
    fclose(fp_watermark);
    fclose(fp_watermarked);
}

// Driver function
int main(){
    char imageFile[] = "image.pgm";
    char watermarkFile[] = "watermark.txt";

    // Function call to add watermark to the image
    digitalWatermark(imageFile, watermarkFile);
    printf("Digital watermark added successfully!\n");

    return 0;
}