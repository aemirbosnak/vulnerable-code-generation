//FormAI DATASET v1.0 Category: File Synchronizer ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to recursively synchronize files from source path to destination path
void sync_files(char *source, char *dest) {
    struct dirent *dir;
    DIR *dirp = opendir(source);
    char src_file[1000], dst_file[1000];
    
    // Traverse through all the files in source directory
    while ((dir = readdir(dirp)) != NULL) {
        // Ignore ".", ".." and hidden files
        if (dir->d_name[0] == '.') continue;
        
        // Construct source file path
        sprintf(src_file, "%s/%s", source, dir->d_name);
        
        // Construct destination file path
        sprintf(dst_file, "%s/%s", dest, dir->d_name);
        
        struct stat st;
        stat(src_file, &st);
        
        // If the file is a directory, create it in the destination if it doesn't exist
        if (S_ISDIR(st.st_mode)) {
            DIR *subdir = opendir(dst_file);
            if (subdir == NULL) {
                mkdir(dst_file, 0777);
            } else {
                closedir(subdir);
            }
            // Recursively synchronize files in the directory
            sync_files(src_file, dst_file);
        } else {
            // If the file is not a directory, copy it to the destination if it is newer
            struct stat dst_st;
            int exists = stat(dst_file, &dst_st);
            if (exists == -1 || st.st_mtime > dst_st.st_mtime) {
                FILE *src_fptr = fopen(src_file, "r");
                FILE *dst_fptr = fopen(dst_file, "w");
                
                char buffer[1000];
                size_t length;
                while ((length = fread(buffer, 1, sizeof(buffer), src_fptr)) > 0) {
                    fwrite(buffer, 1, length, dst_fptr);
                }
                
                fclose(src_fptr);
                fclose(dst_fptr);
            }
        }
    }
    closedir(dirp);
}


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        return 0;
    }
    
    sync_files(argv[1], argv[2]);
    
    printf("Files synchronized successfully.\n");
    
    return 0;
}