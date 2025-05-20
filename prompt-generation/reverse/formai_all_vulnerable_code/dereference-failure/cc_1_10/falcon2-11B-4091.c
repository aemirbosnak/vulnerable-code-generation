//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct to store file information
typedef struct {
    char file_name[100];
    int file_size;
} FileInfo;

// Function to read file information from disk
FileInfo* read_file_info(const char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    
    // Read file size
    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    rewind(file);
    
    // Allocate memory for file info
    FileInfo* info = (FileInfo*)malloc(sizeof(FileInfo));
    if (info == NULL) {
        printf("Error: Memory allocation failed\n");
        exit(1);
    }
    
    // Read file name
    fread(info->file_name, sizeof(char), 100, file);
    fclose(file);
    
    return info;
}

// Function to write file information to disk
void write_file_info(const FileInfo* info, const char* file_name) {
    FILE* file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error: File not found\n");
        exit(1);
    }
    
    // Write file size
    fwrite(&info->file_size, sizeof(int), 1, file);
    
    // Write file name
    fwrite(info->file_name, sizeof(char), 100, file);
    
    fclose(file);
}

int main() {
    const char* file_name = "data.txt";
    
    // Read file information
    FileInfo* info = read_file_info(file_name);
    if (info == NULL) {
        return 1;
    }
    
    // Print file information
    printf("File Name: %s\n", info->file_name);
    printf("File Size: %d\n", info->file_size);
    
    // Write file information back to disk
    write_file_info(info, file_name);
    
    free(info);
    
    return 0;
}