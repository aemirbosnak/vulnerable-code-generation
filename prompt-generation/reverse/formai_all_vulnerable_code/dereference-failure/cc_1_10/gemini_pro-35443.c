//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>

void sigHandler(int signum)
{
    printf("Exiting...\n");
    exit(0);
}

int main()
{
    pid_t pid = getpid();
    printf("Current process ID: %d\n", pid);

    struct dirent *dp;
    DIR *dir = opendir("/proc");

    if (dir == NULL)
    {
        perror("Could not open /proc directory");
        return -1;
    }

    while ((dp = readdir(dir)) != NULL)
    {
        if (atoi(dp->d_name) != pid && atoi(dp->d_name) > 0)
        {
            char procDir[1024];
            sprintf(procDir, "/proc/%s", dp->d_name);

            char cmdlineFile[1024];
            sprintf(cmdlineFile, "%s/cmdline", procDir);

            int fd = open(cmdlineFile, O_RDONLY);

            if (fd == -1)
            {
                perror("Could not open cmdline file");
            }
            else
            {
                char cmdline[1024];
                int n = read(fd, cmdline, 1023);
                cmdline[n] = '\0';

                printf("Process ID: %s\n", dp->d_name);
                printf("Command line: %s\n", cmdline);
                close(fd);
            }
        }
    }

    closedir(dir);

    signal(SIGINT, sigHandler);

    while (1)
    {
        pause();
    }

    return 0;
}