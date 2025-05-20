//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/* File and directory struct */
struct file {
    char name[255];
    double size;
};

/* Function to get size of file/directory */
double get_size(char* path) {
    struct stat st;
    if (stat(path, &st) == 0) {
        if (S_ISDIR(st.st_mode)) {
            double total_size = 0;
            DIR *dir;
            struct dirent *entry;
            char file_path[255];
            dir = opendir(path);
            if (dir == NULL) {
                printf("Error opening directory '%s'\n", path);
                exit(EXIT_FAILURE);
            }
            while ((entry = readdir(dir)) != NULL) {
                if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                    sprintf(file_path, "%s/%s", path, entry->d_name);
                    total_size += get_size(file_path);
                }
            }
            closedir(dir);
            return total_size;
        }
        else {
            return (double) st.st_size;
        }
    }
    return 0;
}

/* Function to sort files and directories by size */
int size_sort(const void* a, const void* b) {
    const struct file *file1 = *(const struct file **)a;
    const struct file *file2 = *(const struct file **)b;
    if (file1->size > file2->size) {
        return -1;
    }
    else if (file1->size < file2->size) {
        return 1;
    }
    else {
        return 0;
    }
}

int main(int argc, char **argv) {
    char *path;
    if (argc == 2) {
        path = argv[1];
    }
    else {
        path = ".";
    }
    double total_size = get_size(path);
    printf("Total disk usage: %f MB\n\n", total_size / (1024 * 1024));
    int num_files = 0;
    DIR *dir;
    struct dirent *entry;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory '%s'\n", path);
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            num_files++;
        }
    }
    closedir(dir);
    printf("Number of files in '%s': %d\n\n", path, num_files);
    struct file** files = malloc(num_files * sizeof(struct file*));
    int i = 0;
    dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory '%s'\n", path);
        exit(EXIT_FAILURE);
    }
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_REG) {
            char file_path[255];
            sprintf(file_path, "%s/%s", path, entry->d_name);
            files[i] = malloc(sizeof(struct file));
            strcpy(files[i]->name, entry->d_name);
            files[i]->size = get_size(file_path);
            i++;
        }
    }
    closedir(dir);
    qsort(files, num_files, sizeof(struct file*), size_sort);
    printf("Files sorted by size:\n\n");
    for (i = 0; i < num_files; i++) {
        printf("%s - %f MB\n", files[i]->name, files[i]->size / (1024 * 1024));
    }
    return 0;
}