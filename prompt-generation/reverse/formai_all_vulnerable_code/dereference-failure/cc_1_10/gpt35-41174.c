//FormAI DATASET v1.0 Category: Data recovery tool ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

// This struct represents a single block of data on the disk
typedef struct {
    unsigned char data[BLOCK_SIZE];
} block_t;

// This function reads in data from the file and populates a block
void read_block(FILE *file, unsigned int block_number, block_t *block) {
    fseek(file, block_number * BLOCK_SIZE, SEEK_SET);
    fread(block->data, sizeof(unsigned char), BLOCK_SIZE, file);
}

int main() {
    FILE *disk = fopen("disk.bin", "rb");
    if (disk == NULL) {
        printf("Error opening disk\n");
        return 1;
    }

    // Get the size of the disk
    fseek(disk, 0L, SEEK_END);
    unsigned int num_blocks = ftell(disk) / BLOCK_SIZE;
    fseek(disk, 0L, SEEK_SET);
    printf("Disk size: %u blocks\n", num_blocks);

    // Prompt the user for the block number to recover
    unsigned int block_num;
    printf("Enter the block number to recover: ");
    scanf("%u", &block_num);

    if (block_num >= num_blocks) {
        printf("Invalid block number\n");
        return 1;
    }

    // Allocate a buffer for the recovered data
    unsigned char *recovered_data = malloc(BLOCK_SIZE);
    if (recovered_data == NULL) {
        printf("Error allocating memory\n");
        return 1;
    }

    // Read in the block data
    block_t block;
    read_block(disk, block_num, &block);

    // Prompt the user for the file name to save the recovered data to
    char file_name[255];
    printf("Enter the file name to save the recovered data to: ");
    scanf("%s", file_name);

    // Open the file for writing
    FILE *recovered_file = fopen(file_name, "wb");
    if (recovered_file == NULL) {
        printf("Error opening file for writing\n");
        return 1;
    }

    // Write the recovered data to the file
    fwrite(block.data, sizeof(unsigned char), BLOCK_SIZE, recovered_file);

    printf("Data recovered successfully!\n");

    // Cleanup
    free(recovered_data);
    fclose(recovered_file);
    fclose(disk);

    return 0;
}