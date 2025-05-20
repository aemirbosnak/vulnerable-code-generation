//FormAI DATASET v1.0 Category: File Synchronizer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFSIZE 4096

void synchronize(char *src, char *dst) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char src_path[BUFSIZE], dst_path[BUFSIZE];
    
    // open source directory
    if ((dir = opendir(src)) == NULL) {
        fprintf(stderr, "Error: Cannot open directory '%s'\n", src);
        exit(EXIT_FAILURE);
    }
    
    // check if destination directory exists, if not create it
    if (access(dst, F_OK) != 0) {
        mkdir(dst, 0777);
    }
    
    // iterate over all entries in source directory
    while ((entry = readdir(dir)) != NULL) {
        // ignore . and ..
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        
        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, entry->d_name);
        
        if (lstat(src_path, &statbuf) == -1) {
            fprintf(stderr, "Error: Cannot stat file '%s'\n", src_path);
            continue;
        }
        
        if (S_ISDIR(statbuf.st_mode)) {
            // recursively synchronize directories
            synchronize(src_path, dst_path);
        } else {
            // synchronize files
            FILE *src_file, *dst_file;
            char buf[BUFSIZE];
            size_t size;
            
            if ((src_file = fopen(src_path, "rb")) == NULL) {
                fprintf(stderr, "Error: Cannot open file '%s'\n", src_path);
                continue;
            }
            
            if ((dst_file = fopen(dst_path, "wb")) == NULL) {
                fprintf(stderr, "Error: Cannot create file '%s'\n", dst_path);
                fclose(src_file);
                continue;
            }
            
            while ((size = fread(buf, 1, sizeof(buf), src_file)) > 0) {
                if (fwrite(buf, 1, size, dst_file) != size) {
                    fprintf(stderr, "Error: Cannot write file '%s'\n", dst_path);
                    break;
                }
            }
            
            fclose(src_file);
            fclose(dst_file);
        }
    }
    
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source directory> <destination directory>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // synchronize directories
    synchronize(argv[1], argv[2]);
    
    return EXIT_SUCCESS;
}