//FormAI DATASET v1.0 Category: File Synchronizer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void sync_files(char *dir_a, char *dir_b);

int main() {
    // Define directories to synchronize
    char dir_a[] = "/home/user/documents";
    char dir_b[] = "/media/user/externalHDD/documents";
    
    // Call the syncing function
    sync_files(dir_a, dir_b);

    return 0;
}

void sync_files(char *dir_a, char *dir_b) {
    // Initialize directory pointers
    DIR *dp_a, *dp_b;
    struct dirent *entry_a, *entry_b;

    // Open both directories
    dp_a = opendir(dir_a);
    dp_b = opendir(dir_b);

    if (dp_a == NULL || dp_b == NULL) {
        printf("Error opening directories!\n");
        exit(1);
    }

    // Loop through directory A
    while ((entry_a = readdir(dp_a)) != NULL) {
        // Ignore hidden files and directories
        if (entry_a->d_name[0] == '.') {
            continue;
        }

        // Define the file paths
        char filepath_a[100], filepath_b[100];
        sprintf(filepath_a, "%s/%s", dir_a, entry_a->d_name);
        sprintf(filepath_b, "%s/%s", dir_b, entry_a->d_name);

        struct stat stat_a, stat_b;
        // Get the metadata for file A
        if (stat(filepath_a, &stat_a) < 0) {
            printf("Error getting metadata for %s\n", filepath_a);
            exit(1);
        }

        // Check if file exists in directory B
        if (access(filepath_b, F_OK) == 0) {
            // Get the metadata for file B
            if (stat(filepath_b, &stat_b) < 0) {
                printf("Error getting metadata for %s\n", filepath_b);
                exit(1);
            }

            // Check if file A is newer than file B
            if (difftime(stat_a.st_mtime, stat_b.st_mtime) > 0) {
                // Copy file A to directory B
                FILE *file_a = fopen(filepath_a, "r");
                FILE *file_b = fopen(filepath_b, "w");
                char buffer[BUFSIZ];
                size_t n;

                while ((n = fread(buffer, 1, sizeof buffer, file_a)) > 0) {
                    fwrite(buffer, 1, n, file_b);
                }

                fclose(file_a);
                fclose(file_b);

                printf("%s successfully synchronized with %s\n", filepath_a, filepath_b);
            }
        } else {
            // Copy file A to directory B
            FILE *file_a = fopen(filepath_a, "r");
            FILE *file_b = fopen(filepath_b, "w");
            char buffer[BUFSIZ];
            size_t n;

            while ((n = fread(buffer, 1, sizeof buffer, file_a)) > 0) {
                fwrite(buffer, 1, n, file_b);
            }

            fclose(file_a);
            fclose(file_b);

            printf("%s successfully synchronized with %s\n", filepath_a, filepath_b);
        }
    }

    // Close directory A
    closedir(dp_a);

    // Loop through directory B
    while ((entry_b = readdir(dp_b)) != NULL) {
        // Ignore hidden files and directories
        if (entry_b->d_name[0] == '.') {
            continue;
        }

        // Define the file paths
        char filepath_a[100], filepath_b[100];
        sprintf(filepath_a, "%s/%s", dir_a, entry_b->d_name);
        sprintf(filepath_b, "%s/%s", dir_b, entry_b->d_name);

        struct stat stat_a, stat_b;
        // Get the metadata for file B
        if (stat(filepath_b, &stat_b) < 0) {
            printf("Error getting metadata for %s\n", filepath_b);
            exit(1);
        }

        // Check if file exists in directory A
        if (access(filepath_a, F_OK) == -1) {
            // Delete file B
            remove(filepath_b);
            
            printf("%s successfully removed from %s\n", entry_b->d_name, dir_b);
        }
    }

    // Close directory B
    closedir(dp_b);
}