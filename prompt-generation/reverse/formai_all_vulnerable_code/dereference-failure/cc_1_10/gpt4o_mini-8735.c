//GPT-4o-mini DATASET v1.0 Category: File Synchronizer ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_PATH_LEN 256

void print_usage(const char *prog_name) {
    printf("Usage: %s <source_directory> <target_directory>\n", prog_name);
}

int get_file_size(const char *file_path) {
    struct stat st;
    if (stat(file_path, &st) == 0) {
        return st.st_size;
    }
    return -1;
}

int compare_files(const char *file1, const char *file2) {
    FILE *f1 = fopen(file1, "rb");
    FILE *f2 = fopen(file2, "rb");
    
    if (f1 == NULL || f2 == NULL) {
        if (f1) fclose(f1);
        if (f2) fclose(f2);
        return -1;  // Error opening files
    }

    int size1 = get_file_size(file1);
    int size2 = get_file_size(file2);

    if (size1 != size2) {
        fclose(f1);
        fclose(f2);
        return 0; // Files differ in size
    }

    char *buf1 = malloc(size1);
    char *buf2 = malloc(size2);

    fread(buf1, 1, size1, f1);
    fread(buf2, 1, size2, f2);

    fclose(f1);
    fclose(f2);

    int result = memcmp(buf1, buf2, size1);
    free(buf1);
    free(buf2);
    return result == 0; // Returns 1 if the files are the same, 0 otherwise
}

void synchronize(const char *src_dir, const char *tgt_dir) {
    DIR *src = opendir(src_dir);
    DIR *tgt = opendir(tgt_dir);
    struct dirent *entry;

    int files_copied = 0;
    int files_skipped = 0;

    if (!src) {
        perror("Source directory opening failed");
        return;
    }

    while ((entry = readdir(src)) != NULL) {
        char src_path[MAX_PATH_LEN];
        char tgt_path[MAX_PATH_LEN];

        snprintf(src_path, MAX_PATH_LEN, "%s/%s", src_dir, entry->d_name);
        snprintf(tgt_path, MAX_PATH_LEN, "%s/%s", tgt_dir, entry->d_name);

        if (entry->d_name[0] == '.') { // skip hidden files
            continue;
        }

        if (get_file_size(src_path) == -1) {
            printf("Could not access file: %s\n", src_path);
            continue;
        }

        if (access(tgt_path, F_OK) == -1) { // If target file does not exist
            FILE *src_file = fopen(src_path, "rb");
            FILE *tgt_file = fopen(tgt_path, "wb");
            char buffer[1024];
            size_t bytes;

            while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                fwrite(buffer, 1, bytes, tgt_file);
            }

            fclose(src_file);
            fclose(tgt_file);
            printf("Copied: %s to %s\n", src_path, tgt_path);
            files_copied++;
        } else {
            if (!compare_files(src_path, tgt_path)) {
                FILE *src_file = fopen(src_path, "rb");
                FILE *tgt_file = fopen(tgt_path, "wb");
                char buffer[1024];
                size_t bytes;

                while ((bytes = fread(buffer, 1, sizeof(buffer), src_file)) > 0) {
                    fwrite(buffer, 1, bytes, tgt_file);
                }

                fclose(src_file);
                fclose(tgt_file);
                printf("Updated: %s to %s\n", src_path, tgt_path);
                files_copied++;
            } else {
                files_skipped++;
                printf("Skipped: %s (same content)\n", tgt_path);
            }
        }
    }

    closedir(src);
    closedir(tgt);

    printf("\nSynchronization complete!\n");
    printf("Files copied: %d\n", files_copied);
    printf("Files skipped: %d\n", files_skipped);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    synchronize(argv[1], argv[2]);
    return EXIT_SUCCESS;
}