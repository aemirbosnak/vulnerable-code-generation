//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>

// Data structures
typedef struct {
    char *name;
    long long size;
    time_t last_modified;
} FileData;

// Function declarations
FileData* get_file_data(const char *path);
void free_file_data(FileData *data);
void print_file_data(const FileData *data);
void analyze_directory(const char *path);

// Main function
int main(int argc, char **argv) {
    // Check arguments
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Analyze the directory
    analyze_directory(argv[1]);

    return EXIT_SUCCESS;
}

// Get file data
FileData* get_file_data(const char *path) {
    // Allocate memory for the data
    FileData *data = malloc(sizeof(FileData));
    if (data == NULL) {
        return NULL;
    }

    // Get file size and last modified time
    struct stat st;
    if (stat(path, &st) != 0) {
        free(data);
        return NULL;
    }

    // Set the data
    data->name = strdup(path);
    data->size = st.st_size;
    data->last_modified = st.st_mtime;

    return data;
}

// Free file data
void free_file_data(FileData *data) {
    // Free the memory
    free(data->name);
    free(data);
}

// Print file data
void print_file_data(const FileData *data) {
    // Print the data
    printf("%-20s %10lld %s", data->name, data->size, ctime(&data->last_modified));
}

// Analyze directory
void analyze_directory(const char *path) {
    // Open the directory
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    // Read the directory
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        // Skip hidden files
        if (entry->d_name[0] == '.') {
            continue;
        }

        // Get the file data
        FileData *data = get_file_data(entry->d_name);
        if (data == NULL) {
            continue;
        }

        // Print the file data
        print_file_data(data);
        
        // Free the data
        free_file_data(data);
    }

    // Close the directory
    closedir(dir);
}