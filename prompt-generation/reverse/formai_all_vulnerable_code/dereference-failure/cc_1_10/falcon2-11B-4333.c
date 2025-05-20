//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LENGTH 100

typedef struct {
    char filename[MAX_FILE_NAME_LENGTH];
    int size;
    char* data;
} file_info;

file_info read_file(const char* filename) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(1);
    }
    
    fseek(fp, 0, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    char* buffer = (char*)malloc(file_size);
    if (buffer == NULL) {
        fprintf(stderr, "Error allocating memory\n");
        exit(1);
    }
    
    if (fread(buffer, 1, file_size, fp)!= file_size) {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }
    
    fclose(fp);
    
    file_info info;
    strcpy(info.filename, filename);
    info.size = file_size;
    info.data = buffer;
    
    return info;
}

bool write_file(const char* filename, const char* data) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return false;
    }
    
    fwrite(data, 1, strlen(data), fp);
    fclose(fp);
    
    return true;
}

int main() {
    file_info info = read_file("example.txt");
    printf("File name: %s\n", info.filename);
    printf("File size: %d bytes\n", info.size);
    printf("Data: %s\n", info.data);
    
    char* new_data = "Hello, World!";
    bool success = write_file("example.txt", new_data);
    if (success) {
        printf("Successfully wrote new data to file\n");
    } else {
        printf("Error writing new data to file\n");
    }
    
    return 0;
}