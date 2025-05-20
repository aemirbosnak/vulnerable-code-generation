//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;
    struct stat buf;
    char *path;
    pid_t pid;
    FILE *fp;

    // Get the list of processes
    if ((dir = opendir("/proc")) == NULL)
    {
        perror("opendir");
        return EXIT_FAILURE;
    }

    // Iterate over the processes
    while ((ent = readdir(dir)) != NULL)
    {
        // Get the process ID
        pid = atoi(ent->d_name);

        // Check if the process is a valid PID
        if (pid <= 0 || pid >= 1000000)
        {
            continue;
        }

        // Get the process stat file
        path = malloc(strlen("/proc/") + strlen(ent->d_name) + strlen("/stat") + 1);
        snprintf(path, strlen("/proc/") + strlen(ent->d_name) + strlen("/stat") + 1, "/proc/%s/stat", ent->d_name);

        if ((fp = fopen(path, "r")) == NULL)
        {
            perror("fopen");
            free(path);
            continue;
        }

        // Read the process stat file
        fscanf(fp, "%*d %*s %*c %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*u %*u %*d %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*u %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d%*s", &pid);
        fclose(fp);
        free(path);

        // Print the process name
        path = malloc(strlen("/proc/") + strlen(ent->d_name) + strlen("/cmdline") + 1);
        snprintf(path, strlen("/proc/") + strlen(ent->d_name) + strlen("/cmdline") + 1, "/proc/%s/cmdline", ent->d_name);

        if ((fp = fopen(path, "r")) == NULL)
        {
            perror("fopen");
            free(path);
            continue;
        }

        // Read the process command line
        fscanf(fp, "%s", path);
        fclose(fp);
        free(path);

        // Print the process information
        printf("%d %s\n", pid, path);
    }

    // Close the directory
    closedir(dir);

    return EXIT_SUCCESS;
}