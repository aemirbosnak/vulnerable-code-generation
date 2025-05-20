//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH 1024

struct file_info {
    char *name;
    long size;
};

struct file_info *files;
int num_files;

void analyze_directory(char *path) {
    DIR *dir;
    struct dirent *ent;
    char full_path[MAX_PATH];

    if ((dir = opendir(path)) == NULL) {
        perror("opendir");
        return;
    }

    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0) {
            continue;
        }

        snprintf(full_path, sizeof(full_path), "%s/%s", path, ent->d_name);

        struct stat st;
        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            analyze_directory(full_path);
        } else {
            files = realloc(files, sizeof(struct file_info) * (num_files + 1));
            files[num_files].name = strdup(ent->d_name);
            files[num_files].size = st.st_size;
            num_files++;
        }
    }

    closedir(dir);
}

int compare_files(const void *a, const void *b) {
    struct file_info *fa = (struct file_info *)a;
    struct file_info *fb = (struct file_info *)b;

    return fb->size - fa->size;
}

void print_results() {
    qsort(files, num_files, sizeof(struct file_info), compare_files);

    printf("Top 10 largest files:\n");
    for (int i = 0; i < 10 && i < num_files; i++) {
        printf("%s: %ld bytes\n", files[i].name, files[i].size);
    }

    free(files);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    analyze_directory(argv[1]);
    print_results();

    return 0;
}