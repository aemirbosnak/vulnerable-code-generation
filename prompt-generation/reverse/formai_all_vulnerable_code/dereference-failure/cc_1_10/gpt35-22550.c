//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define KILO_BYTE 1024
#define MEGA_BYTE (KILO_BYTE * 1024)
#define GIGA_BYTE (MEGA_BYTE * 1024)

typedef struct file_node {
    char *name;
    long size;
    struct file_node *next;
} file_node;

typedef struct directory {
    char *name;
    long size;
    file_node *files;
    struct directory *subdirs;
    struct directory *next;
} directory;

int analyze_directory(directory *dir) {
    DIR *d = opendir(dir->name);
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (strncmp(entry->d_name, ".", 1) == 0 || strncmp(entry->d_name, "..", 2) == 0) {
            continue;
        }
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", dir->name, entry->d_name);
        struct stat statbuf;
        if (stat(path, &statbuf) == -1) {
            perror("stat");
            continue;
        }
        if (S_ISDIR(statbuf.st_mode)) {
            directory *subdir = (directory*)malloc(sizeof(directory));
            if (subdir == NULL) {
                perror("malloc");
                continue;
            }
            subdir->name = strdup(path);
            subdir->size = 0;
            subdir->files = NULL;
            subdir->subdirs = NULL;
            subdir->next = NULL;
            if (dir->subdirs == NULL) {
                dir->subdirs = subdir;
            } else {
                directory *last = dir->subdirs;
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = subdir;
            }
            analyze_directory(subdir);
        } else {
            file_node *fnode = (file_node*)malloc(sizeof(file_node));
            if (fnode == NULL) {
                perror("malloc");
                continue;
            }
            fnode->name = strdup(path);
            fnode->size = statbuf.st_size;
            fnode->next = NULL;
            if (dir->files == NULL) {
                dir->files = fnode;
            } else {
                file_node *last = dir->files;
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = fnode;
            }
            dir->size += fnode->size;
        }
    }
    closedir(d);
    return 0;
}

void print_size(long size) {
    if (size >= GIGA_BYTE) {
        printf("%.2f GB", (double)size / GIGA_BYTE);
    } else if (size >= MEGA_BYTE) {
        printf("%.2f MB", (double)size / MEGA_BYTE);
    } else if (size >= KILO_BYTE) {
        printf("%.2f KB", (double)size / KILO_BYTE);
    } else {
        printf("%ld B", size);
    }
}

void print_files(file_node *files) {
    file_node *fnode = files;
    while (fnode != NULL) {
        printf("  - %s: ", fnode->name);
        print_size(fnode->size);
        printf("\n");
        fnode = fnode->next;
    }
}

void print_subdirs(directory *subdirs) {
    directory *subdir = subdirs;
    while (subdir != NULL) {
        printf("%s\n", subdir->name);
        printf("  files:\n");
        print_files(subdir->files);
        printf("  subdirs:\n");
        print_subdirs(subdir->subdirs);
        printf("  total size: ");
        print_size(subdir->size);
        printf("\n");
        subdir = subdir->next;
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }
    directory root;
    root.name = argv[1];
    root.size = 0;
    root.files = NULL;
    root.subdirs = NULL;
    analyze_directory(&root);
    printf("%s\n", root.name);
    printf("  files:\n");
    print_files(root.files);
    printf("  subdirs:\n");
    print_subdirs(root.subdirs);
    printf("total size: ");
    print_size(root.size);
    printf("\n");
    return 0;
}