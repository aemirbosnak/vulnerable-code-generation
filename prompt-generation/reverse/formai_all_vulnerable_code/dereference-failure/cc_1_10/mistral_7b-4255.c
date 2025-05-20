//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    char name[256];
    int size;
} FileOrFolder;

void recursive_dir(const char *path, FileOrFolder *files, int *num_files, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    if ((dir = opendir(path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            char new_path[256];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);

            if (stat(new_path, &info) == 0 && S_ISDIR(info.st_mode)) {
                recursive_dir(new_path, files, num_files, depth + 1);
            } else {
                if (depth > 0) {
                    strncpy(files[*num_files].name, new_path, sizeof(files[*num_files].name) - 1);
                    files[*num_files].size = info.st_size;
                    (*num_files)++;
                }
            }
        }
        closedir(dir);
    }
}

int main() {
    char cwd[256];
    getcwd(cwd, sizeof(cwd));

    FileOrFolder files[1024];
    int num_files = 0;

    recursive_dir(cwd, files, &num_files, 0);

    printf("\nDirectory Size Analysis:\n");
    printf("-------------------------\n");

    int total_size = 0;
    for (int i = 0; i < num_files; i++) {
        printf("%s (%ld bytes)\n", files[i].name, files[i].size);
        total_size += files[i].size;
    }

    printf("\nTotal size of %s: %ld bytes\n", cwd, total_size);

    return 0;
}