//FormAI DATASET v1.0 Category: File Synchronizer ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

void sync_directories(char *source_folder, char *destination_folder, char *log_file) {
    FILE *log = fopen(log_file, "a");
    
    // Check if source folder exists
    struct stat st = {0};
    if (stat(source_folder, &st) == -1) {
        fprintf(log, "Error: Source folder does not exist\n");
        fclose(log);
        return;
    }
    
    // Check if destination folder exists, if not create it
    if (stat(destination_folder, &st) == -1) {
        mkdir(destination_folder, 0700);
    }
    
    // Get list of files in source folder
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(source_folder)) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_type == DT_REG) {
                // Build file paths
                char source_file[500];
                strcpy(source_file, source_folder);
                strcat(source_file, "/");
                strcat(source_file, ent->d_name);
                
                char dest_file[500];
                strcpy(dest_file, destination_folder);
                strcat(dest_file, "/");
                strcat(dest_file, ent->d_name);
                
                // Check if file exists in destination folder
                if (stat(dest_file, &st) == -1) {
                    // File does not exist in destination folder, copy file
                    FILE *source = fopen(source_file, "rb");
                    FILE *dest = fopen(dest_file, "wb");
                    char buffer[1024];
                    size_t size;
                    while ((size = fread(buffer, 1, sizeof(buffer), source)) > 0) {
                        fwrite(buffer, 1, size, dest);
                    }
                    fclose(source);
                    fclose(dest);
                    fprintf(log, "Copied file %s\n", ent->d_name);
                }
                else {
                    // File exists in destination folder, check modification time
                    struct stat source_st;
                    struct stat dest_st;
                    stat(source_file, &source_st);
                    stat(dest_file, &dest_st);
                    if (source_st.st_mtime > dest_st.st_mtime) {
                        // Source file is newer than the destination file, copy file
                        FILE *source = fopen(source_file, "rb");
                        FILE *dest = fopen(dest_file, "wb");
                        char buffer[1024];
                        size_t size;
                        while ((size = fread(buffer, 1, sizeof(buffer), source)) > 0) {
                            fwrite(buffer, 1, size, dest);
                        }
                        fclose(source);
                        fclose(dest);
                        fprintf(log, "Updated file %s\n", ent->d_name);
                    }
                }
            }
        }
        closedir(dir);
    }
    else {
        fprintf(log, "Error: Could not open source folder\n");
    }
    fclose(log);
}

int main() {
    char source_folder[500] = "/home/user/Documents/source";
    char destination_folder[500] = "/home/user/Documents/destination";
    char log_file[500] = "/home/user/Documents/file_sync.log";
    
    sync_directories(source_folder, destination_folder, log_file);
    
    return 0;
}