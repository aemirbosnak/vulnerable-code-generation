//FormAI DATASET v1.0 Category: Disk space analyzer ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

void analyze_directory(const char *root_path, const char *prefix, const int depth, long long *total_size) {
    DIR *dir;
    struct dirent *entry;
    char sub_path[1024];
    struct stat file_stat;
    long long size = 0;

    if ((dir = opendir(root_path)) == NULL) {
        perror("Error opening directory");
        return;
    }

    printf("%*s+ %s/\n", depth*2, prefix, root_path);

    while ((entry = readdir(dir)) != NULL) {
        sprintf(sub_path, "%s/%s", root_path, entry->d_name);

        if (stat(sub_path, &file_stat) == -1) {
            perror("Error getting file information");
            continue;
        }

        if (S_ISDIR(file_stat.st_mode)) {
            if (strcmp(entry->d_name,".") == 0 || strcmp(entry->d_name,"..") == 0) {
                continue;
            }

            analyze_directory(sub_path, "|", depth+1, total_size);
        } else {
            printf("%*s%s [size=%lld bytes]\n", (depth+1)*2, prefix, entry->d_name, (long long)file_stat.st_size);
            size += file_stat.st_size;
        }
    }

    printf("%*sTotal size: %lld bytes\n", (depth+1)*2, prefix, size);
    *total_size += size;
    closedir(dir);
}

int main() {
    const char *root_path = "/usr";
    long long total_size = 0;
    analyze_directory(root_path, "", 0, &total_size);
    printf("Total disk space used by %s: %lld bytes\n", root_path, total_size);

    return 0;
}