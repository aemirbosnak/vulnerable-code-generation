//FormAI DATASET v1.0 Category: File system simulation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100             // Maximum number of files in the file system
#define MAX_NAME_LENGTH 20        // Maximum length of file name
#define MAX_BLOCK_SIZE 1024       // Maximum size of file blocks
#define MAX_FILE_SIZE 1024*1024   // Maximum size of a file

typedef struct{
    char name[MAX_NAME_LENGTH];
    int size;
    int block_count;
    int *blocks;
    int current_position;
} file;

// The file system
file files[MAX_FILES];
int current_number_of_files = 0;
int current_block = 0;

// Function to create a new file
int create_file(char *name, int size){
    // Check if the file already exists
    for(int i=0; i<current_number_of_files; i++){
        if(strcmp(files[i].name,name)==0){
            printf("File %s already exists.\n",name);
            return -1;
        }
    }
    // Check if there is enough space in the file system
    if(current_block + size/MAX_BLOCK_SIZE >= MAX_FILES){
        printf("Not enough space in file system.\n");
        return -1;
    }
    // Create the new file
    files[current_number_of_files].size = size;
    files[current_number_of_files].block_count = (size-1)/MAX_BLOCK_SIZE + 1;
    files[current_number_of_files].blocks = (int*)malloc(files[current_number_of_files].block_count*sizeof(int));
    for(int i=0; i<files[current_number_of_files].block_count; i++){
        files[current_number_of_files].blocks[i] = current_block+i;
    }
    strcpy(files[current_number_of_files].name,name);
    current_number_of_files++;
    current_block += files[current_number_of_files-1].block_count;
    printf("File %s created successfully.\n",name);
    return 0;
}

// Function to write to a file
int write_file(char *name, char *data){
    int file_index = -1;
    for(int i=0; i<current_number_of_files; i++){
        if(strcmp(files[i].name,name)==0){
            file_index = i;
            break;
        }
    }
    if(file_index==-1){
        printf("File %s does not exist.\n",name);
        return -1;
    }
    if(strlen(data) > files[file_index].size){
        printf("Data too large for file %s.\n",name);
        return -1;
    }
    for(int i=0; i<files[file_index].block_count; i++){
        printf("Writing to block %d.\n",files[file_index].blocks[i]);
    }
    printf("Data written to file %s.\n",name);
    return 0;
}

// Function to read from a file
int read_file(char *name, int byte_count){
    int file_index = -1;
    for(int i=0; i<current_number_of_files; i++){
        if(strcmp(files[i].name,name)==0){
            file_index = i;
            break;
        }
    }
    if(file_index==-1){
        printf("File %s does not exist.\n",name);
        return -1;
    }
    if(byte_count > files[file_index].size){
        printf("Byte count larger than file size for file %s.\n",name);
        return -1;
    }
    int blocks_to_read = (byte_count-1)/MAX_BLOCK_SIZE + 1;
    for(int i=0; i<blocks_to_read; i++){
        printf("Reading from block %d.\n",files[file_index].blocks[i]);
    }
    printf("%d bytes read from file %s.\n",byte_count,name);
    return 0;
}

int main(){
    // Testing the file system
    create_file("test1.txt",1000);
    create_file("test2.txt",5000);
    create_file("test3.txt",10000);
    write_file("test1.txt","This is test data.");
    read_file("test2.txt",2000);
    return(0);
}