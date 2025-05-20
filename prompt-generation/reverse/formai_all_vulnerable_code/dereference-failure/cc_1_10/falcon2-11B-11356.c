//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

struct file_system {
    char *root;
    char *working_dir;
    int num_files;
    int num_dirs;
    char *dir_contents[100];
};

struct file_system *create_fs(char *root, char *working_dir) {
    struct file_system *fs = malloc(sizeof(struct file_system));
    if (!fs) {
        fprintf(stderr, "Error allocating memory for file system\n");
        exit(1);
    }
    fs->root = root;
    fs->working_dir = working_dir;
    fs->num_files = 0;
    fs->num_dirs = 0;
    return fs;
}

int add_file(struct file_system *fs, char *path, int mode, size_t size) {
    if (strcmp(path, ".") == 0 || strcmp(path, "..") == 0) {
        fprintf(stderr, "Error: invalid file path\n");
        return -1;
    }
    if (strlen(path) >= sizeof(fs->dir_contents[0]) - 1) {
        fprintf(stderr, "Error: file path is too long\n");
        return -1;
    }
    int len = strlen(fs->working_dir) + strlen(path) + 2; // 2 for "/"
    char *new_path = malloc(len * sizeof(char));
    if (!new_path) {
        fprintf(stderr, "Error allocating memory for file path\n");
        return -1;
    }
    strcpy(new_path, fs->working_dir);
    strcat(new_path, "/");
    strcat(new_path, path);
    DIR *dir;
    struct dirent *ent;
    if (dir = opendir(new_path)) {
        closedir(dir);
        return -1;
    }
    struct stat st;
    if (stat(new_path, &st)!= 0) {
        if (errno == ENOENT) {
            if (mkdir(new_path, mode)!= 0) {
                fprintf(stderr, "Error creating directory: %s\n", strerror(errno));
                return -1;
            }
            fs->num_dirs++;
            fs->dir_contents[fs->num_dirs] = malloc(strlen(new_path) * sizeof(char));
            if (!fs->dir_contents[fs->num_dirs]) {
                fprintf(stderr, "Error allocating memory for directory contents\n");
                return -1;
            }
            strcpy(fs->dir_contents[fs->num_dirs], new_path);
            fs->num_dirs++;
        } else {
            fprintf(stderr, "Error creating file: %s\n", strerror(errno));
            return -1;
        }
    } else {
        fprintf(stderr, "Error creating file: %s\n", strerror(errno));
        return -1;
    }
    free(new_path);
    return 0;
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <root_dir>\n", argv[0]);
        exit(1);
    }
    char *root_dir = argv[1];
    struct file_system *fs = create_fs(root_dir, "");
    if (!fs) {
        fprintf(stderr, "Error creating file system\n");
        exit(1);
    }
    char *path = ".";
    int mode = 0777;
    size_t size = 0;
    if (argc == 3) {
        path = argv[2];
        mode = atoi(argv[3]);
        size = atoi(argv[4]);
    }
    if (add_file(fs, path, mode, size) < 0) {
        fprintf(stderr, "Error adding file to file system\n");
        exit(1);
    }
    char *working_dir = ".";
    int num_entries;
    char **entries;
    if (argc == 4) {
        working_dir = argv[2];
        num_entries = atoi(argv[3]);
    }
    entries = malloc(num_entries * sizeof(char *));
    if (!entries) {
        fprintf(stderr, "Error allocating memory for directory contents\n");
        exit(1);
    }
    for (int i = 0; i < num_entries; i++) {
        entries[i] = malloc(strlen(working_dir) * sizeof(char));
        if (!entries[i]) {
            fprintf(stderr, "Error allocating memory for directory contents\n");
            exit(1);
        }
        strcpy(entries[i], working_dir);
        strcat(entries[i], "/");
        strcat(entries[i], "entry");
        add_file(fs, entries[i], 0777, 0);
    }
    free(entries);
    char *dir_contents_str[fs->num_dirs];
    for (int i = 0; i < fs->num_dirs; i++) {
        dir_contents_str[i] = malloc(strlen(fs->dir_contents[i]) * sizeof(char));
        if (!dir_contents_str[i]) {
            fprintf(stderr, "Error allocating memory for directory contents\n");
            exit(1);
        }
        strcpy(dir_contents_str[i], fs->dir_contents[i]);
    }
    for (int i = 0; i < fs->num_dirs; i++) {
        printf("%s\n", dir_contents_str[i]);
    }
    free(dir_contents_str);
    return 0;
}