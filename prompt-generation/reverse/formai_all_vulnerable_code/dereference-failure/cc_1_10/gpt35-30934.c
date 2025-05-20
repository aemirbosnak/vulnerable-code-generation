//FormAI DATASET v1.0 Category: File Synchronizer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void sync_files(char* source, char* destination) {
    DIR* dir = opendir(source);
    if (dir == NULL) {
        printf("Error opening directory\n");
        return;
    }

    struct dirent* entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_name[0] == '.') {
            continue; // ignore hidden files
        }

        char src_path[256];
        sprintf(src_path, "%s/%s", source, entry->d_name);

        char dest_path[256];
        sprintf(dest_path, "%s/%s", destination, entry->d_name);

        struct stat src_stat, dest_stat;
        if (stat(src_path, &src_stat) != 0) {
            printf("Error getting stats for %s\n", src_path);
            continue;
        }

        if (stat(dest_path, &dest_stat) == 0) {
            if (src_stat.st_mtime <= dest_stat.st_mtime) {
                continue; // no need to sync
            }
        }

        FILE* src_file = fopen(src_path, "rb");
        if (src_file == NULL) {
            printf("Error opening file %s\n", src_path);
            continue;
        }

        FILE* dest_file = fopen(dest_path, "wb");
        if (dest_file == NULL) {
            printf("Error opening file %s\n", dest_path);
            fclose(src_file);
            continue;
        }

        char buffer[4096];
        size_t count;
        while ((count = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
            fwrite(buffer, 1, count, dest_file);
        }

        fclose(src_file);
        fclose(dest_file);
        printf("Synced %s\n", src_path);
    }

    closedir(dir);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}