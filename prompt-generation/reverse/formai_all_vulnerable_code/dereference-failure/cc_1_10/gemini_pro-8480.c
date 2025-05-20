//GEMINI-pro DATASET v1.0 Category: System administration ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s file user group\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *file = argv[1];
    char *user = argv[2];
    char *group = argv[3];

    struct passwd *pw = getpwnam(user);
    if (pw == NULL) {
        fprintf(stderr, "User %s not found\n", user);
        return EXIT_FAILURE;
    }

    struct group *gr = getgrnam(group);
    if (gr == NULL) {
        fprintf(stderr, "Group %s not found\n", group);
        return EXIT_FAILURE;
    }

    struct stat st;
    if (stat(file, &st) == -1) {
        perror("stat");
        return EXIT_FAILURE;
    }

    if (st.st_uid != pw->pw_uid || st.st_gid != gr->gr_gid) {
        gid_t groups[] = {gr->gr_gid, st.st_gid};
        // Set file group ownership first to avoid EPERM when changing user ownership
        if (fchown(open(file, O_RDONLY), -1, gr->gr_gid) == -1) {
            perror("fchown");
            return EXIT_FAILURE;
        }
        // Then set file user ownership
        if (fchown(open(file, O_RDONLY), pw->pw_uid, gr->gr_gid) == -1) {
            perror("fchown");
            return EXIT_FAILURE;
        }
    }

    return EXIT_SUCCESS;
}