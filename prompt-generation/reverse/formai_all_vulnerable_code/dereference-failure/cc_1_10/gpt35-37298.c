//FormAI DATASET v1.0 Category: File system simulation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 512
#define MAX_FILES 50

typedef struct file_t {
    char name[20];
    int size;
    int blocks[10];
} File;

typedef struct buffer_t {
    int block_num;
    char data[BLOCK_SIZE];
} Buffer;

typedef struct disk_t {
    int num_blocks;
    Buffer* buffers;
} Disk;

typedef struct open_file_t {
    File file;
    int current_block;
} OpenFile;

typedef struct file_system_t {
    Disk disk;
    File files[MAX_FILES];
    int num_files;
    OpenFile open_files[MAX_FILES];
    int num_open_files;
} FileSystem;

void initialize_file_system(FileSystem* fs) {
    // Initialize disk with 1000 blocks
    Disk disk;
    disk.num_blocks = 1000;
    disk.buffers = (Buffer*)malloc(disk.num_blocks * sizeof(Buffer));
    for (int i = 0; i < disk.num_blocks; i++) {
        disk.buffers[i].block_num = i;
        memset(disk.buffers[i].data, 0, BLOCK_SIZE);
    }
    fs->disk = disk;
    fs->num_files = 0;
    fs->num_open_files = 0;
}

int find_free_block(FileSystem* fs) {
    for (int i = 0; i < fs->disk.num_blocks; i++) {
        int is_free = 1;
        for (int j = 0; j < fs->num_files; j++) {
            for (int k = 0; k < fs->files[j].size; k++) {
                if (fs->files[j].blocks[k] == i) {
                    is_free = 0;
                    break;
                }
            }
        }
        if (is_free) {
            return i;
        }
    }
    return -1;
}

int add_file_to_system(FileSystem* fs, char* name, int size) {
    if (fs->num_files >= MAX_FILES) {
        return -1;
    }
    File file;
    strcpy(file.name, name);
    file.size = size;
    for (int i = 0; i < size; i++) {
        int block_num = find_free_block(fs);
        if (block_num == -1) {
            return -1;
        }
        file.blocks[i] = block_num;
    }
    fs->files[fs->num_files] = file;
    fs->num_files++;
    return 0;
}

int open_file(FileSystem* fs, char* name) {
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].name, name) == 0) {
            if (fs->num_open_files >= MAX_FILES) {
                return -1;
            }
            OpenFile open_file;
            open_file.file = fs->files[i];
            open_file.current_block = 0;
            fs->open_files[fs->num_open_files] = open_file;
            fs->num_open_files++;
            return fs->num_open_files - 1;
        }
    }
    return -1;
}

int close_file(FileSystem* fs, int file_index) {
    if (file_index < 0 || file_index >= fs->num_open_files) {
        return -1;
    }
    for (int i = file_index; i < fs->num_open_files - 1; i++) {
        fs->open_files[i] = fs->open_files[i+1];
    }
    fs->num_open_files--;
    return 0;
}

int read_block(FileSystem* fs, int file_index, char* data) {
    if (file_index < 0 || file_index >= fs->num_open_files) {
        return -1;
    }
    OpenFile open_file = fs->open_files[file_index];
    if (open_file.current_block >= open_file.file.size) {
        return -1;
    }
    int block_num = open_file.file.blocks[open_file.current_block];
    Buffer buffer = fs->disk.buffers[block_num];
    memcpy(data, buffer.data, BLOCK_SIZE);
    open_file.current_block++;
    return 0;
}

int write_block(FileSystem* fs, int file_index, char* data) {
    if (file_index < 0 || file_index >= fs->num_open_files) {
        return -1;
    }
    OpenFile open_file = fs->open_files[file_index];
    if (open_file.current_block >= open_file.file.size) {
        return -1;
    }
    int block_num = open_file.file.blocks[open_file.current_block];
    Buffer buffer = fs->disk.buffers[block_num];
    memcpy(buffer.data, data, BLOCK_SIZE);
    fs->disk.buffers[block_num] = buffer;
    open_file.current_block++;
    return 0;
}

int main() {
    FileSystem fs;
    initialize_file_system(&fs);
    
    add_file_to_system(&fs, "file1.txt", 3);
    add_file_to_system(&fs, "file2.txt", 2);
    
    int file1_index = open_file(&fs, "file1.txt");
    int file2_index = open_file(&fs, "file2.txt");
    
    char data[BLOCK_SIZE] = "Hello, world!";
    write_block(&fs, file1_index, data);
    read_block(&fs, file1_index, data);
    printf("%s\n", data);
    
    close_file(&fs, file1_index);
    close_file(&fs, file2_index);
    
    return 0;
}