//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// function prototypes
void traverse_directory(char* directory_path, int depth);
void print_spaces(int cnt);

int main(int argc, char* argv[]) {
    int depth = 0;
    char* start_dir = ".";
    if(argc > 1) {
        start_dir = argv[1];
        depth = atoi(argv[2]);
    }
    traverse_directory(start_dir, depth);
    return 0;
}

void traverse_directory(char* directory_path, int depth) {
    DIR* dir = opendir(directory_path);
    struct dirent* entry;
    struct stat file_info;
    char path[1024];
    long long total_space = 0;
    while((entry = readdir(dir)) != NULL) {
        if(entry->d_name[0] == '.') continue; // skip hidden files
        sprintf(path, "%s/%s", directory_path, entry->d_name);
        if(stat(path, &file_info) == -1) continue; // unable to access file
        if(S_ISDIR(file_info.st_mode)) { // directory
            if(depth > 0) {
                print_spaces(depth);
                printf("[dir] %s\n", entry->d_name);
                traverse_directory(path, depth - 1);
            }
        }
        else { // file
            total_space += file_info.st_size;
            print_spaces(depth);
            printf("[file] %s, size: %lld bytes\n", entry->d_name, file_info.st_size);
        }
    }
    print_spaces(depth);
    printf("[dir] %s, total size: %lld bytes\n", directory_path, total_space);
    closedir(dir);
}

void print_spaces(int cnt) {
    while(cnt--) printf("  "); // print two spaces for each depth level
}