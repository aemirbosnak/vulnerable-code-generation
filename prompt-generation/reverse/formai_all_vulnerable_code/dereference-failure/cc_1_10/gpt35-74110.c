//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define KILO_BYTE 1024
#define MEGA_BYTE (KILO_BYTE * KILO_BYTE)
#define GIGA_BYTE (KILO_BYTE * MEGA_BYTE)

// function declarations
long long int get_file_size(char *file_path);
void print_file_info(char *file_path);
void analyze_directory(char *directory_path);

int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc != 2) {
        printf("Usage: %s directory_path\n", argv[0]);
        exit(1);
    }
    
    // analyze the directory
    analyze_directory(argv[1]);
    
    return 0;
}

// returns the size of a file in bytes
long long int get_file_size(char *file_path) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) == -1) {
        fprintf(stderr, "Error: cannot get file status for %s\n", file_path);
        return -1;
    }
    return file_stat.st_size;
}

// prints information about a file
void print_file_info(char *file_path) {
    long long int file_size = get_file_size(file_path);
    if (file_size == -1) {
        printf("%s (size unknown)\n", file_path);
    } else if (file_size < KILO_BYTE) {
        printf("%s (%lld bytes)\n", file_path, file_size);
    } else if (file_size < MEGA_BYTE) {
        printf("%s (%lld KB)\n", file_path, file_size / KILO_BYTE);
    } else if (file_size < GIGA_BYTE) {
        printf("%s (%lld MB)\n", file_path, file_size / MEGA_BYTE);
    } else {
        printf("%s (%lld GB)\n", file_path, file_size / GIGA_BYTE);
    }
}

// analyzes a directory recursively
void analyze_directory(char *directory_path) {
    DIR *dir = opendir(directory_path);
    if (!dir) {
        fprintf(stderr, "Error: cannot open directory %s\n", directory_path);
        return;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // ignore hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }
        
        // construct the path of the file or directory
        char file_path[1024];
        snprintf(file_path, sizeof(file_path), "%s/%s", directory_path, entry->d_name);
        
        // analyze the file or directory
        if (entry->d_type == DT_DIR) {
            analyze_directory(file_path);
        } else {
            print_file_info(file_path);
        }
    }
    
    closedir(dir);
}