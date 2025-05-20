//FormAI DATASET v1.0 Category: File Synchronizer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define SOURCE_DIR "./source_folder"
#define DEST_DIR "./dest_folder"

void sync_dirs(const char *src_dir, const char *dest_dir);

int main(int argc, char **argv) {
    sync_dirs(SOURCE_DIR, DEST_DIR);

    printf("Done!\n");

    return 0;
}

void sync_dirs(const char *src_dir, const char *dest_dir) {
    DIR *src_dp, *dest_dp;
    struct dirent *src_entry, *dest_entry;
    struct stat src_stat, dest_stat;
    char src_path[1024], dest_path[1024];

    // Open source directory
    if ((src_dp = opendir(src_dir)) == NULL) {
        fprintf(stderr, "Failed to open directory %s: %s\n", src_dir, strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Open destination directory (create it if it doesn't exist)
    if ((dest_dp = opendir(dest_dir)) == NULL) {
        if (errno == ENOENT) {
            if (mkdir(dest_dir, 0777) != 0) {
                fprintf(stderr, "Failed to create destination directory %s: %s\n", dest_dir, strerror(errno));
                exit(EXIT_FAILURE);
            }

            dest_dp = opendir(dest_dir);
        } else {
            fprintf(stderr, "Failed to open directory %s: %s\n", dest_dir, strerror(errno));
            exit(EXIT_FAILURE);
        }
    }

    // Iterate over source directory entries
    while ((src_entry = readdir(src_dp)) != NULL) {
        // Skip "." and ".." entries
        if (strcmp(src_entry->d_name, ".") == 0 || strcmp(src_entry->d_name, "..") == 0) {
            continue;
        }

        // Build source file/directory path
        sprintf(src_path, "%s/%s", src_dir, src_entry->d_name);

        // Get source file/directory status
        if (lstat(src_path, &src_stat) != 0) {
            fprintf(stderr, "Failed to get status for %s: %s\n", src_path, strerror(errno));
            continue;
        }

        // Build destination file/directory path
        sprintf(dest_path, "%s/%s", dest_dir, src_entry->d_name);

        // Get destination file/directory status (if it exists)
        if (lstat(dest_path, &dest_stat) != 0 && errno != ENOENT) {
            fprintf(stderr, "Failed to get status for %s: %s\n", dest_path, strerror(errno));
            continue;
        }

        // Sync file if it's a regular file and it's either newer or doesn't exist in the destination
        if (S_ISREG(src_stat.st_mode)) {
            if (dest_stat.st_mtime < src_stat.st_mtime || errno == ENOENT) {
                printf("Syncing file %s...\n", src_path);

                // Open source file
                FILE *src_file = fopen(src_path, "rb");
                if (src_file == NULL) {
                    fprintf(stderr, "Failed to open %s: %s\n", src_path, strerror(errno));
                    continue;
                }

                // Create/overwrite destination file
                FILE *dest_file = fopen(dest_path, "wb");
                if (dest_file == NULL) {
                    fprintf(stderr, "Failed to create %s: %s\n", dest_path, strerror(errno));
                    fclose(src_file);
                    continue;
                }

                // Copy file contents
                int c;
                while ((c = fgetc(src_file)) != EOF) {
                    fputc(c, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);
            }
        }
        // Sync directory recursively
        else if (S_ISDIR(src_stat.st_mode)) {
            sync_dirs(src_path, dest_path);
        }
        // Unsupported file type
        else {
            fprintf(stderr, "Unsupported file type for %s\n", src_path);
            continue;
        }
    }

    closedir(src_dp);
    closedir(dest_dp);
}