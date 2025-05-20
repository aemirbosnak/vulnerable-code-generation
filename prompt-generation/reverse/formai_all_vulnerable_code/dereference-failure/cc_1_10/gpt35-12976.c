//FormAI DATASET v1.0 Category: Data recovery tool ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 1024
#define FILE_NAME_MAX 256

/* struct to represent each file block */
typedef struct {
    int block_number;
    char data[BLOCK_SIZE];
} block_t;

/* struct to represent recovered file */
typedef struct {
    char name[FILE_NAME_MAX];
    int size;
    block_t** blocks;
    int num_blocks;
} recovered_file_t;

/* function to recover file from blocks */
recovered_file_t* recover_file(block_t** blocks, int num_blocks) {
    recovered_file_t* file = malloc(sizeof(recovered_file_t));
    
    // initialize file
    memset(file->name, 0, FILE_NAME_MAX);
    file->size = 0;
    file->blocks = NULL;
    file->num_blocks = 0;
    
    // determine file name (use first block's data)
    strncpy(file->name, blocks[0]->data, FILE_NAME_MAX-1);
    
    // determine file size (use last block's number and size)
    file->size = (num_blocks-1) * BLOCK_SIZE + strlen(blocks[num_blocks-1]->data);
    
    // allocate blocks for recovered file
    file->blocks = malloc(sizeof(block_t*) * num_blocks);
    file->num_blocks = num_blocks;
    
    // copy block data to recovered file blocks
    int i;
    for (i = 0; i < num_blocks; i++) {
        file->blocks[i] = malloc(sizeof(block_t));
        file->blocks[i]->block_number = blocks[i]->block_number;
        memcpy(file->blocks[i]->data, blocks[i]->data, BLOCK_SIZE);
    }
    
    return file;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    
    // read data from file
    FILE* fp = fopen(argv[1], "rb");
    if (!fp) {
        printf("Error opening file.\n");
        return 1;
    }
    
    // determine file size
    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);
    
    // determine number of blocks
    int num_blocks = (file_size-1) / BLOCK_SIZE + 1;
    
    // allocate memory for blocks
    block_t** blocks = malloc(sizeof(block_t*) * num_blocks);
    int i;
    for (i = 0; i < num_blocks; i++) {
        blocks[i] = malloc(sizeof(block_t));
        blocks[i]->block_number = i;
        memset(blocks[i]->data, 0, BLOCK_SIZE);
    }
    
    // read data into blocks
    int bytes_read;
    for (i = 0; i < num_blocks; i++) {
        bytes_read = fread(blocks[i]->data, 1, BLOCK_SIZE, fp);
        if (bytes_read != BLOCK_SIZE && i != num_blocks-1) {
            printf("Error reading file.\n");
            return 1;
        }
    }
    fclose(fp);
    
    // recover files
    int block_index = 0;
    int file_index = 0;
    int num_files_recovered = 0;
    recovered_file_t** recovered_files = malloc(sizeof(recovered_file_t*) * num_blocks);
    
    while (block_index < num_blocks) {
        // determine file name
        char file_name[FILE_NAME_MAX];
        memset(file_name, 0, FILE_NAME_MAX);
        strncpy(file_name, blocks[block_index]->data, FILE_NAME_MAX-1);
        
        // create block list for file
        block_t** file_blocks = malloc(sizeof(block_t*) * num_blocks);
        int num_file_blocks = 0;
        
        // read blocks into file until next file name or end of blocks
        while (block_index < num_blocks && strncmp(blocks[block_index]->data, file_name, strlen(file_name)) == 0) {
            file_blocks[num_file_blocks] = blocks[block_index];
            num_file_blocks++;
            block_index++;
        }
        
        // check if file is valid
        if (num_file_blocks > 1) {
            recovered_files[file_index] = recover_file(file_blocks, num_file_blocks);
            file_index++;
            num_files_recovered++;
        }
    }
    
    // print recovered files
    printf("%d files recovered.\n", num_files_recovered);
    for (i = 0; i < num_files_recovered; i++) {
        printf("File name: %s\n", recovered_files[i]->name);
        printf("File size: %d bytes\n", recovered_files[i]->size);
        printf("Block numbers: ");
        int j;
        for (j = 0; j < recovered_files[i]->num_blocks; j++) {
            printf("%d ", recovered_files[i]->blocks[j]->block_number);
        }
        printf("\n");
    }
    
    // free memory
    for (i = 0; i < num_blocks; i++) {
        free(blocks[i]);
    }
    free(blocks);
    for (i = 0; i < num_files_recovered; i++) {
        int j;
        for (j = 0; j < recovered_files[i]->num_blocks; j++) {
            free(recovered_files[i]->blocks[j]);
        }
        free(recovered_files[i]->blocks);
        free(recovered_files[i]);
    }
    free(recovered_files);
    
    return 0;
}