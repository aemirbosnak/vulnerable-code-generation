//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int power(int base, int exponent){
    if(exponent == 0){
        return 1;
    }
    else if(exponent % 2 == 0){
        int half = power(base, exponent/2);
        return half * half;
    }
    else{
        return base * power(base, exponent - 1);
    }
}

void embed(int* img, int* watermark, int img_width, int img_height, int mark_width, int mark_height, int row, int col, int bit_index){
    // Check if finished embedding
    if(row >= img_height || col >= img_width || bit_index == mark_width * mark_height){
        return;
    }
    
    // Get pixel value and watermark bit
    int pixel = img[row * img_width + col];
    int bit = (watermark[bit_index / mark_width] >> (bit_index % mark_width)) & 1;
    
    // Set last bit of pixel based on watermark bit
    if(bit == 0){
        img[row * img_width + col] = (pixel >> 1) << 1;
    }
    else{
        img[row * img_width + col] = ((pixel >> 1) << 1) + 1;
    }
    
    // Recursively embed next bit
    int next_col = (col + 1) % img_width;
    if(next_col == 0){
        embed(img, watermark, img_width, img_height, mark_width, mark_height, row+1, 0, bit_index+1);
    }
    else{
        embed(img, watermark, img_width, img_height, mark_width, mark_height, row, next_col, bit_index+1);
    }
}

void extract(int* img, int* watermark, int img_width, int img_height, int mark_width, int mark_height, int row, int col, int bit_index){
    // Check if finished extracting
    if(row >= img_height || col >= img_width || bit_index == mark_width * mark_height){
        return;
    }
    
    // Get pixel value
    int pixel = img[row * img_width + col];
    
    // Extract last bit and add to watermark
    int bit = pixel & 1;
    int mark_row = bit_index / mark_width;
    watermark[mark_row] += bit * power(2, bit_index % mark_width);
    
    // Recursively extract next bit
    int next_col = (col + 1) % img_width;
    if(next_col == 0){
        extract(img, watermark, img_width, img_height, mark_width, mark_height, row+1, 0, bit_index+1);
    }
    else{
        extract(img, watermark, img_width, img_height, mark_width, mark_height, row, next_col, bit_index+1);
    }
}

int main(){
    // Set image and watermark dimensions
    int img_width = 6;
    int img_height = 4;
    int mark_width = 3;
    int mark_height = 2;
    
    // Allocate memory for image and watermark
    int* img = (int*)calloc(img_width*img_height, sizeof(int));
    int* watermark = (int*)calloc(mark_height, sizeof(int));
    
    // Set image values
    img[0] = 255;
    img[1] = 123;
    img[2] = 211;
    img[3] = 14;
    img[4] = 209;
    img[5] = 178;
    img[6] = 23;
    img[7] = 111;
    img[8] = 234;
    img[9] = 76;
    img[10] = 201;
    img[11] = 88;
    img[12] = 45;
    img[13] = 237;
    img[14] = 98;
    img[15] = 43;
    img[16] = 221;
    img[17] = 199;
    img[18] = 102;
    img[19] = 222;
    
    // Print original image
    printf("Original Image:\n");
    for(int i=0;i<img_height;i++){
        for(int j=0;j<img_width;j++){
            printf("%d ", img[i*img_width+j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Embed watermark
    embed(img, watermark, img_width, img_height, mark_width, mark_height, 0, 0, 0);
    
    // Print embedded image
    printf("Embedded Image:\n");
    for(int i=0;i<img_height;i++){
        for(int j=0;j<img_width;j++){
            printf("%d ", img[i*img_width+j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // Extract watermark
    extract(img, watermark, img_width, img_height, mark_width, mark_height, 0, 0, 0);
    
    // Print extracted watermark
    printf("Extracted Watermark:\n");
    for(int i=0;i<mark_height;i++){
        for(int j=0;j<mark_width;j++){
            printf("%d ", (watermark[i] >> j) & 1);
        }
        printf("\n");
    }
    
    // Free memory
    free(img);
    free(watermark);
    
    return 0;
}