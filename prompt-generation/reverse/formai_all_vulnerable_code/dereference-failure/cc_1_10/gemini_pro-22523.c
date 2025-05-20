//GEMINI-pro DATASET v1.0 Category: Disk space analyzer ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void print_tree(char *path, int level) {
    DIR *dir = opendir(path);
    if (dir == NULL) {
        perror("opendir");
        return;
    }

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue;
        }

        char full_path[strlen(path) + strlen(entry->d_name) + 2];
        sprintf(full_path, "%s/%s", path, entry->d_name);

        struct stat statbuf;
        if (stat(full_path, &statbuf) == -1) {
            perror("stat");
            continue;
        }

        for (int i = 0; i < level; i++) {
            printf("    ");
        }

        if (S_ISDIR(statbuf.st_mode)) {
            printf("%s\n", entry->d_name);
            print_tree(full_path, level + 1);
        } else {
            printf("%s (%ld bytes)\n", entry->d_name, statbuf.st_size);
        }
    }

    closedir(dir);
}

int main() {
    char path[1024];
    printf("Enter the path to analyze: ");
    scanf("%s", path);

    print_tree(path, 0);

    return 0;
}