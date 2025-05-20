//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLENGTH 10000
#define WN 32  // Number of bits in watermark
#define KEY 0x7F05  // Key for the watermarking technique

// Function to embed watermark into the given matrix
void embedWatermark(unsigned char *data, int rows, int cols){
    int i, j, count;
    unsigned char watermark[WN];
    for(i = 0; i < WN; i++){
        watermark[i] = (KEY >> i) & 1;
    }
    count = 0;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(count < WN){
                data[i * cols + j] |= watermark[count];
                count++;
            }
        }
        if(count >= WN){
            break;
        }
    }
}

// Function to extract watermark from the given matrix
void extractWatermark(unsigned char *data, int rows, int cols){
    int i, j, count, match;
    unsigned char watermark[WN];
    for(i = 0; i < WN; i++){
        watermark[i] = (KEY >> i) & 1;
    }
    count = 0;
    match = 0;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(count < WN){
                if((data[i * cols + j] & 1) == watermark[count]){
                    match++;
                }
                count++;
            }
        }
        if(count >= WN){
            break;
        }
    }
    if(match == WN){
        printf("Watermark extracted successfully!\n");
    } else {
        printf("Error: Watermark extraction failed.\n");
    }
}

int main(){
    FILE *fp;
    unsigned char data[MAXLENGTH];
    int rows, cols, i, j;
    
    // Load data from file
    fp = fopen("input.bin", "rb");
    if(fp == NULL){
        printf("Error: Could not open input file.\n");
        return 1;
    }
    fread(&rows, sizeof(int), 1, fp);
    fread(&cols, sizeof(int), 1, fp);
    if(rows * cols > MAXLENGTH){
        printf("Error: Input matrix size too large.\n");
        return 1;
    }
    fread(data, sizeof(unsigned char), rows * cols, fp);
    fclose(fp);
    
    printf("Original Data:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", data[i * cols + j]);
        }
        printf("\n");
    }
    
    // Embed watermark into the data
    embedWatermark(data, rows, cols);
    
    printf("\nEmbedded Watermark:\n");
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            printf("%d ", data[i * cols + j]);
        }
        printf("\n");
    }
    
    // Extract watermark from the data
    extractWatermark(data, rows, cols);
    
    return 0;
}