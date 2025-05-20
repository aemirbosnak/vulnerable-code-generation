//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define BLOCKSIZE 512

// function prototypes
int checkFileType(char *filename);
long getDirectorySize(char *path);

int main(int argc, char *argv[]) {
    
    // check for correct number of arguments
    if(argc != 2) {
        printf("Incorrect number of arguments.\n");
        printf("Usage: disk_space_analyzer [path]\n");
        exit(1);
    }
    
    // declare variables
    char *path = argv[1];
    long total_size = 0;
    
    // check if path is a directory
    struct stat path_stat;
    if(stat(path, &path_stat) != 0) {
        printf("Error: Cannot access %s\n", path);
        exit(1);
    }
    if(!S_ISDIR(path_stat.st_mode)) {
        printf("Error: %s is not a directory\n", path);
        exit(1);
    }
    
    // get directory size
    total_size = getDirectorySize(path);
    
    // convert total size to human-readable format
    char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int unit = 0;
    while(total_size >= 1024 && unit < 4) {
        total_size /= 1024;
        unit++;
    }
    char size_string[10];
    sprintf(size_string, "%ld %s", total_size, units[unit]);
    
    // print results
    printf("%s\n", size_string);
    
    return 0;
}

// function to determine if file is valid for size calculation
// returns 0 for valid, 1 for invalid
int checkFileType(char *filename) {
    char *invalid_extensions[] = {"exe", "dll", "sys", "lnk", "ini"};
    int num_extensions = sizeof(invalid_extensions)/sizeof(invalid_extensions[0]);
    for(int i=0; i<num_extensions; i++) {
        if(strstr(filename, invalid_extensions[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// function to recursively get size of directory
long getDirectorySize(char *path) {
    long total_size = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if(dir == NULL) {
        return total_size;
    }
    while((entry = readdir(dir)) != NULL) {
        char filepath[1024];
        sprintf(filepath, "%s/%s", path, entry->d_name);
        struct stat file_stat;
        if(lstat(filepath, &file_stat) == 0) {
            if(S_ISDIR(file_stat.st_mode)) { // recurse for directories
                if(strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    total_size += getDirectorySize(filepath);
                }
            }
            else { // add size of files to total
                if(checkFileType(entry->d_name) == 0) {
                    total_size += file_stat.st_size/BLOCKSIZE*BLOCKSIZE + BLOCKSIZE; // round up to nearest block
                }
            }
        }
    }
    closedir(dir);
    return total_size;    
}