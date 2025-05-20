//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUF_SIZE 256

void dir_compare(const char *dir1, const char *dir2) {
    struct stat st1, st2;
    DIR *dp1, *dp2;
    char buf[BUF_SIZE];

    if ((dp1 = opendir(dir1)) == NULL) {
        printf("Cannot open directory %s\n", dir1);
        return;
    }

    if ((dp2 = opendir(dir2)) == NULL) {
        printf("Cannot open directory %s\n", dir2);
        return;
    }

    while (1) {
        if (readdir(dp1) == NULL) {
            closedir(dp1);
            break;
        }

        if (stat(dir1, &st1)!= 0) {
            printf("Cannot get directory info for %s\n", dir1);
            return;
        }

        if (stat(dir2, &st2)!= 0) {
            printf("Cannot get directory info for %s\n", dir2);
            return;
        }

        if (strcmp(readdir(dp1)->d_name, ".") == 0 || strcmp(readdir(dp1)->d_name, "..") == 0) {
            continue;
        }

        sprintf(buf, "%s/%s", dir1, readdir(dp1)->d_name);
        if (stat(buf, &st1) == 0) {
            if (st1.st_mtime!= st2.st_mtime) {
                printf("File %s modified in %s\n", readdir(dp1)->d_name, dir2);
            }
        } else {
            printf("File %s not found in %s\n", readdir(dp1)->d_name, dir2);
        }
    }

    closedir(dp1);
    closedir(dp2);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        return 1;
    }

    dir_compare(argv[1], argv[2]);

    return 0;
}