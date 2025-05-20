//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>

// Colors
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define BLUE "\033[0;34m"
#define WHITE "\033[0;37m"

// File types
#define FILE_TYPE_FILE "File"
#define FILE_TYPE_DIR "Directory"
#define FILE_TYPE_LINK "Link"
#define FILE_TYPE_OTHER "Other"

// Data structures
typedef struct {
    char *name;
    char *path;
    long long size;
    char *type;
} File;

typedef struct {
    File *files;
    int num_files;
} FileList;

// Function declarations
FileList *get_files(const char *path);
void print_files(FileList *files);
void free_files(FileList *files);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <path>\n", argv[0]);
        return 1;
    }

    const char *path = argv[1];

    FileList *files = get_files(path);

    print_files(files);

    free_files(files);

    return 0;
}

FileList *get_files(const char *path) {
    FileList *files = malloc(sizeof(FileList));
    files->files = NULL;
    files->num_files = 0;

    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return NULL;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char *full_path = malloc(strlen(path) + strlen(entry->d_name) + 2);
        sprintf(full_path, "%s/%s", path, entry->d_name);

        File file;
        file.name = malloc(strlen(entry->d_name) + 1);
        strcpy(file.name, entry->d_name);
        file.path = full_path;
        file.size = 0;
        file.type = NULL;

        if (entry->d_type == DT_REG) {
            file.type = FILE_TYPE_FILE;
        } else if (entry->d_type == DT_DIR) {
            file.type = FILE_TYPE_DIR;
        } else if (entry->d_type == DT_LNK) {
            file.type = FILE_TYPE_LINK;
        } else {
            file.type = FILE_TYPE_OTHER;
        }

        files->files = realloc(files->files, (files->num_files + 1) * sizeof(File));
        files->files[files->num_files] = file;
        files->num_files++;
    }

    closedir(dir);

    return files;
}

void print_files(FileList *files) {
    printf("Files in '%s':\n", files->files[0].path);
    printf("%-20s %-10s %-10s\n", "Name", "Size", "Type");
    for (int i = 0; i < files->num_files; i++) {
        File file = files->files[i];

        char *color = WHITE;
        if (file.type == FILE_TYPE_FILE) {
            color = GREEN;
        } else if (file.type == FILE_TYPE_DIR) {
            color = BLUE;
        } else if (file.type == FILE_TYPE_LINK) {
            color = RED;
        }

        printf("%-20s %10lld %10s\n", file.name, file.size, color);
    }
}

void free_files(FileList *files) {
    for (int i = 0; i < files->num_files; i++) {
        File file = files->files[i];
        free(file.name);
        free(file.path);
    }

    free(files->files);
    free(files);
}