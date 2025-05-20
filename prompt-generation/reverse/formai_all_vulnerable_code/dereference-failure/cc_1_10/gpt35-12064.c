//FormAI DATASET v1.0 Category: File system simulation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME_LENGTH 20
#define BLOCK_SIZE 512
#define MAX_BLOCKS 100

struct SuperBlock {
    int num_blocks;
    int *free_blocks;
};

struct DiskBlock {
    char data[BLOCK_SIZE];
    int next_block_idx;
};

struct FileDescriptor {
    char name[MAX_FILE_NAME_LENGTH];
    int size;
    int first_block_idx;
};

struct FileSystem {
    struct SuperBlock super_block;
    struct DiskBlock *disk_blocks;
    struct FileDescriptor *file_descriptors;
    int num_files;
};

void initialize_file_system(struct FileSystem *file_system, int num_blocks) {
    file_system->super_block.num_blocks = num_blocks;
    file_system->super_block.free_blocks = malloc(sizeof(int) * num_blocks);
    for (int i = 0; i < num_blocks; i++) {
        file_system->super_block.free_blocks[i] = i;
    }
    file_system->disk_blocks = malloc(sizeof(struct DiskBlock) * num_blocks);
    for (int i = 0; i < num_blocks; i++) {
        memset(file_system->disk_blocks[i].data, 0, BLOCK_SIZE);
        file_system->disk_blocks[i].next_block_idx = -1;
    }
    file_system->file_descriptors = malloc(sizeof(struct FileDescriptor) * MAX_FILES);
    file_system->num_files = 0;
}

void cleanup_file_system(struct FileSystem *file_system) {
    free(file_system->super_block.free_blocks);
    free(file_system->disk_blocks);
    free(file_system->file_descriptors);
}

int allocate_block(struct FileSystem *file_system) {
    if (file_system->super_block.num_blocks == 0) {
        return -1;
    }
    int idx = file_system->super_block.free_blocks[0];
    file_system->super_block.num_blocks--;
    for (int i = 0; i < file_system->super_block.num_blocks; i++) {
        file_system->super_block.free_blocks[i] = file_system->super_block.free_blocks[i+1];
    }
    return idx;
}

void free_block(struct FileSystem *file_system, int idx) {
    if (file_system->super_block.num_blocks == MAX_BLOCKS) {
        return;
    }
    int i = 0;
    while (file_system->super_block.free_blocks[i] < idx && i < file_system->super_block.num_blocks) {
        i++;
    }
    for (int j = file_system->super_block.num_blocks; j > i; j--) {
        file_system->super_block.free_blocks[j] = file_system->super_block.free_blocks[j-1];
    }
    file_system->super_block.free_blocks[i] = idx;
    file_system->super_block.num_blocks++;
}

int create_file(struct FileSystem *file_system, char *name) {
    if (file_system->num_files == MAX_FILES) {
        return -1;
    }
    strcpy(file_system->file_descriptors[file_system->num_files].name, name);
    file_system->file_descriptors[file_system->num_files].size = 0;
    file_system->file_descriptors[file_system->num_files].first_block_idx = allocate_block(file_system);
    file_system->num_files++;
    return 0;
}

int delete_file(struct FileSystem *file_system, char *name) {
    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->file_descriptors[i].name, name) == 0) {
            int idx = file_system->file_descriptors[i].first_block_idx;
            while (idx != -1) {
                int next_idx = file_system->disk_blocks[idx].next_block_idx;
                free_block(file_system, idx);
                idx = next_idx;
            }
            for (int j = i; j < file_system->num_files - 1; j++) {
                file_system->file_descriptors[j] = file_system->file_descriptors[j+1];
            }
            file_system->num_files--;
            return 0;
        }
    }
    return -1;
}

int write_file(struct FileSystem *file_system, char *name, char *data, int size) {
    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->file_descriptors[i].name, name) == 0) {
            int block_idx = file_system->file_descriptors[i].first_block_idx;
            int data_idx = 0;
            while (block_idx != -1 && data_idx < size) {
                strncpy(file_system->disk_blocks[block_idx].data, data + data_idx, BLOCK_SIZE);
                file_system->file_descriptors[i].size += BLOCK_SIZE;
                data_idx += BLOCK_SIZE;
                if (data_idx < size) {
                    if (file_system->disk_blocks[block_idx].next_block_idx == -1) {
                        file_system->disk_blocks[block_idx].next_block_idx = allocate_block(file_system);
                    }
                    block_idx = file_system->disk_blocks[block_idx].next_block_idx;
                }
            }
            return 0;
        }
    }
    return -1;
}

int read_file(struct FileSystem *file_system, char *name, char *data, int size) {
    for (int i = 0; i < file_system->num_files; i++) {
        if (strcmp(file_system->file_descriptors[i].name, name) == 0) {
            int block_idx = file_system->file_descriptors[i].first_block_idx;
            int data_idx = 0;
            while (block_idx != -1 && data_idx < size) {
                strncat(data, file_system->disk_blocks[block_idx].data, BLOCK_SIZE);
                data_idx += BLOCK_SIZE;
                block_idx = file_system->disk_blocks[block_idx].next_block_idx;
            }
            return 0;
        }
    }
    return -1;
}

int main() {
    struct FileSystem file_system;
    initialize_file_system(&file_system, 100);
    create_file(&file_system, "file1");
    create_file(&file_system, "file2");
    write_file(&file_system, "file1", "Lorem ipsum dolor sit amet, consectetur adipiscing elit.", 51);
    write_file(&file_system, "file1", " Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.", 68);
    char read_data[256];
    read_file(&file_system, "file1", read_data, 256);
    printf("Read data: %s\n", read_data);
    delete_file(&file_system, "file1");
    cleanup_file_system(&file_system);
    return 0;
}