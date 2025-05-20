//Falcon-180B DATASET v1.0 Category: File Synchronizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

typedef struct {
    char *path;
    int fd;
} File;

void sync_files(File *files, int num_files) {
    for (int i = 0; i < num_files; i++) {
        if (files[i].fd == -1) {
            files[i].fd = open(files[i].path, O_RDWR);
        }
        if (files[i].fd!= -1) {
            char buffer[BUFFER_SIZE];
            while (1) {
                int bytes_read = read(files[i].fd, buffer, BUFFER_SIZE);
                if (bytes_read == 0) {
                    break;
                }
                if (bytes_read == -1) {
                    perror("read");
                    exit(1);
                }
                for (int j = 0; j < bytes_read; j++) {
                    printf("%c", buffer[j]);
                }
            }
        }
    }
}

int main() {
    int num_files;
    printf("Enter the number of files to synchronize: ");
    scanf("%d", &num_files);

    File *files = malloc(num_files * sizeof(File));

    for (int i = 0; i < num_files; i++) {
        printf("Enter the path of file %d: ", i + 1);
        char *path = malloc(100 * sizeof(char));
        scanf("%s", path);
        files[i].path = path;
        files[i].fd = -1;
    }

    sync_files(files, num_files);

    for (int i = 0; i < num_files; i++) {
        if (files[i].fd!= -1) {
            close(files[i].fd);
        }
        free(files[i].path);
    }
    free(files);

    return 0;
}