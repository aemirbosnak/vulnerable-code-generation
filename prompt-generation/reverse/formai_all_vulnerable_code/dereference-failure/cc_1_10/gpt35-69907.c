//FormAI DATASET v1.0 Category: File system simulation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 10
#define MAX_BLOCKS 20
#define BLOCK_SIZE 512

typedef struct {
    char* name;
    int size;
    int* blocks;
} File;

typedef struct {
    int index;
    int is_free;
} Block;

typedef struct {
    Block* blocks;
    File* files[MAX_FILES];
} FileSystem;

void int_to_binary(int n, int* binary) {
    int i = 0;
    while (n > 0) {
        binary[i] = n % 2;
        n /= 2;
        i++;
    }
}

void generate_block_data(char* data) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        data[i] = rand() % 94 + 32; //Generate printable ASCII characters
    }
}

int find_free_block(Block* blocks, int num_blocks) {
    for (int i = 0; i < num_blocks; i++) {
        if (blocks[i].is_free) {
            return i;
        }
    }
    return -1;
}

File* create_file(FileSystem* fs, char* name, int size) {
    int num_blocks_needed = (size / BLOCK_SIZE) + 1;
    int* blocks_indices = malloc(sizeof(int) * num_blocks_needed);
    for (int i = 0; i < num_blocks_needed; i++) {
        int free_block_index = find_free_block(fs->blocks, MAX_BLOCKS);
        if (free_block_index == -1) {
            printf("No free blocks available\n");
            return NULL;
        }
        fs->blocks[free_block_index].is_free = 0;
        blocks_indices[i] = free_block_index;
    }
    File* f = malloc(sizeof(File));
    f->name = strdup(name);
    f->size = size;
    f->blocks = blocks_indices;
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] == NULL) {
            fs->files[i] = f;
            return f;
        }
    }
    printf("No more files can be created\n");
    return NULL;
}

void delete_file(FileSystem* fs, char* name) {
    for (int i = 0; i < MAX_FILES; i++) {
        if (fs->files[i] != NULL && strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]->name);
            free(fs->files[i]->blocks);
            free(fs->files[i]);
            fs->files[i] = NULL;
            printf("File '%s' deleted successfully\n", name);
            return;
        }
    }
    printf("File '%s' not found\n", name);
}

void print_filesystem_status(FileSystem* fs) {
    int* blocks_binary = malloc(sizeof(int) * MAX_BLOCKS * 8);
    for (int i = 0; i < MAX_BLOCKS; i++) {
        int_to_binary(fs->blocks[i].is_free, blocks_binary + (i * 8));
    }
    printf("File system status:\n");
    for (int i = 0; i < MAX_BLOCKS; i++) {
        if (i % 8 == 0) printf("|");
        printf("%c", blocks_binary[(i * 8) + 7] ? '1' : '0');
    }
    printf("|\n");
    free(blocks_binary);
}

int main() {
    srand(time(NULL));
    FileSystem fs;
    fs.blocks = malloc(sizeof(Block) * MAX_BLOCKS);
    for (int i = 0; i < MAX_BLOCKS; i++) {
        fs.blocks[i].index = i;
        fs.blocks[i].is_free = 1;
    }
    create_file(&fs, "file1", 2050);
    File* f1 = create_file(&fs, "file2", 2000);
    create_file(&fs, "file3", 100);
    delete_file(&fs, "file2");
    print_filesystem_status(&fs);
    return 0;
}