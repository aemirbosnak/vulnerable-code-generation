//GEMINI-pro DATASET v1.0 Category: Antivirus scanner ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdint.h>

#define MAX_SCAN_DEPTH 5

// Signature database
char *signatures[] = {
    "EICAR-STANDARD-ANTIVIRUS-TEST-FILE",
    "W32.Stuxnet.A",
    "W32.Conficker.A",
    "W32.Sality.AE",
    "W32.Zeus.A"
};

// Helper functions
int is_directory(const char *path);
int scan_file(const char *path);
int scan_directory(const char *path, int depth);
void print_results(const char *path, int infected);

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    // Scan the specified path
    int infected = scan_directory(argv[1], 0);

    // Print the results
    print_results(argv[1], infected);

    return 0;
}

// Checks if the specified path is a directory
int is_directory(const char *path) {
    struct stat statbuf;
    if (stat(path, &statbuf) != 0) {
        return 0;
    }
    return S_ISDIR(statbuf.st_mode);
}

// Scans the specified file for viruses
int scan_file(const char *path) {
    // Open the file
    int fd = open(path, O_RDONLY);
    if (fd == -1) {
        return 0;
    }

    // Read the file into a buffer
    char *buffer = malloc(1024);
    if (buffer == NULL) {
        close(fd);
        return 0;
    }
    ssize_t bytes_read = read(fd, buffer, 1024);
    if (bytes_read == -1) {
        free(buffer);
        close(fd);
        return 0;
    }

    // Search the buffer for virus signatures
    for (int i = 0; i < sizeof(signatures) / sizeof(char *); i++) {
        if (strstr(buffer, signatures[i]) != NULL) {
            free(buffer);
            close(fd);
            return 1;
        }
    }

    // No viruses found
    free(buffer);
    close(fd);
    return 0;
}

// Scans the specified directory for viruses
int scan_directory(const char *path, int depth) {
    // Check if the directory exists
    if (!is_directory(path)) {
        return 0;
    }

    // Check if the maximum scan depth has been reached
    if (depth >= MAX_SCAN_DEPTH) {
        return 0;
    }

    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }

    // Scan the directory entries
    struct dirent *entry;
    int infected = 0;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files and directories
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Build the full path to the entry
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        // Check if the entry is a directory
        if (is_directory(full_path)) {
            // Recursively scan the directory
            infected |= scan_directory(full_path, depth + 1);
        } else {
            // Scan the file
            infected |= scan_file(full_path);
        }
    }

    // Close the directory
    closedir(dir);

    // Return whether any viruses were found
    return infected;
}

// Prints the results of the scan
void print_results(const char *path, int infected) {
    if (infected) {
        printf("Viruses found in %s\n", path);
    } else {
        printf("No viruses found in %s\n", path);
    }
}