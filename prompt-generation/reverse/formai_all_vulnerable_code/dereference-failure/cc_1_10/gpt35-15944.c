//FormAI DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>

// Function to get the modified time of a file
time_t get_mod_time(const char* path) {
    struct stat attr;
    stat(path, &attr);
    return attr.st_mtime;
}

// Function to check if two files are the same
bool same_file(const char* path1, const char* path2) {
    return (strcmp(path1, path2) == 0) && (get_mod_time(path1) == get_mod_time(path2));
}

// Function to copy a file from one directory to another
void copy_file(const char* path_src, const char* path_dest) {
    FILE* src = fopen(path_src, "rb");
    FILE* dest = fopen(path_dest, "wb");
    if (src == NULL || dest == NULL) {
        printf("Error opening file!\n");
        return;
    }
    char buffer[1024];
    size_t n = 0;
    while ((n = fread(buffer, sizeof(char), sizeof(buffer), src)) > 0) {
        fwrite(buffer, sizeof(char), n, dest);
    }
    fclose(src);
    fclose(dest);
}

// Function to synchronize two directories
void sync_directories(const char* dir1, const char* dir2) {
    struct dirent* ent;
    DIR* dir = opendir(dir1);
    if (dir == NULL) {
        printf("Error opening directory!\n");
        return;
    }
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        char path1[256], path2[256];
        sprintf(path1, "%s/%s", dir1, ent->d_name);
        sprintf(path2, "%s/%s", dir2, ent->d_name);
        if (ent->d_type == DT_REG) {
            if (!same_file(path1, path2)) {
                copy_file(path1, path2);
                printf("Copied %s to %s\n", path1, path2);
            }
        } else if (ent->d_type == DT_DIR) {
            sync_directories(path1, path2);
        }
    }
    closedir(dir);
}

// Main function to synchronize two directories in real time
int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: sync_dir <dir1> <dir2>\n");
        return 1;
    }
    while (true) {
        sync_directories(argv[1], argv[2]);
        sleep(5); // synchronizes directories every 5 seconds
    }
    return 0;
}