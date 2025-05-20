//GPT-4o-mini DATASET v1.0 Category: Disk space analyzer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/statvfs.h>
#include <dirent.h>
#include <limits.h>

#define MAX_PATH_LENGTH 4096
#define TOP_N 5

struct FileInfo {
    char path[MAX_PATH_LENGTH];
    long size;
};

void analyze_directory(const char *dir_path, struct FileInfo *files, int *file_count) {
    DIR *dir;
    struct dirent *entry;
    struct statvfs stat;

    if (!(dir = opendir(dir_path))) {
        perror("opendir");
        return;
    }

    while ((entry = readdir(dir))) {
        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", dir_path, entry->d_name);

        if (entry->d_type == DT_DIR) {
            if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
                analyze_directory(full_path, files, file_count);
            }
        } else {
            if (statvfs(dir_path, &stat) != 0) {
                perror("statvfs");
                closedir(dir);
                return;
            }

            FILE *file = fopen(full_path, "rb");
            if (file) {
                fseek(file, 0, SEEK_END);
                long file_size = ftell(file);
                fclose(file);

                if (*file_count < TOP_N) {
                    strcpy(files[*file_count].path, full_path);
                    files[*file_count].size = file_size;
                    (*file_count)++;
                } else {
                    for (int i = 0; i < TOP_N; i++) {
                        if (file_size > files[i].size) {
                            files[i].size = file_size;
                            strcpy(files[i].path, full_path);
                            break;
                        }
                    }
                }
            }
        }
    }

    closedir(dir);
}

void print_report(struct FileInfo *files, int file_count) {
    printf("\nTop %d largest files:\n", file_count);
    printf("%-50s %s\n", "File Path", "Size (bytes)");
    printf("%-50s %s\n", "---------", "-----------");
    
    for (int i = 0; i < file_count; i++) {
        printf("%-50s %ld\n", files[i].path, files[i].size);
    }
}

int compare_file_size(const void *a, const void *b) {
    struct FileInfo *file_a = (struct FileInfo *)a;
    struct FileInfo *file_b = (struct FileInfo *)b;
    return (file_b->size - file_a->size);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct FileInfo files[TOP_N] = {0};
    int file_count = 0;

    analyze_directory(argv[1], files, &file_count);

    // Sort files based on size
    qsort(files, file_count, sizeof(struct FileInfo), compare_file_size);

    print_report(files, file_count);

    return EXIT_SUCCESS;
}