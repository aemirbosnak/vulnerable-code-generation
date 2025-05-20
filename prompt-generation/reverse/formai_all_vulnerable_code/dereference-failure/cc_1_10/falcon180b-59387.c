//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_FILE_NAME_LENGTH 1024

// Function to compare file names (for sorting)
int compare_names(const void *a, const void *b) {
    return strcmp(*(char **)a, *(char **)b);
}

// Function to get file size in human-readable format
char *get_file_size(unsigned long long size) {
    static char buffer[32];
    if (size == 0) {
        strcpy(buffer, "0 B");
    } else if (size < 1024) {
        sprintf(buffer, "%lu B", size);
    } else if (size < 1048576) {
        sprintf(buffer, "%.2f KB", (double)size / 1024);
    } else if (size < 1073741824) {
        sprintf(buffer, "%.2f MB", (double)size / (1024 * 1024));
    } else {
        sprintf(buffer, "%.2f GB", (double)size / (1024 * 1024 * 1024));
    }
    return buffer;
}

// Function to print file information
void print_file_info(const char *path, unsigned long long size) {
    printf("%s (%s)\n", path, get_file_size(size));
}

// Function to analyze disk space usage
void analyze_disk_space(const char *directory) {
    DIR *d;
    struct dirent *dir;
    d = opendir(directory);

    if (d) {
        char **files = NULL;
        unsigned int num_files = 0;

        while ((dir = readdir(d))!= NULL) {
            files = realloc(files, sizeof(char *) * ++num_files);
            files[num_files - 1] = strdup(dir->d_name);
        }

        // Sort files by name
        qsort(files, num_files, sizeof(char *), compare_names);

        // Print file information
        for (unsigned int i = 0; i < num_files; i++) {
            char path[MAX_FILE_NAME_LENGTH];
            snprintf(path, MAX_FILE_NAME_LENGTH, "%s/%s", directory, files[i]);
            struct stat st;
            if (stat(path, &st) == 0) {
                if (S_ISDIR(st.st_mode)) {
                    printf("Directory: %s\n", path);
                } else {
                    print_file_info(path, st.st_size);
                }
            }
            free(files[i]);
        }
        free(files);

        closedir(d);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1]);

    return 0;
}