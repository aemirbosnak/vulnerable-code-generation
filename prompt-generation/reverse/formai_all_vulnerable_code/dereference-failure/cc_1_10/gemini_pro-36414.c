//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <dirent.h>

// Function to copy a file
int copy_file(const char *src_file, const char *dst_file) {
    FILE *src, *dst;
    int ch;
    src = fopen(src_file, "r");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }
    dst = fopen(dst_file, "w");
    if (dst == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
    fclose(src);
    fclose(dst);
    return 0;
}

// Function to backup a directory
int backup_directory(const char *src_dir, const char *dst_dir) {
    DIR *dir;
    struct dirent *ent;
    char src_file[256], dst_file[256];
    dir = opendir(src_dir);
    if (dir == NULL) {
        perror("Error opening source directory");
        return -1;
    }
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        sprintf(src_file, "%s/%s", src_dir, ent->d_name);
        sprintf(dst_file, "%s/%s", dst_dir, ent->d_name);
        if (ent->d_type == DT_DIR) {
            if (backup_directory(src_file, dst_file) != 0) {
                return -1;
            }
        } else {
            if (copy_file(src_file, dst_file) != 0) {
                return -1;
            }
        }
    }
    closedir(dir);
    return 0;
}

// Main function
int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s src_dir dst_dir\n", argv[0]);
        return -1;
    }
    if (backup_directory(argv[1], argv[2]) != 0) {
        fprintf(stderr, "Error backing up directory\n");
        return -1;
    }
    return 0;
}