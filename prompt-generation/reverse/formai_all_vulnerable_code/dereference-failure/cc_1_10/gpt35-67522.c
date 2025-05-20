//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>

struct directory {
    char name[256];
    struct directory *subdirs;
    int num_subdirs;
    long long size;
};

void analyze_dir(const char *path, struct directory *dir) {
    DIR *d = opendir(path);
    struct dirent *entry;
    while ((entry = readdir(d)) != NULL) {
        if (entry->d_type == DT_DIR && strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0) {
            // This is a subdirectory
            struct directory *subdir = malloc(sizeof(struct directory));
            strcpy(subdir->name, entry->d_name);
            subdir->subdirs = NULL;
            subdir->num_subdirs = 0;
            subdir->size = 0;
            analyze_dir(entry->d_name, subdir);
            dir->subdirs = realloc(dir->subdirs, sizeof(struct directory) * (dir->num_subdirs + 1));
            dir->subdirs[dir->num_subdirs] = *subdir;
            dir->num_subdirs++;
            dir->size += subdir->size;
            free(subdir);
        } else if (entry->d_type == DT_REG) {
            // This is a regular file
            char file_path[512];
            sprintf(file_path, "%s/%s", path, entry->d_name);
            struct stat st;
            if (stat(file_path, &st) == 0) {
                dir->size += st.st_size;
            }
        }
    }
    closedir(d);
}

int main(void) {
    struct directory root = {"root", NULL, 0, 0};
    analyze_dir(".", &root);
    printf("Total size: %lld\n", root.size);
    printf("Subdirectories:\n");
    for (int i = 0; i < root.num_subdirs; i++) {
        printf("- %s: %lld\n", root.subdirs[i].name, root.subdirs[i].size);
    }
    return 0;
}