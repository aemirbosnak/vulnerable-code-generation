//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dirent.h>
#include <sys/stat.h>

#define KB 1024
#define MB (KB * 1024)
#define GB (MB * 1024)

struct disk_space {
    char *path;
    double size;
};

double calculate_size(const char *path) {
    double total_size = 0;
    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR) { // check directory
            if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
                continue;
            }
            char *sub_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
            sprintf(sub_path, "%s/%s", path, ent->d_name);
            total_size += calculate_size(sub_path);
            free(sub_path);
        } else { // file
            char *file_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
            sprintf(file_path, "%s/%s", path, ent->d_name);
            struct stat st;
            if (stat(file_path, &st) == 0) {
                total_size += st.st_size;
            }
            free(file_path);
        }
    }
    closedir(dir);
    return total_size;
}

void display_space(double size) {
    if (size > GB) {
        printf("%.2f GB\n", size / GB);
    } else if (size > MB) {
        printf("%.2f MB\n", size / MB);
    } else if (size > KB) {
        printf("%.2f KB\n", size / KB);
    } else {
        printf("%.2f B\n", size);
    }
}

int compare(const void *a, const void *b) {
    double first = ((struct disk_space *) a)->size;
    double second = ((struct disk_space *) b)->size;
    if (first < second) {
        return 1;
    } else if (first > second) {
        return -1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *path = argv[1];
    double total_size = calculate_size(path);
    display_space(total_size);

    struct disk_space *disk_spaces = malloc(sizeof(struct disk_space));
    int count = 1;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        return 0;
    }

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_DIR || ent->d_type == DT_REG) { // check directory and regular file
            char *sub_path = malloc(strlen(path) + strlen(ent->d_name) + 2);
            sprintf(sub_path, "%s/%s", path, ent->d_name);
            struct disk_space disk_space = { sub_path, calculate_size(sub_path) };
            disk_spaces = realloc(disk_spaces, ++count * sizeof(struct disk_space));
            disk_spaces[count - 1] = disk_space;
        }
    }
    closedir(dir);

    qsort(disk_spaces, count, sizeof(struct disk_space), compare);

    for (int i = 0; i < count - 1; i++) {
        printf("%s : ", disk_spaces[i].path);
        display_space(disk_spaces[i].size);
    }

    for (int i = 0; i < count - 1; i++) {
        free(disk_spaces[i].path); // free memory
    }
    free(disk_spaces);

    return EXIT_SUCCESS;
}