//GPT-4o-mini DATASET v1.0 Category: Data recovery tool ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_RECOVERY_FILES 1024
#define BUFFER_SIZE 1024

// Struct to represent a possible recoverable file
typedef struct {
    char filename[256];
    off_t size;
    time_t modified_time;
} RecoverableFile;

// Function prototypes
void log_error(const char *message);
void search_for_recoverable_files(const char *directory, RecoverableFile *files, int *count);
void display_files(RecoverableFile *files, int count);
void attempt_recovery(const char *source, const char *destination);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage();
        return 1;
    }

    const char *search_dir = argv[1];
    const char *recovery_dir = argv[2];

    // This is where we keep track of possible recoverable files
    RecoverableFile recoverable_files[MAX_RECOVERY_FILES];
    int file_count = 0;

    search_for_recoverable_files(search_dir, recoverable_files, &file_count);
    display_files(recoverable_files, file_count);
    
    for (int i = 0; i < file_count; i++) {
        char destination[256];
        snprintf(destination, sizeof(destination), "%s/%s", recovery_dir, recoverable_files[i].filename);
        attempt_recovery(recoverable_files[i].filename, destination);
    }

    return 0;
}

void log_error(const char *message) {
    fprintf(stderr, "[ERROR]: %s - %s\n", message, strerror(errno));
}

void search_for_recoverable_files(const char *directory, RecoverableFile *files, int *count) {
    DIR *dir = opendir(directory);
    if (dir == NULL) {
        log_error("Failed to open directory");
        return;
    }

    struct dirent *entry;
    struct stat file_stats;

    while ((entry = readdir(dir)) != NULL) {
        // Skip the "." and ".." entries
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", directory, entry->d_name);
        
        if (stat(full_path, &file_stats) == -1) {
            log_error("Failed to get file stats");
            continue;
        }

        // Check if the file is a regular file (not a directory/symlink)
        if (S_ISREG(file_stats.st_mode)) {
            if (*count < MAX_RECOVERY_FILES) {
                strncpy(files[*count].filename, entry->d_name, sizeof(files[*count].filename));
                files[*count].size = file_stats.st_size;
                files[*count].modified_time = file_stats.st_mtime;
                (*count)++;
            } else {
                fprintf(stderr, "Max file count reached, some files may not be listed.\n");
                break;
            }
        }
    }
    closedir(dir);
}

void display_files(RecoverableFile *files, int count) {
    printf("Found %d recoverable files:\n", count);
    for (int i = 0; i < count; i++) {
        printf("File: %s, Size: %ld bytes, Last Modified: %s", 
               files[i].filename, files[i].size, ctime(&files[i].modified_time));
    }
}

void attempt_recovery(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        log_error("Error opening source file for recovery");
        return;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        log_error("Error opening destination file for recovery");
        fclose(src);
        return;
    }

    char buffer[BUFFER_SIZE];
    size_t bytes;

    while ((bytes = fread(buffer, 1, BUFFER_SIZE, src)) > 0) {
        if (fwrite(buffer, 1, bytes, dest) != bytes) {
            log_error("Error writing to the recovery file");
            break;
        }
    }

    fclose(src);
    fclose(dest);
    printf("Recovered file: %s to %s\n", source, destination);
}

void print_usage() {
    printf("Usage: data_recovery_tool <source_directory> <recovery_directory>\n");
    printf("Example: data_recovery_tool ./data_recycle ./recovered_files\n");
}