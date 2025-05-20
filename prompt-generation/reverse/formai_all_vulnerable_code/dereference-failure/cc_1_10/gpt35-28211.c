//FormAI DATASET v1.0 Category: System process viewer ; Style: energetic
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include<ctype.h>
#include<string.h>

/* This is an example C program that shows the current running processes in a Unix-like system.
   It works by reading the contents of the /proc directory, which contains information about running processes.
   The program parses the contents of each subdirectory in /proc and retrieves information such as the process ID, name, and status. */

int main()
{
    DIR* dir;
    struct dirent* diread;
    char proc_path[256];
    char buf[256];
    FILE* fd;
    int pid;
    char pname[256];
    char state;
    int ppid, pgrp, sid, tty_nr, tty_pgrp;
    unsigned long int utime, stime, cutime, cstime, starttime, total_time;
    long int num_threads;
    long int rss;
    
    printf("Current Processes:\n");
    printf("PID\tNAME\tSTATE\tPPID\tPGRP\tSID\tTHREADS\tRSS\n");
    
    if ((dir = opendir("/proc")) == NULL) {
        perror("opendir() error");
        exit(1);
    }
    
    while ((diread = readdir(dir)) != NULL) {
        if (!isdigit(diread->d_name[0]))
            continue;
        
        sprintf(proc_path, "/proc/%s/stat", diread->d_name);
        
        if ((fd = fopen(proc_path, "r")) == NULL)
            continue;
        
        fscanf(fd, "%d %s %c %d %d %d %d %d %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %ld %ld %lu %lu %ld",
               &pid, pname, &state, &ppid, &pgrp, &sid, &tty_nr, &tty_pgrp, &utime, &stime, &cutime, &cstime,
               &starttime, &num_threads, &rss);
        
        total_time = utime + stime + cutime + cstime;
        
        printf("%d\t%s\t%c\t%d\t%d\t%d\t%ld\t%ld\n", pid, pname, state, ppid, pgrp, sid, num_threads, rss);
        
        fclose(fd);
    }
    
    closedir(dir);
    
    return 0;
}