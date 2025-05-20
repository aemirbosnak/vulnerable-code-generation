//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

// Function to calculate the disk space used by a directory
long long calculate_directory_size(const char *path) {
    long long directory_size = 0;
    DIR *directory_pointer = opendir(path);
    struct dirent *entry_pointer;
    
    // Iterate through all the entries in the directory
    while ((entry_pointer = readdir(directory_pointer)) != NULL) {
        char entry_path[FILENAME_MAX];
        struct stat entry_information;
        
        // Create the full path of the entry
        sprintf(entry_path, "%s/%s", path, entry_pointer->d_name);
        
        // Get the information of the entry
        if (stat(entry_path, &entry_information) < 0) {
            perror("stat");
            exit(EXIT_FAILURE);
        }
        
        // If the entry is a directory, recurse the function
        if (S_ISDIR(entry_information.st_mode)) {
            if (strcmp(entry_pointer->d_name, ".") == 0 || strcmp(entry_pointer->d_name, "..") == 0) {
                continue;
            }
            directory_size += calculate_directory_size(entry_path);
        } else {
            // Add the size of the file to the directory size
            directory_size += entry_information.st_size;
        }
    }
    
    // Close the directory
    closedir(directory_pointer);
    
    return directory_size;
}

int main(int argc, char *argv[]) {
    // Check if the user provided a path, otherwise use the current directory
    char *path;
    if (argc > 1) {
        path = argv[1];
    } else {
        path = ".";
    }
    
    // Calculate the directory size
    long long directory_size = calculate_directory_size(path);
    
    // Print the result
    printf("The size of the directory '%s' is %lld bytes.\n", path, directory_size);
    
    return 0;
}