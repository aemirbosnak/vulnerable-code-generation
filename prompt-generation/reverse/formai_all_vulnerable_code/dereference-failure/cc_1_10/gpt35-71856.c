//FormAI DATASET v1.0 Category: File Synchronizer ; Style: systematic
/*
* C File Synchronizer
* Author: [Your Name]
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_dir(char* src_dir, char* dest_dir);
void sync_file(char* src_file, char* dest_file);

int main(int argc, char *argv[]) {

    if(argc != 3) {
        printf("Usage: %s src_dir dest_dir\n", argv[0]);
        exit(1);
    }

    char* src_dir = argv[1];
    char* dest_dir = argv[2];

    sync_dir(src_dir, dest_dir);

    printf("Synchronization successful!\n");

    return 0;
}

/* Function to synchronize a directory */
void sync_dir(char* src_dir, char* dest_dir) {

    DIR* src_dir_ptr = opendir(src_dir);  // Open src directory
    if(src_dir_ptr == NULL) {
        printf("Error opening source directory: %s\n", src_dir);
        exit(1);
    }

    DIR* dest_dir_ptr = opendir(dest_dir);  // Open dest directory
    if(dest_dir_ptr == NULL) {
        printf("Error opening destination directory: %s\n", dest_dir);
        exit(1);
    }

    struct dirent* dir_entry;  // Directory entry struct
    char src_file_path[500];  // Full path of source file
    char dest_file_path[500];  // Full path of destination file

    while((dir_entry = readdir(src_dir_ptr)) != NULL) {  // Loop through each entry in src directory

        if(strcmp(dir_entry->d_name, ".") == 0 || strcmp(dir_entry->d_name, "..") == 0) {
            continue; // Ignore . and .. entries
        }

        sprintf(src_file_path, "%s/%s", src_dir, dir_entry->d_name);  // Build full path of source file
        sprintf(dest_file_path, "%s/%s", dest_dir, dir_entry->d_name);  // Build full path of destination file

        struct stat src_stat, dest_stat;
        if(stat(src_file_path, &src_stat) == -1) {
            printf("Error getting file status: %s\n", src_file_path);
            continue;
        }
        if(stat(dest_file_path, &dest_stat) == -1) {
            if(S_ISDIR(src_stat.st_mode)) {  // Create destination directory if source is a directory
                mkdir(dest_file_path, 0755);
            } else {  // Copy source file to destination if source is a file
                sync_file(src_file_path, dest_file_path);
            }
            continue;
        }

        if(S_ISDIR(src_stat.st_mode)) {
            if(!S_ISDIR(dest_stat.st_mode)) { // Create destination directory if it doesn't exist
                mkdir(dest_file_path, 0755);
            }
            sync_dir(src_file_path, dest_file_path);  // Recursive call to sync subdirectories
        } else {
            sync_file(src_file_path, dest_file_path);  // Sync file
        }
    }

    closedir(src_dir_ptr);  // Close src directory
    closedir(dest_dir_ptr);  // Close dest directory
}

/* Function to synchronize a file */
void sync_file(char* src_file, char* dest_file) {

    FILE* src_file_ptr = fopen(src_file, "rb");  // Open source file
    if(src_file_ptr == NULL) {
        printf("Error opening source file: %s\n", src_file);
        return;
    }

    FILE* dest_file_ptr = fopen(dest_file, "rb");  // Open destination file
    if(dest_file_ptr != NULL) {  // File exists, check if it needs to be updated
        fseek(src_file_ptr, 0, SEEK_END);
        int src_size = ftell(src_file_ptr);  // Get size of source file
        fseek(dest_file_ptr, 0, SEEK_END);
        int dest_size = ftell(dest_file_ptr);  // Get size of destination file

        if(src_size == dest_size) {  // Files are same size, check if they have same content
            fseek(src_file_ptr, 0, SEEK_SET);
            fseek(dest_file_ptr, 0, SEEK_SET);

            char src_data[1024], dest_data[1024]; // Buffers to hold file contents
            int src_read, dest_read;

            do {
                src_read = fread(src_data, 1, 1024, src_file_ptr);
                dest_read = fread(dest_data, 1, 1024, dest_file_ptr);
                if(memcmp(src_data, dest_data, src_read) != 0) { // Content is different
                    fclose(src_file_ptr);
                    fclose(dest_file_ptr);
                    printf("Syncing file: %s\n", src_file);
                    if(remove(dest_file) == -1) { // Delete destination file
                        printf("Error deleting destination file: %s\n", dest_file);
                        return;
                    }
                    sync_file(src_file, dest_file); // Recursive call to sync file
                    return;
                }
            } while(src_read == dest_read && src_read != 0);

            fclose(src_file_ptr);
            fclose(dest_file_ptr);
            return; // Content is same, no need to sync
        }
        fclose(dest_file_ptr);
    }

    printf("Syncing file: %s\n", src_file);  // Sync source file to destination file
    dest_file_ptr = fopen(dest_file, "wb");
    if(dest_file_ptr == NULL) {
        printf("Error opening destination file: %s\n", dest_file);
        fclose(src_file_ptr);
        return;
    }

    fseek(src_file_ptr, 0, SEEK_SET);
    char data[1024];
    int read;

    do {  // Copy data from source to destination file
        read = fread(data, 1, 1024, src_file_ptr);
        fwrite(data, 1, read, dest_file_ptr);
    } while(read == 1024);
    
    fclose(src_file_ptr);
    fclose(dest_file_ptr);
}