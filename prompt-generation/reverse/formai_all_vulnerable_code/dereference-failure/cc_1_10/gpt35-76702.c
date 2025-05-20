//FormAI DATASET v1.0 Category: File system simulation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 100

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    int start_block;
    int end_block;
    int size;
} file_entry;

typedef struct {
    int block_id;
    int next_block;
    char data[MAX_FILE_SIZE];
} block;

file_entry* directory;
block* blocks;
int num_blocks;


int allocate_block() {
    for (int i = 0; i < num_blocks - 1; i++) {
        if (blocks[i].next_block == -1) {
            blocks[i].next_block = i + 1;
            return i;
        }
    }
    return -1;
}

void write_block(int block_id, char* data) {
    strncpy(blocks[block_id].data, data, MAX_FILE_SIZE);
    blocks[block_id].next_block = -1;
}

int write_file(char* filename, char* data, int size) {
    int start_block = allocate_block();
    if (start_block == -1) {
        return -1;
    }
    
    blocks[start_block].block_id = start_block;
    write_block(start_block, data);
    
    int end_block = start_block;
    int remaining_size = size - MAX_FILE_SIZE;
    while (remaining_size > 0) {
        int next_block = allocate_block();
        if (next_block == -1) {
            return -1;
        }
        
        write_block(next_block, data + size - remaining_size);
        blocks[end_block].next_block = next_block;
        end_block = next_block;
        
        remaining_size -= MAX_FILE_SIZE;
    }
    
    int file_index = -1;
    for (int i = 0; i < num_blocks; i++) {
        if (directory[i].size == -1) {
            file_index = i;
            break;
        }
    }
    if (file_index == -1) {
        return -1;
    }
    
    file_entry new_entry = {
        .start_block = start_block,
        .end_block = end_block,
        .size = size
    };
    strncpy(new_entry.filename, filename, MAX_FILENAME_LENGTH);
    
    directory[file_index] = new_entry;
    
    return file_index;
}

char* read_file(char* filename) {
    for (int i = 0; i < num_blocks; i++) {
        if (strcmp(directory[i].filename, filename) == 0) {
            char* data = malloc(directory[i].size + 1);
            int current_block = directory[i].start_block;
            int current_pos = 0;
            while (current_block != -1) {
                strncpy(data + current_pos, blocks[current_block].data, MAX_FILE_SIZE);
                current_block = blocks[current_block].next_block;
                current_pos += MAX_FILE_SIZE;
            }
            return data;
        }
    }
    return NULL;
}

int main() {
    num_blocks = 5;
    directory = malloc(num_blocks * sizeof(file_entry));
    blocks = malloc(num_blocks * sizeof(block));
    
    for (int i = 0; i < num_blocks; i++) {
        file_entry empty_entry = {
            .size = -1,
            .start_block = -1,
            .end_block = -1
        };
        directory[i] = empty_entry;
        
        block empty_block = {
            .block_id = i,
            .next_block = -1
        };
        blocks[i] = empty_block;
    }
    
    char file1[] = "file1";
    char file1_data[] = "This is the data for file1.";
    write_file(file1, file1_data, strlen(file1_data));
    
    char file2[] = "file2";
    char file2_data[] = "This is the data for file2. It is longer than file1.";
    write_file(file2, file2_data, strlen(file2_data));
    
    char* read_file1 = read_file(file1);
    char* read_file2 = read_file(file2);
    
    printf("File 1 data: %s\n", read_file1);
    printf("File 2 data: %s\n", read_file2);
    
    free(read_file1);
    free(read_file2);
    free(directory);
    free(blocks);
    
    return 0;
}