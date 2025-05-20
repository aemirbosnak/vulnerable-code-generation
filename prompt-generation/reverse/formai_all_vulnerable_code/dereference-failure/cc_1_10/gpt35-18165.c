//FormAI DATASET v1.0 Category: System administration ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFERSIZE 256

int main(int argc, char *argv[]) {

    if(argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    char filename[BUFFERSIZE];
    strcpy(filename, argv[1]);

    // Check if the file exists
    if(access(filename, F_OK) == -1) {
        printf("%s does not exist\n", filename);
        exit(1);
    }

    // Get the current user id and group id
    uid_t uid = getuid();
    gid_t gid = getgid();

    // Get the file status
    struct stat filestat;
    stat(filename, &filestat);

    // Check if the user owns the file
    if(uid != filestat.st_uid) {
        printf("You do not own %s\n", filename);
        exit(1);
    }

    // Check if the file is readable and writable
    if(access(filename, R_OK | W_OK) == -1) {
        printf("You do not have permission to read and write %s\n", filename);
        exit(1);
    }

    // Change the file owner to root
    chown(filename, 0, gid);

    // Change the file permissions to read-only for everyone else
    chmod(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);

    printf("%s has been successfully modified\n", filename);

    return 0;
}