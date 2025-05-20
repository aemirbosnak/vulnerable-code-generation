//GEMINI-pro DATASET v1.0 Category: System process viewer ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char buf[1024];
    char *proc_path = "/proc";
    int pid;
    char *stat_path;
    char *cmdline_path;
    FILE *stat_file;
    FILE *cmdline_file;
    char state;
    int ppid;
    unsigned long starttime;
    unsigned long utime;
    unsigned long stime;
    char *name;
    int i;

    // Open the /proc directory
    fd = open(proc_path, O_RDONLY | O_DIRECTORY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    // Get all the pids
    pid = 1;
    while (pid != 0) {
        sprintf(buf, "%s/%d", proc_path, pid);
        if (stat(buf, &buf) == 0) {
            // Get the stat file path
            stat_path = malloc(strlen(buf) + 6);
            strcpy(stat_path, buf);
            strcat(stat_path, "/stat");

            // Get the stat file
            stat_file = fopen(stat_path, "r");
            if (stat_file == NULL) {
                perror("fopen");
                return 1;
            }

            // Get the state
            fscanf(stat_file, "%*d %s %c %d %*d %d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %lu %lu %lu %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d %*d", buf, &state, &ppid, &pid, &starttime, &utime, &stime);
            fclose(stat_file);
            free(stat_path);

            // Get the cmdline file path
            cmdline_path = malloc(strlen(buf) + 8);
            strcpy(cmdline_path, buf);
            strcat(cmdline_path, "/cmdline");

            // Get the cmdline file
            cmdline_file = fopen(cmdline_path, "r");
            if (cmdline_file == NULL) {
                perror("fopen");
                return 1;
            }

            // Get the name
            fscanf(cmdline_file, "%s", buf);
            name = strdup(buf);
            fclose(cmdline_file);
            free(cmdline_path);

            // Print the process information
            printf("%d %c %d %s\n", pid, state, ppid, name);
            free(name);
        }
        pid++;
    }

    // Close the /proc directory
    close(fd);

    return 0;
}