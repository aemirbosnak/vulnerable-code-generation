//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

#define FILE_NAME_MAX 256

void backup_file(char *src_path, char *dest_path, char *backup_dir) {
    FILE *src, *dest;
    char backup_file[FILE_NAME_MAX];
    sprintf(backup_file, "%s/%s", backup_dir, src_path);
    src = fopen(src_path, "r");
    dest = fopen(backup_file, "w");
    if (src != NULL && dest != NULL) {
        char c;
        while ((c = fgetc(src)) != EOF) {
            fputc(c, dest);
        }
        fclose(src);
        fclose(dest);
    }
}

void backup_directory(char *src_dir, char *backup_dir) {
    DIR *dir;
    struct dirent *dirent;
    dir = opendir(src_dir);
    if (dir != NULL) {
        while ((dirent = readdir(dir)) != NULL) {
            if (strcmp(dirent->d_name, ".") == 0 || strcmp(dirent->d_name, "..") == 0) {
                continue;
            }
            char src_path[FILE_NAME_MAX];
            char dest_path[FILE_NAME_MAX];
            sprintf(src_path, "%s/%s", src_dir, dirent->d_name);
            sprintf(dest_path, "%s/%s", backup_dir, src_path);
            struct stat statbuf;
            if (stat(src_path, &statbuf) == 0) {
                if (S_ISREG(statbuf.st_mode)) {
                    backup_file(src_path, dest_path, backup_dir);
                } else if (S_ISDIR(statbuf.st_mode)) {
                    mkdir(dest_path, statbuf.st_mode);
                    backup_directory(src_path, dest_path);
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <src_dir> <backup_dir>\n", argv[0]);
        return 1;
    }
    char *src_dir = argv[1];
    char *backup_dir = argv[2];
    mkdir(backup_dir, 0755);
    backup_directory(src_dir, backup_dir);
    return 0;
}