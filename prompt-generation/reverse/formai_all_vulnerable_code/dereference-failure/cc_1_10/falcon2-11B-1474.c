//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

void analyze_disk_space(const char* path) {
    // Open directory
    DIR* dir = opendir(path);
    if (dir == NULL) {
        perror("Error opening directory");
        return;
    }

    // Print directory listing
    struct dirent* ent;
    while ((ent = readdir(dir))!= NULL) {
        const char* filename = ent->d_name;
        if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
            continue;
        }

        // Calculate file size
        char filepath[MAX_PATH];
        snprintf(filepath, MAX_PATH, "%s/%s", path, filename);
        struct stat fileinfo;
        if (stat(filepath, &fileinfo) == -1) {
            perror("Error getting file information");
            continue;
        }
        long filesize = fileinfo.st_size;

        // Print file information
        printf("%s (%ld bytes)\n", filename, filesize);
    }

    // Close directory
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Analyze disk space
    analyze_disk_space(argv[1]);

    return 0;
}