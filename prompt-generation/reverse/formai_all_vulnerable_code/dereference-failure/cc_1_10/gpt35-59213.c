//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: happy
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>

#define KB 1024
#define MB 1048576
#define GB 1073741824

// function prototypes
void analyze_dir(char *dir_path, long int *total_size, long int *dir_size,
                 long int *file_size, int *num_dirs, int *num_files);
void print_results(long int total_size, long int dir_size, long int file_size,
                   int num_dirs, int num_files);

// main function
int main(int argc, char **argv) {
    // check command-line arguments
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    long int total_size = 0;
    long int dir_size = 0;
    long int file_size = 0;
    int num_dirs = 0;
    int num_files = 0;

    // analyze the specified directory
    analyze_dir(argv[1], &total_size, &dir_size, &file_size, &num_dirs, &num_files);

    // print the results
    print_results(total_size, dir_size, file_size, num_dirs, num_files);

    return 0;
}

// recursive function to analyze directory and subdirectories
void analyze_dir(char *dir_path, long int *total_size, long int *dir_size,
                 long int *file_size, int *num_dirs, int *num_files) {
    DIR *dir = opendir(dir_path);
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }
        char full_path[1024];
        sprintf(full_path, "%s/%s", dir_path, entry->d_name);
        struct stat st;
        stat(full_path, &st);
        if (S_ISDIR(st.st_mode)) {
            (*num_dirs)++;
            long int sub_dir_size = 0;
            analyze_dir(full_path, total_size, &sub_dir_size, file_size,
                        num_dirs, num_files);
            (*dir_size) += sub_dir_size;
        } else {
            (*num_files)++;
            long int size = st.st_size;
            (*total_size) += size;
            (*file_size) += size;
        }
    }
    closedir(dir);
}

// function to print the results of disk space analysis
void print_results(long int total_size, long int dir_size, long int file_size,
                   int num_dirs, int num_files) {
    printf("Total space used: %.2f GB\n", (double)total_size / GB);
    printf("Directory space used: %.2f GB (%.2f%%)\n", (double)dir_size / GB,
           (double)dir_size / total_size * 100);
    printf("File space used: %.2f GB (%.2f%%)\n", (double)file_size / GB,
           (double)file_size / total_size * 100);
    printf("Number of directories: %d\n", num_dirs);
    printf("Number of files: %d\n", num_files);
}