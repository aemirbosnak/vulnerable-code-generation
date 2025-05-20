//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function prototypes
int isDirectory(const char *path);
long long int get_dir_size(const char *path);

int main(int argc, char *argv[]) {
    long long int total_size = 0;   // total size of the directory
    DIR *dir;   // directory pointer
    struct dirent *dir_entry;   // directory entry
    struct stat file_stat;   // file stats

    // check if correct number of arguments are provided
    if (argc != 2) {
        printf("Invalid arguments. Usage: ./disk_analyzer <directory_path>\n");
        exit(1);
    }

    // open the directory
    if ((dir = opendir(argv[1])) == NULL) {
        printf("Unable to open directory: %s\n", argv[1]);
        exit(1);
    }

    // iterate over the directory entries
    while ((dir_entry = readdir(dir)) != NULL) {
        char path[1024];
        sprintf(path, "%s/%s", argv[1], dir_entry->d_name);

        // check if the path is a directory and not '.' or '..' 
        if (isDirectory(path) && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            long long int dir_size = get_dir_size(path);     // get directory size
            total_size += dir_size;     // add directory size to total size
            printf("%-30s %10lld bytes\n", path, dir_size);     // print directory path and size
        }
        else if (!isDirectory(path)) {
            // get file stats
            if (stat(path, &file_stat) != -1) {
                total_size += file_stat.st_size;    // add file size to total size
                printf("%-30s %10lld bytes\n", path, file_stat.st_size);    // print file path and size
            }
        }
    }

    // print total size
    printf("\nTotal size of directory %s: %lld bytes\n", argv[1], total_size);

    // close the directory
    closedir(dir);

    return 0;
}

// function to check if the given path is a directory
int isDirectory(const char *path) {
    struct stat file_stat;
    if (stat(path, &file_stat) == -1) {
        return 0;
    }
    return S_ISDIR(file_stat.st_mode);
}

// function to get the size of the given directory
long long int get_dir_size(const char *path) {
    long long int total_size = 0;
    DIR *dir;
    struct dirent *dir_entry;
    struct stat file_stat;

    // open the directory
    if ((dir = opendir(path)) == NULL) {
        return 0;
    }

    // iterate over the directory entries
    while ((dir_entry = readdir(dir)) != NULL) {
        char entry_path[1024];
        sprintf(entry_path, "%s/%s", path, dir_entry->d_name);

        // check if the path is a directory and not '.' or '..' 
        if (isDirectory(entry_path) && strcmp(dir_entry->d_name, ".") != 0 && strcmp(dir_entry->d_name, "..") != 0) {
            long long int dir_size = get_dir_size(entry_path);   // get directory size
            total_size += dir_size;     // add directory size to total size
        }
        else if(!isDirectory(entry_path)){  // check if the path is a file
            // get file stats
            if(stat(entry_path, &file_stat) != -1) {
                total_size += file_stat.st_size;    // add file size to total size
            }
        }
    }

    // close the directory
    closedir(dir);

    return total_size;
}