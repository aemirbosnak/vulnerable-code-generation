//FormAI DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to check if file exists
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

// Function to synchronize two directories
void directory_synchronizer(const char *dir1, const char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *p1, *p2;
    struct stat info1, info2;
    char dir1_path[256], dir2_path[256];
    int dir1_len = strlen(dir1), dir2_len = strlen(dir2);

    // Open both directories
    if ((dp1 = opendir(dir1)) == NULL) {
        printf("Error: could not open directory %s\n", dir1);
        return;
    } else if ((dp2 = opendir(dir2)) == NULL) {
        printf("Error: could not open directory %s\n", dir2);
        closedir(dp1);
        return;
    }

    // Loop through all files in dir1
    while ((p1 = readdir(dp1)) != NULL) {
        if (strcmp(p1->d_name, ".") == 0 || strcmp(p1->d_name, "..") == 0) continue;

        // Construct full file paths
        snprintf(dir1_path, sizeof(dir1_path), "%s/%s", dir1, p1->d_name);
        snprintf(dir2_path, sizeof(dir2_path), "%s/%s", dir2, p1->d_name);

        // Check if file exists in dir2
        if (file_exists(dir2_path)) {
            // Check file modification times
            stat(dir1_path, &info1);
            stat(dir2_path, &info2);
            if (info1.st_mtime > info2.st_mtime) {
                // File in dir1 is newer, so copy to dir2
                char command[256];
                snprintf(command, sizeof(command), "cp %s %s", dir1_path, dir2_path);
                system(command);
                printf("Copied %s to %s\n", dir1_path, dir2_path);
            } else if (info1.st_mtime < info2.st_mtime) {
                // File in dir2 is newer, so copy to dir1
                char command[256];
                snprintf(command, sizeof(command), "cp %s %s", dir2_path, dir1_path);
                system(command);
                printf("Copied %s to %s\n", dir2_path, dir1_path);
            }
        } else {
            // File does not exist in dir2, so copy from dir1
            char command[256];
            snprintf(command, sizeof(command), "cp %s %s", dir1_path, dir2);
            system(command);
            printf("Copied %s to %s\n", dir1_path, dir2);
        }
    }

    // Loop through all files in dir2
    while ((p2 = readdir(dp2)) != NULL) {
        if (strcmp(p2->d_name, ".") == 0 || strcmp(p2->d_name, "..") == 0) continue;

        // Construct full file paths
        snprintf(dir2_path, sizeof(dir2_path), "%s/%s", dir2, p2->d_name);
        snprintf(dir1_path, sizeof(dir1_path), "%s/%s", dir1, p2->d_name);

        // Check if file exists in dir1
        if (!file_exists(dir1_path)) {
            // File does not exist in dir1, so copy from dir2
            char command[256];
            snprintf(command, sizeof(command), "cp %s %s", dir2_path, dir1);
            system(command);
            printf("Copied %s to %s\n", dir2_path, dir1);
        }
    }

    // Close directories
    closedir(dp1);
    closedir(dp2);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s [directory1] [directory2]\n", argv[0]);
        return -1;
    }

    const char *dir1 = argv[1];
    const char *dir2 = argv[2];

    printf("Synchronizing directories %s and %s...\n", dir1, dir2);
    directory_synchronizer(dir1, dir2);
    printf("Done.\n");

    return 0;
}