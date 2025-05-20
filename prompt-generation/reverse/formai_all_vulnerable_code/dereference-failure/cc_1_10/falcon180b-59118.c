//Falcon-180B DATASET v1.0 Category: System boot optimizer ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_LINE_LEN 100
#define MAX_FILE_NAME 50

void optimize_boot(char *file_name) {
    int fd, new_fd;
    char buffer[BUF_SIZE];
    char line[MAX_LINE_LEN];
    char file_name_copy[MAX_FILE_NAME];
    strncpy(file_name_copy, file_name, strlen(file_name));
    strcat(file_name_copy, ".tmp");
    fd = open(file_name, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", file_name, strerror(errno));
        exit(1);
    }
    new_fd = open(file_name_copy, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (new_fd == -1) {
        printf("Error creating file %s: %s\n", file_name_copy, strerror(errno));
        exit(1);
    }
    while (fgets(line, MAX_LINE_LEN, fd)!= NULL) {
        char *token = strtok(line, " ");
        while (token!= NULL) {
            if (strncmp(token, "sleep", 5) == 0) {
                char *value = strtok(NULL, " ");
                int sleep_time = atoi(value);
                if (sleep_time > 1) {
                    fprintf(new_fd, "sleep 1\n");
                }
            } else if (strncmp(token, "wait", 4) == 0) {
                char *value = strtok(NULL, " ");
                int wait_time = atoi(value);
                if (wait_time > 1) {
                    fprintf(new_fd, "wait 1\n");
                }
            } else {
                fprintf(new_fd, "%s ", line);
            }
            token = strtok(NULL, " ");
        }
    }
    close(fd);
    close(new_fd);
    remove(file_name);
    rename(file_name_copy, file_name);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <boot_script> <boot_script.tmp>\n", argv[0]);
        exit(1);
    }
    optimize_boot(argv[1]);
    return 0;
}