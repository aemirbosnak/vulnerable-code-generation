//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <dirent.h>

#define MAGIC_FILE_SIZE 100
#define MAX_FILE_NAME_SIZE 50

typedef struct file_info {
    char filename[MAX_FILE_NAME_SIZE];
    char content[MAGIC_FILE_SIZE];
    int file_size;
} file_info;

void handle_sigint(int sig) {
    printf("Caught SIGINT, exiting...\n");
    exit(0);
}

void scan_directory(const char* dir_path, file_info* files) {
    DIR* dir = opendir(dir_path);
    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    struct dirent* entry;
    while ((entry = readdir(dir))!= NULL) {
        char file_path[MAX_FILE_NAME_SIZE];
        strncpy(file_path, dir_path, MAX_FILE_NAME_SIZE - 1);
        strncat(file_path, entry->d_name, MAX_FILE_NAME_SIZE - 1 - strlen(file_path));

        int fd = open(file_path, O_RDONLY);
        if (fd < 0) {
            perror("open");
            continue;
        }

        file_info* file = (file_info*)malloc(sizeof(file_info));
        if (file == NULL) {
            perror("malloc");
            close(fd);
            continue;
        }

        int file_size = lseek(fd, 0, SEEK_END);
        if (file_size < 0) {
            perror("lseek");
            free(file);
            close(fd);
            continue;
        }

        memset(file->content, 0, MAGIC_FILE_SIZE);
        file->file_size = file_size;
        read(fd, file->content, file_size);
        closedir(dir);
        files = (file_info*)realloc(files, (sizeof(file_info) * (files? files->file_size : 0) + 1));
        if (files == NULL) {
            perror("realloc");
            free(file);
            close(fd);
            continue;
        }
        files[files->file_size] = *file;
        free(file);
    }
    closedir(dir);
}

void scan_files(file_info* files) {
    for (int i = 0; i < files->file_size; i++) {
        printf("File Name: %s\n", files[i].filename);
        printf("File Size: %d\n", files[i].file_size);
        printf("File Content: %s\n", files[i].content);
    }
}

int main(int argc, char* argv[]) {
    signal(SIGINT, handle_sigint);
    file_info* files = NULL;
    if (argc < 2) {
        printf("Usage: %s <directory_path>\n", argv[0]);
        return 1;
    }

    scan_directory(argv[1], files);
    scan_files(files);

    free(files);
    return 0;
}