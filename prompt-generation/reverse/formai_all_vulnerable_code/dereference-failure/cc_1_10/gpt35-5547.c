//FormAI DATASET v1.0 Category: File system simulation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_BLOCKS 1000
#define MAX_FILENAME_LEN 20

typedef struct {
    char filename[MAX_FILENAME_LEN];
    int block_start;
    int block_count;
} file_entry;

typedef struct {
    file_entry* entries;
    int count;
} directory;

typedef struct {
    void* data;
    int size;
} block;

typedef struct {
    block blocks[MAX_BLOCKS];
    int count;
    int free_list[MAX_BLOCKS];
    int free_count;
} file_system;

directory* create_directory() {
    directory* dir = malloc(sizeof(directory));
    dir->entries = NULL;
    dir->count = 0;
    return dir;
}

int add_file(directory* dir, char* filename, int block_start, int block_count) {
    file_entry entry;
    strncpy(entry.filename, filename, MAX_FILENAME_LEN);
    entry.block_start = block_start;
    entry.block_count = block_count;
    
    dir->entries = realloc(dir->entries, (dir->count + 1) * sizeof(file_entry));
    if (!dir->entries) {
        return 0;
    }
    
    dir->entries[dir->count] = entry;
    dir->count++;
    
    return 1;
}

void print_directory(directory* dir) {
    printf("Directory:\n");
    printf("%-20s %-10s %-10s\n", "Filename", "Block Start", "Block Count");
    for (int i = 0; i < dir->count; i++) {
        printf("%-20s %-10d %-10d\n", dir->entries[i].filename, dir->entries[i].block_start, dir->entries[i].block_count);
    }
}

int get_free_block(file_system* fs) {
    if (fs->free_count == 0) {
        return -1;
    }
    
    int block_index = fs->free_list[0];
    for (int i = 0; i < fs->free_count - 1; i++) {
        fs->free_list[i] = fs->free_list[i+1];
    }
    fs->free_count--;
    
    return block_index;
}

void free_block(file_system* fs, int block_index) {
    fs->free_list[fs->free_count] = block_index;
    fs->free_count++;
}

block* read_block(file_system* fs, int block_index) {
    if (block_index >= fs->count || block_index < 0) {
        return NULL;
    }
    return &fs->blocks[block_index];
}

int write_block(file_system* fs, int block_index, void* data, int size) {
    if (block_index >= fs->count || block_index < 0) {
        return 0;
    }
    if (size > BLOCK_SIZE) {
        return 0;
    }
    memcpy(fs->blocks[block_index].data, data, size);
    fs->blocks[block_index].size = size;
    return 1;
}

file_system* create_file_system() {
    file_system* fs = malloc(sizeof(file_system));
    fs->count = 0;
    fs->free_count = 0;
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fs->free_list[i] = i;
    }
    return fs;
}

int add_file_to_system(file_system* fs, directory* dir, char* filename, void* data, int size) {
    int num_blocks = size / BLOCK_SIZE + (size % BLOCK_SIZE == 0 ? 0 : 1);
    int* blocks = malloc(num_blocks * sizeof(int));
    if (!blocks) {
        return 0;
    }
    
    for (int i = 0; i < num_blocks; i++) {
        int block_index = get_free_block(fs);
        if (block_index == -1) {
            return 0;
        }
        blocks[i] = block_index;
        if (!write_block(fs, block_index, data + i*BLOCK_SIZE, size - i*BLOCK_SIZE > BLOCK_SIZE ? BLOCK_SIZE : size - i*BLOCK_SIZE)) {
            return 0;
        }
    }
    
    if (!add_file(dir, filename, blocks[0], num_blocks)) {
        for (int i = 0; i < num_blocks; i++) {
            free_block(fs, blocks[i]);
        }
        return 0;
    }
    
    return 1;
}

void print_block(block* b) {
    printf("Block size: %d\n", b->size);
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02X ", ((unsigned char*)b->data)[i]);
        if ((i+1) % 16 == 0) {
            printf("\n");
        }
    }
    printf("\n");
}

int main() {
    file_system* fs = create_file_system();
    directory* dir = create_directory();
    
    char data[] = "Hello, world!";
    if (!add_file_to_system(fs, dir, "example.txt", data, strlen(data))) {
        printf("Error adding file to system.\n");
        return 0;
    }
    
    print_directory(dir);
    
    block* b = read_block(fs, dir->entries[0].block_start);
    print_block(b);
    
    return 1;
}