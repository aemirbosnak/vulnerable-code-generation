//FormAI DATASET v1.0 Category: File Synchronizer ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

#define BUF_SIZE 1024

void sync_files(char *src_path, char *dest_path);
void copy_file(char *src, char *dest, struct stat statbuf);
void sync_dir(char *src_path, char *dest_path);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: file_sync <source_directory> <destination_directory>\n");
        exit(1);
    }

    char *src_path = argv[1];
    char *dest_path = argv[2];

    sync_files(src_path, dest_path);

    printf("Sync successful!\n");

    return 0;
}

void sync_files(char *src_path, char *dest_path) {
    DIR *src_dir;
    struct dirent *entry;
    struct stat src_statbuf, dest_statbuf;
    char src[1024], dest[1024], dest_file[1024];

    if ((src_dir = opendir(src_path)) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(src_dir)) != NULL) {
        sprintf(src, "%s/%s", src_path, entry -> d_name);
        sprintf(dest, "%s/%s", dest_path, entry -> d_name);
        
        if (strcmp(entry -> d_name, ".") == 0 || strcmp(entry -> d_name, "..") == 0) {
            continue;
        }

        if (stat(src, &src_statbuf) < 0) {
            perror("stat");
            exit(1);
        }

        if (stat(dest, &dest_statbuf) == 0) {
            if (difftime(src_statbuf.st_mtime, dest_statbuf.st_mtime) > 0.0) {
                if (S_ISREG(src_statbuf.st_mode)) {
                    copy_file(src, dest, src_statbuf);
                }
                else {
                    sync_dir(src, dest);
                }
            }

            if (S_ISREG(src_statbuf.st_mode)) {
                printf("File '%s' in sync\n", entry -> d_name);
            }
            else {
                printf("Directory '%s' in sync\n", entry -> d_name);
            }
        }
        else {
            if (S_ISREG(src_statbuf.st_mode)) {
                copy_file(src, dest, src_statbuf);
            }
            else {
                mkdir(dest, src_statbuf.st_mode);
                sync_dir(src, dest);
                printf("Directory '%s' created in '%s'\n", entry -> d_name, dest_path);
            }
        }
    }

    closedir(src_dir);
}

void copy_file(char *src, char *dest, struct stat statbuf) {
    int input_fd, output_fd, open_flags;
    mode_t file_perms;
    ssize_t num_read;
    char buffer[BUF_SIZE];
    off_t offset = 0;

    if ((input_fd = open(src, O_RDONLY)) == -1) {
        perror("open");
        exit(1);
    }

    file_perms = statbuf.st_mode & ~S_IFMT;

    if ((output_fd = open(dest, O_WRONLY | O_CREAT | O_TRUNC, file_perms)) == -1) {
        perror("open");
        exit(1);
    }

    while ((num_read = read(input_fd, buffer, BUF_SIZE)) > 0) {
        if (write(output_fd, buffer, num_read) != num_read) {
            perror("write");
            exit(1);
        }
    }

    if (num_read == -1) {
        perror("read");
        exit(1);
    }

    if (close(input_fd) == -1 || close(output_fd) == -1) {
        perror("close");
        exit(1);
    }

    chown(dest, statbuf.st_uid, statbuf.st_gid);
    chmod(dest, statbuf.st_mode);
    utimes(dest, NULL);
    printf("File '%s' copied to '%s'\n", src, dest);
}

void sync_dir(char *src_path, char *dest_path) {
    DIR *src_dir;
    struct dirent *entry;

    if ((src_dir = opendir(src_path)) == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((entry = readdir(src_dir)) != NULL) {
        char src[1024], dest[1024];

        sprintf(src, "%s/%s", src_path, entry -> d_name);
        sprintf(dest, "%s/%s", dest_path, entry -> d_name);

        if (strcmp(entry -> d_name, ".") == 0 || strcmp(entry -> d_name, "..") == 0) {
            continue;
        }

        sync_files(src, dest);
    }

    closedir(src_dir);
}