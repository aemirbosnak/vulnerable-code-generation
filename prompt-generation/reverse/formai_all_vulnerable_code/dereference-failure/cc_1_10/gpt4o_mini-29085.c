//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_FILENAME_LEN 256
#define MAX_FILES 1000

typedef struct {
    char filename[MAX_FILENAME_LEN];
    size_t size;
    char creation_time[20];
} FileMetadata;

// Function to get the file size and creation time
void get_file_metadata(const char *file_path, FileMetadata *metadata) {
    struct stat file_stat;
    if (stat(file_path, &file_stat) == 0) {
        metadata->size = file_stat.st_size;
        strftime(metadata->creation_time, sizeof(metadata->creation_time), "%Y-%m-%d %H:%M:%S", localtime(&file_stat.st_mtime));
    } else {
        perror("stat error");
    }
}

// Function to scan a directory and extract metadata from files
int scan_directory(const char *dir_path, FileMetadata *files, int max_files) {
    struct dirent *entry;
    DIR *dp = opendir(dir_path);
    if (dp == NULL) {
        perror("opendir error");
        return -1;
    }

    int count = 0;
    while ((entry = readdir(dp)) != NULL) {
        // Skip the current and parent directories
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char full_path[MAX_FILENAME_LEN];
            snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);
            get_file_metadata(full_path, &files[count]);
            strncpy(files[count].filename, entry->d_name, MAX_FILENAME_LEN);
            count++;
            if (count >= max_files) {
                break; // Limit to max_files
            }
        }
    }
    
    closedir(dp);
    return count;
}

// Function to sort files by size
void sort_files_by_size(FileMetadata *files, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (files[i].size > files[j].size) {
                FileMetadata temp = files[i];
                files[i] = files[j];
                files[j] = temp;
            }
        }
    }
}

// Function to display file metadata
void display_file_metadata(FileMetadata *files, int count) {
    printf("%-40s %-10s %-20s\n", "Filename", "Size (bytes)", "Creation Time");
    printf("---------------------------------------------------------\n");
    
    for (int i = 0; i < count; i++) {
        printf("%-40s %-10zu %-20s\n", files[i].filename, files[i].size, files[i].creation_time);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FileMetadata files[MAX_FILES];
    int file_count = scan_directory(argv[1], files, MAX_FILES);
    
    if (file_count < 0) {
        return EXIT_FAILURE;
    }

    sort_files_by_size(files, file_count);
    display_file_metadata(files, file_count);

    return EXIT_SUCCESS;
}