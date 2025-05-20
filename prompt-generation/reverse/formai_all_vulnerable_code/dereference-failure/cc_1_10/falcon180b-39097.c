//Falcon-180B DATASET v1.0 Category: File handling ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000

// Struct to hold file information
typedef struct {
    FILE* file;
    char filename[MAX_LINE_LENGTH];
} FileInfo;

// Function prototypes
int open_file(char* filename, FileInfo* file_info);
int close_file(FileInfo* file_info);
int read_file(FileInfo* file_info, char* buffer, int buffer_size);
int write_file(FileInfo* file_info, char* buffer, int buffer_size);

// Main function
int main() {
    char filename[MAX_LINE_LENGTH];
    printf("Enter filename: ");
    scanf("%s", filename);

    // Open file
    FileInfo file_info;
    if (!open_file(filename, &file_info)) {
        printf("Failed to open file.\n");
        return 1;
    }

    // Read file contents
    char buffer[MAX_LINE_LENGTH];
    int buffer_size = 0;
    while (read_file(&file_info, buffer + buffer_size, MAX_LINE_LENGTH - buffer_size) > 0) {
        buffer_size += strlen(buffer);
    }
    buffer[buffer_size] = '\0';
    printf("File contents:\n%s", buffer);

    // Write to file
    char new_buffer[MAX_LINE_LENGTH];
    printf("Enter new file contents: ");
    scanf("%s", new_buffer);
    if (!write_file(&file_info, new_buffer, strlen(new_buffer))) {
        printf("Failed to write to file.\n");
        return 1;
    }

    // Close file
    if (!close_file(&file_info)) {
        printf("Failed to close file.\n");
        return 1;
    }

    return 0;
}

// Open file
int open_file(char* filename, FileInfo* file_info) {
    file_info->file = fopen(filename, "r+");
    if (file_info->file == NULL) {
        return 0;
    }
    strcpy(file_info->filename, filename);

    return 1;
}

// Close file
int close_file(FileInfo* file_info) {
    fclose(file_info->file);
    file_info->file = NULL;

    return 1;
}

// Read file
int read_file(FileInfo* file_info, char* buffer, int buffer_size) {
    return fread(buffer, 1, buffer_size, file_info->file);
}

// Write file
int write_file(FileInfo* file_info, char* buffer, int buffer_size) {
    return fwrite(buffer, 1, buffer_size, file_info->file);
}