//Falcon2-11B DATASET v1.0 Category: Digital Watermarking ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define BLOCK_SIZE 8
#define NUM_BLOCKS 16
#define NUM_DIGITS 4

int main()
{
    FILE *watermarked_file, *original_file;
    char *watermark, *image;
    int i, j, k;
    int block_index;

    watermark = (char *)malloc(NUM_BLOCKS * NUM_BLOCKS * BLOCK_SIZE);
    image = (char *)malloc(NUM_BLOCKS * NUM_BLOCKS * BLOCK_SIZE);

    printf("Enter the watermark: ");
    fflush(stdout);
    fgets(watermark, NUM_BLOCKS * NUM_BLOCKS * BLOCK_SIZE, stdin);

    watermarked_file = fopen("watermarked.dat", "w");
    original_file = fopen("original.dat", "r");

    for (block_index = 0; block_index < NUM_BLOCKS; block_index++) {
        for (i = 0; i < NUM_BLOCKS; i++) {
            for (j = 0; j < NUM_BLOCKS; j++) {
                for (k = 0; k < BLOCK_SIZE; k++) {
                    image[block_index * NUM_BLOCKS * BLOCK_SIZE + i * NUM_BLOCKS * BLOCK_SIZE + j] = watermark[block_index * NUM_BLOCKS * BLOCK_SIZE + i * NUM_BLOCKS * BLOCK_SIZE + j];
                }
            }
        }
    }

    for (i = 0; i < NUM_BLOCKS; i++) {
        for (j = 0; j < NUM_BLOCKS; j++) {
            for (k = 0; k < BLOCK_SIZE; k++) {
                fprintf(watermarked_file, "%c", image[i * NUM_BLOCKS * BLOCK_SIZE + j]);
            }
        }
        fprintf(watermarked_file, "\n");
    }

    fclose(watermarked_file);
    fclose(original_file);

    free(watermark);
    free(image);

    return 0;
}