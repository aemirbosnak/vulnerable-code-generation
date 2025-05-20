//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>

#define PATH_MAX_LENGTH 4096

struct File {
    char *name;
    long size;
};

struct Directory {
    char *name;
    long size;
    struct File *files;
    struct Directory *directories;
};

/* Removes whitespace from both ends of a string. */
void trim(char *s) {
    char *start = s;
    char *end = s + strlen(s) - 1;

    while (isspace(*start)) {
        start++;
    }

    while (isspace(*end)) {
        end--;
    }

    *(end + 1) = '\0';

    memmove(s, start, end - start + 2);
}

/* Returns the size of a file in bytes. */
long get_file_size(char *path) {
    struct stat st;

    if (stat(path, &st) == 0) {
        return st.st_size;
    } else {
        return -1;
    }
}

/* Returns the size of a directory in bytes. */
long get_directory_size(char *path) {
    long size = 0;
    DIR *dir = opendir(path);

    if (dir != NULL) {
        struct dirent *dp;

        while ((dp = readdir(dir)) != NULL) {
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
                continue;
            }

            char *child_path = malloc(sizeof(char) * PATH_MAX_LENGTH);
            snprintf(child_path, PATH_MAX_LENGTH, "%s/%s", path, dp->d_name);

            if (dp->d_type == DT_DIR) {
                long child_size = get_directory_size(child_path);
                size += child_size;
            } else if (dp->d_type == DT_REG) {
                long child_size = get_file_size(child_path);

                if (child_size > 0) {
                    size += child_size;
                }
            }

            free(child_path);
        }

        closedir(dir);
    }

    return size;
}

/* Returns an array of files and directories in a directory. */
void get_children(char *path, struct File **files, int *num_files, struct Directory **directories, int *num_directories) {
    DIR *dir = opendir(path);

    if (dir != NULL) {
        struct dirent *dp;

        while ((dp = readdir(dir)) != NULL) {
            if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
                continue;
            }

            char *child_path = malloc(sizeof(char) * PATH_MAX_LENGTH);
            snprintf(child_path, PATH_MAX_LENGTH, "%s/%s", path, dp->d_name);

            if (dp->d_type == DT_DIR) {
                *num_directories += 1;
                *directories = realloc(*directories, sizeof(struct Directory) * (*num_directories));
                struct Directory *new_directory = &(*directories)[*num_directories - 1];
                new_directory->name = strdup(dp->d_name);
                new_directory->size = get_directory_size(child_path);
                new_directory->files = NULL;
                new_directory->directories = NULL;
            } else if (dp->d_type == DT_REG) {
                long size = get_file_size(child_path);

                if (size > 0) {
                    *num_files += 1;
                    *files = realloc(*files, sizeof(struct File) * (*num_files));
                    struct File *new_file = &(*files)[*num_files - 1];
                    new_file->name = strdup(dp->d_name);
                    new_file->size = size;
                }
            }

            free(child_path);
        }

        closedir(dir);
    }
}

/* Returns a string with the size of a file or directory formatted with the appropriate units. */
char *format_size(long size) {
    const char *units[] = {"B", "KB", "MB", "GB", "TB"};
    int i;

    for (i = 0; size > 1024 && i < sizeof(units) / sizeof(char *) - 1; i++) {
        size /= 1024;
    }

    char *result = malloc(sizeof(char) * 16);
    snprintf(result, 16, "%ld %s", size, units[i]);

    return result;
}

/* Prints the contents of a directory and its sizes recursively. */
void print_directory(char *path, int depth) {
    struct File *files = NULL;
    int num_files = 0;
    struct Directory *directories = NULL;
    int num_directories = 0;

    get_children(path, &files, &num_files, &directories, &num_directories);

    struct Directory *parent_directory = NULL;

    if (depth > 0) {
        parent_directory = malloc(sizeof(struct Directory));
        parent_directory->size = get_directory_size(path);
        parent_directory->name = path;
    }

    int i;

    for (i = 0; i < depth; i++) {
        printf("|  ");
    }

    if (depth > 0) {
        printf("|--");
    }

    printf("%s (%s)\n", path, format_size(get_directory_size(path)));

    for (i = 0; i < num_files; i++) {
        struct File *file = &files[i];

        for (int j = 0; j < depth + 1; j++) {
            printf("|  ");
        }

        printf("|--%s (%s)\n", file->name, format_size(file->size));
    }

    for (i = 0; i < num_directories; i++) {
        struct Directory *directory = &directories[i];
        print_directory(directory->name, depth + 1);

        for (int j = 0; j < depth + 1; j++) {
            printf("|  ");
        }

        printf("|--%s (%s)\n", directory->name, format_size(directory->size));
    }

    free(files);

    for (i = 0; i < num_directories; i++) {
        struct Directory *directory = &directories[i];
        free(directory->name);
        free(directory->files);
        free(directory->directories);
    }

    free(directories);
    free(parent_directory);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char *path = argv[1];
    trim(path);
    print_directory(path, 0);

    return 0;
}