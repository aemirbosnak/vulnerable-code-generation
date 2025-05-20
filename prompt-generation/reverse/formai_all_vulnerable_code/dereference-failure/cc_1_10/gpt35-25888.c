//FormAI DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <fcntl.h>

#define MAX_PATH_LENGTH 1024
#define BUFF_SIZE 1024

int main()
{
    DIR *dirp;
    struct dirent *dp;
    char proc_path[MAX_PATH_LENGTH];
    char cmd_path[MAX_PATH_LENGTH];
    char line[BUFF_SIZE];
    pid_t pid;
    int fd;

    printf("PID\t\tName\t\tState\n");

    dirp = opendir("/proc");
    if(!dirp) {
        perror("Could not open /proc directory");
        return EXIT_FAILURE;
    }

    while ((dp = readdir(dirp)) != NULL) {
        if (!isdigit(dp->d_name[0])) {
            continue;
        }
        pid = atoi(dp->d_name);
        sprintf(proc_path, "/proc/%d/status", pid);
        fd = open(proc_path, O_RDONLY);
        if (fd == -1) {
            perror(proc_path);
            continue;
        }
        while(read(fd, line, BUFF_SIZE)) {
            if(strncmp(line, "State:", 6) == 0) {
                printf("%-10d\t", pid);
                sscanf(line + 7, "%s", line);
                printf("%-15s\t", dp->d_name);
                printf("%s\n", line);
                break;
            }
        }
        close(fd);
    }
    closedir(dirp);
    return 0;
}