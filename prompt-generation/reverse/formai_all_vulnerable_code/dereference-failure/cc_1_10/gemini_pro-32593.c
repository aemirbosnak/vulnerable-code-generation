//GEMINI-pro DATASET v1.0 Category: System administration ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char *argv[]) {
    int fd;
    struct stat sb;
    struct passwd *pw;
    struct group *gr;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        exit(1);
    }

    // Check if the file exists and is readable
    if (stat(argv[1], &sb) == -1) {
        perror("stat");
        exit(1);
    }

    if (access(argv[1], R_OK) == -1) {
        perror("access");
        exit(1);
    }

    // Open the file with read-only permissions
    fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    // Get the file's owner and group
    pw = getpwuid(sb.st_uid);
    if (pw == NULL) {
        perror("getpwuid");
        exit(1);
    }

    gr = getgrgid(sb.st_gid);
    if (gr == NULL) {
        perror("getgrgid");
        exit(1);
    }

    // Print the file's permissions, owner, and group
    printf("Permissions: %o\n", sb.st_mode);
    printf("Owner: %s\n", pw->pw_name);
    printf("Group: %s\n", gr->gr_name);

    // Close the file
    close(fd);

    return 0;
}