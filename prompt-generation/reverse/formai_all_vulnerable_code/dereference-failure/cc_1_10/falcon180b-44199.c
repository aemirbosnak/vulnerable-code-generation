//Falcon-180B DATASET v1.0 Category: File Backup System ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>

#define MAX_PATH 1024

typedef struct {
    char *path;
    struct dirent *ent;
} DirItem;

void backup_file(char *src_file, char *dest_dir) {
    char dest_file[MAX_PATH];
    sprintf(dest_file, "%s/%s", dest_dir, src_file);

    FILE *src = fopen(src_file, "rb");
    if (src == NULL) {
        printf("Error opening source file: %s\n", src_file);
        return;
    }

    FILE *dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        printf("Error creating destination file: %s\n", dest_file);
        fclose(src);
        return;
    }

    char buf[1024];
    size_t bytes_read;

    while ((bytes_read = fread(buf, 1, sizeof(buf), src)) > 0) {
        fwrite(buf, 1, bytes_read, dest);
    }

    fclose(src);
    fclose(dest);
}

void backup_dir(char *src_dir, char *dest_dir) {
    DIR *dir = opendir(src_dir);
    if (dir == NULL) {
        printf("Error opening source directory: %s\n", src_dir);
        return;
    }

    char path[MAX_PATH];
    while (readdir(dir)!= NULL) {
        DirItem *item = malloc(sizeof(DirItem));
        item->path = strdup(path);
        item->ent = readdir(dir);

        if (item->ent->d_type == DT_DIR) {
            char *dest_subdir = malloc(strlen(dest_dir) + strlen(item->ent->d_name) + 2);
            sprintf(dest_subdir, "%s/%s", dest_dir, item->ent->d_name);
            mkdir(dest_subdir, 0777);
            backup_dir(item->path, dest_subdir);
            free(dest_subdir);
        } else {
            backup_file(item->path, dest_dir);
            free(item->path);
            free(item);
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    backup_dir(argv[1], argv[2]);

    return 0;
}