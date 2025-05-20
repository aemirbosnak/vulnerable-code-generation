//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#define DEFAULT_BLOCK_SIZE 4096
#define MAX_PATH_LENGTH 255

typedef struct file_info {
    char path[MAX_PATH_LENGTH];
    size_t size;
    uid_t uid;
    gid_t gid;
    struct tm *mtime;
} file_info_t;

int compare_file_infos(const void *a, const void *b) {
    const file_info_t *a_info = (const file_info_t *)a;
    const file_info_t *b_info = (const file_info_t *)b;
    return (int)(a_info->size - b_info->size);
}

void print_file_info(const file_info_t *file_info) {
    struct passwd *pw = getpwuid(file_info->uid);
    struct group *gr = getgrgid(file_info->gid);
    char mtime_str[26];
    strftime(mtime_str, sizeof(mtime_str), "%Y-%m-%d %H:%M:%S", file_info->mtime);

    printf("%-10s %7lu %7lu %s %s %s %s\n",
        mtime_str,
        file_info->size,
        file_info->uid,
        pw->pw_name,
        file_info->gid,
        gr->gr_name,
        file_info->path);
}

void scan_directory(const char *path, file_info_t *file_infos, size_t *num_file_infos) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    struct stat st;
    while ((entry = readdir(dir)) != NULL) {
        if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, "..")) {
            continue;
        }

        char full_path[MAX_PATH_LENGTH];
        snprintf(full_path, sizeof(full_path), "%s/%s", path, entry->d_name);

        if (lstat(full_path, &st) == -1) {
            perror("lstat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            scan_directory(full_path, file_infos, num_file_infos);
        } else {
            file_info_t *new_file_info = &file_infos[*num_file_infos];
            strcpy(new_file_info->path, full_path);
            new_file_info->size = st.st_size;
            new_file_info->uid = st.st_uid;
            new_file_info->gid = st.st_gid;
            new_file_info->mtime = gmtime(&st.st_mtime);
            (*num_file_infos)++;
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    char *path = ".";
    if (argc > 1) {
        path = argv[1];
    }

    file_info_t file_infos[1024];
    size_t num_file_infos = 0;
    scan_directory(path, file_infos, &num_file_infos);

    qsort(file_infos, num_file_infos, sizeof(file_info_t), compare_file_infos);

    for (size_t i = 0; i < num_file_infos; i++) {
        print_file_info(&file_infos[i]);
    }

    return 0;
}