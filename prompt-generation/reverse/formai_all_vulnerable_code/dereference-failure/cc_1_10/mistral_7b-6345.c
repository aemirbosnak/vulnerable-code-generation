//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void analyze_directory(char *path);

int main(int argc, char **argv) {
    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);
    return 0;
}

void analyze_directory(char *path) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;

    dir = opendir(path);

    if(dir != NULL) {
        while((entry = readdir(dir)) != NULL) {
            char full_path[1024];
            strcpy(full_path, path);
            strcat(full_path, "/");
            strcat(full_path, entry->d_name);

            if(entry->d_type == DT_DIR) {
                if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }
                analyze_directory(full_path);
            } else {
                stat(full_path, &file_stat);
                printf("%s : %ld bytes\n", full_path, file_stat.st_size);
                int file_size = file_stat.st_size;
                int total_size = lstat(path, &file_stat);
                int dir_size = total_size - file_size;
                printf("%s : %ld bytes\n", path, dir_size);
            }
        }

        closedir(dir);
    } else {
        perror("opendir");
    }
}