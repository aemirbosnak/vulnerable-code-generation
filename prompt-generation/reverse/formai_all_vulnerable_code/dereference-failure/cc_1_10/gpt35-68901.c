//FormAI DATASET v1.0 Category: System process viewer ; Style: Donald Knuth
// Donald Knuth Style System Process Viewer

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 256
#define STAT_FILE "stat"
#define MAX_CHILDREN 1024

typedef struct {
    int pid;
    char comm[MAX_LEN];
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    unsigned int flags;
    unsigned long int minflt;
    unsigned long int cminflt;
    unsigned long int majflt;
    unsigned long int cmajflt;
    unsigned long int utime;
    unsigned long int stime;
    long int cutime;
    long int cstime;
    long int priority;
    long int nice;
    long int num_threads;
    long int itrealvalue;
    unsigned long long int starttime;
    unsigned long int vsize;
    long int rss;
    unsigned long int rsslim;
    unsigned long int startcode;
    unsigned long int endcod;
    unsigned long int startstack;
    unsigned long int kstkesp;
    unsigned long int kstkeip;
    unsigned long int signal;
    unsigned long int blocked;
    unsigned long int sigignore;
    unsigned long int sigcatch;
    unsigned long int wchan;
} proc_t;

// function to get the process information from the /proc directory
void get_proc_info(proc_t *proc_info, int pid) {
    char path[MAX_LEN];
    FILE *fp;

    sprintf(path, "/proc/%d/%s", pid, STAT_FILE);

    fp = fopen(path, "r");

    if(fp == NULL) {
        printf("Error: Could not open file %s\n", path);
        exit(1);
    }

    fscanf(fp, "%d %s %c %d %d %d %d %d %u "
                "%lu %lu %lu %lu %lu %lu %ld "
                "%ld %ld %ld %ld %ld %llu %lu "
                "%ld %lu %lu %lu %lu %lu %lu "
                "%lu %lu %lu %lu %lu %lu %lu "
                "%lu %lu %lu",
            &proc_info->pid, proc_info->comm, &proc_info->state, 
            &proc_info->ppid, &proc_info->pgrp, &proc_info->session, 
            &proc_info->tty_nr, &proc_info->tpgid, &proc_info->flags, 
            &proc_info->minflt, &proc_info->cminflt, &proc_info->majflt, 
            &proc_info->cmajflt, &proc_info->utime, &proc_info->stime, 
            &proc_info->cutime, &proc_info->cstime, &proc_info->priority, 
            &proc_info->nice, &proc_info->num_threads, &proc_info->itrealvalue, 
            &proc_info->starttime, &proc_info->vsize, &proc_info->rss, 
            &proc_info->rsslim, &proc_info->startcode, &proc_info->endcod, 
            &proc_info->startstack, &proc_info->kstkesp, &proc_info->kstkeip, 
            &proc_info->signal, &proc_info->blocked, &proc_info->sigignore, 
            &proc_info->sigcatch, &proc_info->wchan
    );

    fclose(fp);
}

// print process information
void print_proc_info(proc_t *proc_info) {
    printf("PID: %d\n", proc_info->pid);
    printf("Comm: %s\n", proc_info->comm);
    printf("State: %c\n", proc_info->state);
    printf("-----------------------------------------\n");
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *dp;
    int pid_list[MAX_CHILDREN], pid_count = 0;
    proc_t proc_info;

    dir = opendir("/proc");

    if(dir == NULL) {
        printf("Error: Could not open directory /proc\n");
        exit(1);
    }

    // scan /proc to find all running processes
    while((dp = readdir(dir)) != NULL && pid_count < MAX_CHILDREN) {
        if(isdigit(dp->d_name[0])) {
            pid_list[pid_count++] = atoi(dp->d_name);
        }
    }

    closedir(dir);

    printf("Donald Knuth Style System Process Viewer\n");
    printf("-----------------------------------------\n");

    for(int i = 0; i < pid_count; i++) {
        get_proc_info(&proc_info, pid_list[i]);
        print_proc_info(&proc_info);
    }

    return 0;
}