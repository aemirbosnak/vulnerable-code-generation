//FormAI DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>

#define BUF_SIZE 512

void backup_files(char *src_dirname, char *dest_dirname);
void copy_files(char *src_file, char *dest_file);
char *get_filename(char *path);

int main(int argc, char *argv[]) {
    char *src_dirname, *dest_dirname;

    if (argc != 3) {
        printf("Invalid number of arguments.\n");
        printf("Usage: %s src_directory dest_directory\n", argv[0]);
        return 1;
    }

    src_dirname = argv[1];
    dest_dirname = argv[2];

    backup_files(src_dirname, dest_dirname);

    return 0;
}

void backup_files(char *src_dirname, char *dest_dirname) {
    DIR *src_dir, *dest_dir;
    struct dirent *file;
    struct stat file_info;
    char src_path[BUF_SIZE], dest_path[BUF_SIZE], filename[BUF_SIZE];
    time_t time_modified;

    if ((src_dir = opendir(src_dirname)) == NULL) {
        printf("Unable to open source directory: %s\n", src_dirname);
        return;
    }

    if ((dest_dir = opendir(dest_dirname)) == NULL) {
        printf("Unable to open destination directory: %s\n", dest_dirname);
        return;
    }

    while ((file = readdir(src_dir)) != NULL) {
        strcpy(src_path, src_dirname);
        strcat(src_path, "/");
        strcat(src_path, file->d_name);

        strcpy(dest_path, dest_dirname);
        strcat(dest_path, "/");
        strcat(dest_path, file->d_name);

        if (stat(src_path, &file_info) == -1) {
            printf("Unable to read file info for %s\n", src_path);
            continue;
        }

        if (S_ISREG(file_info.st_mode)) {
            copy_files(src_path, dest_path);
            printf("Copied %s to %s\n", src_path, dest_path);
        } else if (S_ISDIR(file_info.st_mode) && strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0) {
            mkdir(dest_path, 0755);
            backup_files(src_path, dest_path);
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

void copy_files(char *src_file, char *dest_file) {
    FILE *src, *dest;
    char buf[BUF_SIZE];
    size_t bytes;

    if ((src = fopen(src_file, "rb")) == NULL) {
        printf("Unable to open source file: %s\n", src_file);
        return;
    }

    if ((dest = fopen(dest_file, "wb")) == NULL) {
        printf("Unable to open destination file: %s\n", dest_file);
        return;
    }

    while ((bytes = fread(buf, 1, BUF_SIZE, src)) != 0) {
        fwrite(buf, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
}

char *get_filename(char *path) {
    char *filename;

    filename = strrchr(path, '/');
    if (filename == NULL) {
        filename = path;
    } else {
        filename++;
    }

    return filename;
}