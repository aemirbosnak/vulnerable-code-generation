//FormAI DATASET v1.0 Category: File system simulation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILE_NAME 50
#define MAX_FILE_SIZE 1024

// Define a file struct to hold file information
struct file {
    char filename[MAX_FILE_NAME];
    int size;
    char* content;
};

struct file_system {
    struct file files[MAX_FILES];
    int num_files;
    int max_size;
    int used_size;
};

// Initialize a new file system with zero files and maximum size of 10 MB
struct file_system* initialize_file_system() {
    struct file_system* fs = malloc(sizeof(struct file_system));
    fs->num_files = 0;
    fs->max_size = 10 * 1024 * 1024;  // 10 MB
    fs->used_size = 0;
    return fs;
}

// Create a new file with a given filename and content, and add it to the file system
void create_file(struct file_system* fs, char* filename, char* content) {
    if (fs->num_files == MAX_FILES) {
        printf("File system is full\n");
        return;
    }
    if (fs->used_size + strlen(content) > fs->max_size) {
        printf("File system is out of space\n");
        return;
    }
    struct file* new_file = &fs->files[fs->num_files];
    strcpy(new_file->filename, filename);
    new_file->size = strlen(content);
    new_file->content = malloc(new_file->size);
    strcpy(new_file->content, content);
    fs->num_files++;
    fs->used_size += new_file->size;
}

// Delete an existing file with a given filename from the file system
void delete_file(struct file_system* fs, char* filename) {
    int i;
    for (i = 0; i < fs->num_files; i++) {
        if (strcmp(fs->files[i].filename, filename) == 0) {
            // Free memory allocated for the file content
            free(fs->files[i].content);
            // Overwrite the deleted file with the last file in the array
            fs->files[i] = fs->files[fs->num_files - 1];
            fs->num_files--;
            fs->used_size -= fs->files[i].size;
            printf("Deleted file %s\n", filename);
            return;
        }
    }
    printf("File %s not found\n", filename);
}

// Display the list of all files in the file system
void list_files(struct file_system* fs) {
    int i;
    printf("List of files:\n");
    for (i = 0; i < fs->num_files; i++) {
        printf("%s (%d bytes)\n", fs->files[i].filename, fs->files[i].size);
    }
}

int main() {
    struct file_system* fs = initialize_file_system();
    create_file(fs, "file1.txt", "This is the content of file1");
    create_file(fs, "file2.txt", "This is the content of file2");
    list_files(fs);
    delete_file(fs, "file1.txt");
    list_files(fs);
    delete_file(fs, "file1.txt");
    return 0;
}