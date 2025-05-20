//Falcon2-11B DATASET v1.0 Category: File system simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments are passed
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    // Open the specified directory
    DIR *dir = opendir(argv[1]);
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory: %s\n", strerror(errno));
        exit(1);
    }

    // Print the contents of the directory
    struct dirent *entry;
    while ((entry = readdir(dir))!= NULL) {
        char *file_name = entry->d_name;
        if (strcmp(file_name, ".") == 0 || strcmp(file_name, "..") == 0) {
            continue;
        }

        // Open the file and print its contents
        int fd = open(file_name, O_RDONLY);
        if (fd == -1) {
            fprintf(stderr, "Error opening file: %s\n", strerror(errno));
            exit(1);
        }
        printf("%s\n", file_name);
        char buffer[1024];
        while (read(fd, buffer, sizeof(buffer)) > 0) {
            printf("%s", buffer);
        }
        close(fd);
    }

    // Close the directory
    closedir(dir);

    return 0;
}