//Falcon-180B DATASET v1.0 Category: Disk space analyzer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/statvfs.h>
#include <sys/stat.h>

#define MAX_FILE_NAME_LENGTH 1024
#define MAX_DIR_NAME_LENGTH 1024
#define MAX_FILE_SIZE 1024 * 1024 * 100

typedef struct {
    char file_name[MAX_FILE_NAME_LENGTH];
    int file_size;
    int file_type;
} file_t;

typedef struct {
    char dir_name[MAX_DIR_NAME_LENGTH];
    int dir_size;
    int num_files;
    file_t *files;
} dir_t;

void add_file(dir_t *dir, const char *file_name, int file_size, int file_type) {
    if (dir->num_files == MAX_FILE_SIZE) {
        return;
    }

    dir->files = realloc(dir->files, sizeof(file_t) * (dir->num_files + 1));
    strcpy(dir->files[dir->num_files].file_name, file_name);
    dir->files[dir->num_files].file_size = file_size;
    dir->files[dir->num_files].file_type = file_type;
    dir->num_files++;
}

void analyze_dir(const char *dir_path, dir_t *dir) {
    DIR *dp;
    struct dirent *dirp;
    struct stat stat_buf;
    char path[MAX_DIR_NAME_LENGTH + MAX_FILE_NAME_LENGTH];

    dp = opendir(dir_path);
    if (dp == NULL) {
        return;
    }

    while ((dirp = readdir(dp))!= NULL) {
        strcpy(path, dir_path);
        strcat(path, "/");
        strcat(path, dirp->d_name);

        if (stat(path, &stat_buf)!= 0) {
            continue;
        }

        if (S_ISDIR(stat_buf.st_mode)) {
            dir->dir_size += stat_buf.st_size;
            analyze_dir(path, dir);
        } else {
            add_file(dir, dirp->d_name, stat_buf.st_size, S_ISREG(stat_buf.st_mode));
        }
    }

    closedir(dp);
}

void print_dir(const char *dir_name, dir_t *dir) {
    printf("Directory: %s\n", dir_name);
    printf("Size: %d bytes\n", dir->dir_size);
    printf("Number of files: %d\n", dir->num_files);

    if (dir->num_files == 0) {
        return;
    }

    printf("Largest files:\n");
    for (int i = 0; i < dir->num_files; i++) {
        printf("%d. %s (%d bytes)\n", i + 1, dir->files[i].file_name, dir->files[i].file_size);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s directory\n", argv[0]);
        return 1;
    }

    dir_t dir;
    memset(&dir, 0, sizeof(dir_t));

    analyze_dir(argv[1], &dir);
    print_dir(argv[1], &dir);

    return 0;
}