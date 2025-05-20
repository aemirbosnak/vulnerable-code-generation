//FormAI DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>

void list_directory(char* path, int level) {
    DIR* dir = opendir(path);
    if (dir == NULL) {
        printf("Error opening directory %s\n", path);
        exit(1);
    }

    struct dirent* de;
    while ((de = readdir(dir)) != NULL) {
        if (strcmp(de->d_name, ".") == 0 || strcmp(de->d_name, "..") == 0) {
            continue;
        }

        printf("%*s%s\n", level * 4, "", de->d_name);
        if (de->d_type == DT_DIR) {
            char new_path[1024];
            snprintf(new_path, sizeof(new_path), "%s/%s", path, de->d_name);
            list_directory(new_path, level + 1);
        }
    }

    closedir(dir);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    char* path = argv[1];
    struct stat sb;
    if (stat(path, &sb) == -1) {
        printf("Error getting file information for %s\n", path);
        exit(1);
    }

    if (!S_ISDIR(sb.st_mode)) {
        printf("%s is not a directory\n", path);
        exit(1);
    }

    printf("%s\n", path);
    list_directory(path, 1);

    return 0;
}