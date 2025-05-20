//FormAI DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void sync_files(char *src, char *dest);

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: ./sync src_folder dest_folder\n");
        exit(1);
    }

    char *src_folder = argv[1];
    char *dest_folder = argv[2];

    sync_files(src_folder, dest_folder);

    return 0;
}

void sync_files(char *src, char *dest) {
    DIR *dir;
    struct dirent *entry;
    char path_src[1024], path_dest[1024];

    if ((dir = opendir(src)) == NULL)
        return;

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;

            // Recursively call sync_files for subdirectories
            sprintf(path_src, "%s/%s", src, entry->d_name);
            sprintf(path_dest, "%s/%s", dest, entry->d_name);
            sync_files(path_src, path_dest);
        } else {
            // Copy file from src to dest
            sprintf(path_src, "%s/%s", src, entry->d_name);
            sprintf(path_dest, "%s/%s", dest, entry->d_name);

            struct stat stat_src, stat_dest;
            if (stat(path_src, &stat_src) == -1) {
                printf("Failed to get stats for file %s\n", path_src);
                continue;
            }
            if (stat(path_dest, &stat_dest) == -1) {
                printf("Failed to get stats for file %s\n", path_dest);
                continue;
            }

            // Check if file exists in destination and has same size and modification time as source
            if (S_ISREG(stat_src.st_mode) && S_ISREG(stat_dest.st_mode)) {
                if (stat_src.st_size == stat_dest.st_size && stat_src.st_mtime == stat_dest.st_mtime) {
                    printf("File %s already exists in %s and is up-to-date\n", entry->d_name, dest);
                    continue;
                }
            }

            // Copy file from src to dest
            FILE *f_src, *f_dest;
            f_src = fopen(path_src, "rb");
            if (f_src == NULL) {
                printf("Error opening file %s\n", path_src);
                continue;
            }

            f_dest = fopen(path_dest, "wb");
            if (f_dest == NULL) {
                printf("Error opening file %s\n", path_dest);
                fclose(f_src);
                continue;
            }

            printf("Copying file %s to %s\n", path_src, path_dest);

            char buffer[1024];
            size_t n;

            while ((n = fread(buffer, 1, sizeof(buffer), f_src)) > 0) {
                if (fwrite(buffer, 1, n, f_dest) != n) {
                    printf("Write error!\n");
                    break;
                }
            }

            if (n == 0) {
                printf("File %s copied successfully to %s\n", path_src, path_dest);
            } else {
                printf("Error copying file %s to %s\n", path_src, path_dest);
            }

            fclose(f_src);
            fclose(f_dest);
        }
    }

    closedir(dir);
}