//Falcon-180B DATASET v1.0 Category: System administration ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

#define BUF_SIZE 1024

void list_dir(char *path) {
    DIR *dir;
    struct dirent *ent;
    dir = opendir(path);

    if (dir!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            printf("%s\n", ent->d_name);
        }
        closedir(dir);
    }
}

void change_owner(char *path, char *user, char *group) {
    struct stat st;
    stat(path, &st);

    if (chown(path, getpwuid(user)->pw_uid, getgrnam(group)->gr_gid) == -1) {
        perror("chown");
        exit(1);
    }
}

void change_perm(char *path, int mode) {
    struct stat st;
    stat(path, &st);

    if (chmod(path, mode) == -1) {
        perror("chmod");
        exit(1);
    }
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <path> <user> <group>\n", argv[0]);
        return 1;
    }

    char path[BUF_SIZE];
    strcpy(path, argv[1]);

    char user[BUF_SIZE];
    strcpy(user, argv[2]);

    char group[BUF_SIZE];
    strcpy(group, argv[3]);

    int mode = S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH;

    change_owner(path, user, group);
    change_perm(path, mode);

    list_dir(path);

    return 0;
}