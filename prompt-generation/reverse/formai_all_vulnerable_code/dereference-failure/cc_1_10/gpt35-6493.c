//FormAI DATASET v1.0 Category: File Synchronizer ; Style: intelligent
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void SyncFile(char* source_path, char* dest_path);
void CopyFile(char* source_path, char* dest_path);
int IsFileExists(char* path);
void CreateDirectory(char* path);
void CopyDirectory(char* source_path, char* dest_path);

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Usage: %s [source_directory] [destination_directory]\n", argv[0]);
        exit(1);
    }

    char* source_path = argv[1];
    char* dest_path = argv[2];

    SyncFile(source_path, dest_path);
  
    printf("Sync complete!\n");

    return 0;
}

void SyncFile(char* source_path, char* dest_path) {
    struct dirent* dp;
    DIR* source_dir = opendir(source_path);
    DIR* dest_dir = opendir(dest_path);

    if (!source_dir || !dest_dir) {
        printf("Error: cannot open directory\n");
        exit(1);
    }

    while ((dp = readdir(source_dir)) != NULL) {
        // Ignore . and ..
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        char source_file[256];
        char dest_file[256];

        sprintf(source_file, "%s/%s", source_path, dp->d_name);
        sprintf(dest_file, "%s/%s", dest_path, dp->d_name);

        if (IsFileExists(dest_file)) {
            struct stat source_stat, dest_stat;

            stat(source_file, &source_stat);
            stat(dest_file, &dest_stat);

            if (source_stat.st_mtime > dest_stat.st_mtime) {
                // Source file has been modified, copy it to destination
                printf("Copying %s to %s\n", source_file, dest_file);
                CopyFile(source_file, dest_file);
            }
        } else {
            if (dp->d_type == DT_DIR) {
                // destination directory doesn't exist, create it
                CreateDirectory(dest_file);
                // recursively sync the source directory with the newly created destination directory
                CopyDirectory(source_file, dest_file);
            } else {
                // destination file doesn't exist, copy it
                printf("Copying %s to %s\n", source_file, dest_file);
                CopyFile(source_file, dest_file);
            }
        }
    }
}

void CopyDirectory(char* source_path, char* dest_path) {
    struct dirent* dp;
    DIR* source_dir = opendir(source_path);

    if (!source_dir) {
        printf("Error: cannot open directory\n");
        exit(1);
    }

    CreateDirectory(dest_path);

    while ((dp = readdir(source_dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        char source_file[256];
        char dest_file[256];

        sprintf(source_file, "%s/%s", source_path, dp->d_name);
        sprintf(dest_file, "%s/%s", dest_path, dp->d_name);

        if (dp->d_type == DT_DIR) {
            // recursive call to sync subdirectories
            CopyDirectory(source_file, dest_file);
        } else {
            // copy individual files
            printf("Copying %s to %s\n", source_file, dest_file);
            CopyFile(source_file, dest_file);
        }
    }
}

void CopyFile(char* source_path, char* dest_path) {
    FILE* source_file = fopen(source_path, "rb");
    FILE* dest_file = fopen(dest_path, "wb");

    if (!source_file || !dest_file) {
        printf("Error: cannot open file\n");
        exit(1);
    }

    char buffer[1024];
    size_t read_size;

    while ((read_size = fread(buffer, 1, sizeof(buffer), source_file)) > 0) {
        fwrite(buffer, 1, read_size, dest_file);
    }

    fclose(source_file);
    fclose(dest_file);
}

int IsFileExists(char* path) {
    return access(path, F_OK) != -1;
}

void CreateDirectory(char* path) {
    mkdir(path, 0777);
}