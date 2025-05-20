//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define MAX_PATH_LEN 256

typedef struct {
    char *name;
    long size;
    char *owner;
    char *group;
    char *date;
} file_info_t;

int compare_files(const void *a, const void *b) {
    const file_info_t *fa = (const file_info_t *)a;
    const file_info_t *fb = (const file_info_t *)b;

    return strcmp(fa->name, fb->name);
}

void print_file_info(file_info_t *file) {
    printf("%10ld %s %s %s %s\n", file->size, file->name, file->owner, file->group, file->date);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *directory = argv[1];
    char path[MAX_PATH_LEN];

    DIR *dir = opendir(directory);
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    int num_files = 0;
    long total_size = 0;
    file_info_t *files = NULL;

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        snprintf(path, MAX_PATH_LEN, "%s/%s", directory, entry->d_name);

        struct stat st;
        if (lstat(path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (!S_ISREG(st.st_mode)) {
            continue;
        }

        num_files++;
        total_size += st.st_size;

        files = realloc(files, sizeof(file_info_t) * num_files);
        if (files == NULL) {
            perror("realloc");
            return EXIT_FAILURE;
        }

        file_info_t *file = &files[num_files - 1];
        file->name = strdup(entry->d_name);
        file->size = st.st_size;

        struct passwd *pw = getpwuid(st.st_uid);
        if (pw != NULL) {
            file->owner = strdup(pw->pw_name);
        } else {
            file->owner = strdup("unknown");
        }

        struct group *gr = getgrgid(st.st_gid);
        if (gr != NULL) {
            file->group = strdup(gr->gr_name);
        } else {
            file->group = strdup("unknown");
        }

        char *date = ctime(&st.st_mtime);
        file->date = strdup(date);
    }

    closedir(dir);

    qsort(files, num_files, sizeof(file_info_t), compare_files);

    printf("Total size: %ld bytes\n", total_size);
    printf("Number of files: %d\n", num_files);
    printf("\n");
    printf("%10s %s %s %s %s\n", "Size", "Name", "Owner", "Group", "Date");
    for (int i = 0; i < num_files; i++) {
        print_file_info(&files[i]);
    }

    for (int i = 0; i < num_files; i++) {
        free(files[i].name);
        free(files[i].owner);
        free(files[i].group);
        free(files[i].date);
    }
    free(files);

    return EXIT_SUCCESS;
}