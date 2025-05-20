//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

// Function to recursively scan a directory for viruses
int scan_directory(char *path) {
    DIR *dir;
    struct dirent *entry;
    int status = 0;

    // Open the directory
    dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return -1;
    }

    // Read the directory entries
    while ((entry = readdir(dir)) != NULL) {
        // Ignore the current and parent directories
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        // Check if the entry is a directory
        if (entry->d_type == DT_DIR) {
            // Recursively scan the directory
            status = scan_directory(entry->d_name);
            if (status != 0) {
                break;
            }
        } else {
            // Check if the file is a virus
            if (is_virus(entry->d_name)) {
                // The file is a virus, so delete it
                remove(entry->d_name);
            }
        }
    }

    // Close the directory
    closedir(dir);

    return status;
}

// Function to check if a file is a virus
int is_virus(char *filename) {
    // Open the file
    FILE *file;
    file = fopen(filename, "r");
    if (file == NULL) {
        perror("fopen");
        return -1;
    }

    // Read the file into a buffer
    char buffer[1024];
    int bytes_read = fread(buffer, 1, sizeof(buffer), file);
    if (bytes_read < 0) {
        perror("fread");
        return -1;
    }

    // Close the file
    fclose(file);

    // Search the buffer for the virus signature
    char *signature = "VIRUS";
    char *result = strstr(buffer, signature);
    if (result != NULL) {
        // The virus signature was found, so the file is a virus
        return 1;
    } else {
        // The virus signature was not found, so the file is not a virus
        return 0;
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check if a path was provided
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return -1;
    }

    // Scan the directory recursively
    int status = scan_directory(argv[1]);
    if (status != 0) {
        printf("Error scanning directory: %s\n", argv[1]);
        return -1;
    }

    // Return success
    return 0;
}