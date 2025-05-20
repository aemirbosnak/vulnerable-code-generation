//FormAI DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024

int file_exists(char *filename) {
    struct stat st;
    return (stat(filename, &st) == 0);
}

void copy_file(char *src_filename, char *dest_filename) {
    FILE *src_file, *dest_file;
    int ch;

    src_file = fopen(src_filename, "rb");
    if (src_file == NULL) {
        printf("Error opening source file %s\n", src_filename);
        return;
    }

    dest_file = fopen(dest_filename, "wb");
    if (dest_file == NULL) {
        printf("Error creating destination file %s\n", dest_filename);
        fclose(src_file);
        return;
    }
    
    while ((ch = fgetc(src_file)) != EOF) {
        fputc(ch, dest_file);
    }

    printf("Copied file %s to %s\n", src_filename, dest_filename);

    fclose(src_file);
    fclose(dest_file);
}

void sync_files(char *src_dirname, char *dest_dirname) {
    DIR *src_dir, *dest_dir;
    struct dirent *ent;
    char src_path[MAX_PATH_LENGTH], dest_path[MAX_PATH_LENGTH];

    src_dir = opendir(src_dirname);
    if (src_dir == NULL) {
        printf("Error opening source directory %s\n", src_dirname);
        return;
    }

    dest_dir = opendir(dest_dirname);
    if (dest_dir == NULL) {
        printf("Error opening destination directory %s\n", dest_dirname);
        closedir(src_dir);
        return;
    }

    while ((ent = readdir(src_dir)) != NULL) {
        if (ent->d_name[0] == '.') {
            continue;  // ignore hidden files/directories
        }

        sprintf(src_path, "%s/%s", src_dirname, ent->d_name);
        sprintf(dest_path, "%s/%s", dest_dirname, ent->d_name);

        if (ent->d_type == DT_DIR) {
            if (file_exists(dest_path)) {
                sync_files(src_path, dest_path);
            } else {
                mkdir(dest_path, 0755);
                printf("Created directory %s\n", dest_path);
                sync_files(src_path, dest_path);
            }
        } else {
            if (!file_exists(dest_path)) {
                copy_file(src_path, dest_path);
            }
        }
    }

    closedir(src_dir);
    closedir(dest_dir);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    printf("Files synchronized successfully.\n");

    return 0;
}