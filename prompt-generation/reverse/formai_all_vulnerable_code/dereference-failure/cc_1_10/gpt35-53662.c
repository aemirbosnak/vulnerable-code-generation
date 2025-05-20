//FormAI DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

#define FILE_BUFSIZ 1024

void sync_directories(char *dir1, char *dir2);
void copy_file(char *src, char *dst, struct stat *st);

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *dir1 = argv[1];
    char *dir2 = argv[2];

    sync_directories(dir1, dir2);

    printf("Done syncing %s and %s\n", dir1, dir2);

    return EXIT_SUCCESS;
}

void sync_directories(char *dir1, char *dir2) {
    DIR *dirp1, *dirp2;
    struct dirent *direntp1, *direntp2;

    if ((dirp1 = opendir(dir1)) == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    if ((dirp2 = opendir(dir2)) == NULL) {
        perror("opendir failed");
        exit(EXIT_FAILURE);
    }

    // Loop over directory 1
    while ((direntp1 = readdir(dirp1)) != NULL) {
        // Ignore hidden files and directories
        if (direntp1->d_name[0] == '.')
            continue;

        char d1_path[FILE_BUFSIZ];
        char d2_path[FILE_BUFSIZ];

        sprintf(d1_path, "%s/%s", dir1, direntp1->d_name);
        sprintf(d2_path, "%s/%s", dir2, direntp1->d_name);

        struct stat st1;
        stat(d1_path, &st1);

        // If file exists in directory 2, check if it needs to be updated
        if ((direntp2 = readdir(dirp2)) != NULL) {
            sprintf(d2_path, "%s/%s", dir2, direntp2->d_name);

            if (strcmp(direntp1->d_name, direntp2->d_name) == 0) {
                struct stat st2;
                stat(d2_path, &st2);

                // If file in directory 1 is newer, copy it to directory 2
                if (st1.st_mtime > st2.st_mtime) {
                    copy_file(d1_path, d2_path, &st1);
                }
            }
        }
        // If file does not exist in directory 2, copy it there
        else {
            copy_file(d1_path, d2_path, &st1);
        }

        rewinddir(dirp2);
    }

    // Loop over directory 2 to check for missing files
    rewinddir(dirp1);

    while ((direntp2 = readdir(dirp2)) != NULL) {
        // Ignore hidden files and directories
        if (direntp2->d_name[0] == '.')
            continue;

        char d2_path[FILE_BUFSIZ];
        sprintf(d2_path, "%s/%s", dir2, direntp2->d_name);

        struct stat st2;
        stat(d2_path, &st2);

        // If file does not exist in directory 1, remove it from directory 2
        if ((direntp1 = readdir(dirp1)) == NULL) {
            unlink(d2_path);
        }

        rewinddir(dirp1);
    }

    closedir(dirp1);
    closedir(dirp2);
}

void copy_file(char *src, char *dst, struct stat *st) {
    FILE *src_file = fopen(src, "rb");
    FILE *dst_file = fopen(dst, "wb");

    if (!src_file || !dst_file) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }

    char buf[FILE_BUFSIZ];
    size_t size;

    while ((size = fread(buf, 1, sizeof(buf), src_file)) > 0) {
        if (fwrite(buf, 1, size, dst_file) != size) {
            perror("fwrite failed");
            exit(EXIT_FAILURE);
        }
    }

    fclose(src_file);
    fclose(dst_file);

    chmod(dst, st->st_mode);
    utime(dst, &st->st_atime);
}