//FormAI DATASET v1.0 Category: File Synchronizer ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUF_SIZE 1024

void copy_file(const char *source, const char *dest) {
    FILE *src_file, *dst_file;
    size_t nread;
    char buf[BUF_SIZE];

    src_file = fopen(source, "rb");
    dst_file = fopen(dest, "wb");

    while ((nread = fread(buf, 1, BUF_SIZE, src_file)) > 0) {
        fwrite(buf, 1, nread, dst_file);
    }

    fclose(src_file);
    fclose(dst_file);
}

void synchronize_dir(const char *source_dir, const char *dest_dir) {
    struct dirent *entry;
    DIR *dir = opendir(source_dir);

    if (!dir) {
        printf("Failed to open directory: %s\n", source_dir);
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            char sub_dir_source[BUF_SIZE];
            char sub_dir_dest[BUF_SIZE];

            snprintf(sub_dir_source, BUF_SIZE, "%s/%s", source_dir, entry->d_name);
            snprintf(sub_dir_dest, BUF_SIZE, "%s/%s", dest_dir, entry->d_name);

            synchronize_dir(sub_dir_source, sub_dir_dest);
        } else if (entry->d_type != DT_DIR) {
            char source_file[BUF_SIZE];
            char dest_file[BUF_SIZE];

            snprintf(source_file, BUF_SIZE, "%s/%s", source_dir, entry->d_name);
            snprintf(dest_file, BUF_SIZE, "%s/%s", dest_dir, entry->d_name);

            struct stat s;

            if (stat(source_file, &s) != 0) {
                printf("Unable to stat file: %s\n", source_file);
                continue;
            }

            time_t mtime = s.st_mtime;

            struct stat dest_stat;

            if (stat(dest_file, &dest_stat) == 0) {
                if (mtime <= dest_stat.st_mtime) {
                    continue;
                }
            }

            printf("Copying file: %s to %s\n", source_file, dest_file);
            copy_file(source_file, dest_file);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <source_dir> <dest_dir>\n", argv[0]);
        exit(1);
    }

    synchronize_dir(argv[1], argv[2]);

    return 0;
}