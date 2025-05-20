//FormAI DATASET v1.0 Category: Data recovery tool ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 256

// Data structures to store file system information
typedef struct _SuperBlock {
    int magic_number;
    int block_size;
    int root_dir_inode_num;
} SuperBlock;

typedef struct _Inode {
    int inode_num;
    int size;
    int data_block_num;
} Inode;

typedef struct _DataBlock {
    int data_block_num;
    char data[1024];
} DataBlock;

// Function to read super block from disk
SuperBlock read_super_block(FILE *fp) {
    SuperBlock super_block;

    fseek(fp, 0, SEEK_SET);
    fread(&super_block, sizeof(SuperBlock), 1, fp);

    return super_block;
}

// Function to read inode from disk
Inode read_inode(FILE *fp, int inode_num, int block_size, int root_dir_inode_num) {
    Inode inode;
    int inode_offset = sizeof(SuperBlock) + ((inode_num - 1) * sizeof(Inode));

    if (inode_num < 1 || inode_num > root_dir_inode_num) {
        fprintf(stderr, "Invalid inode number\n");
        exit(1);
    }

    fseek(fp, inode_offset, SEEK_SET);
    fread(&inode, sizeof(Inode), 1, fp);

    if (inode.data_block_num == 0 || inode.size == 0) {
        fprintf(stderr, "Inode is empty\n");
        exit(1);
    }

    return inode;
}

// Function to read data block from disk
DataBlock read_data_block(FILE *fp, int data_block_num, int block_size) {
    DataBlock data_block;

    fseek(fp, block_size * data_block_num, SEEK_SET);
    fread(&data_block, sizeof(DataBlock), 1, fp);

    return data_block;
}

// Function to recover file from corrupted file system
void recover_file(char *filename) {
    FILE *fp;
    SuperBlock super_block;
    Inode inode;
    DataBlock data_block;
    char recovered_data[1024 * 1024];
    int bytes_read = 0;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s\n", filename);
        exit(1);
    }

    // Read super block
    super_block = read_super_block(fp);

    // Read root directory inode
    inode = read_inode(fp, super_block.root_dir_inode_num, super_block.block_size, super_block.root_dir_inode_num);

    // Read data blocks of file
    for (int i = 0; i < inode.size; i++) {
        data_block = read_data_block(fp, inode.data_block_num + i, super_block.block_size);
        memcpy(&recovered_data[bytes_read], data_block.data, strlen(data_block.data));
        bytes_read += strlen(data_block.data);
    }

    // Write recovered data to new file
    char recovered_filename[MAX_FILENAME_LEN];
    strcpy(recovered_filename, "recovered_");
    strcat(recovered_filename, filename);
    FILE *recovered_fp = fopen(recovered_filename, "wb");
    if (recovered_fp == NULL) {
        fprintf(stderr, "Cannot create recovered file\n");
        exit(1);
    }
    fwrite(recovered_data, sizeof(char), bytes_read, recovered_fp);
    fclose(recovered_fp);

    printf("File %s recovered successfully as %s\n", filename, recovered_filename);

    fclose(fp);
}

int main() {
    recover_file("corrupted_file_system");
    return 0;
}