//FormAI DATASET v1.0 Category: Music Library Management System ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <libgen.h>

#define MAX_PATH 1024

static bool is_dir(const char *path)
{
    struct stat st;
    return (stat(path, &st) == 0) && S_ISDIR(st.st_mode);
}

static bool is_audio_file(const char *path)
{
    const char *ext = strrchr(path, '.');
    if (!ext) return false;
    return strcmp(ext, ".mp3") == 0 ||
           strcmp(ext, ".ogg") == 0 ||
           strcmp(ext, ".m4a") == 0;
}

static void list_directory(const char *dir_path, char **result, int *count, int max_count)
{
    DIR *dir = opendir(dir_path);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory %s: %s\n", dir_path, strerror(errno));
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR) {
            // skip "." and ".." directories
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
                continue;
            }

            // recursively list subdirectory
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            list_directory(path, result, count, max_count);
        } else if (entry->d_type == DT_REG && is_audio_file(entry->d_name)) {
            // add file to list
            char path[MAX_PATH];
            snprintf(path, sizeof(path), "%s/%s", dir_path, entry->d_name);
            if (*count < max_count) {
                result[*count] = strdup(path);
                (*count)++;
            }
        }
    }
    closedir(dir);
}

static int compare_strings(const void *a, const void *b)
{
    return strcmp(*(char **)a, *(char **)b);
}

static void sort_list(char **list, int count)
{
    qsort(list, count, sizeof(char *), compare_strings);
}

static void print_list(char **list, int count)
{
    for (int i = 0; i < count; i++) {
        printf("%s\n", basename(list[i]));
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s [directory]\n", argv[0]);
        return 1;
    }

    const char *dir_path = argv[1];
    if (!is_dir(dir_path)) {
        printf("Error: %s is not a directory\n", dir_path);
        return 1;
    }

    const int max_count = 1000;
    char *audio_files[max_count];
    int count = 0;

    list_directory(dir_path, audio_files, &count, max_count);
    sort_list(audio_files, count);
    print_list(audio_files, count);

    for (int i = 0; i < count; i++) {
        free(audio_files[i]);
    }

    return 0;
}