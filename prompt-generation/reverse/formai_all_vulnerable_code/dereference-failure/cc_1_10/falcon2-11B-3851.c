//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>

void displayUsage() {
    printf("Usage:./disk-space <directory>\n");
}

void printDirectory(const char *path, int depth, char *fileName) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                if (depth < 3) {
                    printf("%*s%s%s\n", depth * 4, "", ent->d_name, "");
                    printDirectory(path, depth + 1, ent->d_name);
                }
            }
        } else {
            if (strcmp(ent->d_name, ".")!= 0 && strcmp(ent->d_name, "..")!= 0) {
                printf("%*s%s%s\n", depth * 4, "", ent->d_name, "");
                struct stat st;
                stat(path, &st);
                printf("Size: %d\n", st.st_size);
            }
        }
    }

    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        displayUsage();
        return EXIT_FAILURE;
    }

    char path[PATH_MAX];
    strcpy(path, argv[1]);
    printDirectory(path, 0, NULL);

    return EXIT_SUCCESS;
}