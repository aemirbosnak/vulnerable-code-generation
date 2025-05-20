//FormAI DATASET v1.0 Category: File system simulation ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILES 100
#define FILE_NAME_LEN 20
#define BLOCK_SIZE 512
#define BLOCK_COUNT 10000

typedef struct file {
    char name[FILE_NAME_LEN];
    int size;
    int block_count;
    int block_pointer;
}file_t;

typedef struct block {
    int id;
    char data[BLOCK_SIZE];
    struct block *next;
}block_t;

block_t *block_list;

file_t file_table[MAX_FILES];
int file_count = 0;

void init_fs() {
    block_list = (block_t*)malloc(sizeof(block_t));
    block_list->id = 0;
    block_list->next = NULL;
}

void make_blocks(int count) {
    block_t *curr_block = block_list;
    while (curr_block->next != NULL) {
        curr_block = curr_block->next;
    }
    for (int i = 0; i < count; i++) {
        block_t *new_block = (block_t*)malloc(sizeof(block_t));
        new_block->id = curr_block->id + 1;
        new_block->next = NULL;
        curr_block->next = new_block;
        curr_block = new_block;
    }
}

int get_free_block() {
    int block_id = -1;
    block_t *curr_block = block_list;
    while (curr_block->next != NULL) {
        if (curr_block->next->id > 0) {
            if (curr_block->next->id - curr_block->id > 1) {
                block_id = curr_block->id + 1;
                break;
            }
        }
        curr_block = curr_block->next;
    }
    if (block_id == -1) {
        block_id = curr_block->id + 1;
        make_blocks(1);
    }
    return block_id;
}

void create_file(char *file_name) {
    if (file_count < MAX_FILES) {
        file_t *new_file = &file_table[file_count];
        new_file->size = 0;
        new_file->block_count = 0;
        new_file->block_pointer = -1;
        strcpy(new_file->name, file_name);
        file_count++;
    }
    else {
        printf("Sorry, maximum file limit has reached!\n");
    }
}

void write_data(char *file_name, char *data, int size) {
    int file_index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index != -1) {
        int blocks_needed = (size / BLOCK_SIZE) + 1;
        if (file_table[file_index].block_pointer == -1) {
            for (int i = 0; i < blocks_needed; i++) {
                int block_id = get_free_block();
                if (i == 0) {
                    file_table[file_index].block_pointer = block_id;
                }
                file_table[file_index].block_count++;
            }
        }
        block_t *curr_block = block_list;
        int blocks_visited = 0;
        while (curr_block != NULL && blocks_visited < file_table[file_index].block_pointer) {
            curr_block = curr_block->next;
            blocks_visited++;
        }
        int bytes_written = 0;
        while (curr_block != NULL && bytes_written < size) {
            int bytes_to_write = size - bytes_written;
            if (bytes_to_write > BLOCK_SIZE) {
                bytes_to_write = BLOCK_SIZE;
            }
            memcpy(curr_block->data, data+bytes_written, bytes_to_write);
            bytes_written += bytes_to_write;
            curr_block = curr_block->next;
        }
        file_table[file_index].size += size;
    }
    else {
        printf("Sorry, File not found!\n");
    }
}

void delete_file(char *file_name) {
    int file_index = -1;
    for (int i = 0; i < file_count; i++) {
        if (strcmp(file_table[i].name, file_name) == 0) {
            file_index = i;
            break;
        }
    }
    if (file_index != -1) {
        file_t *current_file = &file_table[file_index];
        block_t *current_block = block_list;
        int blocks_visited = 0;
        while (current_block != NULL && blocks_visited < current_file->block_pointer) {
            current_block = current_block->next;
            blocks_visited++;
        }
        for (int i = 0; i < current_file->block_count; i++) {
            int block_id = current_block->id;
            current_block->id = -1;
            current_block = current_block->next;
        }
        current_file->block_pointer = -1;
        current_file->block_count = 0;
        current_file->size = 0;
        memmove(&file_table[file_index], &file_table[file_index+1], sizeof(file_t)*(file_count-file_index-1));
        file_count--;
    }
    else {
        printf("Sorry, File not found!\n");
    }
}

void list_files() {
    printf("Name\tSize\n");
    for (int i = 0; i < file_count; i++) {
        printf("%s\t%d\n",file_table[i].name, file_table[i].size);
    }
}

int main() {
    init_fs();
    create_file("my_file.txt");
    char data[] = "Hello, World!";
    write_data("my_file.txt", data, 13);
    list_files();
    delete_file("my_file.txt");
    list_files();
    return 0;
}