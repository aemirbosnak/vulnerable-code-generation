//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_FILENAME_LENGTH 256
#define MAX_METADATA_LENGTH 512

typedef struct {
    char filename[MAX_FILENAME_LENGTH];
    size_t size;
    time_t last_modified;
} FileMetadata;

void extract_metadata(const char *directory_path, FileMetadata *metadata_array, int *count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *directory = opendir(directory_path);

    if (directory == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(directory)) != NULL) {
        if (entry->d_type == DT_REG) { // Only regular files
            char full_path[MAX_FILENAME_LENGTH];
            snprintf(full_path, MAX_FILENAME_LENGTH, "%s/%s", directory_path, entry->d_name);
            if (stat(full_path, &file_stat) == 0) {
                strncpy(metadata_array[*count].filename, entry->d_name, MAX_FILENAME_LENGTH);
                metadata_array[*count].size = file_stat.st_size;
                metadata_array[*count].last_modified = file_stat.st_mtime;
                (*count)++;
            }
        }
    }
    closedir(directory);
}

void print_metadata(FileMetadata *metadata_array, int count) {
    printf("%-30s %-10s %-20s\n", "Filename", "Size (bytes)", "Last Modified");
    printf("%-30s %-10s %-20s\n", "-------------------------------", "-----------", "--------------------");

    for (int i = 0; i < count; i++) {
        char time_str[20];
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", localtime(&metadata_array[i].last_modified));
        printf("%-30s %-10lu %-20s\n", metadata_array[i].filename, metadata_array[i].size, time_str);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    const char *directory_path = argv[1];
    FileMetadata metadata_array[100];
    int count = 0;

    extract_metadata(directory_path, metadata_array, &count);
    
    if (count > 0) {
        print_metadata(metadata_array, count);
    } else {
        printf("No files found in the directory.\n");
    }

    return 0;
}