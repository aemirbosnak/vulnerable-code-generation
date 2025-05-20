//FormAI DATASET v1.0 Category: File Synchronizer ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PATH_LENGTH 256
#define BUFFER_SIZE 1024

void sync_files(const char* source_path, const char* destination_path) {
    struct dirent *dir_info;
    DIR *dir = opendir(source_path);
    char buffer[BUFFER_SIZE];
    int fd_src, fd_dst;
    size_t n;

    if(dir == NULL) {
        perror("Error opening directory.");
        exit(EXIT_FAILURE);
    }

    while((dir_info = readdir(dir)) != NULL) {
        if(dir_info->d_type == DT_REG) { // only regular files
            char source_file[MAX_PATH_LENGTH], destination_file[MAX_PATH_LENGTH];
            sprintf(source_file, "%s/%s", source_path, dir_info->d_name);
            sprintf(destination_file, "%s/%s", destination_path, dir_info->d_name);
            // open source and destination files
            if((fd_src = open(source_file, O_RDONLY)) == -1) {
                fprintf(stderr, "Could not open %s: %s\n", source_file, strerror(errno));
                continue;
            }
            if((fd_dst = open(destination_file, O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) {
                fprintf(stderr, "Could not open %s: %s\n", destination_file, strerror(errno));
                close(fd_src);
                continue;
            }
            // copy data from source to destination
            while((n = read(fd_src, buffer, BUFFER_SIZE)) > 0) {
                if(write(fd_dst, buffer, n) != n) {
                    fprintf(stderr, "Error writing to %s: %s\n", destination_file, strerror(errno));
                    break;
                }
            }
            if(n == -1) {
                fprintf(stderr, "Error reading from %s: %s\n", source_file, strerror(errno));
            }
            // close files
            close(fd_src);
            close(fd_dst);
        }
    }
    closedir(dir);
}

int main(int argc, char* argv[]) {
    if(argc != 3) {
        printf("Usage: %s <source_dir> <destination_dir>\n", argv[0]);
        return 1;
    }

    sync_files(argv[1], argv[2]);

    printf("File synchronization completed successfully.\n");

    return 0;
}