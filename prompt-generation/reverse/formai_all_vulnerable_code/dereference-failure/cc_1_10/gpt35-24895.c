//FormAI DATASET v1.0 Category: File Synchronizer ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1000

void sync(char* src_dir, char* dest_dir) {
    DIR* src_dp = opendir(src_dir);
    DIR* dest_dp = opendir(dest_dir);

    if (!src_dp) {
        printf("Error: Could not open source directory: %s\n", src_dir);
        return;
    }

    if (!dest_dp) {
        printf("Error: Could not open destination directory: %s\n", dest_dir);
        return;
    }

    // iterate over all files in the source directory
    struct dirent* src_dentry;
    while ((src_dentry = readdir(src_dp))) {
        if (!strcmp(src_dentry->d_name, ".") || !strcmp(src_dentry->d_name, "..")) {
            continue;
        }

        struct stat src_dentry_stat;
        char src_dentry_path[MAX_PATH_LENGTH];
        sprintf(src_dentry_path, "%s/%s", src_dir, src_dentry->d_name);
        stat(src_dentry_path, &src_dentry_stat);

        // if the file does not exist in the destination directory, copy over
        char dest_dentry_path[MAX_PATH_LENGTH];
        sprintf(dest_dentry_path, "%s/%s", dest_dir, src_dentry->d_name);
        if (!stat(dest_dentry_path, NULL)) {
            continue;
        }

        FILE* src_file = fopen(src_dentry_path, "r");
        FILE* dest_file = fopen(dest_dentry_path, "w");

        char buffer[1024];
        int bytes_read;
        while ((bytes_read = fread(buffer, 1, sizeof(buffer), src_file))) {
            fwrite(buffer, 1, bytes_read, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
    }

    closedir(src_dp);
    closedir(dest_dp);

    printf("Sync complete!\n");
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        return 0;
    }

    sync(argv[1], argv[2]);

    return 0;
}