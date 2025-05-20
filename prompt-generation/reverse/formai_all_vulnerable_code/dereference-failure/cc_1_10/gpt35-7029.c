//FormAI DATASET v1.0 Category: File system simulation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define BLOCKS_NUM 100

typedef struct block {
    int index; 
    char data[BLOCK_SIZE];
    struct block *next;
} Block;

typedef struct file {
    char name[30];
    int size;
    Block *block;
    struct file *next;
} File;

Block *disk[BLOCKS_NUM];
File *files = NULL;

void initialize_disk() {
    for(int i = 0; i < BLOCKS_NUM; i++) {
        disk[i] = (Block*) malloc(sizeof(Block));
        disk[i]->index = i;
        disk[i]->next = NULL;
        memset(disk[i]->data, 0, sizeof(disk[i]->data));
    }
}

void create_file(char *name, int size) {
    if(files == NULL) {
        File *new_file = (File*) malloc(sizeof(File));
        new_file->size = size;
        strcpy(new_file->name, name);
        int blocks_needed = size / BLOCK_SIZE;
        if(size % BLOCK_SIZE != 0) {
            blocks_needed++;
        }
        Block *block = NULL;
        for(int i = 0; i < blocks_needed; i++) {
            if(block == NULL) {
                block = disk[0];
            } else {
                block = block->next;
            }
            if(block == NULL) {
                printf("Error: Disk full!\n");
                return;
            }
            if(i == 0) {
                new_file->block = block;
            } else {
                new_file->block->next = block;
                new_file->block = new_file->block->next;
            }
        }
        new_file->next = files;
        files = new_file;
        printf("File created successfully!\n");
    } else {
        File *current = files;
        while(current != NULL) {
            if(strcmp(current->name, name) == 0) {
                printf("Error: A file with that name already exists!\n");
                return;
            }
            current = current->next;
        }
        File *new_file = (File*) malloc(sizeof(File));
        new_file->size = size;
        strcpy(new_file->name, name);
        int blocks_needed = size / BLOCK_SIZE;
        if(size % BLOCK_SIZE != 0) {
            blocks_needed++;
        }
        Block *block = NULL;
        for(int i = 0; i < blocks_needed; i++) {
            if(block == NULL) {
                block = disk[0];
            } else {
                block = block->next;
            }
            if(block == NULL) {
                printf("Error: Disk full!\n");
                return;
            }
            if(i == 0) {
                new_file->block = block;
            } else {
                new_file->block->next = block;
                new_file->block = new_file->block->next;
            }
        }
        new_file->next = files;
        files = new_file;
        printf("File created successfully!\n");
    }
}

void delete_file(char *name) {
    if(files == NULL) {
        printf("Error: No files to delete!\n");
        return;
    }
    File *current = files;
    if(strcmp(current->name, name) == 0) {
        files = current->next;
        Block *block = current->block;
        while(block != NULL) {
            block = block->next;
            free(current->block);
            current->block = block;
        }
        free(current);
        printf("File deleted successfully!\n");
        return;
    }
    while(current->next != NULL && strcmp(current->next->name, name) != 0) {
        current = current->next;
    }
    if(current->next != NULL) {
        Block *block = current->next->block;
        while(block != NULL) {
            block = block->next;
            free(current->next->block);
            current->next->block = block;
        }
        current->next = current->next->next;
        free(current->next);
        printf("File deleted successfully!\n");
    } else {
        printf("Error: File not found!\n");
    }
}

void list_files() {
    if(files == NULL) {
        printf("No files to display!\n");
        return;
    }
    File *current = files;
    while(current != NULL) {
        printf("File name: %s\n", current->name);
        printf("File size: %d bytes\n", current->size);
        current = current->next;
    }
}

int main() {
    initialize_disk();
    create_file("file1.txt", 1536);
    create_file("file2.txt", 2048);
    create_file("file3.txt", 1024);
    list_files();
    delete_file("file1.txt");
    list_files();
    return 0;
}