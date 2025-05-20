//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<math.h>

//function to embed the watermark in a given image
void embed_watermark(uint8_t *image, uint8_t *watermark, uint32_t image_size, uint32_t watermark_size) {
    uint32_t i, j, k;
    uint8_t mask;
    uint8_t wm_bit, im_bit;
    uint8_t *temp;
    
    //Allocate memory for temporary copy of image
    temp = (uint8_t *)malloc(image_size);
    memcpy(temp, image, image_size);

    //Embed watermark bit-by-bit using LSB steganography
    for (i = 0, j = 0, k = 0; i < watermark_size*8; i++) {
        wm_bit = (watermark[j] & (1 << (i % 8))) > 0;
        im_bit = (temp[k] & 1);

        if (wm_bit == im_bit) { // If bits are the same, do nothing
            mask = 0xfe;
        } else {
            mask = 0xff; // Else, set the LSB of image pixel
        }
        // Apply mask to set the LSB of image pixel
        image[k] = (image[k] & mask) | (wm_bit & 1);
        k++; //Next pixel of image
        if (i % 8 == 7) j++; // Next byte of watermark
    }
    free(temp); // Free temporary memory
    return;
}

//Function to extract the watermark from a given image
void extract_watermark(uint8_t *image, uint8_t *watermark, uint32_t image_size, uint32_t watermark_size) {
    uint32_t i, j, k;
    uint8_t wm_bit, im_bit;

    //Extract watermark bit-by-bit using LSB steganography
    for (i = 0, j = 0, k = 0; i < watermark_size*8; i++) {
        im_bit = (image[k] & 1);
        wm_bit = wm_bit | (im_bit << (i % 8));

        if (i % 8 == 7) {
            watermark[j] = wm_bit;
            j++; // Next byte of watermark
            wm_bit = 0;
        }
        k++; // Next pixel of image
    }
    return;
}

int main() {
    FILE *fptr;
    char *input_file_name = "input.bmp";
    char *output_file_name = "output.bmp";
    uint32_t image_size, watermark_size, offset;
    uint8_t *image_data, *watermark_data;

    // Open input file
    fptr = fopen(input_file_name, "rb");
    if (fptr == NULL) {
        printf("Error: Unable to open file %s\n", input_file_name);
        return 1;
    } 

    //Get size of image file
    fseek(fptr, 0, SEEK_END);
    image_size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    //Allocate memory for image data
    image_data = (uint8_t *)malloc(image_size);
    if (image_data == NULL) {
        printf("Error: Unable to allocate memory for image data\n");
        fclose(fptr);
        return 1;
    }

    //Read image data from file
    if (fread(image_data, 1, image_size, fptr) != image_size) {
        printf("Error: Unable to read image data from file\n");
        fclose(fptr);
        free(image_data);
        return 1;
    }

    //Close input file
    fclose(fptr);

    //Calculate offset value to get to image data
    offset = *(uint32_t *)(image_data + 10);

    //Open output file
    fptr = fopen(output_file_name, "wb");
    if (fptr == NULL) {
        printf("Error: Unable to open file %s\n", output_file_name);
        free(image_data);
        return 1;
    }

    //Write image data to output file
    if (fwrite(image_data, 1, offset, fptr) != offset) {
        printf("Error: Unable to write image data to file\n");
        fclose(fptr);
        free(image_data);
        return 1;
    }

    //Allocate memory for watermark data
    watermark_size = 8;
    watermark_data = (uint8_t *)malloc(watermark_size);
    if (watermark_data == NULL) {
        printf("Error: Unable to allocate memory for watermark data\n");
        fclose(fptr);
        free(image_data);
        return 1;
    }

    //Set the watermark data
    watermark_data[0] = 'W';
    watermark_data[1] = 'a';
    watermark_data[2] = 't';
    watermark_data[3] = 'e';
    watermark_data[4] = 'r';
    watermark_data[5] = 'm';
    watermark_data[6] = 'a';
    watermark_data[7] = 'r';

    //Embed watermark in image
    embed_watermark(image_data + offset, watermark_data, image_size - offset, watermark_size);

    //Write modified image data to output file
    fwrite(image_data + offset, 1, image_size - offset, fptr);

    //Close output file
    fclose(fptr);

    //Allocate memory for extracted watermark
    watermark_data = (uint8_t *)malloc(watermark_size);
    if (watermark_data == NULL) {
        printf("Error: Unable to allocate memory for watermark data\n");
        free(image_data);
        return 1;
    }

    //Extract watermark from image
    extract_watermark(image_data + offset, watermark_data, image_size - offset, watermark_size);

    printf("The extracted watermark is: %s\n", watermark_data);

    //Free memory
    free(image_data);
    free(watermark_data);

    return 0;
}