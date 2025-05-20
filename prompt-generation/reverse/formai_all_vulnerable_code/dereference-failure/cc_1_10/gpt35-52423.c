//FormAI DATASET v1.0 Category: File Synchronizer ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024

void synchronize(const char *dir1, const char *dir2);
void recursive_sync(const char *path1, const char *path2);
void sync_file(const char *path1, const char *path2);
void check_and_create_directory(const char *dir_path, const char *sync_to_path);
void sync_permissions(const char *path1, const char *path2);
void sync_time_modified(const char *path1, const char *path2);
void sync_content(const char *path1, const char *path2);

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dir1> <dir2>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    synchronize(argv[1], argv[2]);
    return 0;
}

void synchronize(const char *dir1, const char *dir2) {
    DIR *dirp1 = opendir(dir1);
    if (dirp1 == NULL) {
        fprintf(stderr, "Could not open directory \"%s\": %s\n", dir1, strerror(errno));
        exit(EXIT_FAILURE);
    }

    DIR *dirp2 = opendir(dir2);
    if (dirp2 == NULL) {
        fprintf(stderr, "Could not open directory \"%s\": %s\n", dir2, strerror(errno));
        exit(EXIT_FAILURE);
    }

    recursive_sync(dir1, dir2);
    recursive_sync(dir2, dir1);

    closedir(dirp1);
    closedir(dirp2);
}

void recursive_sync(const char *path1, const char *path2) {
    struct dirent *dp;
    DIR *dirp1 = opendir(path1);
    if (dirp1 == NULL) {
        fprintf(stderr, "Could not open directory \"%s\": %s\n", path1, strerror(errno));
        return;
    }

    while ((dp = readdir(dirp1)) != NULL) {
        if (dp->d_name[0] == '.') continue; // skip hidden files and directories

        char path1_buf[BUF_SIZE];
        snprintf(path1_buf, BUF_SIZE, "%s/%s", path1, dp->d_name);

        char path2_buf[BUF_SIZE];
        snprintf(path2_buf, BUF_SIZE, "%s/%s", path2, dp->d_name);

        struct stat statbuf1;
        if (lstat(path1_buf, &statbuf1) == -1) {
            fprintf(stderr, "Could not stat file \"%s\": %s\n", path1_buf, strerror(errno));
        } else {
            struct stat statbuf2;
            if (lstat(path2_buf, &statbuf2) == -1) {
                // if the file doesn't exist in the other directory, directly create it
                if (errno == ENOENT) {
                    sync_file(path1_buf, path2_buf);
                } else {
                    fprintf(stderr, "Could not stat file \"%s\": %s\n", path2_buf, strerror(errno));
                }
            } else {
                // if the file types are different, ignore
                if (S_ISDIR(statbuf1.st_mode) != S_ISDIR(statbuf2.st_mode)) continue;

                if (S_ISDIR(statbuf1.st_mode)) {
                    recursive_sync(path1_buf, path2_buf);
                } else {
                    sync_file(path1_buf, path2_buf);
                }

                sync_permissions(path1_buf, path2_buf);
                sync_time_modified(path1_buf, path2_buf);
            }
        }
    }

    closedir(dirp1);
}

void sync_file(const char *path1, const char *path2) {
    FILE *fp1 = fopen(path1, "rb");
    if (fp1 == NULL) {
        fprintf(stderr, "Could not open file \"%s\": %s\n", path1, strerror(errno));
        return;
    }

    FILE *fp2 = fopen(path2, "wb");
    if (fp2 == NULL) {
        fprintf(stderr, "Could not open file \"%s\": %s\n", path2, strerror(errno));
        fclose(fp1);
        return;
    }

    char buf[BUF_SIZE];
    size_t nread;
    while ((nread = fread(buf, 1, BUF_SIZE, fp1)) > 0) {
        fwrite(buf, 1, nread, fp2);
    }

    fclose(fp1);
    fclose(fp2);
}

void check_and_create_directory(const char *dir_path, const char *sync_to_path) {
    struct stat statbuf;
    if (lstat(dir_path, &statbuf) == -1) {
        if (errno == ENOENT) {
            printf("Creating directory \"%s\".\n", sync_to_path);
            if (mkdir(sync_to_path, S_IRWXU | S_IRWXG | S_IRWXO) == -1) {
                fprintf(stderr, "Could not create directory \"%s\": %s\n", sync_to_path, strerror(errno));
            }
        } else {
            fprintf(stderr, "Could not stat directory \"%s\": %s\n", dir_path, strerror(errno));
        }
    } else {
        if (!S_ISDIR(statbuf.st_mode)) {
            printf("\"%s\" is not a directory, skipping.\n", sync_to_path);
        }
    }
}

void sync_permissions(const char *path1, const char *path2) {
    struct stat statbuf1;
    if (lstat(path1, &statbuf1) == -1) {
        fprintf(stderr, "Could not stat file \"%s\": %s\n", path1, strerror(errno));
    } else {
        struct stat statbuf2;
        if (lstat(path2, &statbuf2) == -1) {
            fprintf(stderr, "Could not stat file \"%s\": %s\n", path2, strerror(errno));
        } else {
            if ((statbuf1.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)) != (statbuf2.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO))) {
                if (chmod(path2, statbuf1.st_mode) == -1) {
                    fprintf(stderr, "Could not modify permissions of file \"%s\": %s\n", path2, strerror(errno));
                }
            }
        }
    }
}

void sync_time_modified(const char *path1, const char *path2) {
    struct stat statbuf1;
    if (lstat(path1, &statbuf1) == -1) {
        fprintf(stderr, "Could not stat file \"%s\": %s\n", path1, strerror(errno));
    } else {
        struct stat statbuf2;
        if (lstat(path2, &statbuf2) == -1) {
            fprintf(stderr, "Could not stat file \"%s\": %s\n", path2, strerror(errno));
        } else {
            if (statbuf1.st_mtime != statbuf2.st_mtime) {
                struct timeval times[2];
                times[0].tv_sec = statbuf1.st_atime;
                times[0].tv_usec = 0;
                times[1].tv_sec = statbuf1.st_mtime;
                times[1].tv_usec = 0;
                if (utimes(path2, times) == -1) {
                    fprintf(stderr, "Could not modify time modified of file \"%s\": %s\n", path2, strerror(errno));
                }
            }
        }
    }
}

void sync_content(const char *path1, const char *path2) {
    struct stat statbuf1;
    if (lstat(path1, &statbuf1) == -1) {
        fprintf(stderr, "Could not stat file \"%s\": %s\n", path1, strerror(errno));
    } else {
        struct stat statbuf2;
        if (lstat(path2, &statbuf2) == -1) {
            fprintf(stderr, "Could not stat file \"%s\": %s\n", path2, strerror(errno));
        } else {
            if (statbuf1.st_size != statbuf2.st_size) {
                sync_file(path1, path2);
            } else {
                FILE *fp1 = fopen(path1, "rb");
                if (fp1 == NULL) {
                    fprintf(stderr, "Could not open file \"%s\": %s\n", path1, strerror(errno));
                } else {
                    FILE *fp2 = fopen(path2, "rb");
                    if (fp2 == NULL) {
                        fprintf(stderr, "Could not open file \"%s\": %s\n", path2, strerror(errno));
                        fclose(fp1);
                    } else {
                        char buf1[BUF_SIZE], buf2[BUF_SIZE];
                        while (!feof(fp1) || !feof(fp2)) {
                            size_t nread1 = fread(buf1, 1, BUF_SIZE, fp1);
                            size_t nread2 = fread(buf2, 1, BUF_SIZE, fp2);
                            if (nread1 != nread2 || memcmp(buf1, buf2, nread1) != 0) {
                                sync_file(path1, path2);
                                break;
                            }
                        }
                        fclose(fp1);
                        fclose(fp2);
                    }
                }
            }
        }
    }
}