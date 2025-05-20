//FormAI DATASET v1.0 Category: File Synchronizer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

const int BUF_SIZE = 1024;

void sync_files(char* path1, char* path2) {
    DIR* dir1 = opendir(path1);
    DIR* dir2 = opendir(path2);

    if (dir1 == NULL || dir2 == NULL) {
        printf("Unable to open directories\n");
        return;
    }

    struct dirent* dp1, *dp2;

    while ((dp1 = readdir(dir1)) != NULL) {
        char* filename1 = dp1->d_name;

        if (strcmp(filename1, ".") == 0 || strcmp(filename1, "..") == 0) {
            // ignore . and ..
            continue;
        }

        char filepath1[BUF_SIZE];
        strcpy(filepath1, path1);
        strcat(filepath1, "/");
        strcat(filepath1, filename1);

        struct stat st1;
        if (stat(filepath1, &st1) < 0) {
            printf("Error getting file stats for %s\n", filepath1);
            continue;
        }

        int found = 0;

        while ((dp2 = readdir(dir2)) != NULL) {
            char* filename2 = dp2->d_name;

            if (strcmp(filename2, ".") == 0 || strcmp(filename2, "..") == 0) {
                // ignore . and ..
                continue;
            }

            char filepath2[BUF_SIZE];
            strcpy(filepath2, path2);
            strcat(filepath2, "/");
            strcat(filepath2, filename2);

            struct stat st2;
            if (stat(filepath2, &st2) < 0) {
                printf("Error getting file stats for %s\n", filepath2);
                continue;
            }

            if (strcmp(filename1, filename2) == 0) {
                // same file name, check timestamps
                if (st1.st_mtime > st2.st_mtime) {
                    // file in path1 is newer, overwrite file in path2
                    int fd1 = open(filepath1, O_RDONLY);
                    int fd2 = open(filepath2, O_WRONLY | O_TRUNC);
                    char buf[BUF_SIZE];
                    int nread;
                    while ((nread = read(fd1, buf, BUF_SIZE)) > 0) {
                        write(fd2, buf, nread);
                    }
                    printf("%s -> Updated\n", filename1);
                    close(fd1);
                    close(fd2);
                }
                found = 1;
                break;
            }
        }

        if (!found) {
            // file not found in path2, copy file over
            int fd1 = open(filepath1, O_RDONLY);
            char filepath2[BUF_SIZE];
            strcpy(filepath2, path2);
            strcat(filepath2, "/");
            strcat(filepath2, filename1);
            int fd2 = open(filepath2, O_CREAT | O_WRONLY, st1.st_mode);
            char buf[BUF_SIZE];
            int nread;
            while ((nread = read(fd1, buf, BUF_SIZE)) > 0) {
                write(fd2, buf, nread);
            }
            printf("%s -> Copied\n", filename1);
            close(fd1);
            close(fd2); 
        }
        rewinddir(dir2);
    }

    closedir(dir1);
    closedir(dir2);
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("Usage: %s [directory1] [directory2]\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    return 0;
}