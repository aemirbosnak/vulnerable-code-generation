//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024
#define MAX_FILES 100
#define THRESHOLD 100 // Threshold for file size in KB

typedef struct {
    char name[MAX_PATH];
    off_t size; // Size in bytes
} FileInfo;

void generate_file_report(const char* directory, FileInfo* files, int* count) {
    struct stat fileStat;
    DIR* dir;
    struct dirent* entry;

    if ((dir = opendir(directory)) == NULL) {
        printf("Failed to open directory: %s\n", directory);
        return;
    }

    *count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Regular file
            // Form full path
            char fullPath[MAX_PATH];
            snprintf(fullPath, sizeof(fullPath), "%s/%s", directory, entry->d_name);
            
            if (stat(fullPath, &fileStat) == 0) {
                strncpy(files[*count].name, entry->d_name, MAX_PATH);
                files[*count].size = fileStat.st_size;

                // Increment the count of files
                (*count)++;
                if (*count >= MAX_FILES) {
                    printf("Maximum file limit reached, truncating further entries.\n");
                    break;
                }
            } else {
                perror("Stat failed");
            }
        }
    }
    
    closedir(dir);
}

void display_large_files(FileInfo* files, int count) {
    printf("Files larger than %d KB:\n", THRESHOLD);
    for (int i = 0; i < count; i++) {
        if (files[i].size > THRESHOLD * 1024) {
            printf("File: %s, Size: %.2f KB\n", files[i].name, files[i].size / 1024.0);
        }
    }
}

void calculate_statistics(FileInfo* files, int count) {
    off_t totalSize = 0;
    int fileCount = count;

    for (int i = 0; i < count; i++) {
        totalSize += files[i].size;
    }

    double averageSize = (fileCount > 0) ? (double)totalSize / fileCount : 0;

    printf("\nStatistics:\n");
    printf("Total number of files scanned: %d\n", fileCount);
    printf("Total size of files: %.2f KB\n", totalSize / 1024.0);
    printf("Average file size: %.2f KB\n", averageSize / 1024.0);
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char* directory = argv[1];
    
    FileInfo files[MAX_FILES];
    int fileCount = 0;

    generate_file_report(directory, files, &fileCount);
    display_large_files(files, fileCount);
    calculate_statistics(files, fileCount);

    return EXIT_SUCCESS;
}