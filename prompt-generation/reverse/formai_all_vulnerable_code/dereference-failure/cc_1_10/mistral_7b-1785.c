//MISTRAL-7B DATASET v1.0 Category: System administration ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

typedef struct {
    int files;
    int dirs;
} dir_stats_t;

void get_dir_stats(const char *path, dir_stats_t *stats) {
    DIR *dir;
    struct dirent *entry;
    struct stat info;

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        char full_path[1024];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (stat(full_path, &info) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(info.st_mode)) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            stats->dirs++;
            get_dir_stats(full_path, stats);
        } else {
            stats->files++;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    dir_stats_t stats = { 0, 0 };
    get_dir_stats(argv[1], &stats);

    printf("Total number of files: %d\n", stats.files);
    printf("Total number of directories: %d\n", stats.dirs);

    return 0;
}