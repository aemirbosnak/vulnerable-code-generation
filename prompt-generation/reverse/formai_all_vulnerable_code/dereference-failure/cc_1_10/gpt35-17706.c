//FormAI DATASET v1.0 Category: File system simulation ; Style: active
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BLOCK_SIZE 1024                // Block size of the file system
#define MAX_FILES 10                  // Maximum number of files that can be created
#define FILE_NAME_SIZE 20             // Maximum size of file name in characters

// File descriptor structure
typedef struct FileDescriptor{
    int offset;                       // Current cursor position in file
    int start_block;                  // Starting block in file system
    char* file_name;                  // Name of the file
    int fd_size;                      // Size of the file
    int fd_id;                        // ID of the file
}fd;

// Directory Entry structure
typedef struct DirectoryEntry{
    char* file_name;                  // Name of the file
    int start_block;                  // Starting block in file system
    int size;                         // Size of the file
}directory_entry;

// File system structure
typedef struct FileSystem{
    int num_blocks;                   // Total number of blocks in file system
    int free_blocks;                  // Number of free blocks in file system
    fd* file_descriptors[MAX_FILES];  // Array of file descriptors
    directory_entry* directory;       // Array of directory entries
    char* file_system_data;           // Actual file system data
}file_system;

// Function definitions
void initialize_file_system(file_system* fs);
int create_file(file_system* fs, char* file_name, int file_size);
void delete_file(file_system* fs, int fd_id);
void read_file(file_system* fs, int fd_id, int num_bytes);
void write_file(file_system* fs, int fd_id, char* data);
int find_free_block(file_system* fs);
void print_directory(file_system* fs);

// Main function
int main()
{
    file_system fs;                            // Create a file system
    initialize_file_system(&fs);               // Initialize the file system

    int id1 = create_file(&fs, "file1", 2048); // Create file1 in file system
    printf("Created file1 with ID: %d\n", id1);

    int id2 = create_file(&fs, "file2", 1024); // Create file2 in file system
    printf("Created file2 with ID: %d\n", id2);

    int id3 = create_file(&fs, "file3", 4096); // Create file3 in file system
    printf("Created file3 with ID: %d\n", id3);

    printf("Directory:\n");
    print_directory(&fs);                      // Print the directory

    char data[] = "Hello World!";              // Data to write to file
    write_file(&fs, id1, data);                // Write data to file1

    printf("Reading %d bytes from file1...\n", strlen(data));
    read_file(&fs, id1, strlen(data));         // Read data from file1

    delete_file(&fs, id2);                     // Delete file2

    printf("Directory after deletion of file2:\n");
    print_directory(&fs);                      // Print the directory

    return 0;
}

// Function to initialize the file system
void initialize_file_system(file_system* fs){
    fs->num_blocks = 512;                            // Set total blocks in file system
    fs->free_blocks = fs->num_blocks;                // Set free blocks in file system
    fs->directory = (directory_entry*)malloc(sizeof(directory_entry)*MAX_FILES);  // Allocate directory memory
    fs->file_system_data = (char*)malloc(sizeof(char)*fs->num_blocks*BLOCK_SIZE);  // Allocate file system memory
    for(int i=0; i<MAX_FILES; i++){
        fs->file_descriptors[i] = NULL;             // Set all file descriptors to NULL initially
        fs->directory[i].file_name = NULL;           // Set file names to NULL initially in directory
    }
    printf("File system initialized with %d blocks of size %d bytes\n", fs->num_blocks, BLOCK_SIZE);
}

// Function to create a file
int create_file(file_system* fs, char* file_name, int file_size){
    if(fs->free_blocks <= 0){                        // Check if any free blocks are available
        printf("ERROR: No free blocks available in file system\n");
        return -1;
    }

    for(int i=0; i<MAX_FILES; i++){                  // Check if file with same name already exists
        if((fs->directory[i].file_name != NULL) && (strcmp(fs->directory[i].file_name, file_name) == 0)){
            printf("ERROR: File with same name already exists\n");
            return -1;
        }
    }

    int start_block = find_free_block(fs);           // Find a free block to write file data
    if(start_block == -1){
        printf("ERROR: No free blocks available in file system\n");
        return -1;
    }

    fd* new_fd = (fd*)malloc(sizeof(fd));            // Allocate memory for new file descriptor
    new_fd->offset = 0;                              // Set offset to beginning of file
    new_fd->start_block = start_block;               // Set start block of file
    new_fd->file_name = (char*)malloc(sizeof(char)*FILE_NAME_SIZE);  // Allocate memory for file name
    strcpy(new_fd->file_name, file_name);            // Copy file name to file descriptor
    new_fd->fd_size = file_size;                      // Set size of file descriptor
    new_fd->fd_id = MAX_FILES - fs->free_blocks;     // Set ID of file descriptor (Max files - remaining free blocks)

    fs->file_descriptors[new_fd->fd_id] = new_fd;    // Add new file descriptor to file system
    fs->directory[new_fd->fd_id].file_name = (char*)malloc(sizeof(char)*FILE_NAME_SIZE);  // Allocate memory for file name in directory
    strcpy(fs->directory[new_fd->fd_id].file_name, file_name);  // Copy file name to directory entry
    fs->directory[new_fd->fd_id].start_block = start_block;        // Set start block of directory entry
    fs->directory[new_fd->fd_id].size = file_size;                 // Set size of directory entry

    fs->free_blocks--;                               // Decrement free blocks in file system
    printf("File %s created successfully with start block %d and ID %d\n", file_name, start_block, new_fd->fd_id);

    return new_fd->fd_id;                             // Return file ID
}

// Function to delete a file
void delete_file(file_system* fs, int fd_id){
    if(fs->file_descriptors[fd_id] == NULL){         // Check if file descriptor with ID exists
        printf("ERROR: File descriptor with ID %d does not exist\n", fd_id);
        return;
    }

    int start_block = fs->file_descriptors[fd_id]->start_block;  // Get start block of file
    int fd_size = fs->file_descriptors[fd_id]->fd_size;          // Get size of file descriptor

    for(int i=start_block; i<start_block+(fd_size/BLOCK_SIZE); i++){  // Free all blocks used by file
        fs->file_system_data[i*BLOCK_SIZE] = '\0';
    }

    free(fs->file_descriptors[fd_id]->file_name);          // Free memory allocated to file name in file descriptor
    free(fs->file_descriptors[fd_id]);                     // Free memory allocated to file descriptor
    free(fs->directory[fd_id].file_name);                  // Free memory allocated to file name in directory
    fs->directory[fd_id].file_name = NULL;                 // Set file name in directory to NULL
    fs->directory[fd_id].start_block = -1;              // Set start block in directory to -1 to show file is deleted
    fs->free_blocks += fd_size/BLOCK_SIZE;                  // Add blocks used by file back to free blocks in file system
    printf("File descriptor with ID %d deleted successfully!\n", fd_id);
}

// Function to read from a file
void read_file(file_system* fs, int fd_id, int num_bytes){
    if(fs->file_descriptors[fd_id] == NULL){         // Check if file descriptor with ID exists
        printf("ERROR: File descriptor with ID %d does not exist\n", fd_id);
        return;
    }

    if(fs->file_descriptors[fd_id]->offset + num_bytes > fs->file_descriptors[fd_id]->fd_size){  // Check if reading beyond the file size
        printf("ERROR: Attempting to read beyond file size\n");
        return;
    }

    int start_block = fs->file_descriptors[fd_id]->start_block;         // Get starting block of file
    int offset = fs->file_descriptors[fd_id]->offset;                   // Get current cursor position in file
    char* file_data = (char*)malloc(sizeof(char)*(num_bytes+1));        // Allocate memory to store file data
    int block_to_read = start_block + (offset/BLOCK_SIZE);              // Get block to read from

    int i,j;
    for(i=0; i<num_bytes; i++){
        if(offset == fs->file_descriptors[fd_id]->fd_size){            // If end of file is reached, break out of loop
            break;
        }

        if((offset % BLOCK_SIZE) == 0){                                // If cursor is at the start of a block, load next block
            block_to_read++;
        }

        file_data[i] = fs->file_system_data[block_to_read*BLOCK_SIZE + (offset % BLOCK_SIZE)];  // Read data from file system to file data
        offset++;
    }

    file_data[i] = '\0';                                               // Append null character to end of data

    printf("Data read from file with ID %d:\n%s\n", fd_id, file_data);
    fs->file_descriptors[fd_id]->offset = offset;                      // Update cursor position in file
    free(file_data);                                                    // Free memory allocated to file data
}

// Function to write to a file
void write_file(file_system* fs, int fd_id, char* data){
    if(fs->file_descriptors[fd_id] == NULL){         // Check if file descriptor with ID exists
        printf("ERROR: File descriptor with ID %d does not exist\n", fd_id);
        return;
    }

    int num_bytes = strlen(data);                     // Get number of bytes to write
    int start_block = fs->file_descriptors[fd_id]->start_block;  // Get starting block of file
    int offset = fs->file_descriptors[fd_id]->offset;            // Get current cursor position in file
    int block_to_write = start_block + (offset/BLOCK_SIZE);       // Get block to write to

    for(int i=0; i<num_bytes; i++){
        if((offset % BLOCK_SIZE) == 0){                            // If cursor is at the start of a block, allocate new block
            if(fs->free_blocks <= 0){                              // Check if any free blocks are available
                printf("ERROR: No free blocks available in file system\n");
                break;
            }
            int new_block = find_free_block(fs);                   // Find a free block to write data
            if(new_block == -1){
                printf("ERROR: No free blocks available in file system\n");
                break;
            }
            fs->file_system_data[(block_to_write+1)*BLOCK_SIZE-1] = new_block;
            fs->free_blocks--;
            block_to_write++;
        }

        fs->file_system_data[block_to_write*BLOCK_SIZE + (offset % BLOCK_SIZE)] = data[i];  // Write data to file system
        offset++;
    }

    fs->file_descriptors[fd_id]->offset = offset;       // Update cursor position in file
    fs->file_descriptors[fd_id]->fd_size = offset;       // Update file size in file descriptor
    fs->directory[fd_id].size = offset;                 // Update file size in directory

    printf("Data written to file with ID %d successfully\n", fd_id);
}

// Function to find a free block in file system
int find_free_block(file_system* fs){
    for(int i=0; i<fs->num_blocks; i++){
        if(fs->file_system_data[i*BLOCK_SIZE] == '\0'){
            return i;
        }
    }
    return -1;
}

// Function to print the directory
void print_directory(file_system* fs){
    printf("ID\tName\t\tStart Block\tSize\n");
    for(int i=0; i<MAX_FILES; i++){
        if(fs->directory[i].file_name != NULL){
            printf("%d\t%s\t\t%d\t\t%d bytes\n", i, fs->directory[i].file_name, fs->directory[i].start_block, fs->directory[i].size);
        }
    }
}