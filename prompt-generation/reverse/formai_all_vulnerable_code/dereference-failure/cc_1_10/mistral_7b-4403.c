//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

typedef struct {
    char name[256];
    double size;
} File;

void calculate_directory_size(DIR *dirp, File *files, int *num_files, double *total_size) {
    struct dirent *dp;
    struct stat file_stat;

    while ((dp = readdir(dirp)) != NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        char path[512];
        snprintf(path, sizeof(path), "%s/%s", getcwd(NULL, 0), dp->d_name);

        if (lstat(path, &file_stat) == -1) {
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            File subdir;
            strcpy(subdir.name, dp->d_name);
            subdir.size = file_stat.st_size;

            calculate_directory_size(opendir(path), files, num_files, total_size);
            files[*num_files] = subdir;
            (*num_files)++;
        } else if (S_ISREG(file_stat.st_mode)) {
            File file;
            strcpy(file.name, dp->d_name);
            file.size = file_stat.st_size;

            files[*num_files] = file;
            (*num_files)++;
            (*total_size) += file.size;
        }
    }
}

int main() {
    File files[1024];
    int num_files = 0;
    double total_size = 0.0;

    if (chdir("/") != 0) {
        perror("Error changing directory");
        return 1;
    }

    calculate_directory_size(opendir("."), files, &num_files, &total_size);

    printf("Total disk space used: %.2f bytes\n", total_size);

    for (int i = 0; i < num_files; i++) {
        double percentage = (files[i].size / total_size) * 100.0;

        printf("%s: %.2f bytes (%.2f%%)\n", files[i].name, files[i].size, percentage);
    }

    free(files);

    return 0;
}