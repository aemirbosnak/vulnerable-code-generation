//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_PATH 1024

int copy_file(const char *src, const char *dst) {
    FILE *in, *out;
    char buf[4096];
    size_t nread;

    // Open the source file for reading.
    in = fopen(src, "rb");
    if (in == NULL) {
        perror("fopen(src)");
        return -1;
    }

    // Open the destination file for writing.
    out = fopen(dst, "wb");
    if (out == NULL) {
        perror("fopen(dst)");
        fclose(in);
        return -1;
    }

    // Copy the data from the source file to the destination file.
    while ((nread = fread(buf, 1, sizeof(buf), in)) > 0) {
        if (fwrite(buf, 1, nread, out) != nread) {
            perror("fwrite");
            fclose(in);
            fclose(out);
            return -1;
        }
    }

    // Close the files.
    fclose(in);
    fclose(out);

    return 0;
}

int sync_dirs(const char *src, const char *dst) {
    DIR *src_dir, *dst_dir;
    struct dirent *src_ent, *dst_ent;
    char src_path[MAX_PATH], dst_path[MAX_PATH];

    // Open the source directory for reading.
    src_dir = opendir(src);
    if (src_dir == NULL) {
        perror("opendir(src)");
        return -1;
    }

    // Open the destination directory for reading.
    dst_dir = opendir(dst);
    if (dst_dir == NULL) {
        perror("opendir(dst)");
        closedir(src_dir);
        return -1;
    }

    // Synchronize the files in the source and destination directories.
    while ((src_ent = readdir(src_dir)) != NULL) {
        // Skip the current and parent directories.
        if (strcmp(src_ent->d_name, ".") == 0 || strcmp(src_ent->d_name, "..") == 0) {
            continue;
        }

        // Get the full path to the source file.
        snprintf(src_path, sizeof(src_path), "%s/%s", src, src_ent->d_name);

        // Get the full path to the destination file.
        snprintf(dst_path, sizeof(dst_path), "%s/%s", dst, src_ent->d_name);

        // Check if the destination file exists.
        dst_ent = NULL;
        while ((dst_ent = readdir(dst_dir)) != NULL) {
            if (strcmp(dst_ent->d_name, src_ent->d_name) == 0) {
                break;
            }
        }

        // If the destination file does not exist, create it.
        if (dst_ent == NULL) {
            printf("Creating %s\n", dst_path);
            if (copy_file(src_path, dst_path) != 0) {
                perror("copy_file");
                closedir(src_dir);
                closedir(dst_dir);
                return -1;
            }
        } else {
            // If the destination file exists, compare its size and modification time to the source file.
            struct stat src_stat, dst_stat;
            if (stat(src_path, &src_stat) != 0) {
                perror("stat(src_path)");
                closedir(src_dir);
                closedir(dst_dir);
                return -1;
            }
            if (stat(dst_path, &dst_stat) != 0) {
                perror("stat(dst_path)");
                closedir(src_dir);
                closedir(dst_dir);
                return -1;
            }

            // If the destination file is older than the source file, copy the source file to the destination file.
            if (src_stat.st_mtime > dst_stat.st_mtime) {
                printf("Updating %s\n", dst_path);
                if (copy_file(src_path, dst_path) != 0) {
                    perror("copy_file");
                    closedir(src_dir);
                    closedir(dst_dir);
                    return -1;
                }
            }
        }
    }

    // Close the directories.
    closedir(src_dir);
    closedir(dst_dir);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <src> <dst>\n", argv[0]);
        return 1;
    }

    // Synchronize the source and destination directories.
    if (sync_dirs(argv[1], argv[2]) != 0) {
        return 1;
    }

    return 0;
}