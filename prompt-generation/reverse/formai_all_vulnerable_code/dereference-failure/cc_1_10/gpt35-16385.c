//FormAI DATASET v1.0 Category: File Synchronizer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>

const char* SYNCHRONIZED_FOLDER = "/path/to/synchronization/folder/";

void synchronize(const char* path) {
    struct dirent* entry;
    DIR* directory;
    directory = opendir(path);
    if(directory == NULL) {
        printf("Error: Failed to open directory %s\n", path);
        return;
    }
    while((entry = readdir(directory)) != NULL) {
        char full_path[512];
        struct stat info;
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
        if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        if(lstat(full_path, &info) == 0) {
            if(S_ISDIR(info.st_mode)) {
                synchronize(full_path);
            }
            else if(S_ISREG(info.st_mode)) {
                char synchronized_path[512];
                snprintf(synchronized_path, sizeof(synchronized_path), "%s/%s", SYNCHRONIZED_FOLDER, full_path);
                struct stat synchronized_info;
                if(lstat(synchronized_path, &synchronized_info) != 0 || info.st_mtime > synchronized_info.st_mtime) {
                    FILE* source = fopen(full_path, "rb");
                    if(source == NULL) {
                        printf("Error: Failed to open file %s\n", full_path);
                        continue;
                    }
                    FILE* target = fopen(synchronized_path, "wb");
                    if(target == NULL) {
                        fclose(source);
                        printf("Error: Failed to create file %s\n", synchronized_path);
                        continue;
                    }
                    size_t bytes_read;
                    char buffer[4096];
                    while((bytes_read = fread(buffer, 1, sizeof(buffer), source)) > 0) {
                        fwrite(buffer, 1, bytes_read, target);
                    }
                    fclose(source);
                    fclose(target);
                    printf("Synchronized file %s\n", full_path);
                }
            }
        }
    }
    closedir(directory);
}

int main(int argc, char** argv) {
    if(argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }
    const char* path = argv[1];
    synchronize(path);
    printf("File synchronization completed successfully\n");
    return 0;
}