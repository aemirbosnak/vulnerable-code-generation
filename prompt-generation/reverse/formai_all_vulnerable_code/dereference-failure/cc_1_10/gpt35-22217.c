//FormAI DATASET v1.0 Category: File Synchronizer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUFFER_SIZE 1024

typedef struct {
    char* source_path;
    char* target_path;
} SyncArgs;

void sync_files(char* source_path, char* target_path);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s SOURCE_DIR TARGET_DIR\n", argv[0]);
        return 1;
    }
    
    SyncArgs args = { argv[1], argv[2] };
    sync_files(args.source_path, args.target_path);
    
    printf("All files synced successfully!\n");
    return 0;
}

void sync_files(char* source_path, char* target_path) {
    DIR* source_dir = opendir(source_path);
    DIR* target_dir = opendir(target_path);
    
    if (!source_dir) {
        printf("Error: Failed to open source directory %s\n", source_path);
        return;
    }
    
    if (!target_dir) {
        printf("Error: Failed to open target directory %s\n", target_path);
        return;
    }
    
    struct dirent* entry;
    
    while ((entry = readdir(source_dir)) != NULL) {
        if (entry->d_type & DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            
            char* new_source_path = malloc(strlen(source_path) + 1 + strlen(entry->d_name) + 1);
            sprintf(new_source_path, "%s/%s", source_path, entry->d_name);
            
            char* new_target_path = malloc(strlen(target_path) + 1 + strlen(entry->d_name) + 1);
            sprintf(new_target_path, "%s/%s", target_path, entry->d_name);
            
            sync_files(new_source_path, new_target_path);
        } else {
            char* source_file_path = malloc(strlen(source_path) + 1 + strlen(entry->d_name) + 1);
            sprintf(source_file_path, "%s/%s", source_path, entry->d_name);
            
            char* target_file_path = malloc(strlen(target_path) + 1 + strlen(entry->d_name) + 1);
            sprintf(target_file_path, "%s/%s", target_path, entry->d_name);
            
            struct stat source_stat, target_stat;
            
            if (stat(source_file_path, &source_stat) != 0) {
                printf("Error: Failed to get source file stats: %s\n", source_file_path);
                continue;
            }
            
            if (stat(target_file_path, &target_stat) == 0) {
                if (difftime(source_stat.st_mtime, target_stat.st_mtime) <= 0) {
                    printf("Skipping %s: File already synced\n", source_file_path);
                    continue;
                }
            }
            
            FILE* source_file = fopen(source_file_path, "rb");
            
            if (!source_file) {
                printf("Error: Failed to open source file %s\n", source_file_path);
                continue;
            }
            
            FILE* target_file = fopen(target_file_path, "wb");
            
            if (!target_file) {
                printf("Error: Failed to open target file %s\n", target_file_path);
                fclose(source_file);
                continue;
            }
            
            char buffer[BUFFER_SIZE];
            size_t bytes_read;
            
            while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
                if (fwrite(buffer, 1, bytes_read, target_file) != bytes_read) {
                    printf("Error: Failed to write to target file %s\n", target_file_path);
                    break;
                }
            }
            
            fclose(target_file);
            fclose(source_file);
            printf("Synced %s successfully!\n", source_file_path);
        }
    }
    
    closedir(source_dir);
    closedir(target_dir);
}