//Falcon-180B DATASET v1.0 Category: System administration ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <file> <user> <group>\n", argv[0]);
        return 1;
    }

    char *file = argv[1];
    char *user = argv[2];
    char *group = argv[3];

    struct passwd *pw = getpwnam(user);
    if (pw == NULL) {
        printf("User %s not found.\n", user);
        return 1;
    }

    struct group *gr = getgrnam(group);
    if (gr == NULL) {
        printf("Group %s not found.\n", group);
        return 1;
    }

    int fd = open(file, O_RDWR);
    if (fd == -1) {
        printf("Error opening file %s: %s\n", file, strerror(errno));
        return 1;
    }

    if (fchown(fd, pw->pw_uid, gr->gr_gid) == -1) {
        printf("Error changing ownership of file %s: %s\n", file, strerror(errno));
        return 1;
    }

    if (fchmod(fd, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH) == -1) {
        printf("Error changing permissions of file %s: %s\n", file, strerror(errno));
        return 1;
    }

    printf("Successfully changed ownership and permissions of file %s.\n", file);

    return 0;
}