//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

void sighandler(int signum) {
    switch(signum) {
        case SIGCHLD:
            waitpid(-1, NULL, WNOHANG);
            break;
        default:
            break;
    }
}

void print_process_info(pid_t pid, char *name) {
    char path[1024];
    sprintf(path, "/proc/%d", pid);
    DIR *dir = opendir(path);
    struct dirent *dent;
    while ((dent = readdir(dir))!= NULL) {
        if (strcmp(dent->d_name, "cmdline") == 0) {
            char cmdline_path[1024];
            sprintf(cmdline_path, "%s/cmdline", path);
            FILE *fp = fopen(cmdline_path, "r");
            char cmdline[1024];
            fgets(cmdline, 1024, fp);
            fclose(fp);
            printf("Process name: %s\n", name);
            printf("PID: %d\n", pid);
            printf("Command line: %s\n", cmdline);
        }
    }
    closedir(dir);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <process_name>\n", argv[0]);
        exit(1);
    }

    char *process_name = argv[1];
    DIR *dir = opendir("/proc");
    struct dirent *dent;
    int found = 0;
    while ((dent = readdir(dir))!= NULL) {
        int pid = atoi(dent->d_name);
        char path[1024];
        sprintf(path, "/proc/%d/comm", pid);
        char comm[1024];
        FILE *fp = fopen(path, "r");
        fgets(comm, 1024, fp);
        fclose(fp);
        if (strcmp(comm, process_name) == 0) {
            print_process_info(pid, process_name);
            found = 1;
        }
    }
    closedir(dir);

    if (!found) {
        printf("Process not found.\n");
    }

    return 0;
}