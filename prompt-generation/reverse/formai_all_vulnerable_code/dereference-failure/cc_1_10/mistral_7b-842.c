//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <math.h>

#define BLOCK_SIZE 1024
#define MAX_FILES 10000

struct file_info {
    char name[256];
    off_t size;
};

struct file_info files[MAX_FILES];
int num_files = 0;

void scan_directory(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            scan_directory(full_path);
            continue;
        }

        if (stat(full_path, &file_stat) < 0) {
            perror("Error while getting file info");
            continue;
        }

        if (num_files >= MAX_FILES) {
            printf("Max number of files reached\n");
            break;
        }

        files[num_files].size = file_stat.st_size;
        strcpy(files[num_files].name, entry->d_name);
        num_files++;
    }

    closedir(dir);
}

void print_stats(void) {
    off_t total_size = 0;
    double avg_size, stddev;

    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
    }

    avg_size = (double) total_size / num_files;

    double sum_squares = 0;
    for (int i = 0; i < num_files; i++) {
        sum_squares += pow(files[i].size - avg_size, 2);
    }

    stddev = sqrt(sum_squares / num_files);

    printf("Total size: %lld bytes\n", (long long) total_size);
    printf("Average size: %.2f bytes\n", avg_size);
    printf("Standard deviation: %.2f bytes\n", stddev);

    printf("\nFile\tSize (bytes)\n");
    for (int i = 0; i < num_files; i++) {
        printf("%s\t%lld\n", files[i].name, (long long) files[i].size);
    }
}

int main(void) {
    scan_directory(".");
    print_stats();

    return 0;
}