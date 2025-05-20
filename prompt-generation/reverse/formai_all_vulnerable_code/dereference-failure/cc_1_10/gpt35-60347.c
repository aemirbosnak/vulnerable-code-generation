//FormAI DATASET v1.0 Category: File system simulation ; Style: optimized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int FILENAME_LENGTH = 10;

typedef struct {
    char* filename;
    int file_size;
    char* data;
    int* block_ptrs;
} File;

typedef struct {
    int* free_blocks;
    int free_blocks_size;
    int num_files;
    File** files;
} FileSystem;

void initialize_fs(FileSystem* fs, int num_blocks) {
    fs->free_blocks_size = num_blocks;
    fs->num_files = 0;
    fs->free_blocks = (int*)malloc(num_blocks * sizeof(int));
    for (int i = 0; i < num_blocks; i++) {
        fs->free_blocks[i] = i;
    }
    fs->files = NULL;
}

int allocate_block(FileSystem* fs) {
    if (fs->free_blocks_size == 0) {
        return -1;
    }
    int block_num = fs->free_blocks[fs->free_blocks_size - 1];
    fs->free_blocks_size--;
    return block_num;
}

void deallocate_block(FileSystem* fs, int block_num) {
    fs->free_blocks_size++;
    fs->free_blocks[fs->free_blocks_size - 1] = block_num;
}

void create_file(FileSystem* fs, char* filename, int file_size, char* data) {
    if (fs->num_files == 0) {
        fs->files = (File**)malloc(sizeof(File*));
    } else {
        fs->files = (File**)realloc(fs->files, (fs->num_files + 1) * sizeof(File*));
    }
    File* new_file = (File*)malloc(sizeof(File));
    new_file->filename = (char*)malloc(FILENAME_LENGTH * sizeof(char));
    strncpy(new_file->filename, filename, FILENAME_LENGTH);
    new_file->file_size = file_size;
    new_file->data = (char*)malloc(file_size * sizeof(char));
    strncpy(new_file->data, data, file_size);
    int num_blocks = (file_size / sizeof(int)) + 1;
    new_file->block_ptrs = (int*)malloc(num_blocks * sizeof(int));
    for (int i = 0; i < num_blocks; i++) {
        new_file->block_ptrs[i] = allocate_block(fs);
        if (new_file->block_ptrs[i] == -1) {
            printf("Error: file creation failed due to lack of free blocks.\n");
            free(new_file->filename);
            free(new_file->data);
            free(new_file->block_ptrs);
            free(new_file);
            fs->num_files--;
            return;
        }
    }
    fs->files[fs->num_files] = new_file;
    fs->num_files++;
}

void delete_file(FileSystem* fs, char* filename) {
    int file_idx = -1;
    for (int i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i]->filename, filename) == 0) {
            file_idx = i;
            break;
        }
    }
    if (file_idx == -1) {
        printf("Error: file not found.\n");
        return;
    }
    for (int i = 0; i < ((fs->files[file_idx]->file_size / sizeof(int)) + 1); i++) {
        deallocate_block(fs, fs->files[file_idx]->block_ptrs[i]);
    }
    free(fs->files[file_idx]->filename);
    free(fs->files[file_idx]->data);
    free(fs->files[file_idx]->block_ptrs);
    free(fs->files[file_idx]);
    for (int i = file_idx; i < fs->num_files - 1; i++) {
        fs->files[i] = fs->files[i + 1];
    }
    fs->num_files--;
    if (fs->num_files == 0) {
        free(fs->files);
        fs->files = NULL;
    } else {
        fs->files = (File**)realloc(fs->files, fs->num_files * sizeof(File*));
    }
}

int main() {
    FileSystem fs;
    initialize_fs(&fs, 10);
    create_file(&fs, "file1", 10, "abcdefghij");
    create_file(&fs, "file2", 7, "abcdefg");
    create_file(&fs, "file3", 14, "abcdefghijklmn");
    for (int i = 0; i < fs.num_files; i++) {
        printf("File %d:\n", i);
        printf("\tFilename: %s\n", fs.files[i]->filename);
        printf("\tFile size: %d\n", fs.files[i]->file_size);
        printf("\tData: %s\n", fs.files[i]->data);
        printf("\tBlock pointers:");
        for (int j = 0; j < ((fs.files[i]->file_size / sizeof(int)) + 1); j++) {
            printf(" %d", fs.files[i]->block_ptrs[j]);
        }
        printf("\n");
    }
    delete_file(&fs, "file2");
    printf("\nAfter deleting file2:\n");
    for (int i = 0; i < fs.num_files; i++) {
        printf("File %d:\n", i);
        printf("\tFilename: %s\n", fs.files[i]->filename);
        printf("\tFile size: %d\n", fs.files[i]->file_size);
        printf("\tData: %s\n", fs.files[i]->data);
        printf("\tBlock pointers:");
        for (int j = 0; j < ((fs.files[i]->file_size / sizeof(int)) + 1); j++) {
            printf(" %d", fs.files[i]->block_ptrs[j]);
        }
        printf("\n");
    }
    delete_file(&fs, "file1");
    delete_file(&fs, "file3");
    return 0;
}