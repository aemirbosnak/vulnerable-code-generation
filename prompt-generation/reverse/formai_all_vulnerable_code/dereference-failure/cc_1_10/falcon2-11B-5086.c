//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main() {
    pid_t pid, wstatus;
    int status;
    char buffer[BUFFER_SIZE];
    char command[BUFFER_SIZE];
    DIR *dir;
    struct dirent *dp;
    struct stat filestat;

    printf("Enter the command to be executed: ");
    fgets(command, BUFFER_SIZE, stdin);

    pid = fork();

    if (pid == 0) {
        printf("Executing command: %s\n", command);
        execvp(command, &command);
        exit(0);
    }

    if (pid < 0) {
        perror("Error: fork");
        exit(1);
    }

    waitpid(pid, &wstatus, 0);

    if (WIFEXITED(wstatus)) {
        printf("Exit status: %d\n", WEXITSTATUS(wstatus));
    } else if (WIFSIGNALED(wstatus)) {
        printf("Signal received: %d\n", WTERMSIG(wstatus));
    } else {
        printf("Error: unknown exit status\n");
    }

    printf("List of running processes:\n");

    dir = opendir("/proc");

    if (dir == NULL) {
        perror("Error: cannot open directory");
        exit(1);
    }

    while ((dp = readdir(dir))!= NULL) {
        if (strcmp(dp->d_name, ".") == 0 || strcmp(dp->d_name, "..") == 0) {
            continue;
        }

        snprintf(buffer, BUFFER_SIZE, "/proc/%s/cmdline", dp->d_name);
        if (stat(buffer, &filestat) == -1) {
            continue;
        }

        printf("%s: %s\n", dp->d_name, buffer);
    }

    closedir(dir);

    return 0;
}