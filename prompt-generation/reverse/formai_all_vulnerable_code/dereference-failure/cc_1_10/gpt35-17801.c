//FormAI DATASET v1.0 Category: File Synchronizer ; Style: unmistakable
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void copy_file(const char *src_file, const char *dest_file) {
    FILE *src, *dest;
    char ch;
    
    src = fopen(src_file, "r");
    dest = fopen(dest_file, "w");
    
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dest);
    }
    
    printf("Copied %s to %s\n", src_file, dest_file);
    
    fclose(src);
    fclose(dest);
}


void sync_dir(const char *dir1_path, const char *dir2_path) {
    DIR *dir1, *dir2;
    struct dirent *dir1_entry, *dir2_entry;
    struct stat dir1_stat, dir2_stat;
    char dir1_buf[1024], dir2_buf[1024], new_dir1_path[1024], new_dir2_path[1024];
    int exists_in_dir2 = 0, sizeof_entry = 0;
    
    dir1 = opendir(dir1_path);
    if (!dir1) {
        printf("Could not open directory %s\n", dir1_path);
        return;
    }
    
    dir2 = opendir(dir2_path);
    if (!dir2) {
        printf("Could not open directory %s\n", dir2_path);
        return;
    }
    
    while ((dir1_entry = readdir(dir1)) != NULL) {
        if (dir1_entry->d_type == DT_DIR) {
            // if entry is a directory and not . or ..
            if (strcmp(dir1_entry->d_name, ".") != 0 && strcmp(dir1_entry->d_name, "..") != 0) {
                sprintf(new_dir1_path, "%s/%s", dir1_path, dir1_entry->d_name);
                sprintf(new_dir2_path, "%s/%s", dir2_path, dir1_entry->d_name);
                
                // recursively sync directories
                sync_dir(new_dir1_path, new_dir2_path);
            }
        } else if (dir1_entry->d_type == DT_REG) {
            // if entry is a regular file
            sprintf(dir1_buf, "%s/%s", dir1_path, dir1_entry->d_name);
            stat(dir1_buf, &dir1_stat);
            
            // check if file exists in dir2
            rewinddir(dir2);
            exists_in_dir2 = 0;
            while ((dir2_entry = readdir(dir2)) != NULL) {
                if (dir2_entry->d_type == DT_REG) {
                    sprintf(dir2_buf, "%s/%s", dir2_path, dir2_entry->d_name);
                    stat(dir2_buf, &dir2_stat);
                    
                    // if file with the same name exists in dir2, check its modification time
                    if (strcmp(dir1_entry->d_name, dir2_entry->d_name) == 0) {
                        if (difftime(dir1_stat.st_mtime, dir2_stat.st_mtime) > 0) {
                            copy_file(dir1_buf, dir2_buf);
                        }
                        exists_in_dir2 = 1;
                        break;
                    }
                }
            }
            
            // if file does not exist in dir2, create it
            if (!exists_in_dir2) {
                copy_file(dir1_buf, dir2_buf);
            }
        }
    }
    
    closedir(dir1);
    closedir(dir2);
}


int main() {
    sync_dir("./dir1", "./dir2");
    
    return 0;
}