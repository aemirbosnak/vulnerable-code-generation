//FormAI DATASET v1.0 Category: File Synchronizer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define BUF_SIZE 1024

void sync_files(char *source_dir, char *destination_dir)
{
    DIR *src_dir_ptr, *dest_dir_ptr;
    struct dirent *src_entry_ptr, *dest_entry_ptr;
    struct stat src_stat_buffer, dest_stat_buffer;
    char src_file_path[BUF_SIZE] = {'\0'};
    char dest_file_path[BUF_SIZE] = {'\0'};
    FILE *src_file_ptr, *dest_file_ptr;
    char buffer[BUF_SIZE];
    size_t n_read, n_written;

    src_dir_ptr = opendir(source_dir);
    if (!src_dir_ptr) {
        printf("Failed to open source directory: %s\n", source_dir);
        return;
    }

    dest_dir_ptr = opendir(destination_dir);
    if (!dest_dir_ptr) {
        printf("Failed to open destination directory: %s\n", destination_dir);
        closedir(src_dir_ptr);
        return;
    }

    while ((src_entry_ptr = readdir(src_dir_ptr))) {
        if (strcmp(src_entry_ptr->d_name, ".") == 0 || strcmp(src_entry_ptr->d_name, "..") == 0) {
            continue; // skip "." and ".." directories
        }
        
        snprintf(src_file_path, sizeof(src_file_path), "%s/%s", source_dir, src_entry_ptr->d_name);
        if (stat(src_file_path, &src_stat_buffer)) {
            printf("Failed to stat source file: %s\n", src_file_path);
            continue;
        }
        
        snprintf(dest_file_path, sizeof(dest_file_path), "%s/%s", destination_dir, src_entry_ptr->d_name);
        if (stat(dest_file_path, &dest_stat_buffer)) {
            printf("Failed to stat destination file: %s\n", dest_file_path);
            continue;
        }
        
        if (difftime(src_stat_buffer.st_mtime, dest_stat_buffer.st_mtime) > 0) {
            // source file has been modified more recently than destination file
            printf("Copying %s to %s\n", src_file_path, dest_file_path);
            
            src_file_ptr = fopen(src_file_path, "rb");
            if (!src_file_ptr) {
                printf("Failed to open source file for reading: %s\n", src_file_path);
                continue;
            }
            
            dest_file_ptr = fopen(dest_file_path, "wb");
            if (!dest_file_ptr) {
                printf("Failed to open destination file for writing: %s\n", dest_file_path);
                fclose(src_file_ptr);
                continue;
            }
            
            while ((n_read = fread(buffer, 1, sizeof(buffer), src_file_ptr))) {
                n_written = fwrite(buffer, 1, n_read, dest_file_ptr);
                if (n_written != n_read) {
                    printf("Failed to write to destination file: %s\n", dest_file_path);
                    fclose(src_file_ptr);
                    fclose(dest_file_ptr);
                    continue;
                }
            }
            fclose(src_file_ptr);
            fclose(dest_file_ptr);
        }
    }
    closedir(src_dir_ptr);
    closedir(dest_dir_ptr);
}

int main(int argc, char **argv)
{
    if (argc < 3) {
        printf("Usage: %s source_directory destination_directory\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    sync_files(argv[1], argv[2]);
    return EXIT_SUCCESS;
}