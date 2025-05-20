//FormAI DATASET v1.0 Category: File system simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INODES_C 50
#define BLOCKS_C 130

struct inode {
    int i_number;
    int block_number;
    int file_size;
};

struct block {
    char data[1024];
};

struct file {
    char name[20];
    struct inode* inode;
    int offset;
};

struct superblock {
    int free_inode_count;
    int free_block_count;
};

struct file file_table[10];
struct inode inode_table[INODES_C];
struct block block_table[BLOCKS_C];
struct superblock fs;

int get_free_inode() {
    if (fs.free_inode_count > 0) {
        fs.free_inode_count--;
        for (int i = 0; i < INODES_C; i++) {
            if (inode_table[i].i_number == 0) {
                inode_table[i].i_number = i + 1;
                return i;
            }
        }
    }
    printf("Error: No free inodes available!\n");
    return -1;
}

int get_free_block() {
    if (fs.free_block_count > 0) {
        fs.free_block_count--;
        for (int i = 0; i < BLOCKS_C; i++) {
            if (strlen(block_table[i].data) == 0) {
                return i;
            }
        }
    }
    printf("Error: No free blocks available!\n");
    return -1;
}

void create_file(char* file_name) {
    for (int i = 0; i < 10; i++) {
        if (!strcmp(file_table[i].name, file_name)) {
            printf("Error: File already exists!\n");
            return;
        }
    }
    int inode_id = get_free_inode();
    int block_id = get_free_block();
    inode_table[inode_id].block_number = block_id;
    inode_table[inode_id].file_size = 0;
    struct inode* inode = &inode_table[inode_id];

    strcpy(file_table[fs.free_inode_count].name, file_name);
    file_table[fs.free_inode_count].inode = inode;
    file_table[fs.free_inode_count].offset = 0;

    printf("File '%s' created with inode %d and block %d.\n", file_name, inode_id + 1, block_id);
}

void write_to_file(char* file_name, char* data) {
    for (int i = 0; i < 10; i++) {
        if (!strcmp(file_table[i].name, file_name)) {
            struct file* file = &file_table[i];
            struct inode* inode = file->inode;
            int block_id = inode->block_number;
            int offset = file->offset;

            int data_size = strlen(data);
            int remaining_space = 1024 - strlen(block_table[block_id].data);

            if (remaining_space < data_size) {
                block_id = get_free_block();
                inode->block_number = block_id;
                offset = 0;
            }

            strncpy(block_table[block_id].data + offset, data, data_size);
            inode->file_size += data_size;
            file->offset += data_size;
            printf("'%s' written to file '%s'.\n", data, file_name);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", file_name);
}

void delete_file(char* file_name) {
    for (int i = 0; i < 10; i++) {
        if (!strcmp(file_table[i].name, file_name)) {
            struct file* file = &file_table[i];
            struct inode* inode = file->inode;
            int block_id = inode->block_number;

            inode->i_number = 0;
            inode->block_number = 0;
            inode->file_size = 0;
            file->offset = 0;

            memset(block_table[block_id].data, 0, sizeof(block_table[block_id].data));
            memset(file_table[i].name, 0, sizeof(file_table[i].name));
            file_table[i].inode = NULL;

            fs.free_inode_count++;
            fs.free_block_count++;

            printf("File '%s' deleted.\n", file_name);
            return;
        }
    }
    printf("Error: File '%s' not found!\n", file_name);
}

int main() {
    fs.free_inode_count = INODES_C;
    fs.free_block_count = BLOCKS_C;

    create_file("test.txt");
    write_to_file("test.txt", "Hello world!");
    write_to_file("test.txt", "This is a file system simulation program.");
    delete_file("test.txt");
    
    return 0;
}