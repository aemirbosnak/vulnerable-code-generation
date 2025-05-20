//FormAI DATASET v1.0 Category: File system simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define NUM_BLOCKS 100

typedef struct block {
    char data[BLOCK_SIZE];
} Block;

typedef struct superblock {
    int num_blocks;
    int block_size;
    int free_blocks;
    int *free_block_list;
} Superblock;

typedef struct directory_entry {
    char name[20];
    int start_block;
    int size;
} DirectoryEntry;

typedef struct directory {
    DirectoryEntry entries[10];
} Directory;

typedef struct file_system {
    Superblock superblock;
    Directory directory;
    Block blocks[NUM_BLOCKS];
} FileSystem;

FileSystem fs;

void initialize_file_system() {
    // initialize superblock
    fs.superblock.num_blocks = NUM_BLOCKS;
    fs.superblock.block_size = BLOCK_SIZE;
    fs.superblock.free_blocks = NUM_BLOCKS;
    fs.superblock.free_block_list = (int *) malloc(NUM_BLOCKS * sizeof(int));
    for(int i=0; i<NUM_BLOCKS; i++) {
        fs.superblock.free_block_list[i] = i;
    }

    // initialize directory
    for(int i=0; i<10; i++) {
        strcpy(fs.directory.entries[i].name, "");
        fs.directory.entries[i].start_block = -1;
        fs.directory.entries[i].size = 0;
    }

    // initialize data blocks
    for(int i=0; i<NUM_BLOCKS; i++) {
        memset(fs.blocks[i].data, 0, BLOCK_SIZE);
    }

    printf("File system initialized!\n");
}

int allocate_block() {
    if(fs.superblock.free_blocks == 0) {
        printf("Error: no free blocks available!\n");
        return -1;
    }
    fs.superblock.free_blocks--;
    int block_num = fs.superblock.free_block_list[fs.superblock.free_blocks];
    return block_num;
}

void free_block(int block_num) {
    fs.superblock.free_block_list[fs.superblock.free_blocks] = block_num;
    fs.superblock.free_blocks++;
}

void create_file(char *filename) {
    // find a free entry in the directory
    int i=0;
    while(i<10 && strcmp(fs.directory.entries[i].name, "") != 0) {
        i++;
    }

    if(i == 10) {
        printf("Error: directory is full!\n");
        return;
    }

    // allocate a block for the file
    int start_block = allocate_block();
    if(start_block == -1) {
        return;
    }

    // update directory entry
    strcpy(fs.directory.entries[i].name, filename);
    fs.directory.entries[i].start_block = start_block;
    fs.directory.entries[i].size = 0;

    printf("File created: %s\n", filename);
}

void write_file(char *filename, char *data) {
    // find the entry in the directory
    int i=0;
    while(i<10 && strcmp(fs.directory.entries[i].name, filename) != 0) {
        i++;
    }

    if(i == 10) {
        printf("Error: file not found!\n");
        return;
    }

    // write data to file
    int block_num = fs.directory.entries[i].start_block;
    int data_offset = fs.directory.entries[i].size % BLOCK_SIZE;
    while(*data != '\0') {
        if(data_offset == BLOCK_SIZE) {
            block_num = allocate_block();
            if(block_num == -1) {
                fs.directory.entries[i].size -= data - fs.blocks[block_num].data;
                return;
            }
            fs.directory.entries[i].size += BLOCK_SIZE;
            data_offset = 0;
        }
        fs.blocks[block_num].data[data_offset++] = *data;
        data++;
    }
    fs.directory.entries[i].size += data - fs.blocks[block_num].data;

    printf("Data written to file: %s\n", filename);
}

void read_file(char *filename) {
    // find the entry in the directory
    int i=0;
    while(i<10 && strcmp(fs.directory.entries[i].name, filename) != 0) {
        i++;
    }

    if(i == 10) {
        printf("Error: file not found!\n");
        return;
    }

    // read data from file
    int block_num = fs.directory.entries[i].start_block;
    int data_offset = 0;
    while(data_offset < fs.directory.entries[i].size) {
        printf("%c", fs.blocks[block_num].data[data_offset++]);
        if(data_offset == BLOCK_SIZE) {
            block_num = fs.blocks[block_num].data[data_offset-1];
            data_offset = 0;
        }
    }
    printf("\n");
}

void delete_file(char *filename) {
    // find the entry in the directory
    int i=0;
    while(i<10 && strcmp(fs.directory.entries[i].name, filename) != 0) {
        i++;
    }

    if(i == 10) {
        printf("Error: file not found!\n");
        return;
    }

    // free blocks used by file
    int block_num = fs.directory.entries[i].start_block;
    while(block_num != -1) {
        free_block(block_num);
        block_num = fs.blocks[block_num].data[BLOCK_SIZE-1];
    }

    // update directory entry
    strcpy(fs.directory.entries[i].name, "");
    fs.directory.entries[i].start_block = -1;
    fs.directory.entries[i].size = 0;

    printf("File deleted: %s\n", filename);
}

int main() {
    initialize_file_system();

    create_file("file1");

    char data1[] = "hello world!";
    write_file("file1", data1);

    read_file("file1");

    char data2[] = "this is a test";
    write_file("file1", data2);

    read_file("file1");

    delete_file("file1");

    return 0;
}