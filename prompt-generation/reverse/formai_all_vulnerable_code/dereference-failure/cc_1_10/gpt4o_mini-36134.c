//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void analyze_directory(const char *dirpath, long long *total_size, int *num_files, int *num_dirs);

int main(int argc, char **argv) {
    char *start_dir = ".";
    
    if (argc > 1) {
        start_dir = argv[1];
    }
    
    long long total_size = 0;
    int num_files = 0, num_dirs = 0;

    analyze_directory(start_dir, &total_size, &num_files, &num_dirs);

    printf("Directory: %s\n", start_dir);
    printf("Total Size: %lld bytes\n", total_size);
    printf("Number of Files: %d\n", num_files);
    printf("Number of Directories: %d\n", num_dirs);

    return 0;
}

void analyze_directory(const char *dirpath, long long *total_size, int *num_files, int *num_dirs) {
    DIR *dir;
    struct dirent *entry;
    struct stat entry_info;
    char path[1024];

    if (!(dir = opendir(dirpath))) {
        perror("Unable to open directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip "." and ".."
        }

        snprintf(path, sizeof(path), "%s/%s", dirpath, entry->d_name);
        if (stat(path, &entry_info) == -1) {
            perror("Unable to get entry information");
            continue;
        }
        
        if (S_ISDIR(entry_info.st_mode)) {
            (*num_dirs)++;
            analyze_directory(path, total_size, num_files, num_dirs);
        } else if (S_ISREG(entry_info.st_mode)) {
            (*num_files)++;
            *total_size += entry_info.st_size;
        }
    }
    
    closedir(dir);
}