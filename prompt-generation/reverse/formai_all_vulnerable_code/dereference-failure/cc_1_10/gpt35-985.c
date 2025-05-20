//FormAI DATASET v1.0 Category: System administration ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function to check if a file exists */
int file_exists(const char *filename) {
    struct stat buffer;
    return (stat(filename, &buffer) == 0);
}

/* Function to check if a user exists */
int user_exists(const char *username) {
    struct passwd *pwd;
    if ((pwd = getpwnam(username)) == NULL) { /* User not found */
        return 0;
    }
    return 1;
}

/* Function to check if a group exists */
int group_exists(const char *groupname) {
    struct group *grp;
    if ((grp = getgrnam(groupname)) == NULL) { /* Group not found */
        return 0;
    }
    return 1;
}

/* Function to set ownership of a file or directory */
void set_ownership(const char *filename, const char *owner, const char *group) {
    uid_t uid;
    gid_t gid;
    struct passwd *pwd;
    struct group *grp;
    if (!file_exists(filename)) {
        printf("File '%s' not found!\n", filename);
        return;
    }
    if (!user_exists(owner)) {
        printf("User '%s' not found!\n", owner);
        return;
    }
    if (!group_exists(group)) {
        printf("Group '%s' not found!\n", group);
        return;
    }
    if ((pwd = getpwnam(owner)) == NULL) {
        printf("Error getting user '%s' information!\n", owner);
        return;
    }
    uid = pwd->pw_uid;
    if ((grp = getgrnam(group)) == NULL) {
        printf("Error getting group '%s' information!\n", group);
        return;
    }
    gid = grp->gr_gid;
    if (chown(filename, uid, gid) != 0) {
        printf("Error changing ownership of '%s'!\n", filename);
        return;
    }
    printf("Ownership of '%s' has been set to user '%s' and group '%s'.\n", filename, owner, group);
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <file or directory> <username> <groupname>\n", argv[0]);
        exit(1);
    }
    set_ownership(argv[1], argv[2], argv[3]);
    return 0;
}