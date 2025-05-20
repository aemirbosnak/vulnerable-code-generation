//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LEN 512

typedef struct {
    char path[MAX_PATH_LEN];
    time_t last_modified;
} FileInfo;

void backup_file(const char* src_path, const char* dest_path) {
    FILE* src_file = fopen(src_path, "rb");
    FILE* dest_file = fopen(dest_path, "wb");

    if (src_file == NULL || dest_file == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char buffer[4096];
    size_t bytes_read;

    while ((bytes_read = fread(buffer, sizeof(char), sizeof(buffer), src_file)) > 0) {
        fwrite(buffer, sizeof(char), bytes_read, dest_file);
    }

    fclose(src_file);
    fclose(dest_file);
}

void backup_directory(const char* src_path, const char* dest_path) {
    DIR* src_dir = opendir(src_path);
    DIR* dest_dir = opendir(dest_path);

    if (src_dir == NULL || dest_dir == NULL) {
        printf("Error opening directory\n");
        exit(1);
    }

    struct dirent* dirent;

    while ((dirent = readdir(src_dir))!= NULL) {
        char src_file_path[MAX_PATH_LEN];
        char dest_file_path[MAX_PATH_LEN];

        sprintf(src_file_path, "%s/%s", src_path, dirent->d_name);
        sprintf(dest_file_path, "%s/%s", dest_path, dirent->d_name);

        if (dirent->d_type == DT_DIR) {
            backup_directory(src_file_path, dest_file_path);
        } else {
            backup_file(src_file_path, dest_file_path);
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

void main() {
    char src_path[MAX_PATH_LEN];
    char dest_path[MAX_PATH_LEN];

    printf("Enter source directory path: ");
    scanf("%s", src_path);

    printf("Enter destination directory path: ");
    scanf("%s", dest_path);

    backup_directory(src_path, dest_path);
}