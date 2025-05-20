//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/statvfs.h>

// Function to calculate total disk space used by a directory
long long get_directory_size(const char* path) {
    struct statvfs buf;
    if (statvfs(path, &buf) == -1) {
        perror("statvfs");
        exit(EXIT_FAILURE);
    }
    return buf.f_blocks * buf.f_frsize;
}

// Function to print disk space information for a directory
void print_directory_info(const char* path, long long size) {
    printf("Directory: %s\n", path);
    printf("Size: %lld bytes\n", size);
}

// Function to recursively analyze disk space usage
void analyze_directory(const char* path) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        char* full_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
        sprintf(full_path, "%s/%s", path, ent->d_name);

        if (ent->d_type == DT_DIR) {
            analyze_directory(full_path);
        } else {
            long long size = get_directory_size(full_path);
            print_directory_info(full_path, size);
        }

        free(full_path);
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    analyze_directory(argv[1]);

    return 0;
}