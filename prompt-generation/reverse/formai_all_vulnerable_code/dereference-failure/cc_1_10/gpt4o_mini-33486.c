//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

typedef struct {
    char name[MAX_PATH];
    long size;
} FileEntry;

void list_files(const char *path, FileEntry *files, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_name[0] == '.') continue; // Skip hidden files

        char full_path[MAX_PATH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &file_stat) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISREG(file_stat.st_mode)) { // Check if it is a regular file
            files[*file_count].size = file_stat.st_size;
            strncpy(files[*file_count].name, entry->d_name, MAX_PATH);
            (*file_count)++;
        }
    }
    closedir(dp);
}

void print_file_statistics(FileEntry *files, int file_count) {
    long total_size = 0;
    
    printf("File Name                                 Size (Bytes)\n");
    printf("-----------------------------------------------------\n");
    
    for (int i = 0; i < file_count; i++) {
        printf("%-40s %ld\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }

    printf("-----------------------------------------------------\n");
    printf("Total Files: %d\n", file_count);
    printf("Total Size: %ld Bytes\n", total_size);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_path = argv[1];
    FileEntry files[MAX_FILES];
    int file_count = 0;

    list_files(directory_path, files, &file_count);

    print_file_statistics(files, file_count);

    return EXIT_SUCCESS;
}