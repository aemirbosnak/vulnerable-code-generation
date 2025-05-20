//GEMINI-pro DATASET v1.0 Category: System administration ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    // Check if run as root
    if (geteuid() != 0) {
        fprintf(stderr, "Must be run as root\n");
        return 1;
    }

    // Get current working directory
    char cwd[1024];
    if (!getcwd(cwd, sizeof(cwd))) {
        perror("getcwd");
        return 1;
    }

    // Check if user exists
    struct passwd *user = getpwnam(argv[1]);
    if (!user) {
        fprintf(stderr, "User %s does not exist\n", argv[1]);
        return 1;
    }

    // Check if group exists
    struct group *group = getgrnam(argv[2]);
    if (!group) {
        fprintf(stderr, "Group %s does not exist\n", argv[2]);
        return 1;
    }

    // Change directory to cwd
    if (chdir(cwd)) {
        perror("chdir");
        return 1;
    }

    // Create file with given owner and group
    int fd = open(argv[3], O_CREAT | O_WRONLY, 0644);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Set file owner and group
    if (fchown(fd, user->pw_uid, group->gr_gid)) {
        perror("fchown");
        close(fd);
        return 1;
    }

    // Write data to file
    if (write(fd, "Hello world!\n", 13) == -1) {
        perror("write");
        close(fd);
        return 1;
    }

    // Close file
    if (close(fd)) {
        perror("close");
        return 1;
    }

    return 0;
}