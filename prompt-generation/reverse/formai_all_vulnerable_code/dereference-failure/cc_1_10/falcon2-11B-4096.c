//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: ultraprecise
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>

void sync_dir(const char* src, const char* dest) {
    DIR *src_dir = opendir(src);
    if (src_dir == NULL) {
        perror("opendir");
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(src_dir))!= NULL) {
        if (entry->d_type == DT_DIR) {
            sync_dir(entry->d_name, dest);
        } else {
            char filepath[256];
            sprintf(filepath, "%s/%s", src, entry->d_name);
            char dest_filepath[256];
            sprintf(dest_filepath, "%s/%s", dest, entry->d_name);
            
            int src_file_size = lstat(filepath, NULL);
            int dest_file_size = lstat(dest_filepath, NULL);
            
            if (src_file_size!= dest_file_size) {
                FILE *src_file = fopen(filepath, "rb");
                FILE *dest_file = fopen(dest_filepath, "wb");
                
                fseek(src_file, 0, SEEK_END);
                long src_file_size_orig = ftell(src_file);
                rewind(src_file);
                
                fseek(dest_file, 0, SEEK_END);
                long dest_file_size_orig = ftell(dest_file);
                rewind(dest_file);
                
                long size_diff = src_file_size_orig - dest_file_size_orig;
                
                if (size_diff > 0) {
                    size_t bytes_read = fread(dest_file, 1, size_diff, src_file);
                    fclose(src_file);
                    fclose(dest_file);
                } else {
                    size_t bytes_read = fread(src_file, 1, size_diff, dest_file);
                    fclose(src_file);
                    fclose(dest_file);
                }
                
                unlink(dest_filepath);
                rename(filepath, dest_filepath);
            }
        }
    }
    
    closedir(src_dir);
}

int main() {
    const char* src_dir = "source_directory";
    const char* dest_dir = "destination_directory";
    
    sync_dir(src_dir, dest_dir);
    
    return 0;
}