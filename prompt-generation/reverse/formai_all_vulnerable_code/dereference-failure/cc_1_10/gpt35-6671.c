//FormAI DATASET v1.0 Category: System administration ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to recursively delete files and directories
void recursiveDelete(char* path) {

    DIR* dp = opendir(path);
    struct dirent* entry;

    while ((entry = readdir(dp))) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            // Skip '.' and '..' directories
            continue;
        }

        char fullname[strlen(path) + 1 + strlen(entry->d_name)];
        sprintf(fullname, "%s/%s", path, entry->d_name);

        struct stat filestat;
        stat(fullname, &filestat);

        // Recursively delete directories
        if (S_ISDIR(filestat.st_mode)) {
            recursiveDelete(fullname);
            rmdir(fullname);
        } else {
            // Delete files
            remove(fullname);
        }
    }

    closedir(dp);
}

int main(int argc, char* argv[]) {

    if (argc != 2) {
        printf("Usage: rmr <path>\n");
        exit(1);
    }

    char* path = argv[1];

    struct stat filestat;
    if (stat(path, &filestat) != 0) {
        printf("Unable to stat file or directory.\n");
        exit(1);
    }

    if (S_ISDIR(filestat.st_mode)) {
        // Delete directory recursively
        recursiveDelete(path);
        rmdir(path);
        printf("Directory '%s' and all its contents deleted.\n", path);
    } else {
        // Delete file
        remove(path);
        printf("File '%s' deleted.\n", path);
    }

    return 0;
}