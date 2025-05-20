//GPT-4o-mini DATASET v1.0 Category: Metadata Extractor ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdint.h>

#define MAX_FILES 100
#define BUFFER_SIZE 256

typedef struct {
    char filename[BUFFER_SIZE];
    uint64_t file_size;
    char file_type[BUFFER_SIZE];
} FileMetadata;

void getFileType(const char *filename, char *file_type) {
    const char *extension = strrchr(filename, '.');
    if (extension) {
        strcpy(file_type, extension + 1);
    } else {
        strcpy(file_type, "unknown");
    }
}

void collectMetadata(const char *dir_path, FileMetadata *files, int *file_count) {
    struct dirent *entry;
    struct stat file_stat;
    DIR *dp = opendir(dir_path);

    if (dp == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dp)) != NULL) {
        if (entry->d_type == DT_REG) { // Check if it is a regular file
            char filepath[BUFFER_SIZE];
            snprintf(filepath, sizeof(filepath), "%s/%s", dir_path, entry->d_name);
            if (stat(filepath, &file_stat) == 0) {
                strcpy(files[*file_count].filename, entry->d_name);
                files[*file_count].file_size = file_stat.st_size;
                getFileType(entry->d_name, files[*file_count].file_type);
                (*file_count)++;
            }
        }
    }
    
    closedir(dp);
}

void displayStatistics(FileMetadata *files, int file_count) {
    uint64_t total_size = 0;
    int file_type_count[10] = {0}; // For counting specific file types
    const char *file_types[10] = {"txt", "c", "h", "jpg", "png", "pdf", "mp3", "mp4", "zip", "unknown"};

    for (int i = 0; i < file_count; i++) {
        total_size += files[i].file_size;
        
        for (int j = 0; j < 10; j++) {
            if (strcmp(files[i].file_type, file_types[j]) == 0) {
                file_type_count[j]++;
                break;
            }
        }
    }

    printf("Total number of files: %d\n", file_count);
    printf("Total size of files: %lu bytes\n\n", total_size);
    printf("File Type Statistics:\n");
    for (int k = 0; k < 10; k++) {
        printf("Type %s: %d files\n", file_types[k], file_type_count[k]);
    }
}

int main(int argc, char *argv[]) {
    FileMetadata files[MAX_FILES];
    int file_count = 0;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    collectMetadata(argv[1], files, &file_count);
    displayStatistics(files, file_count);

    return EXIT_SUCCESS;
}