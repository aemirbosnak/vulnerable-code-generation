//MISTRAL-7B DATASET v1.0 Category: Disk space analyzer ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct file_info {
    char name[1024];
    off_t size;
    int is_dir;
} file_info;

void analyze_disk_space(char *path, int depth) {
    DIR *dir;
    struct dirent *entry;
    struct stat file_stat;
    file_info info;
    char new_path[1024];

    if (depth > 0) {
        printf("%*s|-- %s [Directory]\n", depth * 4, "", path);
    }

    if ((dir = opendir(path)) != NULL) {
        while ((entry = readdir(dir)) != NULL) {
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name);
            if (entry->d_type == DT_DIR) {
                if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                    continue;
                }
                analyze_disk_space(new_path, depth + 1);
            } else {
                stat(new_path, &file_stat);
                strcpy(info.name, entry->d_name);
                info.size = file_stat.st_size;
                info.is_dir = 0;

                if (depth > 0) {
                    printf("%*s|-- %s [File] [%ld bytes]\n", depth * 4, "", entry->d_name, (long)info.size);
                } else {
                    printf("-------------------------------------------------\n");
                    printf("|-- %s [File] [%ld bytes]\n", entry->d_name, (long)info.size);
                    printf("-------------------------------------------------\n");
                }
            }
        }
        closedir(dir);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s [path]\n", argv[0]);
        return 1;
    }

    analyze_disk_space(argv[1], 0);
    return 0;
}