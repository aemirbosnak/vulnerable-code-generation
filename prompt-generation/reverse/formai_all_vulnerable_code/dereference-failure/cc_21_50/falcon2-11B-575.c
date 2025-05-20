//Falcon2-11B DATASET v1.0 Category: File Synchronizer ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 100

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s source_dir target_dir\n", argv[0]);
        return 1;
    }

    struct stat st;
    int src_fd, target_fd, file_cnt, line_cnt, file_cnt_diff, line_cnt_diff;

    src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0) {
        perror("open source dir");
        return 1;
    }

    target_fd = open(argv[2], O_RDONLY);
    if (target_fd < 0) {
        perror("open target dir");
        return 1;
    }

    while (1) {
        char file_name[MAX_LINE_LENGTH];
        char line[MAX_LINE_LENGTH];
        int line_len;

        if (fstat(src_fd, &st) == -1) {
            perror("fstat");
            return 1;
        }

        if (fstat(target_fd, &st) == -1) {
            perror("fstat");
            return 1;
        }

        if (stat(argv[1], &st) == -1) {
            perror("stat source dir");
            return 1;
        }

        if (stat(argv[2], &st) == -1) {
            perror("stat target dir");
            return 1;
        }

        if (src_fd < target_fd) {
            file_cnt = src_fd;
            line_cnt = 0;
        } else {
            file_cnt = target_fd;
            line_cnt = 0;
        }

        while (fread(file_name, sizeof(char), MAX_LINE_LENGTH, src_fd) == 1) {
            if (strcmp(file_name, "..")!= 0 && strcmp(file_name, ".")!= 0) {
                line_len = 0;
                if (fseek(src_fd, 0, SEEK_SET) == -1) {
                    perror("fseek");
                    return 1;
                }

                if (fseek(target_fd, 0, SEEK_SET) == -1) {
                    perror("fseek");
                    return 1;
                }

                while (fread(line, sizeof(char), MAX_LINE_LENGTH, src_fd) == 1) {
                    line_len += strlen(line);
                }

                while (fread(line, sizeof(char), MAX_LINE_LENGTH, target_fd) == 1) {
                    line_len += strlen(line);
                }

                file_cnt_diff = file_cnt - line_cnt;
                line_cnt_diff = line_cnt - line_len;

                if (file_cnt_diff > 0) {
                    printf("Found %d new files in source directory: %s\n", file_cnt_diff, file_name);
                } else if (file_cnt_diff < 0) {
                    printf("Found %d new files in target directory: %s\n", -file_cnt_diff, file_name);
                }

                if (line_cnt_diff > 0) {
                    printf("Found %d new lines in source directory: %s\n", line_cnt_diff, file_name);
                } else if (line_cnt_diff < 0) {
                    printf("Found %d new lines in target directory: %s\n", -line_cnt_diff, file_name);
                }

                line_cnt += line_len;
            }
        }

        if (fseek(src_fd, 0, SEEK_SET) == -1) {
            perror("fseek");
            return 1;
        }

        if (fseek(target_fd, 0, SEEK_SET) == -1) {
            perror("fseek");
            return 1;
        }

        if (fread(file_name, sizeof(char), MAX_LINE_LENGTH, src_fd) == 1) {
            if (strcmp(file_name, "..")!= 0 && strcmp(file_name, ".")!= 0) {
                line_len = 0;
                if (fseek(src_fd, 0, SEEK_SET) == -1) {
                    perror("fseek");
                    return 1;
                }

                if (fseek(target_fd, 0, SEEK_SET) == -1) {
                    perror("fseek");
                    return 1;
                }

                while (fread(line, sizeof(char), MAX_LINE_LENGTH, src_fd) == 1) {
                    line_len += strlen(line);
                }

                while (fread(line, sizeof(char), MAX_LINE_LENGTH, target_fd) == 1) {
                    line_len += strlen(line);
                }

                file_cnt_diff = file_cnt - line_cnt;
                line_cnt_diff = line_cnt - line_len;

                if (file_cnt_diff > 0) {
                    printf("Found %d new files in source directory: %s\n", file_cnt_diff, file_name);
                } else if (file_cnt_diff < 0) {
                    printf("Found %d new files in target directory: %s\n", -file_cnt_diff, file_name);
                }

                if (line_cnt_diff > 0) {
                    printf("Found %d new lines in source directory: %s\n", line_cnt_diff, file_name);
                } else if (line_cnt_diff < 0) {
                    printf("Found %d new lines in target directory: %s\n", -line_cnt_diff, file_name);
                }

                line_cnt += line_len;
            }
        }

        if (fclose(src_fd)!= 0 || fclose(target_fd)!= 0) {
            printf("Error closing file descriptors.\n");
            return 1;
        }

        if (fstat(src_fd, &st) == -1) {
            perror("fstat");
            return 1;
        }

        if (fstat(target_fd, &st) == -1) {
            perror("fstat");
            return 1;
        }

        if (stat(argv[1], &st) == -1) {
            perror("stat source dir");
            return 1;
        }

        if (stat(argv[2], &st) == -1) {
            perror("stat target dir");
            return 1;
        }

        if (src_fd < target_fd) {
            file_cnt = src_fd;
            line_cnt = 0;
        } else {
            file_cnt = target_fd;
            line_cnt = 0;
        }

        if (file_cnt == 0) {
            break;
        }
    }

    return 0;
}