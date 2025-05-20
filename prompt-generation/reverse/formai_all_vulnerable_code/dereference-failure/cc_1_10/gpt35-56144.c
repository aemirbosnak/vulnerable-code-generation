//FormAI DATASET v1.0 Category: File Synchronizer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

void sync_files(char* src_path, char* dest_path);

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: ./sync src_path dest_path");
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}

void sync_files(char* src_path, char* dest_path) {
    DIR* src_dir = opendir(src_path);

    if (src_dir == NULL) {
        printf("Could not open directory %s", src_path);
        exit(1);
    }

    DIR* dest_dir = opendir(dest_path);

    if (dest_dir == NULL) {
        mkdir(dest_path, 0777);
        dest_dir = opendir(dest_path);
    }

    struct dirent* dirent_src;

    while ((dirent_src = readdir(src_dir)) != NULL) {
        if (strcmp(dirent_src->d_name, ".") == 0 || strcmp(dirent_src->d_name, "..") == 0) {
            continue;
        }

        char* src_file = malloc(strlen(src_path) + strlen(dirent_src->d_name) + 2);
        sprintf(src_file, "%s/%s", src_path, dirent_src->d_name);

        struct stat src_stat;
        stat(src_file, &src_stat);

        if (S_ISREG(src_stat.st_mode)) {
            char* dest_file = malloc(strlen(dest_path) + strlen(dirent_src->d_name) + 2);
            sprintf(dest_file, "%s/%s", dest_path, dirent_src->d_name);

            struct stat dest_stat;

            if (stat(dest_file, &dest_stat) == 0) {
                if (src_stat.st_mtime > dest_stat.st_mtime) {
                    FILE* src = fopen(src_file, "r");
                    FILE* dest = fopen(dest_file, "w");

                    int ch;
                    while ((ch = fgetc(src)) != EOF) {
                        fputc(ch, dest);
                    }

                    fclose(src);
                    fclose(dest);

                    printf("Synced %s to %s\n", src_file, dest_file);
                }
            } else {
                FILE* src = fopen(src_file, "r");
                FILE* dest = fopen(dest_file, "w");

                int ch;
                while ((ch = fgetc(src)) != EOF) {
                    fputc(ch, dest);
                }

                fclose(src);
                fclose(dest);

                printf("Copied %s to %s\n", src_file, dest_file);
            }

            free(dest_file);
        } else if (S_ISDIR(src_stat.st_mode)) {
            char* dest_dir_name = malloc(strlen(dest_path) + strlen(dirent_src->d_name) + 2);
            sprintf(dest_dir_name, "%s/%s", dest_path, dirent_src->d_name);

            sync_files(src_file, dest_dir_name);

            free(dest_dir_name);
        }

        free(src_file);
    }

    closedir(src_dir);
    closedir(dest_dir);
}