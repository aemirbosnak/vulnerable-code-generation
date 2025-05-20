//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512

struct Partition {
    unsigned int start;
    unsigned int size;
    char name[8];
};

struct SuperBlock {
    unsigned int block_size;
    unsigned int num_blocks;
    unsigned int num_partitions;
};

struct File {
    char name[32];
    unsigned int size;
    unsigned int starting_block;
};

int main(int argc, char* argv[]) {
    FILE *fp;
    struct SuperBlock super_block;
    struct Partition partitions[4];
    struct File *files = NULL;
    unsigned char *block_data;
    unsigned int num_files = 0;
    unsigned int i, j;
    char search_name[32];

    // Open the disk image file
    fp = fopen("disk.img", "rb");
    if(fp == NULL) {
        printf("Error: Could not open disk image file.\n");
        return -1;
    }

    // Read the super block
    fread(&super_block, sizeof(struct SuperBlock), 1, fp);
    block_data = (unsigned char*) malloc(super_block.block_size);

    // Read the partition table
    fread(partitions, sizeof(struct Partition), super_block.num_partitions, fp);

    // Loop through each partition
    for(i = 0; i < super_block.num_partitions; i++) {
        printf("Partition %d: %s\n", i + 1, partitions[i].name);

        // Seek to the start of the partition
        fseek(fp, partitions[i].start * super_block.block_size, SEEK_SET);

        // Loop through each block in the partition
        for(j = 0; j < partitions[i].size; j++) {
            // Read the block data
            fread(block_data, super_block.block_size, 1, fp);

            // Check if the block is the start of a file
            if(strncmp((char*)block_data, "FILE_START", 10) == 0) {
                // Allocate space for a new file structure
                files = (struct File*) realloc(files, (num_files + 1) * sizeof(struct File));

                // Read the file name and size
                sscanf((char*)block_data + 10, "%s %u", files[num_files].name, &files[num_files].size);

                // Calculate the number of blocks for the file
                files[num_files].starting_block = j;
                j += (files[num_files].size + super_block.block_size - 1) / super_block.block_size;

                // Print out information about the new file
                printf("\tFile %d: %s (size %u blocks)\n", num_files + 1, files[num_files].name, j - files[num_files].starting_block);

                num_files++;
            }
        }
    }

    // Prompt the user for a file name to recover
    printf("Enter the name of a file to recover: ");
    scanf("%s", search_name);

    // Search for the file in the file list
    for(i = 0; i < num_files; i++) {
        if(strcmp(files[i].name, search_name) == 0) {
            // Allocate space for the recovered file data
            block_data = (unsigned char*) realloc(block_data, files[i].size * super_block.block_size);

            // Seek to the start of the file
            fseek(fp, (files[i].starting_block + 1) * super_block.block_size, SEEK_SET);

            // Loop through each block of the file and copy it to the recovered file data buffer
            for(j = 0; j < files[i].size; j++) {
                fread(block_data + (j * super_block.block_size), super_block.block_size, 1, fp);
            }

            // Write the recovered file to disk
            FILE *recovered_file = fopen(files[i].name, "wb");
            fwrite(block_data, super_block.block_size, files[i].size, recovered_file);
            fclose(recovered_file);

            printf("File %s has been recovered.\n", files[i].name);
            break;
        }
    }

    free(files);
    free(block_data);
    fclose(fp);
    return 0;
}