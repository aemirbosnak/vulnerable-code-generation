//FormAI DATASET v1.0 Category: Data recovery tool ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024 // Set block size for data recovery tool

typedef struct {
    int block_num; // block number for each block of data
    char data[BLOCK_SIZE]; // data in the block
} block;

int main(int argc, char *argv[]) {
    if (argc != 2) { // check if file name is provided as argument
        printf("Please provide file name to recover data from.\n");
        exit(EXIT_FAILURE);
    }

    FILE *fp;
    fp = fopen(argv[1], "rb"); // open file in binary mode

    if (fp == NULL) { // check if file is opened successfully
        printf("Unable to open file.\n");
        exit(EXIT_FAILURE);
    }

    int total_blocks = 0; // calculate total number of blocks in file
    fseek(fp, 0, SEEK_END); // move file pointer to end of file
    long int file_size = ftell(fp); // get file size
    total_blocks = (file_size % BLOCK_SIZE == 0) ? (file_size / BLOCK_SIZE) : ((file_size / BLOCK_SIZE) + 1); // calculate total number of blocks

    block *blocks = malloc(total_blocks * sizeof(block)); // dynamically allocate memory for all blocks
    if (blocks == NULL) { // check if memory is allocated successfully
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 0; i < total_blocks; i++) { // read all blocks from file
        blocks[i].block_num = i + 1;
        if (i == total_blocks - 1) { // if last block
            int last_block_size = file_size % BLOCK_SIZE;
            if (last_block_size == 0) {
                last_block_size = BLOCK_SIZE;
            }
            fseek(fp, -(last_block_size), SEEK_END); // move file pointer back to read last block
            fread(blocks[i].data, last_block_size, 1, fp);
        } else {
            fseek(fp, (i * BLOCK_SIZE), SEEK_SET); // move file pointer to read current block
            fread(blocks[i].data, BLOCK_SIZE, 1, fp);
        }
    }

    fclose(fp); // close file as data is read successfully

    int block_num;
    printf("Enter the block number to recover data from : ");
    scanf("%d", &block_num); // take block number from user to recover data from

    if (block_num < 1 || block_num > total_blocks) { // check if valid block number is entered
        printf("Invalid block number.\n");
        exit(EXIT_FAILURE);
    }

    printf("Data in block %d : %s\n", block_num, blocks[block_num-1].data); // print recovered data

    free(blocks); // free dynamically allocated memory
    return 0;
}