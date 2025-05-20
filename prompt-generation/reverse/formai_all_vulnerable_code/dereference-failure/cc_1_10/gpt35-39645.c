//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/stat.h>
#include<string.h>

// Define global variables for keeping track of total disk space and individual file/folder sizes
unsigned long long disk_space = 0;
unsigned long long folder_space = 0;
unsigned long long file_space = 0;

// Function to recursively iterate over directories and files
void analyze(char *dir_path) {
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        perror("Unable to open directory");
        exit(EXIT_FAILURE);
    }
    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
        if (lstat(path, &statbuf) == -1) {
            perror("Unable to get file status");
        }
        // Check if the entry is a directory
        if (S_ISDIR(statbuf.st_mode)) {
            if (strcmp(".", entry->d_name) == 0 || strcmp("..", entry->d_name) == 0) {
                continue;
            }
            analyze(path); // Recurse over the subdirectory
            folder_space += statbuf.st_size;
        }
        // Entry is a file
        else {
            file_space += statbuf.st_size;
        }
    }
    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    analyze(argv[1]);
    disk_space = folder_space + file_space;
    printf("Total disk space used: %llu bytes\n", disk_space);
    printf("Total space used by folders: %llu bytes\n", folder_space);
    printf("Total space used by files: %llu bytes\n", file_space);
    return 0;
}