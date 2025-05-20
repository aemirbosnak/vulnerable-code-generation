//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024

typedef struct {
    char *src_dir;
    char *dest_dir;
} Config;

void sync_dirs(Config *config) {
    DIR *src_dir = opendir(config->src_dir);
    DIR *dest_dir = opendir(config->dest_dir);

    struct dirent *ent;
    while ((ent = readdir(src_dir))!= NULL) {
        char src_path[BUF_SIZE];
        char dest_path[BUF_SIZE];

        snprintf(src_path, BUF_SIZE, "%s/%s", config->src_dir, ent->d_name);
        snprintf(dest_path, BUF_SIZE, "%s/%s", config->dest_dir, ent->d_name);

        struct stat src_stat, dest_stat;
        stat(src_path, &src_stat);
        stat(dest_path, &dest_stat);

        if (S_ISDIR(src_stat.st_mode)) {
            if (!S_ISDIR(dest_stat.st_mode)) {
                mkdir(dest_path, 0777);
            }
        } else if (S_ISREG(src_stat.st_mode)) {
            if (!S_ISREG(dest_stat.st_mode)) {
                FILE *dest_file = fopen(dest_path, "w");
                fclose(dest_file);
            } else if (src_stat.st_mtime > dest_stat.st_mtime) {
                FILE *src_file = fopen(src_path, "r");
                FILE *dest_file = fopen(dest_path, "w");

                char buf[BUF_SIZE];
                while (fgets(buf, BUF_SIZE, src_file)!= NULL) {
                    fputs(buf, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);
            }
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <src_dir> <dest_dir>\n", argv[0]);
        return 1;
    }

    Config config = {
       .src_dir = argv[1],
       .dest_dir = argv[2]
    };

    sync_dirs(&config);

    return 0;
}