//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 4096
#define MAX_NAME_LENGTH 256

typedef struct File {
    char name[MAX_NAME_LENGTH];
    size_t size;
} File;

typedef struct Directory {
    char name[MAX_NAME_LENGTH];
    size_t totalSize;
    int fileCount;
    File *files;
} Directory;

void analyze_directory(const char *dir_path, Directory *directory) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dir = opendir(dir_path);
    
    if (!dir) {
        perror("Failed to open directory");
        return;
    }

    strcpy(directory->name, dir_path);
    directory->totalSize = 0;
    directory->fileCount = 0;
    directory->files = malloc(sizeof(File) * 100); // Assume a maximum of 100 files for simplicity

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_PATH];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            
            if (stat(full_path, &file_stat) == 0) {
                if (S_ISREG(file_stat.st_mode)) {
                    size_t file_size = file_stat.st_size;
                    strcpy(directory->files[directory->fileCount].name, entry->d_name);
                    directory->files[directory->fileCount].size = file_size;
                    directory->totalSize += file_size;
                    directory->fileCount++;
                } 
                // You could handle directories or other file types here if desired
            } else {
                perror("Failed to get file statistics");
            }
        }
    }

    closedir(dir);
}

void print_directory_info(const Directory *directory) {
    printf("Directory: %s\n", directory->name);
    printf("Total files: %d\n", directory->fileCount);
    printf("Total size: %ld bytes\n", directory->totalSize);
    
    printf("Files in directory:\n");
    for (int i = 0; i < directory->fileCount; i++) {
        printf(" - %s: %ld bytes\n", directory->files[i].name, directory->files[i].size);
    }
}

void free_directory(Directory *directory) {
    free(directory->files);
    directory->files = NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Directory directory;
    analyze_directory(argv[1], &directory);
    print_directory_info(&directory);
    free_directory(&directory);

    return EXIT_SUCCESS;
}