//GEMINI-pro DATASET v1.0 Category: File Synchronizer ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define BUF_SIZE 4096

// Function to copy a file
int copy_file(char *src, char *dest) {
    int fd_src, fd_dest;
    char buf[BUF_SIZE];
    int nread;

    if ((fd_src = open(src, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    if ((fd_dest = open(dest, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR)) == -1) {
        perror("open");
        return -1;
    }

    while ((nread = read(fd_src, buf, BUF_SIZE)) > 0) {
        if (write(fd_dest, buf, nread) == -1) {
            perror("write");
            return -1;
        }
    }

    if (nread == -1) {
        perror("read");
        return -1;
    }

    if (close(fd_src) == -1) {
        perror("close");
        return -1;
    }

    if (close(fd_dest) == -1) {
        perror("close");
        return -1;
    }

    return 0;
}

// Function to compare two files
int compare_files(char *file1, char *file2) {
    struct stat stat1, stat2;
    int fd1, fd2;
    char buf1[BUF_SIZE], buf2[BUF_SIZE];
    int nread1, nread2;

    if (stat(file1, &stat1) == -1) {
        perror("stat");
        return -1;
    }

    if (stat(file2, &stat2) == -1) {
        perror("stat");
        return -1;
    }

    if (stat1.st_size != stat2.st_size) {
        return -1;
    }

    if ((fd1 = open(file1, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    if ((fd2 = open(file2, O_RDONLY)) == -1) {
        perror("open");
        return -1;
    }

    while ((nread1 = read(fd1, buf1, BUF_SIZE)) > 0) {
        if ((nread2 = read(fd2, buf2, BUF_SIZE)) != nread1) {
            return -1;
        }

        if (memcmp(buf1, buf2, nread1) != 0) {
            return -1;
        }
    }

    if (nread1 == -1) {
        perror("read");
        return -1;
    }

    if (close(fd1) == -1) {
        perror("close");
        return -1;
    }

    if (close(fd2) == -1) {
        perror("close");
        return -1;
    }

    return 0;
}

// Function to synchronize two directories
int sync_dirs(char *dir1, char *dir2) {
    DIR *dp1, *dp2;
    struct dirent *dirent1, *dirent2;
    char path1[PATH_MAX], path2[PATH_MAX];

    if ((dp1 = opendir(dir1)) == NULL) {
        perror("opendir");
        return -1;
    }

    if ((dp2 = opendir(dir2)) == NULL) {
        perror("opendir");
        return -1;
    }

    while ((dirent1 = readdir(dp1)) != NULL) {
        if (strcmp(dirent1->d_name, ".") == 0 || strcmp(dirent1->d_name, "..") == 0) {
            continue;
        }

        snprintf(path1, sizeof(path1), "%s/%s", dir1, dirent1->d_name);
        snprintf(path2, sizeof(path2), "%s/%s", dir2, dirent1->d_name);

        if (dirent1->d_type == DT_DIR) {
            if (sync_dirs(path1, path2) == -1) {
                return -1;
            }
        } else if (dirent1->d_type == DT_REG) {
            if (compare_files(path1, path2) == -1) {
                if (copy_file(path1, path2) == -1) {
                    return -1;
                }
            }
        } else {
            printf("Unknown file type: %s\n", dirent1->d_name);
        }
    }

    if (closedir(dp1) == -1) {
        perror("closedir");
        return -1;
    }

    if (closedir(dp2) == -1) {
        perror("closedir");
        return -1;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <dir1> <dir2>\n", argv[0]);
        return -1;
    }

    if (sync_dirs(argv[1], argv[2]) == -1) {
        return -1;
    }

    return 0;
}