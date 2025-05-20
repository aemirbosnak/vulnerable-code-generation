//Falcon2-11B DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <signal.h>
#include <pwd.h>
#include <grp.h>

// Function to get the process information
void getProcessInfo(pid_t pid)
{
    struct rusage usage;
    int status;

    if (waitpid(pid, &status, 0) == -1)
    {
        perror("waitpid");
        exit(1);
    }

    getrusage(RUSAGE_SELF, &usage);
    printf("%3d  %16s  %7.2f\n", pid, " ", ((float)usage.ru_utime.tv_sec + (float)usage.ru_utime.tv_usec * 1e-6) / 1000);
}

int main(int argc, char *argv[])
{
    struct passwd *pwd;
    struct group *grp;
    char buffer[1024];
    int pid, status;

    if (argc!= 2)
    {
        fprintf(stderr, "Usage: %s <pid>\n", argv[0]);
        exit(1);
    }

    pid = atoi(argv[1]);

    if (pid <= 0)
    {
        fprintf(stderr, "Invalid process ID\n");
        exit(1);
    }

    if ((pwd = getpwuid(pid)) == NULL)
    {
        fprintf(stderr, "Invalid user ID\n");
        exit(1);
    }

    if ((grp = getgrgid(pwd->pw_gid)) == NULL)
    {
        fprintf(stderr, "Invalid group ID\n");
        exit(1);
    }

    printf("%s %s\n", pwd->pw_name, grp->gr_name);
    printf("Process ID: %d\n", pid);

    int fd = open("/proc/self/status", O_RDONLY);

    if (fd == -1)
    {
        perror("open");
        exit(1);
    }

    while (1)
    {
        int nread;
        read(fd, buffer, sizeof(buffer));

        if (buffer[0] == 'V' && buffer[1] == 'V' && buffer[2] == 'N' && buffer[3] == 'D')
        {
            break;
        }

        nread = read(fd, buffer, sizeof(buffer));

        if (nread < 0)
        {
            perror("read");
            exit(1);
        }

        getProcessInfo(atoi(buffer));
    }

    close(fd);
    return 0;
}