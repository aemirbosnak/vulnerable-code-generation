//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <math.h>

#define KB 1024.0
#define MB (KB * 1024.0)
#define GB (MB * 1024.0)

void analyze_dir(const char* dir_path, long long* total_size)
{
    DIR* dir = opendir(dir_path);

    if(!dir) {
        printf("Failed to open directory %s.\n", dir_path);
        exit(EXIT_FAILURE);
    }

    struct dirent* curr_file = NULL;
    char file_path[256];

    while((curr_file = readdir(dir)) != NULL)
    {
        if(curr_file->d_type == DT_DIR && strcmp(curr_file->d_name, ".") != 0 && strcmp(curr_file->d_name, "..") != 0)
        {
            // Recursively analyze sub-directory
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, curr_file->d_name);
            analyze_dir(file_path, total_size);
        }
        else
        {
            // Analyze file size
            snprintf(file_path, sizeof(file_path), "%s/%s", dir_path, curr_file->d_name);
            struct stat s;
            if(stat(file_path, &s) == 0) {
                *total_size += s.st_size;
            }
        }
    }

    closedir(dir);
}

int main(int argc, char* argv[])
{
    // Need one command-line argument, the path to analyze
    if(argc < 2) {
        printf("Usage: %s <path to analyze>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char* dir_path = argv[1];

    long long total_size = 0;
    analyze_dir(dir_path, &total_size);

    printf("Total size of directory %s:\n", dir_path);
    if(total_size < KB)
    {
        printf("%lld bytes\n", total_size);
    }
    else if(total_size < MB)
    {
        printf("%.2f KB\n", ceil(total_size / KB * 100) / 100);
    }
    else if(total_size < GB)
    {
        printf("%.2f MB\n", ceil(total_size / MB * 100) / 100);
    }
    else
    {
        printf("%.2f GB\n", ceil(total_size / GB * 100) / 100);
    }

    exit(EXIT_SUCCESS);
}