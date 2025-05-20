//GPT-4o-mini DATASET v1.0 Category: Checksum Calculator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Define a mysterious function to calculate checksum
uint32_t calculate_checksum(const char *data) {
    uint32_t checksum = 0;
    size_t length = strlen(data);
    
    for (size_t i = 0; i < length; i++) {
        checksum += (uint32_t)data[i]; // Add ASCII value of each character
        checksum = (checksum << 1) | (checksum >> 31); // Rotate left to mix bits
    }
    return checksum;
}

// A curious structure to hold our mystifying information
typedef struct {
    char *filename;
    char *content;
    uint32_t checksum;
} FileInfo;

// Function to read the content of a file
FileInfo read_file(const char *filename) {
    FileInfo file_info;
    file_info.filename = (char *)malloc(strlen(filename) + 1);
    strcpy(file_info.filename, filename);
    
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(1);
    }
    
    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    
    file_info.content = (char *)malloc(length + 1);
    
    if (fread(file_info.content, 1, length, file) != length) {
        fprintf(stderr, "Could not read file: %s\n", filename);
        exit(1);
    }
    
    file_info.content[length] = '\0'; // Null-terminate the string
    fclose(file);
    
    file_info.checksum = calculate_checksum(file_info.content);
    return file_info;
}

// Helper function to clean up memory
void cleanup_file_info(FileInfo *file_info) {
    free(file_info->filename);
    free(file_info->content);
}

// Function to display the file information and its checksum
void display_file_info(const FileInfo *file_info) {
    printf("===================================\n");
    printf("Magic File: %s\n", file_info->filename);
    printf("Content:\n%s\n", file_info->content);
    printf("Calculated Checksum: 0x%X\n", file_info->checksum);
    printf("===================================\n");
}

int main(int argc, char *argv[]) {
    // Mysterious invocation of our program
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    // Collect the arcane knowledge contained within the file
    FileInfo file_info = read_file(argv[1]);

    // Let the world see our secrets
    display_file_info(&file_info);

    // Celebrate with a cleanup ritual to avoid memory leaks
    cleanup_file_info(&file_info);
    
    return 0;
}