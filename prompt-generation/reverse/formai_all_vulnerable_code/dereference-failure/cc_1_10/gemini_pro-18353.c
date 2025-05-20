//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>
#include <math.h>

// Function to get the size of a file
long long int get_file_size(const char *filename) {
    struct stat st;
    stat(filename, &st);
    return st.st_size;
}

// Function to get the size of a directory
long long int get_dir_size(const char *dirname) {
    DIR *dir = opendir(dirname);
    struct dirent *entry;
    long long int size = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char path[strlen(dirname) + strlen(entry->d_name) + 2];
        sprintf(path, "%s/%s", dirname, entry->d_name);
        if (entry->d_type == DT_DIR) {
            size += get_dir_size(path);
        } else {
            size += get_file_size(path);
        }
    }
    closedir(dir);
    return size;
}

// Function to print the size of a file or directory
void print_size(const char *path, long long int size) {
    printf("%-8s %s\n", size, path);
}

int main() {
    // Get the size of the C drive
    char *path = "C:\\";
    long long int size = get_dir_size(path);

    // Print the size of the C drive
    print_size(path, size);

    return 0;
}