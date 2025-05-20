//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH 256
#define BUF_SIZE 4096

typedef struct {
    char name[MAX_PATH];
    off_t size;
    int is_dir;
} FileOrDir;

void traverse_dir(char *path, FileOrDir *files, int *num_files, int *num_dirs) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    if (!(dir = opendir(path))) {
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[MAX_PATH];
        snprintf(full_path, MAX_PATH, "%s/%s", path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }
            (*num_dirs)++;
            FileOrDir dir;
            strcpy(dir.name, entry->d_name);
            traverse_dir(full_path, files, num_files, num_dirs);
        } else {
            (*num_files)++;
            stat(full_path, &file_stat);
            FileOrDir file;
            strcpy(file.name, entry->d_name);
            file.size = file_stat.st_size;
            file.is_dir = 0;
            files = realloc(files, sizeof(FileOrDir) * (*num_files + 1));
            files[*num_files - 1] = file;
        }
    }

    closedir(dir);
}

int main() {
    char cwd[MAX_PATH];
    FileOrDir *files = NULL;
    int num_files = 0, num_dirs = 0;

    getcwd(cwd, MAX_PATH);

    traverse_dir(cwd, files, &num_files, &num_dirs);

    printf("Total size of %s:\n", cwd);
    off_t total_size = 0;
    for (int i = 0; i < num_files; i++) {
        total_size += files[i].size;
    }
    for (int i = 0; i < num_dirs; i++) {
        traverse_dir(files[i].name, files, &num_files, &num_dirs);
        total_size += files[num_files - 1].size;
        free(files[num_files - 1].name);
    }
    printf("%lld bytes\n", (long long)total_size);

    printf("Size distribution:\n");
    printf("--------------------\n");
    printf("Files       : %d\n", num_files);
    printf("Directories : %d\n", num_dirs);
    printf("Total       : %lld bytes\n", (long long)total_size);

    for (int i = 0; i < num_files; i++) {
        if (files[i].size > 1024 * 1024) {
            printf("%s (%.2f MB)\n", files[i].name, (float)files[i].size / (1024 * 1024));
        }
    }

    for (int i = 0; i < num_files + num_dirs; i++) {
        free(files[i].name);
    }
    free(files);

    return 0;
}