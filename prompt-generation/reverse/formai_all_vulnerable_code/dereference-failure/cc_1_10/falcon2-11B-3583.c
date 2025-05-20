//Falcon2-11B DATASET v1.0 Category: Data recovery tool ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

#define MAX_FILE_NAME_LENGTH 256
#define MAX_FILE_SIZE 1048576

void recover_file(const char* filename, const char* new_filename) {
    int fd = open(filename, O_RDONLY);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", filename, strerror(errno));
        return;
    }

    char buffer[MAX_FILE_SIZE];
    off_t bytes_read;
    while ((bytes_read = read(fd, buffer, MAX_FILE_SIZE)) > 0) {
        write(STDOUT_FILENO, buffer, bytes_read);
    }

    close(fd);

    int fd2 = open(new_filename, O_CREAT | O_TRUNC | O_WRONLY, 0666);
    if (fd2 == -1) {
        printf("Error opening file %s: %s\n", new_filename, strerror(errno));
        return;
    }

    bytes_read = write(fd2, buffer, bytes_read);
    close(fd2);
}

int main() {
    DIR* dir;
    struct dirent* entry;
    char filename[MAX_FILE_NAME_LENGTH];

    dir = opendir("/");
    if (dir == NULL) {
        printf("Error opening directory: %s\n", strerror(errno));
        return 1;
    }

    while ((entry = readdir(dir))!= NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;

        strcpy(filename, entry->d_name);
        if (strstr(filename, "~$")!= NULL) {
            printf("Recovering file: %s\n", filename);
            recover_file(filename, filename);
        }
    }

    closedir(dir);
    return 0;
}