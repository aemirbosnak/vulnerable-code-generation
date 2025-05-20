//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <dirent.h>

#define MAX_PATH 256
#define MAX_SIZE 1024

struct file {
    char name[MAX_PATH];
    long size;
    time_t mtime;
};

struct file_list {
    struct file *files;
    int count;
    int capacity;
};

struct file_list *create_file_list(int capacity) {
    struct file_list *list = malloc(sizeof(struct file_list));
    if (!list) {
        return NULL;
    }
    list->files = malloc(sizeof(struct file) * capacity);
    if (!list->files) {
        free(list);
        return NULL;
    }
    list->count = 0;
    list->capacity = capacity;
    return list;
}

void free_file_list(struct file_list *list) {
    free(list->files);
    free(list);
}

int add_file_to_list(struct file_list *list, struct file *file) {
    if (list->count == list->capacity) {
        return -1;
    }
    list->files[list->count++] = *file;
    return 0;
}

int compare_files(struct file *file1, struct file *file2) {
    return strcmp(file1->name, file2->name);
}

int sort_file_list(struct file_list *list) {
    qsort(list->files, list->count, sizeof(struct file), (int (*)(const void *, const void *))compare_files);
    return 0;
}

int print_file_list(struct file_list *list) {
    for (int i = 0; i < list->count; i++) {
        printf("%s %ld %ld\n", list->files[i].name, list->files[i].size, list->files[i].mtime);
    }
    return 0;
}

int scan_directory(struct file_list *list, char *path) {
    DIR *dir = opendir(path);
    if (!dir) {
        return -1;
    }
    struct dirent *entry;
    struct stat statbuf;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }
        char filepath[MAX_PATH];
        snprintf(filepath, MAX_PATH, "%s/%s", path, entry->d_name);
        if (stat(filepath, &statbuf) == -1) {
            continue;
        }
        struct file file = {
            .name = entry->d_name,
            .size = statbuf.st_size,
            .mtime = statbuf.st_mtime,
        };
        add_file_to_list(list, &file);
    }
    closedir(dir);
    return 0;
}

int sync_files(struct file_list *list1, struct file_list *list2) {
    sort_file_list(list1);
    sort_file_list(list2);
    int i = 0, j = 0;
    while (i < list1->count && j < list2->count) {
        int cmp = strcmp(list1->files[i].name, list2->files[j].name);
        if (cmp == 0) {
            if (list1->files[i].size != list2->files[j].size || list1->files[i].mtime != list2->files[j].mtime) {
                printf("Update %s\n", list1->files[i].name);
            }
            i++;
            j++;
        } else if (cmp < 0) {
            printf("Delete %s\n", list1->files[i].name);
            i++;
        } else {
            printf("Create %s\n", list2->files[j].name);
            j++;
        }
    }
    while (i < list1->count) {
        printf("Delete %s\n", list1->files[i].name);
        i++;
    }
    while (j < list2->count) {
        printf("Create %s\n", list2->files[j].name);
        j++;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <path1> <path2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    struct file_list *list1 = create_file_list(1024);
    if (!list1) {
        fprintf(stderr, "Error: unable to create file list\n");
        exit(EXIT_FAILURE);
    }
    struct file_list *list2 = create_file_list(1024);
    if (!list2) {
        fprintf(stderr, "Error: unable to create file list\n");
        exit(EXIT_FAILURE);
    }
    scan_directory(list1, argv[1]);
    scan_directory(list2, argv[2]);
    sync_files(list1, list2);
    free_file_list(list1);
    free_file_list(list2);
    return 0;
}