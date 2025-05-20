//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>

// Function to get size of folder
long int folder_size(char* folder_path) {
    long int size = 0;
    DIR* dir = opendir(folder_path);
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {   // Check if entry is a directory
            char path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {  // Ignore current and parent directories
                continue;
            }
            snprintf(path, sizeof(path), "%s/%s", folder_path, entry->d_name);  // Create path to subdirectory
            size += folder_size(path);  // Recursive call to get size of subdirectory
        }
        else {
            char file_path[1024];
            struct stat st;
            snprintf(file_path, sizeof(file_path), "%s/%s", folder_path, entry->d_name);  // Create path to file
            stat(file_path, &st);
            size += st.st_size;  // Add size of file to total size
        }
    }
    closedir(dir);
    return size;
}

// Function to print file/folder details
void print_details(char* path) {
    struct stat st;
    stat(path, &st);

    printf("%s\n", path);
    printf("Size: %ld bytes\n", st.st_size);
    printf("Permissions: %o\n", st.st_mode & 0777);
    printf("Last Modified: %s", ctime(&st.st_mtime));  // Convert last modified time to string format for printing
    printf("\n");
}

// Main function
int main(int argc, char** argv) {
    if (argc != 2) {   // Check if path argument is passed
        printf("Invalid arguments. Format: ./diskanalyzer <path>\n");
        exit(1);
    }

    char* path = argv[1];
    long int size = folder_size(path);
    printf("Total size of '%s': %ld bytes\n\n", path, size);

    DIR* dir = opendir(path);
    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {   // Check if entry is a directory
            char sub_path[1024];
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {  // Ignore current and parent directories
                continue;
            }
            snprintf(sub_path, sizeof(sub_path), "%s/%s", path, entry->d_name);  // Create path to subdirectory
            print_details(sub_path);  // Print details of subdirectory
            long int sub_size = folder_size(sub_path);
            printf("Total size of '%s': %ld bytes\n\n", sub_path, sub_size);
        }
        else {
            char file_path[1024];
            if (strcmp(entry->d_name, ".DS_Store") == 0) {  // Ignore mac specific files
                continue;
            }
            snprintf(file_path, sizeof(file_path), "%s/%s", path, entry->d_name);  // Create path to file
            print_details(file_path);  // Print details of file
        }
    }
    closedir(dir);
    return 0;
}