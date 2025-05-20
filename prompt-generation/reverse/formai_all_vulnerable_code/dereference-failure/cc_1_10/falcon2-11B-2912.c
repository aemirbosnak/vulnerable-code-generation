//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    pid_t pid;
    int status;
    int i;
    struct dirent *dent;
    DIR *dirp;

    // create a child process
    pid = fork();

    // if we're in the parent process
    if (pid == 0) {
        // get the process ID of the parent process
        pid = getpid();

        // open a new process table
        dirp = opendir("/proc");

        // loop over the process table
        while ((dent = readdir(dirp))!= NULL) {
            // skip the "." and ".." directories
            if (strcmp(dent->d_name, ".")!= 0 && strcmp(dent->d_name, "..")!= 0) {
                // get the process ID from the directory entry
                pid = atoi(dent->d_name);

                // get the process status
                waitpid(pid, &status, 0);

                // check if the process is still running
                if (WIFEXITED(status) || WIFSIGNALED(status)) {
                    // print the process ID and status
                    printf("%d (%d)\n", pid, WEXITSTATUS(status));
                }
            }
        }

        // close the process table
        closedir(dirp);

        // exit the child process
        exit(0);
    } else {
        // wait for the child process to finish
        waitpid(pid, &status, 0);

        // check if the child process terminated
        if (WIFEXITED(status) || WIFSIGNALED(status)) {
            // print the process ID and status
            printf("%d (%d)\n", pid, WEXITSTATUS(status));
        }
    }

    return 0;
}