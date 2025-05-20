//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void copy_file(char *source_path, char *dest_path) {
    FILE *src_file = fopen(source_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    
    if (!src_file) {
        printf("Failed to open source file %s\n", source_path);
        exit(1);
    }
    
    if (!dest_file) {
        printf("Failed to create destination file %s\n", dest_path);
        exit(1);
    }
    
    char buffer[1024];
    size_t num_bytes;
    
    while ((num_bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, num_bytes, dest_file);
    }
    
    fclose(src_file);
    fclose(dest_file);
}

void sync_files(char *source_dir, char *dest_dir) {
    DIR *src_dir = opendir(source_dir);
    
    if (!src_dir) {
        printf("Failed to open directory %s\n", source_dir);
        exit(1);
    }
    
    DIR *dest_dir_ptr = opendir(dest_dir);
    
    if (!dest_dir_ptr) {
        printf("Destination directory %s does not exist, creating a new one...\n", dest_dir);
        int status = mkdir(dest_dir, 0777);
        if (status != 0) {
            printf("Failed to create directory %s\n", dest_dir);
            exit(1);
        }
        dest_dir_ptr = opendir(dest_dir);
    }
    
    char source_path[1024];
    char dest_path[1024];
    
    struct dirent *entry;
    struct stat stat_buf;
    
    while ((entry = readdir(src_dir)) != NULL) {
        sprintf(source_path, "%s/%s", source_dir, entry->d_name);
        sprintf(dest_path, "%s/%s", dest_dir, entry->d_name);
        
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        lstat(source_path, &stat_buf);
        if (S_ISDIR(stat_buf.st_mode)) {
            sync_files(source_path, dest_path);
        } else {
            struct stat dest_stat_buf;
            if (stat(dest_path, &dest_stat_buf) == 0) {
                if (stat_buf.st_mtime > dest_stat_buf.st_mtime) {
                    printf("Copying %s to %s\n", source_path, dest_path);
                    copy_file(source_path, dest_path);
                }
            } else {
                printf("Copying %s to %s\n", source_path, dest_path);
                copy_file(source_path, dest_path);
            }
        }
    }
    
    closedir(src_dir);
    closedir(dest_dir_ptr);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }
    
    sync_files(argv[1], argv[2]);
    
    printf("Synchronization completed successfully!\n");
    
    return 0;
}