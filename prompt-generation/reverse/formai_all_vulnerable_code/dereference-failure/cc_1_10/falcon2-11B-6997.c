//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    char buf[255];
    DIR *dirp;
    struct dirent *dp;
    struct stat st;
    int fd, i;
    char *file_name;
    FILE *fp;

    dirp = opendir(".");
    if (dirp == NULL) {
        printf("Error opening directory\n");
        exit(1);
    }

    while ((dp = readdir(dirp))!= NULL) {
        if (dp->d_type == DT_REG) {
            file_name = dp->d_name;
            stat(file_name, &st);
            if (S_ISREG(st.st_mode)) {
                fd = open(file_name, O_RDONLY);
                if (fd == -1) {
                    printf("Error opening file %s\n", file_name);
                    continue;
                }
                fp = fdopen(fd, "r");
                if (fp == NULL) {
                    printf("Error opening file for reading %s\n", file_name);
                    exit(1);
                }

                while (fgets(buf, sizeof(buf), fp)!= NULL) {
                    // Your data recovery code goes here
                }
                fclose(fp);
                closedir(dirp);
                exit(0);
            }
        }
    }
    closedir(dirp);
    return 0;
}