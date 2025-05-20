//LLAMA2-13B DATASET v1.0 Category: Data recovery tool ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <dirent.h>

#define MAX_NAME_LEN 256
#define MAX_FILE_LEN 4096

// Structure to store file information
typedef struct {
    char name[MAX_NAME_LEN];
    size_t size;
    time_t modified;
} file_info_t;

// Function to scan a directory and its subdirectories
void scan_directory(const char *directory_path) {
    DIR *dirp;
    struct dirent *dirent;
    file_info_t *files = NULL;
    size_t files_count = 0;

    // Open the directory and its subdirectories
    if ((dirp = opendir(directory_path)) == NULL) {
        perror("Error opening directory");
        return;
    }

    // Loop through the directory and its subdirectories
    while ((dirent = readdir(dirp)) != NULL) {
        // Skip the "." and ".." directories
        if (dirent->d_name[0] == '.' && dirent->d_name[1] == '\0' ||
                dirent->d_name[0] == '..' && dirent->d_name[1] == '\0') {
            continue;
        }

        // Get the file information
        char full_path[MAX_FILE_LEN];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory_path, dirent->d_name);
        struct stat file_stats;
        if (stat(full_path, &file_stats) == 0) {
            file_info_t *file = calloc(1, sizeof(file_info_t));
            strncpy(file->name, dirent->d_name, MAX_NAME_LEN);
            file->size = file_stats.st_size;
            file->modified = file_stats.st_mtime;
            files = realloc(files, (files_count + 1) * sizeof(file_info_t));
            files[files_count] = *file;
            files_count++;
        }
    }

    // Close the directory and its subdirectories
    closedir(dirp);

    // Print the file information
    for (size_t i = 0; i < files_count; i++) {
        printf("%d. %s (%zu bytes, modified %s)\n", i + 1, files[i].name, files[i].size, ctime(&files[i].modified));
    }

    // Free the memory allocated for the file information
    free(files);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    // Scan the specified directory and its subdirectories
    scan_directory(argv[1]);

    return 0;
}