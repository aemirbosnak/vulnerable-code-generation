//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

#define MB 1048576.0

void analyze_directory(char *path, double *total_size);

int main() {
    char cwd[1024];
    double total_size = 0.0;

    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Analyzing directory %s\n\n", cwd);
        analyze_directory(cwd, &total_size);
        printf("\nTotal disk space used: %.2f MB\n", total_size);
    } else {
        printf("Error getting current directory\n");
    }

    return 0;
}

void analyze_directory(char *path, double *total_size) {
    DIR *directory = opendir(path);
    struct dirent *entry;
    struct stat st;

    if (directory != NULL) {
        while ((entry = readdir(directory)) != NULL) {
            char full_path[1024];

            snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);
            if (stat(full_path, &st) == 0) {
                if (S_ISREG(st.st_mode)) {
                    printf("%-50s  %.2f MB\n", entry->d_name, (double)st.st_size / MB);
                    *total_size += (double)st.st_size / MB;
                } else if (S_ISDIR(st.st_mode)) {
                    if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                        continue;
                    }

                    printf("%s/\n", entry->d_name);
                    analyze_directory(full_path, total_size);
                }
            }
        }

        closedir(directory);
    }
}