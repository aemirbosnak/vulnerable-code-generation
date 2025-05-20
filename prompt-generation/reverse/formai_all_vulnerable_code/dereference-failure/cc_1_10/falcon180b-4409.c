//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <sys/stat.h>

#define MAX_PATTERN_LENGTH 1024
#define MAX_FILE_NAME_LENGTH 4096

typedef struct {
    char *pattern;
    int pattern_length;
    int (*callback)(FILE *file, void *data);
    void *data;
} ScanPattern;

int scan_file(FILE *file, void *data) {
    char buffer[4096];
    int bytes_read;
    int total_bytes_read = 0;

    while ((bytes_read = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        total_bytes_read += bytes_read;

        if (data!= NULL) {
            data = (*(int(*)())data)(buffer, bytes_read);
        }
    }

    return total_bytes_read;
}

int scan_directory(const char *path, ScanPattern *patterns, int pattern_count) {
    DIR *dir;
    struct dirent *ent;
    int total_bytes_scanned = 0;

    dir = opendir(path);

    if (dir == NULL) {
        return -1;
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_REG) {
            char file_path[MAX_FILE_NAME_LENGTH];
            snprintf(file_path, sizeof(file_path), "%s/%s", path, ent->d_name);

            FILE *file = fopen(file_path, "rb");

            if (file!= NULL) {
                for (int i = 0; i < pattern_count; i++) {
                    total_bytes_scanned += scan_file(file, patterns[i].data);
                }

                fclose(file);
            }
        }
    }

    closedir(dir);

    return total_bytes_scanned;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <directory> <pattern1> [<pattern2>...]\n", argv[0]);
        return 1;
    }

    char *directory = argv[1];
    int pattern_count = argc - 2;
    ScanPattern *patterns = malloc(sizeof(ScanPattern) * pattern_count);

    for (int i = 0; i < pattern_count; i++) {
        patterns[i].pattern = argv[i + 2];
        patterns[i].pattern_length = strlen(patterns[i].pattern);
        patterns[i].callback = &scan_file;
        patterns[i].data = NULL;
    }

    int total_bytes_scanned = scan_directory(directory, patterns, pattern_count);

    printf("Scanned %d bytes in %d files.\n", total_bytes_scanned, pattern_count);

    for (int i = 0; i < pattern_count; i++) {
        free(patterns[i].pattern);
    }

    free(patterns);

    return 0;
}