//FormAI DATASET v1.0 Category: File Backup System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

// define constants for the maximum file path length and the backup directory name
#define MAX_PATH 1024
#define BACKUP_DIR_NAME "backup"

// function to create a backup of the provided file
int create_backup(char* file_path) {
    // create a backup directory if it doesn't exist
    char backup_dir_path[MAX_PATH];
    sprintf(backup_dir_path, "./%s", BACKUP_DIR_NAME);
    DIR* dir = opendir(backup_dir_path);
    if (!dir) {
        mkdir(backup_dir_path, 0700);
    } else {
        closedir(dir);
    }

    // generate a timestamp string to use for the backup file name
    time_t now = time(NULL);
    struct tm* tm = localtime(&now);
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d_%H-%M-%S", tm);

    // create the backup file in the backup directory with the timestamp in the name
    char backup_file_path[MAX_PATH];
    sprintf(backup_file_path, "./%s/%s_%s", BACKUP_DIR_NAME, timestamp, file_path);
    FILE* src_file = fopen(file_path, "rb");
    FILE* dst_file = fopen(backup_file_path, "wb");
    if (!src_file || !dst_file) {
        return 1;
    }
    char buffer[1024];
    size_t size;
    while ((size = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, 1, size, dst_file);
    }
    fclose(src_file);
    fclose(dst_file);

    return 0;
}

int main(int argc, char** argv) {
    // check if a file path was provided as an argument
    if (argc != 2) {
        printf("Usage: %s [file_path]\n", argv[0]);
        return 1;
    }

    // backup the file and print a message indicating success or failure
    int result = create_backup(argv[1]);
    if (result == 0) {
        printf("File '%s' backed up successfully!\n", argv[1]);
    } else {
        printf("Failed to back up file '%s'\n", argv[1]);
    }

    return 0;
}