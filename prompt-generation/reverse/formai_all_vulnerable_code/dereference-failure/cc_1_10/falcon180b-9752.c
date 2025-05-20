//Falcon-180B DATASET v1.0 Category: System administration ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 1024

void print_user_info(uid_t uid) {
    struct passwd *user_info = getpwuid(uid);
    if (user_info == NULL) {
        printf("User not found.\n");
        return;
    }

    printf("User name: %s\n", user_info->pw_name);
    printf("User ID: %d\n", user_info->pw_uid);
    printf("Group ID: %d\n", user_info->pw_gid);
    printf("Home directory: %s\n", user_info->pw_dir);
    printf("Shell: %s\n", user_info->pw_shell);
}

void print_group_info(gid_t gid) {
    struct group *group_info = getgrgid(gid);
    if (group_info == NULL) {
        printf("Group not found.\n");
        return;
    }

    printf("Group name: %s\n", group_info->gr_name);
    printf("Group ID: %d\n", group_info->gr_gid);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <user/group> <ID>\n", argv[0]);
        return 1;
    }

    char *type = argv[1];
    int id = atoi(argv[2]);

    if (strcmp(type, "user") == 0) {
        print_user_info(id);
    } else if (strcmp(type, "group") == 0) {
        print_group_info(id);
    } else {
        printf("Invalid type.\n");
        return 1;
    }

    return 0;
}