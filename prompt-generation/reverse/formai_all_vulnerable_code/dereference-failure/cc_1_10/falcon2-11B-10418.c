//Falcon2-11B DATASET v1.0 Category: Disk space analyzer ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define MAX_PATH_LEN 256

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <path>\n", argv[0]);
        return 1;
    }

    char path[MAX_PATH_LEN];
    strcpy(path, argv[1]);

    struct stat st;
    if (stat(path, &st)!= 0) {
        fprintf(stderr, "Could not stat path '%s'\n", path);
        return 2;
    }

    if (S_ISDIR(st.st_mode)) {
        DIR *dir = opendir(path);
        if (dir == NULL) {
            fprintf(stderr, "Could not open directory '%s'\n", path);
            return 3;
        }

        struct dirent *entry;
        while ((entry = readdir(dir))!= NULL) {
            if (entry->d_type == DT_REG) {
                char filename[MAX_PATH_LEN];
                sprintf(filename, "%s/%s", path, entry->d_name);
                if (stat(filename, &st)!= 0) {
                    fprintf(stderr, "Could not stat file '%s'\n", filename);
                    return 4;
                }

                if (S_ISREG(st.st_mode)) {
                    fprintf(stderr, "File '%s' is a regular file\n", filename);
                } else if (S_ISDIR(st.st_mode)) {
                    fprintf(stderr, "File '%s' is a directory\n", filename);
                } else {
                    fprintf(stderr, "File '%s' is an unknown type\n", filename);
                }
            }
        }

        closedir(dir);
    } else {
        fprintf(stderr, "Path '%s' is not a directory\n", path);
    }

    return 0;
}