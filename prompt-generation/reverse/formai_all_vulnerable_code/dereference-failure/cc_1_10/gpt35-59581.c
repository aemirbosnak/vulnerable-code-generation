//FormAI DATASET v1.0 Category: Image compression ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define BLOCK_SIZE 8
#define MAX_PIXEL_VAL 255

void compress_image(unsigned char **image, int num_rows, int num_cols);

void main(){
    // Load image into 2D array
    unsigned char **image;
    int num_rows, num_cols;

    // Read image and initialize image array

    // Compress image
    compress_image(image, num_rows, num_cols);

    // Display compressed image
}

void compress_image(unsigned char **image, int num_rows, int num_cols){
    // Calculate number of blocks in rows and columns
    int num_blocks_rows = ceil(num_rows / (double) BLOCK_SIZE);
    int num_blocks_cols = ceil(num_cols / (double) BLOCK_SIZE);

    // Allocate space for compressed image blocks
    int **blocks = (int **)malloc(num_blocks_rows * sizeof(int *));
    for(int i = 0; i < num_blocks_rows; i++){
        blocks[i] = (int *)malloc(num_blocks_cols * sizeof(int));
    }

    // Iterate through image blocks and calculate average value
    for(int i = 0; i < num_blocks_rows; i++){
        for(int j = 0; j < num_blocks_cols; j++){
            int sum = 0;

            // Calculate block pixels average
            for(int k = 0; k < BLOCK_SIZE; k++){
                for(int l = 0; l < BLOCK_SIZE; l++){
                    // If pixel in block boundary, pad with the last pixel value
                    int row = i * BLOCK_SIZE + k;
                    int col = j * BLOCK_SIZE + l;

                    if(row >= num_rows){
                        row = num_rows - 1;
                    }

                    if(col >= num_cols){
                        col = num_cols - 1;
                    }

                    sum += image[row][col];
                }
            }

            // Store average block value
            int avg = round(sum / (double) (BLOCK_SIZE * BLOCK_SIZE));
            blocks[i][j] = avg;
        }
    }

    // Save compressed image blocks to file
    FILE *f = fopen("compressed_image.txt", "w");
    fprintf(f, "%d, %d\n", num_blocks_rows, num_blocks_cols);
    for(int i = 0; i < num_blocks_rows; i++){
        for(int j = 0; j < num_blocks_cols; j++){
            fprintf(f, "%d ", blocks[i][j]);
        }
        fprintf(f, "\n");
    }

    fclose(f);
}