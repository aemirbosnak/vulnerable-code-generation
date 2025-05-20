//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void print_header(const char *header) {
    printf("\n=== %s ===\n", header);
}

void synchronize_files(const char *src, const char *dest) {
    DIR *dir;
    struct dirent *entry;
    struct stat src_stat, dest_stat;

    if (!(dir = opendir(src))) {
        perror("Could not open source directory");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; // Skip the current and parent directories
        }

        char src_path[512];
        char dest_path[512];

        snprintf(src_path, sizeof(src_path), "%s/%s", src, entry->d_name);
        snprintf(dest_path, sizeof(dest_path), "%s/%s", dest, entry->d_name);

        if (stat(src_path, &src_stat) == -1) {
            perror("Could not get source file status");
            continue;
        }

        if (stat(dest_path, &dest_stat) == -1) {
            // If the destination file doesn't exist, copy it!
            printf("Copying new file: %s --> %s\n", src_path, dest_path);
            FILE *src_file = fopen(src_path, "rb");
            FILE *dest_file = fopen(dest_path, "wb");

            if (src_file && dest_file) {
                char buffer[1024];
                size_t bytes;

                while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, bytes, dest_file);
                }

                fclose(src_file);
                fclose(dest_file);
                printf("Yay! Successfully copied: %s\n", entry->d_name);
            } else {
                perror("Error opening files for copy");
            }

        } else {
            // If the destination file exists, check for updates
            if (src_stat.st_mtime > dest_stat.st_mtime) {
                printf("Updating file: %s --> %s\n", src_path, dest_path);
                FILE *src_file = fopen(src_path, "rb");
                FILE *dest_file = fopen(dest_path, "wb");

                if (src_file && dest_file) {
                    char buffer[1024];
                    size_t bytes;

                    while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                        fwrite(buffer, 1, bytes, dest_file);
                    }

                    fclose(src_file);
                    fclose(dest_file);
                    printf("Hooray! Updated: %s\n", entry->d_name);
                } else {
                    perror("Error opening files for update");
                }
            } else {
                printf("Skipping file: %s (no updates found!)\n", entry->d_name);
            }
        }
    }

    closedir(dir);
    printf("\nSynchronization complete! 🌈✨\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source_directory> <destination_directory>\n", argv[0]);
        return 1;
    }

    const char *source_dir = argv[1];
    const char *dest_dir = argv[2];

    print_header("File Synchronizer");
    printf("☀️ Ready to sync files! Let's make sure everything is up to date. ☀️\n");

    synchronize_files(source_dir, dest_dir);

    return 0;
}