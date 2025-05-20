//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH_LENGTH 1024
#define MAX_FILENAME_LENGTH 255

// Struct to hold file information
typedef struct {
    char name[MAX_FILENAME_LENGTH];
    time_t modified_time;
} FileInfo;

// Compare function for sorting FileInfo array
int cmp(const void *a, const void *b) {
    return strcmp(((FileInfo*)a)->name, ((FileInfo*)b)->name);
}

// Function to get file information
void get_file_info(char* path, FileInfo* file_info) {
    struct stat stats;
    stat(path, &stats);
    strcpy(file_info->name, path);
    file_info->modified_time = stats.st_mtime;
}

// Function to synchronize files from source directory to destination directory
void sync_files(char* src_path, char* dst_path) {
    DIR* src_dir = opendir(src_path);
    DIR* dst_dir = opendir(dst_path);

    if (!src_dir) {
        printf("Error opening source directory\n");
        return;
    }

    if (!dst_dir) {
        printf("Error opening destination directory\n");
        closedir(src_dir);
        return;
    }

    // Collect file info for source and destination directories
    FileInfo src_files[MAX_PATH_LENGTH];
    int num_src_files = 0;
    struct dirent* dir_entry;

    while ((dir_entry = readdir(src_dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        sprintf(path, "%s/%s", src_path, dir_entry->d_name);

        // Ignore files starting with .
        if (dir_entry->d_name[0] == '.') {
            continue;
        }

        // Ignore directories
        if (dir_entry->d_type == DT_DIR) {
            continue;
        }

        get_file_info(path, &src_files[num_src_files]);
        num_src_files++;
    }

    FileInfo dst_files[MAX_PATH_LENGTH];
    int num_dst_files = 0;

    while ((dir_entry = readdir(dst_dir)) != NULL) {
        char path[MAX_PATH_LENGTH];
        sprintf(path, "%s/%s", dst_path, dir_entry->d_name);

        // Ignore files starting with .
        if (dir_entry->d_name[0] == '.') {
            continue;
        }

        // Ignore directories
        if (dir_entry->d_type == DT_DIR) {
            continue;
        }

        get_file_info(path, &dst_files[num_dst_files]);
        num_dst_files++;
    }

    // Sort FileInfo arrays by filename
    qsort(src_files, num_src_files, sizeof(FileInfo), cmp);
    qsort(dst_files, num_dst_files, sizeof(FileInfo), cmp);

    // Synchronize files
    int i = 0, j = 0;

    while (i < num_src_files && j < num_dst_files) {
        int cmp_result = strcmp(src_files[i].name, dst_files[j].name);

        if (cmp_result == 0) {
            // Check if modified time is different
            if (src_files[i].modified_time > dst_files[j].modified_time) {
                char cmd[MAX_PATH_LENGTH*2+20];
                sprintf(cmd, "cp %s %s", src_files[i].name, dst_files[j].name);
                system(cmd);
                printf("Synchronized %s\n", dst_files[j].name);
            }

            i++;
            j++;
        } else if (cmp_result < 0) {
            char cmd[MAX_PATH_LENGTH*2+20];
            sprintf(cmd, "cp %s %s", src_files[i].name, dst_path);
            system(cmd);
            printf("Copied %s to %s\n", src_files[i].name, dst_path);
            i++;
        } else {
            j++;
        }
    }

    // Copy remaining files from source to destination
    while (i < num_src_files) {
        char cmd[MAX_PATH_LENGTH*2+20];
        sprintf(cmd, "cp %s %s", src_files[i].name, dst_path);
        system(cmd);
        printf("Copied %s to %s\n", src_files[i].name, dst_path);
        i++;
    }

    printf("Sync completed successfully\n");

    closedir(src_dir);
    closedir(dst_dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: cfsync src_path dst_path\n");
        return 1;
    }

    char* src_path = argv[1];
    char* dst_path = argv[2];

    sync_files(src_path, dst_path);

    return 0;
}