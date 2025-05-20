//Falcon-180B DATASET v1.0 Category: System administration ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>

typedef struct user_info {
    char username[32];
    char fullname[64];
    char home_dir[128];
    char shell[32];
    int uid;
    int gid;
} user_info_t;

void print_user_info(user_info_t *user) {
    printf("Username: %s\n", user->username);
    printf("Full name: %s\n", user->fullname);
    printf("Home directory: %s\n", user->home_dir);
    printf("Shell: %s\n", user->shell);
    printf("UID: %d\n", user->uid);
    printf("GID: %d\n", user->gid);
}

int main() {
    user_info_t user_info;
    struct passwd *pw;
    struct group *gr;
    char *username = "john";

    // Get user information
    pw = getpwnam(username);
    if (pw == NULL) {
        fprintf(stderr, "User not found.\n");
        return 1;
    }

    // Fill in user information
    strcpy(user_info.username, pw->pw_name);
    strcpy(user_info.fullname, pw->pw_gecos);
    strcpy(user_info.home_dir, pw->pw_dir);
    strcpy(user_info.shell, pw->pw_shell);
    user_info.uid = pw->pw_uid;
    user_info.gid = pw->pw_gid;

    // Get group information
    gr = getgrgid(pw->pw_gid);
    if (gr == NULL) {
        fprintf(stderr, "Group not found.\n");
        return 1;
    }

    // Print user information
    print_user_info(&user_info);

    return 0;
}