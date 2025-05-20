//Falcon-180B DATASET v1.0 Category: System administration ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>

#define MAX_LINE_LENGTH 1024

struct user_passwd {
    char username[64];
    char password[64];
};

int main() {
    int fd;
    char line[MAX_LINE_LENGTH];
    struct passwd *pw;
    struct group *gr;
    char *delim = ":";
    struct user_passwd up;

    // Open the /etc/passwd file
    if ((fd = open("/etc/passwd", O_RDONLY)) == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Read the passwd file line by line
    while (fgets(line, MAX_LINE_LENGTH, fd)!= NULL) {
        // Parse the line into username and password
        char *username = strtok(line, delim);
        char *password = strtok(NULL, delim);

        // Get the group id and name for the user
        if ((gr = getgrgid(pw->pw_gid)) == NULL) {
            fprintf(stderr, "No group found for user %s\n", username);
            continue;
        }

        // Store the username and password in a struct
        strncpy(up.username, username, sizeof(up.username));
        strncpy(up.password, password, sizeof(up.password));

        // Print the username, password, and group name
        printf("Username: %s\n", up.username);
        printf("Password: %s\n", up.password);
        printf("Group: %s\n\n", gr->gr_name);
    }

    // Close the passwd file
    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}