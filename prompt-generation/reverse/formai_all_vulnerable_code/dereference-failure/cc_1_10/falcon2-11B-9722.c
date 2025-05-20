//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: genius
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

int main() {
    pid_t pid, ppid, ppid_child;
    int status;
    char username[100], pname[100], pname_child[100];
    DIR *dp;
    struct dirent *dirp;
    int i;

    printf("Process Viewer\n");
    printf("Current process ID: %d\n", getpid());
    printf("Parent process ID: %d\n", getppid());
    printf("User name: %s\n", getlogin());

    if ((pid = fork()) == 0) {
        printf("Child process ID: %d\n", getpid());
        printf("Parent process ID: %d\n", getppid());
        printf("User name: %s\n", getlogin());
        printf("Creating child process...\n");
        if ((ppid_child = fork()) == 0) {
            printf("Child process ID: %d\n", getpid());
            printf("Parent process ID: %d\n", getppid());
            printf("User name: %s\n", getlogin());
            printf("Child process: %s\n", "Process Viewer");
            sleep(5);
            printf("Exiting child process...\n");
        }
        else {
            printf("Parent process ID: %d\n", getppid());
            printf("Child process ID: %d\n", ppid_child);
            printf("User name: %s\n", getlogin());
            printf("Child process: %s\n", "Process Viewer");
        }
    }
    else {
        printf("Parent process ID: %d\n", getppid());
        printf("Child process ID: %d\n", pid);
        printf("User name: %s\n", getlogin());
        printf("Child process: %s\n", "Process Viewer");
    }

    dp = opendir("/proc");
    if (dp!= NULL) {
        while ((dirp = readdir(dp))!= NULL) {
            if (strcmp(dirp->d_name, ".")!= 0 && strcmp(dirp->d_name, "..")!= 0) {
                strcpy(pname, dirp->d_name);
                i = strlen(pname);
                for (; i >= 0; i--) {
                    if (pname[i] == '/') {
                        pname[i] = '\0';
                    }
                }
                printf("Process name: %s\n", pname);
            }
        }
        closedir(dp);
    }
    else {
        printf("Failed to open directory /proc\n");
    }

    return 0;
}