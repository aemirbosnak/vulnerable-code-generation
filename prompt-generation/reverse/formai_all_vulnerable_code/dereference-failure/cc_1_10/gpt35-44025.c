//FormAI DATASET v1.0 Category: System process viewer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 1024

/* Function prototypes */
void print_processes();
void print_process_details(int pid);

/* Main function */
int main(int argc, char *argv[]) {
    int pid;
    if (argc == 1) {
        print_processes();
    } else if (argc == 2) {
        /* Get the PID from the command line argument */
        if (isdigit(argv[1][0])) {
            pid = atoi(argv[1]);
            print_process_details(pid);
        } else {
            printf("Invalid argument.\n");
        }
    } else {
        printf("Invalid number of arguments.\n");
    }
    return 0;
}

/* Function to print all processes */
void print_processes() {
    DIR *dp;
    struct dirent *dirp;
    char path[MAX_BUF], line[MAX_BUF], name[MAX_BUF];
    FILE *fp;
    int pid;
    printf("%10s %10s\n", "PID", "Command Name");
    if ((dp = opendir("/proc/")) == NULL) { /* open the directory /proc */
        perror("opendir failed");
        return;
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (isdigit(dirp->d_name[0])) { /* check if the directory name is a PID */
            pid = atoi(dirp->d_name);
            sprintf(path, "/proc/%d/cmdline", pid);
            if ((fp = fopen(path, "r")) != NULL) { /* open the command line file */
                fgets(line, MAX_BUF, fp);
                fclose(fp);
                strcpy(name, basename(line)); /* get the command name */
                printf("%10d %10s\n", pid, name);
            }
        }
    }
    closedir(dp);
}

/* Function to print details of a specific process */
void print_process_details(int pid) {
    char path[MAX_BUF], line[MAX_BUF];
    FILE *fp;
    printf("Process details for PID %d:\n", pid);
    printf("%-25s %-25s\n", "Parameter", "Value");
    sprintf(path, "/proc/%d/cmdline", pid);
    if ((fp = fopen(path, "r")) != NULL) { /* open the command line file */
        fgets(line, MAX_BUF, fp);
        fclose(fp);
        printf("%-25s %-25s\n", "Command name", basename(line));
    }
    sprintf(path, "/proc/%d/status", pid);
    if ((fp = fopen(path, "r")) != NULL) { /* open the status file */
        while (fgets(line, MAX_BUF, fp)) {
            if (strstr(line, "Name:")) {
                printf("%-25s %-25s\n", "Process name", line+6);
            } else if (strstr(line, "State:")) {
                printf("%-25s %-25s\n", "Process state", line+7);
            } else if (strstr(line, "VmPeak:")) {
                printf("%-25s %-25s\n", "Peak virtual memory", line+8);
            } else if (strstr(line, "VmSize:")) {
                printf("%-25s %-25s\n", "Virtual memory size", line+8);
            } else if (strstr(line, "VmRSS:")) {
                printf("%-25s %-25s\n", "Resident set size", line+7);
            } else if (strstr(line, "father:")) {
                printf("%-25s %-25s\n", "Parent process ID", line+8);
            }
        }
        fclose(fp);
    }
    sprintf(path, "/proc/%d/fd", pid);
    if ((fp = fopen(path, "r")) != NULL) { /* open the file descriptor directory */
        printf("%-25s %-25s\n", "Open file descriptors", "");
        int count = 0;
        struct dirent *dirp;
        int fd_dir;
        char fd_path[MAX_BUF], buf[MAX_BUF];
        while ((dirp = readdir(fp)) != NULL) {
            if (dirp->d_name[0] != '.') {
                ++count;
            }
        }
        rewinddir(fp);
        while ((dirp = readdir(fp)) != NULL) {
            if (dirp->d_name[0] != '.') {
                sprintf(fd_path, "%s/%s", path, dirp->d_name);
                if ((fd_dir = open(fd_path, O_RDONLY)) != -1) {
                    read(fd_dir, buf, MAX_BUF);
                    printf("%d: %s\n", atoi(dirp->d_name), buf);
                    close(fd_dir);
                }
            }
        }
        closedir(fp);
    }
}