//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: sophisticated
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

long long int total_size = 0;

void analyze_directory(const char* folder_path, const int depth, const int max_depth) {
    DIR* dir;
    struct dirent *dp;
    struct stat st;

    if ((dir = opendir(folder_path)) == NULL) {
        printf("Could not open directory: %s\n", folder_path);
        return;
    }

    while ((dp = readdir(dir)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        char path[PATH_MAX];
        sprintf(path, "%s/%s", folder_path, dp->d_name);
        if (stat(path, &st) == -1) {
            printf("Could not stat file: %s\n", path);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (max_depth == -1 || depth < max_depth) {
                analyze_directory(path, depth + 1, max_depth);
            }
        } else {
            printf("%lld bytes: %s\n", st.st_size, path);
            total_size += st.st_size;
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <folder path> [max depth]\n", argv[0]);
        return 0;
    }

    int max_depth = -1;
    if (argc >= 3) {
        max_depth = atoi(argv[2]);
    }

    analyze_directory(argv[1], 0, max_depth);

    printf("\nTotal size of all files: ");
    if (total_size >= GB) {
        printf("%lld GB", total_size / GB);
    } else if (total_size >= MB) {
        printf("%lld MB", total_size / MB);
    } else if (total_size >= KB) {
        printf("%lld KB", total_size / KB);
    } else {
        printf("%lld bytes", total_size);
    }
    printf("\n");

    return 0;
}