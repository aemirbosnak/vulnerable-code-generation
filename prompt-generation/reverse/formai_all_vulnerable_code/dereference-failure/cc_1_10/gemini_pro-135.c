//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

#define KILO  1024
#define MEGA  (KILO * KILO)
#define GIGA  (MEGA * KILO)

struct file_info {
    char *name;
    off_t size;
    time_t mtime;
};

int compare_file_size(const void *a, const void *b)
{
    const struct file_info *fa = a;
    const struct file_info *fb = b;

    return fa->size - fb->size;
}

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    struct file_info *files;
    int nfiles = 0;
    int i;
    off_t total_size = 0;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s directory\n", argv[0]);
        return EXIT_FAILURE;
    }

    dir = opendir(argv[1]);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (ent->d_type == DT_REG) {
            char path[PATH_MAX];

            snprintf(path, sizeof(path), "%s/%s", argv[1], ent->d_name);
            if (stat(path, &st) == -1) {
                perror("stat");
                continue;
            }

            files = realloc(files, (nfiles + 1) * sizeof(struct file_info));
            if (files == NULL) {
                perror("realloc");
                closedir(dir);
                return EXIT_FAILURE;
            }

            files[nfiles].name = strdup(ent->d_name);
            if (files[nfiles].name == NULL) {
                perror("strdup");
                closedir(dir);
                return EXIT_FAILURE;
            }

            files[nfiles].size = st.st_size;
            files[nfiles].mtime = st.st_mtime;
            nfiles++;

            total_size += st.st_size;
        }
    }

    closedir(dir);

    qsort(files, nfiles, sizeof(struct file_info), compare_file_size);

    for (i = 0; i < nfiles; i++) {
        char size[32];

        if (files[i].size < KILO) {
            snprintf(size, sizeof(size), "%lld bytes", files[i].size);
        } else if (files[i].size < MEGA) {
            snprintf(size, sizeof(size), "%.2f KB", (double)files[i].size / KILO);
        } else if (files[i].size < GIGA) {
            snprintf(size, sizeof(size), "%.2f MB", (double)files[i].size / MEGA);
        } else {
            snprintf(size, sizeof(size), "%.2f GB", (double)files[i].size / GIGA);
        }

        printf("%s (%s) - %s\n", files[i].name, size, ctime(&files[i].mtime));
    }

    if (total_size < KILO) {
        printf("Total size: %lld bytes\n", total_size);
    } else if (total_size < MEGA) {
        printf("Total size: %.2f KB\n", (double)total_size / KILO);
    } else if (total_size < GIGA) {
        printf("Total size: %.2f MB\n", (double)total_size / MEGA);
    } else {
        printf("Total size: %.2f GB\n", (double)total_size / GIGA);
    }

    for (i = 0; i < nfiles; i++) {
        free(files[i].name);
    }
    free(files);

    return EXIT_SUCCESS;
}