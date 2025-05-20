//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

struct data_block {          /* Structure to hold data block */
    int size;
    char* data;
};

struct file_system {         /* Structure to hold file system */
    int num_blocks;
    struct data_block* blocks;
};

struct file_system* create_file_system(int num_blocks) {
    struct file_system* fs = (struct file_system*)malloc(sizeof(struct file_system));
    fs->num_blocks = num_blocks;
    fs->blocks = (struct data_block*)malloc(sizeof(struct data_block) * num_blocks);
    for(int i = 0; i < num_blocks; i++) {
        fs->blocks[i].size = 0;
        fs->blocks[i].data = NULL;
    }
    return fs;
}

void delete_file_system(struct file_system** fs) {   /* Deleting file system */
    for(int i = 0; i < (*fs)->num_blocks; i++) {
        if((*fs)->blocks[i].data != NULL) {
            free((*fs)->blocks[i].data);
            (*fs)->blocks[i].data = NULL;
        }
    }
    free((*fs)->blocks);
    free(*fs);
    *fs = NULL;
}

void add_data(struct file_system* fs, int block_num, char* data, int size) {    /* Adding data to blocks */
    if(block_num >= fs->num_blocks) {
        printf("Block number out of range!\n");
        return;
    }
    if(fs->blocks[block_num].data != NULL) {
        printf("Block is already being used!\n");
        return;
    }
    fs->blocks[block_num].size = size;
    fs->blocks[block_num].data = (char*)malloc(sizeof(char) * size);
    for(int i = 0; i < size; i++) {
        fs->blocks[block_num].data[i] = data[i];
    }
}

void delete_data(struct file_system* fs, int block_num) {    /* Clearing data from block */
    if(block_num >= fs->num_blocks) {
        printf("Block number out of range!\n");
        return;
    }
    if(fs->blocks[block_num].data == NULL) {
        printf("Block is already empty!\n");
        return;
    }
    free(fs->blocks[block_num].data);
    fs->blocks[block_num].data = NULL;
    fs->blocks[block_num].size = 0;
}

void print_data(struct file_system* fs, int block_num) {    /* Printing data from block */
    if(block_num >= fs->num_blocks) {
        printf("Block number out of range!\n");
        return;
    }
    if(fs->blocks[block_num].data == NULL) {
        printf("Block is empty!\n");
        return;
    }
    printf("%s\n", fs->blocks[block_num].data);
}

int main() {
    struct file_system* fs = create_file_system(20);
    char data1[] = "Hello world!";
    char data2[] = "This is a test.";
    add_data(fs, 0, data1, sizeof(data1));
    add_data(fs, 1, data2, sizeof(data2));
    print_data(fs, 0);
    print_data(fs, 1);
    delete_data(fs, 1);
    print_data(fs, 1);
    delete_file_system(&fs);
    return 0;
}