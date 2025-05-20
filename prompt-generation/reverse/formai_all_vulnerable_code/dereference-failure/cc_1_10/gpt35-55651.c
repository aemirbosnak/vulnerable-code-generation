//FormAI DATASET v1.0 Category: System process viewer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_PATH 1024
#define MIN_PID 300
#define MAX_PID 5000

int pid_map[MAX_PID-MIN_PID+1];

int allocate_map()  // allocate pid map
{
    memset(pid_map, 0, sizeof(pid_map));
    return MIN_PID;
}

int allocate_pid()  // allocate a pid
{
    for (int i = 0; i < MAX_PID-MIN_PID+1; i++) 
    {
        if (pid_map[i] == 0) 
        {
            pid_map[i] = 1;
            return i + MIN_PID;  // return the allocated pid
        }
    }
    return -1;  // return -1 to indicate failure
}

void release_pid(int pid)  // release a pid
{
    pid_map[pid-MIN_PID] = 0;  // free the pid
}

int main()
{
    DIR *dir;
    struct dirent *entry;

    printf("PID\t\tPPID\t\tSTATE\n");
    printf("===============================================\n");

    dir = opendir("/proc");  // Open the /proc directory
    if (dir == NULL) 
    {
        perror("Unable to open /proc");
        return -1;
    }

    int pid;
    char path[MAX_PATH + 1];
    int ppid;
    char state;

    while (entry = readdir(dir))  // Read the directory entries
    {
        if (entry->d_type != DT_DIR) 
            continue;

        pid = atoi(entry->d_name);
        if (pid == 0) 
            continue;

        sprintf(path, "/proc/%d/stat", pid);
        FILE *fp = fopen(path, "r");
        if (fp == NULL)
            continue;

        fscanf(fp, "%d %*s %c %d", &pid, &state, &ppid);  // Read the contents of the /proc/<pid>/stat file
        fclose(fp);

        printf("%d\t\t%d\t\t%c\n", pid, ppid, state);
    }

    closedir(dir);
    return 0;
}