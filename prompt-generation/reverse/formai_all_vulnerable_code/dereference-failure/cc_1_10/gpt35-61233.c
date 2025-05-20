//FormAI DATASET v1.0 Category: File Synchronizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

#define BUFLEN 512

void copy_file(const char* source, const char* destination);
void synchronize_directory(const char* source_dir, const char* dest_dir);

/**
 * Copies a file from the source path to the destination path.
 *
 * @param source: the source path of the file to be copied
 * @param destination: the destination path to copy the file to
 */
void copy_file(const char* source, const char* destination) {
    char buffer[BUFLEN];
    FILE* source_file;
    FILE* dest_file;

    source_file = fopen(source, "rb");
    if (source_file == NULL) {
        printf("Error: Unable to open `%s`\n", source);
        return;
    }

    dest_file = fopen(destination, "wb");
    if (dest_file == NULL) {
        printf("Error: Unable to create `%s`\n", destination);
        fclose(source_file);
        return;
    }

    while (!feof(source_file) && !ferror(source_file) && !ferror(dest_file)) {
        size_t bytes_read = fread(buffer, sizeof(char), BUFLEN, source_file);
        size_t bytes_written = fwrite(buffer, sizeof(char), bytes_read, dest_file);

        if (bytes_read != bytes_written) {
            printf("Error: Failed to copy `%s` to `%s`\n", source, destination);
            fclose(source_file);
            fclose(dest_file);
            return;
        }
    }

    fclose(source_file);
    fclose(dest_file);
}

/**
 * Synchronizes two directories by copying any missing files from the source directory to
 * the destination directory.
 *
 * @param source_dir: the path to the source directory
 * @param dest_dir: the path to the destination directory
 */
void synchronize_directory(const char* source_dir, const char* dest_dir) {
    DIR* source;
    DIR* dest;
    struct dirent *entry;
    struct stat st;

    source = opendir(source_dir);
    if (source == NULL) {
        printf("Error: Unable to open source directory `%s`", source_dir);
        return;
    }

    dest = opendir(dest_dir);
    if (dest == NULL) {
        if (errno == ENOENT) {
            // Destination directory does not exist, so create it
            mkdir(dest_dir, 0777);
            dest = opendir(dest_dir);
        } else {
            printf("Error: Unable to open destination directory `%s`", dest_dir);
            closedir(source);
            return;
        }
    }

    while ((entry = readdir(source)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // If the entry is a directory and not `.` or `..`, recurse into it
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                char source_subpath[BUFLEN];
                char dest_subpath[BUFLEN];

                snprintf(source_subpath, sizeof(source_subpath), "%s/%s", source_dir, entry->d_name);
                snprintf(dest_subpath, sizeof(dest_subpath), "%s/%s", dest_dir, entry->d_name);

                synchronize_directory(source_subpath, dest_subpath);
            }
        } else {
            // If the entry is a file, check if it exists in the destination directory
            char source_file[BUFLEN];
            char dest_file[BUFLEN];

            snprintf(source_file, sizeof(source_file), "%s/%s", source_dir, entry->d_name);
            snprintf(dest_file, sizeof(dest_file), "%s/%s", dest_dir, entry->d_name);

            if (stat(dest_file, &st) == -1) {
                if (errno == ENOENT) {
                    // Destination file doesn't exist, so copy it from the source directory
                    printf("Copying `%s` to `%s`\n", source_file, dest_file);
                    copy_file(source_file, dest_file);
                } else {
                    printf("Error: Failed to stat file `%s` in destination directory", entry->d_name);
                }
            }
        }
    }

    closedir(source);
    closedir(dest);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s [source directory] [destination directory]\n", argv[0]);
        return EXIT_FAILURE;
    }

    synchronize_directory(argv[1], argv[2]);

    return EXIT_SUCCESS;
}