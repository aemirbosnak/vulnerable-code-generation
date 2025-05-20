//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdbool.h>

// Returns true if the file names are equal, false otherwise
bool file_names_equal(char* file_name1, char* file_name2) {
    if (strcmp(file_name1, file_name2) == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Directory paths to synchronize
    char* directory1 = "dir1/";
    char* directory2 = "dir2/";

    // Open the directories
    DIR* dir1 = opendir(directory1);
    DIR* dir2 = opendir(directory2);

    // Ensure directories exist and can be opened
    if (dir1 == NULL) {
        printf("Could not open directory %s\n", directory1);
        return 1;
    }
    if (dir2 == NULL) {
        printf("Could not open directory %s\n", directory2);
        return 1;
    }

    // Loop through files in directory 1
    struct dirent* file_entry1;
    while ((file_entry1 = readdir(dir1)) != NULL) {
        // Ignore the current directory and parent directory entries
        if (strcmp(file_entry1->d_name, ".") != 0 && strcmp(file_entry1->d_name, "..") != 0) {
            // Loop through files in directory 2
            struct dirent* file_entry2;
            while ((file_entry2 = readdir(dir2)) != NULL) {
                // Ignore the current directory and parent directory entries
                if (strcmp(file_entry2->d_name, ".") != 0 && strcmp(file_entry2->d_name, "..") != 0) {
                    // Check if the file names are equal
                    if (file_names_equal(file_entry1->d_name, file_entry2->d_name)) {
                        // TODO: Check if the file contents are equal
                        // If the file names and contents are not equal, update the file in directory 2
                        printf("File %s is out of sync, updating...\n", file_entry2->d_name);
                    }
                }
            }
        }
    }

    // Close the directories
    closedir(dir1);
    closedir(dir2);

    return 0;
}