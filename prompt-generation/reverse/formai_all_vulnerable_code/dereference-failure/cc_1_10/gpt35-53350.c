//FormAI DATASET v1.0 Category: File system simulation ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_INODES 10
#define BLOCK_SIZE 1024
#define NUM_BLOCKS 1000
#define FILE_NAME_MAX_LENGTH 100

typedef struct inode {
    char* file_name;
    int file_size;
    int blocks_used;
    int* block_list;
} i_node;

typedef struct file_system {
    i_node* inode_list[NUM_INODES];
    char* disk[NUM_BLOCKS];
} file_sys;

file_sys* create_file_system() {
    file_sys* fs = (file_sys*)malloc(sizeof(file_sys));
    for(int i=0; i<NUM_INODES; i++) {
        fs->inode_list[i] = NULL;
    }
    for(int i=0; i<NUM_BLOCKS; i++) {
        fs->disk[i] = NULL;
    }
    return fs;
}

void delete_file_system(file_sys* fs) {
    for(int i=0; i<NUM_INODES; i++) {
        if(fs->inode_list[i] != NULL) {
            free(fs->inode_list[i]->file_name);
            free(fs->inode_list[i]->block_list);
            free(fs->inode_list[i]);
        }
    }
    for(int i=0; i<NUM_BLOCKS; i++) {
        if(fs->disk[i] != NULL) {
            free(fs->disk[i]);
        }
    }
    free(fs);
}

int find_free_inode(file_sys* fs) {
    for(int i=0; i<NUM_INODES; i++) {
        if(fs->inode_list[i] == NULL) {
            return i;
        }
    }
    return -1;
}

int find_free_block(file_sys* fs) {
    for(int i=0; i<NUM_BLOCKS; i++) {
        if(fs->disk[i] == NULL) {
            char* block = (char*)malloc(BLOCK_SIZE);
            memset(block, 0, BLOCK_SIZE);
            fs->disk[i] = block;
            return i;
        }
    }
    return -1;
}

int create_file(file_sys* fs, char* name, int size) {
    int inode_index = find_free_inode(fs);
    if(inode_index == -1) {
        return -1;
    }
    i_node* inode = (i_node*)malloc(sizeof(i_node));
    inode->file_name = (char*)malloc(sizeof(char)*FILE_NAME_MAX_LENGTH);
    strcpy(inode->file_name, name);
    inode->file_size = size;
    inode->blocks_used = 0;
    inode->block_list = (int*)malloc(sizeof(int)*size);
    for(int i=0; i<size; i++) {
        int block_index = find_free_block(fs);
        if(block_index == -1) {
            delete_file_system(fs);
            printf("File system is full!\n");
            return -1;
        }
        inode->block_list[i] = block_index;
    }
    fs->inode_list[inode_index] = inode;
    return inode_index;
}

void delete_file(file_sys* fs, int inode_index) {
    i_node* inode = fs->inode_list[inode_index];
    for(int i=0; i<inode->file_size; i++) {
        int block_index = inode->block_list[i];
        free(fs->disk[block_index]);
        fs->disk[block_index] = NULL;
    }
    free(inode->file_name);
    free(inode->block_list);
    free(inode);
    fs->inode_list[inode_index] = NULL;
}

int main() {
    file_sys* fs = create_file_system();
    
    // create file
    int inode_index = create_file(fs, "sample.txt", 3);
    if(inode_index == -1) {
        printf("Failed to create file!\n");
        return -1;
    }
    
    // write to file
    i_node* inode = fs->inode_list[inode_index];
    char* block1 = fs->disk[inode->block_list[0]];
    char* block2 = fs->disk[inode->block_list[1]];
    char* block3 = fs->disk[inode->block_list[2]];
    memcpy(block1, "abc", 3);
    memcpy(block2, "def", 3);
    memcpy(block3, "ghi", 3);
    
    // read from file
    printf("File contents: ");
    for(int i=0; i<inode->file_size; i++) {
        int block_index = inode->block_list[i];
        char* block = fs->disk[block_index];
        printf("%s", block);
    }
    printf("\n");
    
    // delete file
    delete_file(fs, inode_index);
    
    delete_file_system(fs);
    return 0;
}