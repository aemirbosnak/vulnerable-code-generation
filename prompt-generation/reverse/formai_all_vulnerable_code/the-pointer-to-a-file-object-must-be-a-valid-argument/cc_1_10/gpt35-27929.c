//FormAI DATASET v1.0 Category: File Backup System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of files that can be backed up
#define MAX_FILES 10 

// Define the maximum file name length
#define MAX_NAME_LENGTH 50 

// Define the maximum file size in bytes
#define MAX_FILE_SIZE 10485760 

// Define the backup folder path
#define BACKUP_FOLDER "./backup/"

// Define a struct for our file backup system
typedef struct FileInfo {
    char name[MAX_NAME_LENGTH];
    long size;
    char* data;
} FileInfo;

// Define a function to create a new FileInfo struct
FileInfo* new_file_info(char* name, long size, char* data) {
    FileInfo* info = (FileInfo*)malloc(sizeof(FileInfo));
    if (info) {
        strcpy(info->name, name);
        info->size = size;
        info->data = data;
    }
    return info;
}

// Define a function that backs up a file and returns a FileInfo struct for it
FileInfo* backup_file(char* file_path) {
    // Open the file in read-only mode
    FILE* file = fopen(file_path, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", file_path);
        return NULL;
    }

    // Get the file size
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Check if the file is too large
    if (size > MAX_FILE_SIZE) {
        fprintf(stderr, "File %s is too large to back up\n", file_path);
        fclose(file);
        return NULL;
    }

    // Allocate memory for the file data
    char* data = (char*)malloc(size * sizeof(char));
    if (!data) {
        fprintf(stderr, "Could not allocate memory for file %s\n", file_path);
        fclose(file);
        return NULL;
    }

    // Read the file data into memory
    size_t bytes_read = fread(data, sizeof(char), size, file);
    if (bytes_read != size) {
        fprintf(stderr, "Could not read file %s into memory\n", file_path);
        free(data);
        fclose(file);
        return NULL;
    }

    // Close the file
    fclose(file);

    // Generate a unique file name for the backup
    char backup_file_name[MAX_NAME_LENGTH];
    strcpy(backup_file_name, BACKUP_FOLDER);
    strcat(backup_file_name, strrchr(file_path, '/') + 1);
    char* ext = strrchr(backup_file_name, '.');
    if (ext) *ext = '\0';
    strcat(backup_file_name, "_backup.bin");

    // Create a new FileInfo struct for the backup
    FileInfo* info = new_file_info(backup_file_name, size, data);
    if (!info) {
        fprintf(stderr, "Could not create FileInfo for file %s\n", file_path);
        free(data);
        return NULL;
    }

    return info;
}

// Define a function to save a FileInfo struct to disk
void save_file_info(FileInfo* info) {
    // Open the backup file in write mode
    FILE* file = fopen(info->name, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", info->name);
        return;
    }

    // Write the file data to disk
    size_t bytes_written = fwrite(info->data, sizeof(char), info->size, file);
    if (bytes_written != info->size) {
        fprintf(stderr, "Could not write file data to %s\n", info->name);
    }

    // Close the backup file
    fclose(file);
}

int main() {
    // Define an array of backup file Infos
    FileInfo* backup_files[MAX_FILES];
    int num_files = 0;

    // Loop through each file in the current directory and back them up
    char file_name[MAX_NAME_LENGTH];
    FILE *file_list = popen("ls -1", "r");
    while (fgets(file_name, MAX_NAME_LENGTH, file_list) != NULL) {
        // Check if the file is a binary file
        char* ext = strrchr(file_name, '.');
        if (ext && !strcmp(ext, ".bin")) {
            // Backup the file
            FileInfo* info = backup_file(strtok(file_name, "\n"));
            if (info) {
                // Save the file info to disk
                save_file_info(info);

                // Add the file to the backup_files array
                backup_files[num_files] = info;
                num_files++;

                // Print a message confirming the backup
                printf("Backed up file %s\n", info->name);

                // Check if we've reached the maximum number of files
                if (num_files == MAX_FILES) {
                    printf("Reached maximum number of files to back up\n");
                    break;
                }
            }
        }
    }
    pclose(file_list);

    // Free memory for each FileInfo struct
    for (int i = 0; i < num_files; i++) {
        free(backup_files[i]->data);
        free(backup_files[i]);
    }

    return 0;
}