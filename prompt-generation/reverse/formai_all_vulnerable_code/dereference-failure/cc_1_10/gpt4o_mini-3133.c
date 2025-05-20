//GPT-4o-mini DATASET v1.0 Category: File system simulation ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILES 100
#define MAX_FILENAME_LENGTH 50

typedef struct {
    char name[MAX_FILENAME_LENGTH];
    unsigned int size; // in bytes
    int is_open;
} File;

typedef struct {
    File* files[MAX_FILES];
    int file_count;
} FileSystem;

// Function to initialize the file system
FileSystem* initialize_file_system() {
    FileSystem* fs = (FileSystem*)malloc(sizeof(FileSystem));
    fs->file_count = 0;
    for (int i = 0; i < MAX_FILES; i++) {
        fs->files[i] = NULL;
    }
    printf("🎉 File System Initialized! Ready to rock and roll! 🎉\n");
    return fs;
}

// Function to create a new file
int create_file(FileSystem* fs, const char* name, unsigned int size) {
    if (fs->file_count >= MAX_FILES) {
        printf("🚫 Error: Maximum file limit reached. Can't create file \"%s\".\n", name);
        return -1;
    }
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            printf("🚫 Error: File \"%s\" already exists!\n", name);
            return -1;
        }
    }
    File* new_file = (File*)malloc(sizeof(File));
    strncpy(new_file->name, name, MAX_FILENAME_LENGTH);
    new_file->size = size;
    new_file->is_open = 0;
    fs->files[fs->file_count++] = new_file;
    printf("📄 File \"%s\" created successfully with size %u bytes!\n", name, size);
    return 0;
}

// Function to delete a file
int delete_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            free(fs->files[i]);
            fs->files[i] = fs->files[fs->file_count - 1]; // Replace with the last file
            fs->file_count--;
            printf("🗑️ File \"%s\" deleted successfully!\n", name);
            return 0;
        }
    }
    printf("🚫 Error: File \"%s\" not found!\n", name);
    return -1;
}

// Function to open a file
int open_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            if (fs->files[i]->is_open) {
                printf("🚫 Error: File \"%s\" is already open!\n", name);
                return -1;
            }
            fs->files[i]->is_open = 1;
            printf("🔓 File \"%s\" opened successfully!\n", name);
            return 0;
        }
    }
    printf("🚫 Error: File \"%s\" not found!\n", name);
    return -1;
}

// Function to close a file
int close_file(FileSystem* fs, const char* name) {
    for (int i = 0; i < fs->file_count; i++) {
        if (strcmp(fs->files[i]->name, name) == 0) {
            if (!fs->files[i]->is_open) {
                printf("🚫 Error: File \"%s\" is not open!\n", name);
                return -1;
            }
            fs->files[i]->is_open = 0;
            printf("🔒 File \"%s\" closed successfully!\n", name);
            return 0;
        }
    }
    printf("🚫 Error: File \"%s\" not found!\n", name);
    return -1;
}

// Function to show all files in the file system
void list_files(FileSystem* fs) {
    if (fs->file_count == 0) {
        printf("📂 No files in the system yet! Create some files! 🚀\n");
        return;
    }
    printf("📁 Listing all files:\n");
    for (int i = 0; i < fs->file_count; i++) {
        printf(" - File: %s | Size: %u bytes | Status: %s\n", 
               fs->files[i]->name, 
               fs->files[i]->size, 
               fs->files[i]->is_open ? "Open" : "Closed");
    }
}

int main() {
    FileSystem* fs = initialize_file_system();
    create_file(fs, "document.txt", 1024);
    create_file(fs, "photo.jpg", 2048);
    create_file(fs, "music.mp3", 3072);
    
    list_files(fs);
    
    open_file(fs, "document.txt");
    open_file(fs, "photo.jpg");
    
    close_file(fs, "photo.jpg");
    delete_file(fs, "music.mp3");
    
    list_files(fs);
    
    // Clean up remaining files
    for (int i = 0; i < fs->file_count; i++) {
        free(fs->files[i]);
    }
    free(fs);
    
    printf("✅ File System Shut Down. Have a great day! 👋\n");
    return 0;
}