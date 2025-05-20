//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024

// Get the current time as a string
char* get_current_time() {
    time_t t = time(NULL);
    struct tm* tm = localtime(&t);
    char* time_str = malloc(26);
    strftime(time_str, 26, "%Y-%m-%d_%H-%M-%S", tm);
    return time_str;
}

// Check if a file exists
int file_exists(const char* path) {
    struct stat buf;
    return stat(path, &buf) == 0;
}

// Create a directory
int create_directory(const char* path) {
    return mkdir(path, 0755);
}

// Copy a file
int copy_file(const char* src, const char* dest) {
    FILE* src_file = fopen(src, "rb");
    if (src_file == NULL) {
        return 1;
    }

    FILE* dest_file = fopen(dest, "wb");
    if (dest_file == NULL) {
        fclose(src_file);
        return 1;
    }

    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, n, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);

    return 0;
}

// Backup a file
int backup_file(const char* src, const char* dest) {
    // Get the current time
    char* time_str = get_current_time();

    // Create the backup directory if it doesn't exist
    char backup_dir[MAX_PATH_LENGTH];
    snprintf(backup_dir, MAX_PATH_LENGTH, "%s/%s", dest, time_str);
    if (!file_exists(backup_dir)) {
        if (create_directory(backup_dir) != 0) {
            return 1;
        }
    }

    // Copy the file to the backup directory
    char backup_path[MAX_PATH_LENGTH];
    snprintf(backup_path, MAX_PATH_LENGTH, "%s/%s", backup_dir, src);
    if (copy_file(src, backup_path) != 0) {
        return 1;
    }

    // Free the time string
    free(time_str);

    return 0;
}

// Backup a directory
int backup_directory(const char* src, const char* dest) {
    // Get the current time
    char* time_str = get_current_time();

    // Create the backup directory if it doesn't exist
    char backup_dir[MAX_PATH_LENGTH];
    snprintf(backup_dir, MAX_PATH_LENGTH, "%s/%s", dest, time_str);
    if (!file_exists(backup_dir)) {
        if (create_directory(backup_dir) != 0) {
            return 1;
        }
    }

    // Iterate over the files in the directory
    DIR* dir = opendir(src);
    if (dir == NULL) {
        return 1;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the full path to the file
        char src_path[MAX_PATH_LENGTH];
        snprintf(src_path, MAX_PATH_LENGTH, "%s/%s", src, entry->d_name);

        // Get the full path to the backup file
        char backup_path[MAX_PATH_LENGTH];
        snprintf(backup_path, MAX_PATH_LENGTH, "%s/%s", backup_dir, entry->d_name);

        // Backup the file
        if (backup_file(src_path, backup_path) != 0) {
            closedir(dir);
            return 1;
        }
    }

    closedir(dir);

    // Free the time string
    free(time_str);

    return 0;
}

int main() {
    // Get the source and destination paths from the user
    char src[MAX_PATH_LENGTH];
    printf("Enter the source path: ");
    scanf("%s", src);

    char dest[MAX_PATH_LENGTH];
    printf("Enter the destination path: ");
    scanf("%s", dest);

    // Check if the source path exists
    if (!file_exists(src)) {
        printf("The source path does not exist.\n");
        return 1;
    }

    // Check if the destination path exists
    if (!file_exists(dest)) {
        // Create the destination path
        if (create_directory(dest) != 0) {
            printf("Could not create the destination path.\n");
            return 1;
        }
    }

    // Check if the source path is a file or a directory
    struct stat buf;
    stat(src, &buf);
    if (S_ISREG(buf.st_mode)) {
        // Backup the file
        if (backup_file(src, dest) != 0) {
            printf("Could not backup the file.\n");
            return 1;
        }
    } else if (S_ISDIR(buf.st_mode)) {
        // Backup the directory
        if (backup_directory(src, dest) != 0) {
            printf("Could not backup the directory.\n");
            return 1;
        }
    } else {
        printf("The source path is not a file or a directory.\n");
        return 1;
    }

    printf("Backup complete.\n");

    return 0;
}