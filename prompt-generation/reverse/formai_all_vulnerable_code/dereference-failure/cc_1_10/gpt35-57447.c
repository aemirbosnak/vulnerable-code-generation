//FormAI DATASET v1.0 Category: File system simulation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BLOCK_SIZE 32
#define MAX_FILE_NAME_LENGTH 20

struct index_node{
    int inode_number;
    int file_size;
    int block_count;
    int* block_pointers;
};

struct directory_entry{
    int inode_number;
    char file_name[MAX_FILE_NAME_LENGTH];
};

struct file_system{
    int total_blocks;
    int free_blocks;
    int block_size;
    int inode_count;
    int directory_count;
    struct index_node** inode_list;
    struct directory_entry* root_directory;
};

void init_file_system(struct file_system* fs, int total_blocks, int block_size){
    int i;
    fs -> total_blocks = total_blocks;
    fs -> block_size = block_size;
    fs -> inode_count = 0;
    fs-> directory_count = 0;
    fs -> inode_list = (struct index_node**)malloc(sizeof(struct index_node*) * total_blocks);
    fs -> root_directory = (struct directory_entry*)malloc(sizeof(struct directory_entry) * total_blocks);
    for(i = 0; i < total_blocks; i++){
        fs -> inode_list[i] = NULL;
    }
}

int allocate_block(struct file_system* fs){
    if(fs -> free_blocks == 0){
        printf("No free blocks available\n");
        return -1;
    }else{
        int i;
        for(i = 0; i < fs -> total_blocks; i++){
            if(fs -> inode_list[i] == NULL)
                break;
        }
        fs -> inode_list[i] = (struct index_node*)malloc(sizeof(struct index_node));
        fs -> inode_list[i] -> inode_number = i;
        fs -> inode_list[i] -> file_size = 0;
        fs -> inode_list[i] -> block_count = 0;
        fs -> inode_list[i] -> block_pointers = (int*)malloc(sizeof(int) * BLOCK_SIZE);
        fs -> free_blocks--;
        fs -> inode_count++;
        return i;
    }
}

void deallocate_block(struct file_system* fs, int block_number){
    fs -> inode_count--;
    fs -> free_blocks++;
    free(fs -> inode_list[block_number] -> block_pointers);
    free(fs -> inode_list[block_number]);
    fs -> inode_list[block_number] = NULL;
}

int create_file(struct file_system* fs, char* file_name){
    if(fs -> free_blocks == 0){
        printf("No free blocks available\n");
        return -1;
    }else{
        int i, file_inode_number;
        for(i = 0; i < fs -> total_blocks; i++){
            if(fs -> inode_list[i] == NULL)
                break;
        }
        file_inode_number = allocate_block(fs);
        fs -> root_directory[fs -> directory_count].inode_number = file_inode_number;
        strcpy(fs -> root_directory[fs -> directory_count].file_name, file_name);
        fs -> directory_count++;
        return file_inode_number;
    }
}

void delete_file(struct file_system* fs, int inode_number){
    int i, j;
    for(i = 0; i < fs -> directory_count; i++){
        if(fs -> root_directory[i].inode_number == inode_number)
            break;
    }
    for(j = i; j < fs -> directory_count - 1; j++){
        fs -> root_directory[j] = fs -> root_directory[j+1];
    }
    fs -> directory_count--;
    deallocate_block(fs, inode_number);
}

void write_data(struct file_system* fs, int inode_number, char* data, int size){
    int i, block_number, offset, data_offset = 0;
    while(size > 0){
        if(fs -> inode_list[inode_number] -> block_count == 0){
            block_number = allocate_block(fs);
            fs -> inode_list[inode_number] -> block_pointers[0] = block_number;
            fs -> inode_list[inode_number] -> block_count++;
        }else{
            block_number = fs -> inode_list[inode_number] -> block_pointers[fs -> inode_list[inode_number] -> block_count - 1];
            if(ftell(stdin) % fs -> block_size == 0){
                block_number = allocate_block(fs);
                fs -> inode_list[inode_number] -> block_pointers[fs -> inode_list[inode_number] -> block_count] = block_number;
                fs -> inode_list[inode_number] -> block_count++;
            }
        }
        offset = ftell(stdin) % fs -> block_size;
        fwrite(data + data_offset, sizeof(char), fs -> block_size - offset, stdout);
        size -= fs -> block_size - offset;
        data_offset += fs -> block_size - offset;
    }
    fs -> inode_list[inode_number] -> file_size += data_offset;
}

void read_data(struct file_system* fs, int inode_number, char* data, int size){
    int i, block_number, offset, data_offset = 0;
    while(size > 0){
        if(fs -> inode_list[inode_number] -> block_count == 0){
            printf("No data found\n");
            return;
        }else{
            block_number = fs -> inode_list[inode_number] -> block_pointers[fs -> inode_list[inode_number] -> block_count - 1];
        }
        offset = ftell(stdin) % fs -> block_size;
        fread(data + data_offset, sizeof(char), fs -> block_size - offset, stdin);
        size -= fs -> block_size - offset;
        data_offset += fs -> block_size - offset;
    }
}

int main(){
    char data[100];
    struct file_system fs;
    init_file_system(&fs, 100, 32);
    int file_inode_number1 = create_file(&fs, "file1");
    int file_inode_number2 = create_file(&fs, "file2");
    int file_inode_number3 = create_file(&fs, "file3");
    strcpy(data, "sample data");
    write_data(&fs, file_inode_number1, data, strlen(data));
    read_data(&fs, file_inode_number1, data, strlen(data));
    printf("%s\n", data);
    delete_file(&fs, file_inode_number1);
    delete_file(&fs, file_inode_number2);
    delete_file(&fs, file_inode_number3);
    printf("Program executed successfully\n");
    return 0;
}