//FormAI DATASET v1.0 Category: File Backup System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_PATH 1024
#define MAX_BACKUP_PATH 2048

// function to create a backup copy of a file
void backup_file(const char* src_file, const char* dest_dir) {
    char dest_file[MAX_BACKUP_PATH];
    strcpy(dest_file, dest_dir);
    strcat(dest_file, "/");
    strcat(dest_file, src_file);
    printf("Backing up %s to %s...\n", src_file, dest_file);
    // open source file
    FILE* src = fopen(src_file, "rb");
    if (src == NULL) {
        fprintf(stderr, "Error opening source file %s\n", src_file);
        return;
    }
    // create destination file
    FILE* dest = fopen(dest_file, "wb");
    if (dest == NULL) {
        fprintf(stderr, "Error creating destination file %s\n", dest_file);
        fclose(src);
        return;
    }
    // copy contents of source file to destination file
    char buffer[1024];
    size_t n;
    while ((n = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, n, dest);
    }
    // close files
    fclose(dest);
    fclose(src);
}

// recursive function to backup all files in a directory
void backup_directory(const char* src_dir, const char* dest_dir) {
    // open source directory
    DIR* dir = opendir(src_dir);
    if (dir == NULL) {
        fprintf(stderr, "Error opening source directory %s\n", src_dir);
        return;
    }
    // create destination directory
    struct stat st = {0};
    if (stat(dest_dir, &st) == -1) {
        mkdir(dest_dir, 0700);
    }
    // iterate over all files in source directory
    struct dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        // skip parent and current directories
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }
        // construct full path for source file
        char src_file[MAX_PATH];
        strcpy(src_file, src_dir);
        strcat(src_file, "/");
        strcat(src_file, ent->d_name);
        // construct full path for destination file
        char dest_file[MAX_BACKUP_PATH];
        strcpy(dest_file, dest_dir);
        strcat(dest_file, "/");
        strcat(dest_file, ent->d_name);
        // check if file is a directory
        struct stat file_info;
        if (stat(src_file, &file_info) == -1) {
            fprintf(stderr, "Error getting file info for %s\n", src_file);
            continue;
        }
        if (S_ISDIR(file_info.st_mode)) {
            backup_directory(src_file, dest_file);
        } else {
            backup_file(src_file, dest_dir);
        }
    }
    // close directory
    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: backup <source directory> <destination directory>\n");
        return 1;
    }
    const char* src_dir = argv[1];
    const char* dest_dir = argv[2];
    backup_directory(src_dir, dest_dir);
    printf("Backup complete!\n");
    return 0;
}