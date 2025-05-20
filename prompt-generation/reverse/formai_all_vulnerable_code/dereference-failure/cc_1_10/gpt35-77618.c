//FormAI DATASET v1.0 Category: File Synchronizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

void sync_files(char *dir1, char *dir2);
int compare_files(char *file1, char *file2);
void copy_file(char *file1, char *file2);

int main(int argc, char **argv) {
    if(argc < 3) {
        printf("Usage: %s <directory1> <directory2>\n", argv[0]);
        exit(1);
    }

    char *dir1 = argv[1];
    char *dir2 = argv[2];

    printf("Synchronizing files in %s and %s\n", dir1, dir2);

    sync_files(dir1, dir2);

    printf("Files synchronized successfully!\n");

    return 0;
}

void sync_files(char *dir1, char *dir2) {
    DIR *dir1p = opendir(dir1);
    DIR *dir2p = opendir(dir2);

    struct dirent *dir1_ent;
    struct dirent *dir2_ent;
    char file1_path[PATH_MAX];
    char file2_path[PATH_MAX];
    struct stat file1_stat, file2_stat;

    while((dir1_ent = readdir(dir1p))) {
        if(strcmp(dir1_ent->d_name, ".") == 0 || strcmp(dir1_ent->d_name, "..") == 0) {
            continue;
        }

        strcpy(file1_path, dir1);
        strcat(file1_path, "/");
        strcat(file1_path, dir1_ent->d_name);

        strcpy(file2_path, dir2);
        strcat(file2_path, "/");
        strcat(file2_path, dir1_ent->d_name);

        if(stat(file1_path, &file1_stat) < 0) {
            printf("Failed to get file information for %s\n", file1_path);
            continue;
        }

        if((dir2_ent = opendir(file2_path))) {
            while((dir2_ent = readdir(dir2p))) {
                if(strcmp(dir2_ent->d_name, ".") == 0 || strcmp(dir2_ent->d_name, "..") == 0) {
                    continue;
                }
                strcpy(file2_path, dir2);
                strcat(file2_path, "/");
                strcat(file2_path, dir2_ent->d_name);

                if(stat(file2_path, &file2_stat) < 0) {
                    printf("Failed to get file information for %s\n", file2_path);
                    continue;
                }

                if(strcmp(dir1_ent->d_name, dir2_ent->d_name) == 0) {
                    if(compare_files(file1_path, file2_path)) {
                        printf("%s and %s are already synchronized\n", file1_path, file2_path);
                    } else {
                        copy_file(file1_path, file2_path);
                        printf("%s copied to %s\n", file1_path, file2_path);
                    }
                    break;
                }
            }
        } else {
            copy_file(file1_path, file2_path);
            printf("%s copied to %s\n", file1_path, file2_path);
        }
        rewinddir(dir2p);
    }
}

int compare_files(char *file1, char *file2) {
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    int file_des1, file_des2, nbytes1, nbytes2;

    if((file_des1 = open(file1, O_RDONLY)) < 0) {
        printf("Failed to open file %s\n", file1);
        return 0;
    }
    if((file_des2 = open(file2, O_RDONLY)) < 0) {
        printf("Failed to open file %s\n", file2);
        return 0;
    }

    while((nbytes1 = read(file_des1, buffer1, BUFFER_SIZE)) != 0) {
        if((nbytes2 = read(file_des2, buffer2, BUFFER_SIZE)) == 0) {
            close(file_des1);
            close(file_des2);
            return 0;
        }
        if(nbytes1 != nbytes2 || strncmp(buffer1, buffer2, nbytes1) != 0) {
            close(file_des1);
            close(file_des2);
            return 0;
        }
    }

    if(read(file_des2, buffer2, BUFFER_SIZE) != 0) {
        close(file_des1);
        close(file_des2);
        return 0;
    }

    close(file_des1);
    close(file_des2);
    return 1;
}

void copy_file(char *file1, char *file2) {
    char buffer[BUFFER_SIZE];
    int file_des1, file_des2, nbytes1;

    if((file_des1 = open(file1, O_RDONLY)) < 0) {
        printf("Failed to open file %s\n", file1);
        return;
    }
    if((file_des2 = open(file2, O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU | S_IRGRP | S_IROTH)) < 0) {
        printf("Failed to open file %s\n", file2);
        close(file_des1);
        return;
    }

    while((nbytes1 = read(file_des1, buffer, BUFFER_SIZE)) != 0) {
        if(write(file_des2, buffer, nbytes1) != nbytes1) {
            printf("Failed to write to file %s\n", file2);
            close(file_des1);
            close(file_des2);
            return;
        }
    }

    close(file_des1);
    close(file_des2);
}