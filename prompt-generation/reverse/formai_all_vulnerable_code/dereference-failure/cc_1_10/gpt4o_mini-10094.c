//GPT-4o-mini DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

void list_files(const char *base_path, const char *relative_path) {
    char path[1024];
    struct dirent *dp;
    struct stat statbuf;
    
    // Open the directory
    DIR *dir = opendir(base_path);
    if (!dir) {
        perror("opendir");
        return;
    }
    
    // Iterate through the directory entries
    while ((dp = readdir(dir)) != NULL) {
        // Ignore the special entries "." and ".."
        if (strcmp(dp->d_name, ".") != 0 && strcmp(dp->d_name, "..") != 0) {
            // Create the full path
            snprintf(path, sizeof(path), "%s/%s", base_path, dp->d_name);
            
            // Get file status
            if (stat(path, &statbuf) == -1) {
                perror("stat");
                continue;
            }
            
            // Print relative path
            printf("%s/%s\n", relative_path, dp->d_name);
            
            // If entry is a directory, recursively list its contents
            if (S_ISDIR(statbuf.st_mode)) {
                // Recursive call
                list_files(path, strcat(strdup(relative_path), strcat("/", dp->d_name)));
            }
        }
    }
    
    // Close the directory
    closedir(dir);
}

int main(int argc, char *argv[]) {
    // Check if the user has provided a path
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory-path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    printf("Listing files in directory: %s\n", argv[1]);
    list_files(argv[1], "");
    
    return EXIT_SUCCESS;
}