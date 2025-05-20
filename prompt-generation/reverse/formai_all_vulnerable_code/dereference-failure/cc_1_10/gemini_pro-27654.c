//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

int main(int argc, char **argv) {
    // Get the current working directory
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));

    // Get the system information
    struct utsname uname_info;
    uname(&uname_info);

    // Get the current time
    time_t current_time;
    time(&current_time);

    // Print the system information
    printf("System Information:\n");
    printf("  Hostname: %s\n", uname_info.nodename);
    printf("  Operating System: %s %s %s\n", uname_info.sysname, uname_info.release, uname_info.machine);

    // Print the current time
    printf("Current Time: %s", ctime(&current_time));

    // Print the current working directory
    printf("Current Working Directory: %s\n", cwd);

    // Print the current user information
    struct passwd *pw_info = getpwuid(getuid());
    printf("Current User: %s (%s)\n", pw_info->pw_name, pw_info->pw_gecos);

    // Print the current group information
    struct group *gr_info = getgrgid(getgid());
    printf("Current Group: %s (%s)\n", gr_info->gr_name, gr_info->gr_passwd);

    // Read the directory
    DIR *dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Print the files and directories in the current directory
    printf("Files and Directories in the Current Directory:\n");
    struct dirent *dirent;
    while ((dirent = readdir(dir)) != NULL) {
        printf("  %s\n", dirent->d_name);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}