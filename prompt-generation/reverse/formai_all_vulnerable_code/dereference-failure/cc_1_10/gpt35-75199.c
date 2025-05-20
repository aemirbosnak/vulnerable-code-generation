//FormAI DATASET v1.0 Category: File Synchronizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>

#define MAX_PATH_LENGTH 256
#define MAX_FILE_LENGTH 64

// Function declarations
void synchronize(char* source_dir, char* dest_dir);
void create_dir(char* dir_path, mode_t mode);
void remove_dir(char* dir_path);
void sync_file(char* source_path, char* dest_path);
void remove_file(char* file_path);
int are_files_equal(char* file1, char* file2);

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Error: Expected source directory and destination directory as arguments.\n");
        return -1;
    }

    char* source_dir = argv[1];
    char* dest_dir = argv[2];

    synchronize(source_dir, dest_dir);

    printf("File synchronization complete!\n");

    return 0;
}

void synchronize(char* source_dir, char* dest_dir) {
    struct dirent* dir_entry;
    DIR* dir = opendir(source_dir);
    char source_path[MAX_PATH_LENGTH];
    char dest_path[MAX_PATH_LENGTH];

    if (!dir) {
        printf("Error: Could not open source directory %s.\n", source_dir);
        exit(-1);
    }

    // Synchronize all files and subdirectories
    while ((dir_entry = readdir(dir))) {
        if (!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..")) {
            continue;
        }

        // Build source and destination paths for file or subdirectory
        snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source_dir, dir_entry->d_name);
        snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_dir, dir_entry->d_name);

        if (dir_entry->d_type == DT_REG) {
            // Synchronize individual file
            sync_file(source_path, dest_path);
        } else if (dir_entry->d_type == DT_DIR) {
            // Recursively synchronize subdirectory
            if (access(dest_path, F_OK) == -1) {
                // Destination directory does not exist, create it
                create_dir(dest_path, 0777);
            }
            synchronize(source_path, dest_path);
        }
    }

    closedir(dir);

    // Remove any files or directories in the destination directory that do not exist in the source directory
    dir = opendir(dest_dir);
    if (!dir) {
        printf("Error: Could not open destination directory %s.\n", dest_dir);
        exit(-1);
    }

    while ((dir_entry = readdir(dir))) {
        if (!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..")) {
            continue;
        }

        snprintf(dest_path, MAX_PATH_LENGTH, "%s/%s", dest_dir, dir_entry->d_name);

        if (dir_entry->d_type == DT_REG) {
            // Remove file if it does not exist in source directory
            snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source_dir, dir_entry->d_name);

            if (access(source_path, F_OK) == -1) {
                remove_file(dest_path);
            }

        } else if (dir_entry->d_type == DT_DIR) {
            // Recursively remove subdirectory if it does not exist in source directory
            snprintf(source_path, MAX_PATH_LENGTH, "%s/%s", source_dir, dir_entry->d_name);

            if (access(source_path, F_OK) == -1) {
                remove_dir(dest_path);
            }
        }
    }

    closedir(dir);
}

void create_dir(char* dir_path, mode_t mode) {
    if (mkdir(dir_path, mode) == -1) {
        printf("Error: Could not create directory %s.\n", dir_path);
        exit(-1);
    }
}

void remove_dir(char* dir_path) {
    DIR* dir = opendir(dir_path);
    struct dirent* dir_entry;

    if (!dir) {
        printf("Error: Could not open directory %s for removal.\n", dir_path);
        exit(-1);
    }

    while ((dir_entry = readdir(dir))) {
        if (!strcmp(dir_entry->d_name, ".") || !strcmp(dir_entry->d_name, "..")) {
            continue;
        }

        char file_path[MAX_PATH_LENGTH];
        snprintf(file_path, MAX_PATH_LENGTH, "%s/%s", dir_path, dir_entry->d_name);

        if (dir_entry->d_type == DT_REG) {
            // Remove file
            remove_file(file_path);
        } else if (dir_entry->d_type == DT_DIR) {
            // Recursively remove subdirectory
            remove_dir(file_path);
        }
    }

    closedir(dir);

    if (rmdir(dir_path) == -1) {
        printf("Error: Could not remove directory %s.\n", dir_path);
        exit(-1);
    }
}

void sync_file(char* source_path, char* dest_path) {
    struct stat source_stat;
    struct stat dest_stat;

    if (stat(source_path, &source_stat) == -1) {
        printf("Error: Could not retrieve file information for %s.\n", source_path);
        return;
    }

    if (stat(dest_path, &dest_stat) == -1) {
        // Destination file does not exist, copy source file
        char command[MAX_PATH_LENGTH + MAX_FILE_LENGTH + 16];
        snprintf(command, MAX_PATH_LENGTH + MAX_FILE_LENGTH + 16, "cp %s %s", source_path, dest_path);
        system(command);
        printf("File %s synchronized from source to destination.\n", source_path);
    } else if (are_files_equal(source_path, dest_path)) {
        // Files are equal, skip synchronization
        printf("File %s already synchronized.\n", source_path);
    } else {
        // Files are different, copy source file over destination file
        char command[MAX_PATH_LENGTH + MAX_FILE_LENGTH + 16];
        snprintf(command, MAX_PATH_LENGTH + MAX_FILE_LENGTH + 16, "cp %s %s", source_path, dest_path);
        system(command);
        printf("File %s synchronized from source to destination.\n", source_path);
    }
}

void remove_file(char* file_path) {
    if (remove(file_path) == -1) {
        printf("Error: Could not remove file %s.\n", file_path);
        exit(-1);
    }
}

int are_files_equal(char* file1, char* file2) {
    struct stat stat1;
    struct stat stat2;

    if (stat(file1, &stat1) == -1 || stat(file2, &stat2) == -1) {
        printf("Error: Could not retrieve file information for comparison.\n");
        return 0;
    }

    if (stat1.st_size != stat2.st_size) {
        // Files have different sizes, they are not equal
        return 0;
    }

    FILE* fp1 = fopen(file1, "r");
    FILE* fp2 = fopen(file2, "r");

    if (!fp1 || !fp2) {
        printf("Error: Could not open files for comparison.\n");
        if (fp1) fclose(fp1);
        if (fp2) fclose(fp2);
        return 0;
    }

    int bytes1, bytes2;
    char buffer1[1024], buffer2[1024];

    while ((bytes1 = fread(buffer1, 1, sizeof(buffer1), fp1))) {
        bytes2 = fread(buffer2, 1, sizeof(buffer2), fp2);

        if (bytes1 != bytes2 || memcmp(buffer1, buffer2, bytes1)) {
            fclose(fp1);
            fclose(fp2);
            return 0;
        }
    }

    fclose(fp1);
    fclose(fp2);

    return 1;
}