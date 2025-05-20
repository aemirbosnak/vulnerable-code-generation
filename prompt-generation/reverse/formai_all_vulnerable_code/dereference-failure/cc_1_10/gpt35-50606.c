//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH 1024
#define MAX_FILES 1000

char *src_dir, *dst_dir, *filelist[MAX_FILES];
int num_files = 0;

void sync_dir(char* src, char* dst);

void sync_file(char* src, char* dst) {
    struct stat src_stat, dst_stat;
    stat(src, &src_stat);
    stat(dst, &dst_stat);

    if (src_stat.st_mtime > dst_stat.st_mtime) {
        FILE* src_file = fopen(src, "r");
        FILE* dst_file = fopen(dst, "w");
        int c;

        while ((c = fgetc(src_file)) != EOF) {
            fputc(c, dst_file);
        }

        fclose(src_file);
        fclose(dst_file);
    }
}

void sync_dir(char* src, char* dst) {
    if (num_files == MAX_FILES) {
        perror("Too many files");
        exit(1);
    }

    DIR* dir = opendir(src);
    if (dir == NULL) {
        perror("Could not open directory");
        exit(1);
    }

    struct dirent* entry;

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char src_path[MAX_PATH];
        strcpy(src_path, src);
        strcat(src_path, "/");
        strcat(src_path, entry->d_name);

        char dst_path[MAX_PATH];
        strcpy(dst_path, dst);
        strcat(dst_path, "/");
        strcat(dst_path, entry->d_name);

        struct stat src_stat;
        stat(src_path, &src_stat);

        if (S_ISDIR(src_stat.st_mode)) {
            mkdir(dst_path, src_stat.st_mode);
            sync_dir(src_path, dst_path);
        } else {
            filelist[num_files++] = strdup(src_path);
            sync_file(src_path, dst_path);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: sync <src_dir> <dst_dir>\n");
        exit(1);
    }

    src_dir = argv[1];
    dst_dir = argv[2];

    sync_dir(src_dir, dst_dir);

    for (int i = 0; i < num_files; i++) {
        sync_file(filelist[i], dst_dir);
    }

    return 0;
}