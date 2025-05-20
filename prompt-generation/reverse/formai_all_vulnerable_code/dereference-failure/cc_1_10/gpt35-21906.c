//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WATERMARK "This is a digital watermark."

//Function to embed the watermark into the image buffer
void embedWatermark(unsigned char *image, int image_size, char* watermark) {
    int watermark_length = strlen(watermark);
    int watermark_index = 0;
    for(int i=0; i<image_size; i++) {
        //Skip the last few bytes which are not enough to embed watermark
        if(i >= image_size - 10) {
            break;
        }
        if(image[i] % 2 == 0) {
            //If the least significant bit of the byte is 0
            //Embed the bit from the watermark
            if((watermark[watermark_index/8] & (1 << (watermark_index % 8))) > 0) {
                image[i] += 1;
            }
            watermark_index++;
            if(watermark_index >= watermark_length*8) {
                //If all bits of watermark have been embedded
                break;
            }
        } else {
            //If the least significant bit of the byte is 1
            //Leave the bit as it is
            continue;
        }
    }
}

//Function to extract the watermark from the image buffer
void extractWatermark(unsigned char *image, int image_size, char* watermark, int watermark_size) {
    int watermark_index = 0;
    for(int i=0; i<image_size; i++) {
        //Skip the last few bytes which are not enough to embed watermark
        if(i >= image_size - 10) {
            break;
        }
        if(image[i] % 2 == 0) {
            //If the least significant bit of the byte is 0
            //The bit is same as the original image
            if((WATERMARK[watermark_index/8] & (1 << (watermark_index % 8))) > 0) {
                watermark[watermark_index/8] |= (1 << (watermark_index % 8));
            }
            watermark_index++;
            if(watermark_index >= watermark_size*8) {
                //If all bits of watermark have been extracted
                break;
            }
        } else {
            //If the least significant bit of the byte is 1
            //The bit is different from the original image
            watermark[watermark_index/8] &= ~(1 << (watermark_index % 8));
            watermark_index++;
            if(watermark_index >= watermark_size*8) {
                //If all bits of watermark have been extracted
                break;
            }
        }
    }
}

int main() {
    //Read the original image file
    FILE *fp = fopen("original_image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 0;
    }
    fseek(fp, 0L, SEEK_END);
    int image_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    unsigned char *image = (unsigned char*) malloc(image_size);
    fread(image, sizeof(unsigned char), image_size, fp);
    fclose(fp);

    //Add the watermark to the image buffer
    embedWatermark(image, image_size, WATERMARK);

    //Write the watermarked image to a new file
    fp = fopen("watermarked_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 0;
    }
    fwrite(image, sizeof(unsigned char), image_size, fp);
    fclose(fp);

    //Extract the watermark from the watermarked image buffer
    char extracted_watermark[strlen(WATERMARK)+1];
    memset(extracted_watermark, 0, strlen(WATERMARK)+1);
    extractWatermark(image, image_size, extracted_watermark, strlen(WATERMARK));

    printf("Original watermark: %s\n", WATERMARK);
    printf("Extracted watermark: %s\n", extracted_watermark);

    free(image);
    return 0;
}