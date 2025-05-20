//FormAI DATASET v1.0 Category: Data recovery tool ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// structure to represent a file block
typedef struct file_block{
    unsigned char data[BLOCK_SIZE];
} file_block_t;

// function to recover lost data from a damaged file
void data_recovery(FILE *fp){
    size_t file_size;
    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp); // get the file size in bytes
    fseek(fp, 0, SEEK_SET); // move the file pointer to the beginning

    // check if the file size is a multiple of the block size
    if(file_size % BLOCK_SIZE != 0){
        printf("File size is not a multiple of block size\n");
        return;
    }

    // calculate the number of blocks in the file
    unsigned int num_blocks = file_size / BLOCK_SIZE;

    // allocate memory for a buffer to hold the file blocks
    file_block_t *buffer = (file_block_t*) malloc(num_blocks * sizeof(file_block_t));

    // iterate over each block in the file and read it into the buffer
    for(unsigned int i = 0; i < num_blocks; i++){
        fread(buffer[i].data, 1, BLOCK_SIZE, fp);
    }

    // create a new file to write the recovered data to
    FILE *recovered_file = fopen("recovered_file.txt", "w");
    if(recovered_file == NULL){
        printf("Failed to create recovered file\n");
        free(buffer);
        return;
    }

    // iterate over each block in reverse order and write it to the recovered file
    for(unsigned int i = num_blocks - 1; i >= 0; i--){
        fwrite(buffer[i].data, 1, BLOCK_SIZE, recovered_file);
    }

    fclose(recovered_file);
    free(buffer);

    printf("Data recovery successful! Check the recovered_file.txt\n");
}

int main(){
    // open the file to recover data from
    FILE *fp = fopen("damaged_file.txt", "r");
    if(fp == NULL){
        printf("Failed to open file\n");
        return 1;
    }

    data_recovery(fp);

    fclose(fp);

    return 0;
}