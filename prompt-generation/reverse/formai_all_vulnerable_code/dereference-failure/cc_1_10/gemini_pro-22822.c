//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <time.h>

#define MAX_PATH_LEN 1024
#define MAX_FILE_NAME_LEN 256

typedef struct {
    char name[MAX_FILE_NAME_LEN];
    long size;
    time_t mtime;
} file_entry;

struct dir_entry {
    char name[MAX_FILE_NAME_LEN];
    struct dir_entry *parent;
    struct dir_entry *first_child;
    struct dir_entry *next_sibling;
    long size;
    time_t mtime;
};

struct dir_entry *root_dir;
long total_size;
long max_size;
char *max_size_file;
long oldest_mtime;
char *oldest_file;

void add_file_to_dir(struct dir_entry *dir, file_entry *file) {
    struct dir_entry *new_entry = malloc(sizeof(struct dir_entry));
    strcpy(new_entry->name, file->name);
    new_entry->parent = dir;
    new_entry->first_child = NULL;
    new_entry->next_sibling = dir->first_child;
    dir->first_child = new_entry;
    new_entry->size = file->size;
    new_entry->mtime = file->mtime;

    dir->size += file->size;
    if (file->mtime < oldest_mtime) {
        oldest_mtime = file->mtime;
        oldest_file = file->name;
    }
}

void analyze_dir(struct dir_entry *dir) {
    DIR *d = opendir(dir->name);
    if (d == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char path[MAX_PATH_LEN];
        snprintf(path, MAX_PATH_LEN, "%s/%s", dir->name, entry->d_name);

        struct stat statbuf;
        if (lstat(path, &statbuf) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(statbuf.st_mode)) {
            struct dir_entry *new_dir = malloc(sizeof(struct dir_entry));
            strcpy(new_dir->name, entry->d_name);
            new_dir->parent = dir;
            new_dir->first_child = NULL;
            new_dir->next_sibling = NULL;
            new_dir->size = 0;
            new_dir->mtime = statbuf.st_mtime;
            dir->size += statbuf.st_size;
            analyze_dir(new_dir);
        } else {
            file_entry file;
            strcpy(file.name, entry->d_name);
            file.size = statbuf.st_size;
            file.mtime = statbuf.st_mtime;
            add_file_to_dir(dir, &file);
        }
    }

    closedir(d);
}

void print_dir(struct dir_entry *dir, int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%s\n", dir->name);
    for (struct dir_entry *child = dir->first_child; child != NULL; child = child->next_sibling) {
        print_dir(child, depth + 1);
    }
}

void print_summary() {
    printf("Total size: %ld bytes\n", total_size);
    printf("Max size file: %s (%ld bytes)\n", max_size_file, max_size);
    printf("Oldest file: %s (%ld bytes)\n", oldest_file, oldest_mtime);
}

int main() {
    root_dir = malloc(sizeof(struct dir_entry));
    strcpy(root_dir->name, "/");
    root_dir->parent = NULL;
    root_dir->first_child = NULL;
    root_dir->next_sibling = NULL;
    root_dir->size = 0;
    root_dir->mtime = 0;

    analyze_dir(root_dir);

    print_dir(root_dir, 0);
    print_summary();

    return 0;
}