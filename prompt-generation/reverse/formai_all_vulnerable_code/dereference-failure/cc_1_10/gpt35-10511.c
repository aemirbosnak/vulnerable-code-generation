//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdbool.h>

#define MAX_PATH_LENGTH 1024
#define MAX_TIME_LENGTH 20

struct file_metadata {
    char path[MAX_PATH_LENGTH];
    char name[MAX_PATH_LENGTH];
    char modified_time[MAX_TIME_LENGTH];
    unsigned long long size;
};

// Helper function to convert file size in bytes to human readable format
void format_size(unsigned long long size, char *buf) {
    char *suffix[] = {"B", "KB", "MB", "GB"};
    int i = 0;
    double fsize = size;
    
    while (fsize >= 1024 && i < 4) {
        fsize /= 1024;
        i++;
    }
    
    sprintf(buf, "%.2f %s", fsize, suffix[i]);
}

// Helper function to get last modified time of a file
void get_modified_time(const char *path, char *buf) {
    struct stat attr;
    stat(path, &attr);
    strftime(buf, MAX_TIME_LENGTH, "%Y-%m-%d %H:%M:%S", localtime(&attr.st_mtime));
}

// Helper function to get metadata of a file
void get_file_metadata(const char *path, struct file_metadata *file) {
    strcpy(file->path, path);
    char *name = strrchr(path, '/') + 1;
    strcpy(file->name, name);
    get_modified_time(path, file->modified_time);
    struct stat attr;
    stat(path, &attr);
    file->size = attr.st_size;
}

// Helper function to copy a file from source to destination
bool copy_file(const char *source_path, const char *dest_path) {
    char buffer[4096];
    size_t n;
    FILE *source_file = fopen(source_path, "rb");
    FILE *dest_file = fopen(dest_path, "wb");
    if (source_file && dest_file) {
        while ((n = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
            if (fwrite(buffer, 1, n, dest_file) != n) {
                fclose(source_file);
                fclose(dest_file);
                return false;
            }
        }
        fclose(source_file);
        fclose(dest_file);
        return true;
    }
    return false;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }
    
    char source_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];
    strcpy(source_path, argv[1]);
    strcpy(dest_path, argv[2]);
    
    DIR *source_dir = opendir(source_path);
    if (!source_dir) {
        printf("Error opening source directory.\n");
        return 2;
    }
    
    DIR *dest_dir = opendir(dest_path);
    if (!dest_dir) {
        printf("Error opening destination directory.\n");
        return 3;
    }
    
    struct dirent *source_file;
    while ((source_file = readdir(source_dir)) != NULL) {
        if (source_file->d_type == DT_REG) {
            char source_file_path[MAX_PATH_LENGTH];
            sprintf(source_file_path, "%s/%s", source_path, source_file->d_name);
            
            struct file_metadata source_file_meta;
            get_file_metadata(source_file_path, &source_file_meta);
            
            bool skip_copy = false;
            
            // Check if file with same name and modified time exists in destination folder
            struct dirent *dest_file;
            rewinddir(dest_dir);
            while ((dest_file = readdir(dest_dir)) != NULL) {
                if (dest_file->d_type == DT_REG) {
                    char dest_file_path[MAX_PATH_LENGTH];
                    sprintf(dest_file_path, "%s/%s", dest_path, dest_file->d_name);
                    
                    struct file_metadata dest_file_meta;
                    get_file_metadata(dest_file_path, &dest_file_meta);
                    
                    if (strcmp(source_file_meta.name, dest_file_meta.name) == 0 
                        && strcmp(source_file_meta.modified_time, dest_file_meta.modified_time) == 0) {
                        // File with same name and modified time found in destination directory
                        if (strcmp(source_file_meta.path, dest_file_meta.path) == 0) {
                            // Files are identical, no need to copy
                            skip_copy = true;
                        } else {
                            // File with same name and modified time exists but contents are different, 
                            // delete old file and copy new file
                            remove(dest_file_meta.path);
                        }
                        break;
                    }
                }
            }
            if (!skip_copy) {
                // File doesn't exist in destination directory or contents are different, copy file
                printf("Copying %s\t%s\t%s\n", source_file_meta.name, source_file_meta.modified_time, "");
                char dest_file_path[MAX_PATH_LENGTH];
                sprintf(dest_file_path, "%s/%s", dest_path, source_file_meta.name);
                if (copy_file(source_file_meta.path, dest_file_path)) {
                    printf("Copied successfully.\n");
                } else {
                    printf("Copy failed.\n");
                }
            }
        }
    }
    
    closedir(source_dir);
    closedir(dest_dir);
    
    return 0;
}