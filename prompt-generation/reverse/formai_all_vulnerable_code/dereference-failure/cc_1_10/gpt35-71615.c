//FormAI DATASET v1.0 Category: File Synchronizer ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

#define MAX_BUF 1024

// compare two files
bool compare_files(const char *file1, const char *file2) {
    int fd1, fd2;
    char buf1[MAX_BUF], buf2[MAX_BUF];
    ssize_t n_read1, n_read2;

    fd1 = open(file1, O_RDONLY);
    if (fd1 < 0) {
        perror("open");
        return false;
    }

    fd2 = open(file2, O_RDONLY);
    if (fd2 < 0) {
        close(fd1);
        perror("open");
        return false;
    }

    // read and compare the two files
    while (true) {
        n_read1 = read(fd1, buf1, MAX_BUF);
        if (n_read1 < 0) {
            perror("read");
            close(fd1);
            close(fd2);
            return false;
        }

        n_read2 = read(fd2, buf2, MAX_BUF);
        if (n_read2 < 0) {
            perror("read");
            close(fd1);
            close(fd2);
            return false;
        }

        if (n_read1 != n_read2) {
            close(fd1);
            close(fd2);
            return false;
        }

        if (memcmp(buf1, buf2, n_read1)) {
            close(fd1);
            close(fd2);
            return false;
        }

        if (n_read1 == 0) break;
    }

    close(fd1);
    close(fd2);

    return true;
}

// synchronize two directories
void sync_directories(const char *dir1, const char *dir2) {
    DIR *d1, *d2;
    struct dirent *ent1, *ent2;
    struct stat st1, st2;
    int rc;

    // open the first directory
    d1 = opendir(dir1);
    if (d1 == NULL) {
        perror("opendir");
        return;
    }

    // create the second directory if it doesn't exist
    if (mkdir(dir2, 0777) != 0 && errno != EEXIST) {
        perror("mkdir");
        closedir(d1);
        return;
    }

    // open the second directory
    d2 = opendir(dir2);
    if (d2 == NULL) {
        perror("opendir");
        closedir(d1);
        return;
    }

    // sync files from dir1 to dir2
    while ((ent1 = readdir(d1)) != NULL) {
        // skip . and ..
        if (strcmp(ent1->d_name, ".") == 0 ||
            strcmp(ent1->d_name, "..") == 0)
            continue;

        // get the path of the file in dir1
        char path1[MAX_BUF];
        snprintf(path1, MAX_BUF, "%s/%s", dir1, ent1->d_name);

        // get the stat information for the file in dir1
        rc = stat(path1, &st1);
        if (rc < 0) {
            perror("stat");
            continue;
        }

        // if it's a directory, recursively sync the directories
        if (S_ISDIR(st1.st_mode)) {
            // get the path of the corresponding directory in dir2
            char path2[MAX_BUF];
            snprintf(path2, MAX_BUF, "%s/%s", dir2, ent1->d_name);

            // sync the directories recursively
            sync_directories(path1, path2);
        } else if (S_ISREG(st1.st_mode)) {
            // get the path of the file in dir2
            char path2[MAX_BUF];
            snprintf(path2, MAX_BUF, "%s/%s", dir2, ent1->d_name);

            // if the file doesn't exist in dir2 or it's different,
            // copy it over
            if (access(path2, F_OK) != 0 || !compare_files(path1, path2)) {
                int fd1, fd2;
                char buf[MAX_BUF];
                ssize_t n_read, n_written;

                // open the source file for reading
                fd1 = open(path1, O_RDONLY);
                if (fd1 < 0) {
                    perror("open");
                    continue;
                }

                // open the destination file for writing
                fd2 = open(path2, O_WRONLY | O_TRUNC | O_CREAT, 0666);
                if (fd2 < 0) {
                    perror("open");
                    close(fd1);
                    continue;
                }

                // copy the contents of the source file to the destination file
                while (true) {
                    n_read = read(fd1, buf, MAX_BUF);
                    if (n_read < 0) {
                        perror("read");
                        close(fd1);
                        close(fd2);
                        break;
                    }

                    if (n_read == 0) break;

                    n_written = write(fd2, buf, n_read);
                    if (n_written < n_read) {
                        perror("write");
                        close(fd1);
                        close(fd2);
                        break;
                    }
                }

                close(fd1);
                close(fd2);
            }
        }
    }

    closedir(d1);
    closedir(d2);
}

int main(int argc, char **argv) {
    // check that we have two arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // synchronize the directories
    sync_directories(argv[1], argv[2]);

    return 0;
}