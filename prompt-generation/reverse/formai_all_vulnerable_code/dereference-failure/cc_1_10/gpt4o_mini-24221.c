//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 512
#define BUFFER_SIZE 4096

// Function to check if the file extension is in the list of supported types
int is_supported_file_type(const char *filename) {
    const char *supported_extensions[] = { ".jpg", ".png", ".txt", ".mp3", ".mp4", NULL };
    for (int i = 0; supported_extensions[i] != NULL; i++) {
        if (strstr(filename, supported_extensions[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}

// Function to copy a file from source to destination
int copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return 0;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return 0;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    return 1;
}

// Function to recover files in the specified directory
void recover_files(const char *directory, const char *recovery_folder) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) { // Only process regular files
            if (is_supported_file_type(entry->d_name)) {
                char source_path[MAX_PATH];
                snprintf(source_path, sizeof(source_path), "%s/%s", directory, entry->d_name);

                char dest_path[MAX_PATH];
                snprintf(dest_path, sizeof(dest_path), "%s/%s", recovery_folder, entry->d_name);

                if (copy_file(source_path, dest_path)) {
                    printf("Recovered: %s to %s\n", source_path, dest_path);
                }
            }
        }
    }
    closedir(dir);
}

// Function to create the recovery folder if it does not exist
void create_recovery_folder(const char *recovery_folder) {
    struct stat st = {0};
    if (stat(recovery_folder, &st) == -1) {
        mkdir(recovery_folder, 0700);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <directory_to_scan> <recovery_folder>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *directory_to_scan = argv[1];
    const char *recovery_folder = argv[2];

    // Create the recovery folder if it doesn't exist
    create_recovery_folder(recovery_folder);

    // Recover files from the specified directory
    recover_files(directory_to_scan, recovery_folder);

    return EXIT_SUCCESS;
}