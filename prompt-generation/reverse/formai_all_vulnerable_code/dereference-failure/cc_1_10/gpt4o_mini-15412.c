//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// Function prototypes
void recover_files(const char *directory);
void process_file(const char *filepath);
int is_deleted_file(const char *filename);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory_path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    recover_files(argv[1]);
    return EXIT_SUCCESS;
}

void recover_files(const char *directory) {
    struct dirent *entry;
    struct stat file_info;
    DIR *dir = opendir(directory);

    if (dir == NULL) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char path[BUFFER_SIZE];

        // Skip the special entries "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, sizeof(path), "%s/%s", directory, entry->d_name);
        if (stat(path, &file_info) == -1) {
            perror("Stat failed");
            continue;
        }

        // If it's a directory, recurse into it
        if (S_ISDIR(file_info.st_mode)) {
            recover_files(path);
        } else if (is_deleted_file(entry->d_name)) {
            process_file(path);
        }
    }

    closedir(dir);
}

void process_file(const char *filepath) {
    printf("Recovered file: %s\n", filepath);
    // Simulating content recovery: Here we can read the file and perform recovery operations.
    // In a real-world scenario, you would have specific logic to recover file data.
    // For this example, we'll simply print a message.
    FILE *file = fopen(filepath, "r");
    char buffer[BUFFER_SIZE];

    if (file) {
        while (fgets(buffer, sizeof(buffer), file)) {
            printf("Content: %s", buffer);
        }
        fclose(file);
    } else {
        perror("Failed to open file");
    }
}

int is_deleted_file(const char *filename) {
    // For simplicity, let's assume files containing "deleted" in their name are deleted.
    return strstr(filename, "deleted") != NULL;
}