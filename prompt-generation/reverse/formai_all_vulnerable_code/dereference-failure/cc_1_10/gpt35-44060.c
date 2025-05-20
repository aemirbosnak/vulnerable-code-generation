//FormAI DATASET v1.0 Category: System process viewer ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

/* Structure to store process stats */
typedef struct {
    int pid;
    char name[256];
    char state;
    int ppid;
    int pgrp;
    int session;
    int tty_nr;
    int tpgid;
    unsigned long minflt;
    unsigned long cminflt;
    unsigned long majflt;
    unsigned long cmajflt;
    unsigned long utime;
    unsigned long stime;
    long cutime;
    long cstime;
    long priority;
    long nice;
    long num_threads;
    long itrealvalue;
    unsigned long long starttime;
    unsigned long vsize;
    long rss;
} proc_stats;

/* Function to read process stats from /proc */
void read_proc_stat(proc_stats *p) {
    char filename[256];
    FILE *f;

    /* Create filename from pid */
    sprintf(filename, "/proc/%d/stat", p->pid);

    /* Open file */
    f = fopen(filename, "r");

    /* Read stats */
    if (f) {
        fscanf(f, "%d %s %c %d %d %d %d %d %u %lu %lu %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %ld %llu %lu %ld", 
            &p->pid, p->name, &p->state, &p->ppid, &p->pgrp, &p->session, &p->tty_nr, &p->tpgid,
            &p->minflt, &p->cminflt, &p->majflt, &p->cmajflt, &p->utime, &p->stime,
            &p->cutime, &p->cstime, &p->priority, &p->nice, &p->num_threads,
            &p->itrealvalue, &p->starttime, &p->vsize, &p->rss);

        fclose(f);
    }
}

/* Function to print process stats */
void print_proc_stat(proc_stats p) {
    printf("%5d %-20s %c   %5d %5d %5d %5d %5d  %10lu %10lu %10lu %10lu %10lu %10lu %10ld %10ld %10ld %10ld %10ld %10ld %10ld %10llu %10lu %10ld\n",
           p.pid, p.name, p.state, p.ppid, p.pgrp, p.session, p.tty_nr, p.tpgid,
           p.minflt, p.cminflt, p.majflt, p.cmajflt, p.utime, p.stime,
           p.cutime, p.cstime, p.priority, p.nice, p.num_threads,
           p.itrealvalue, p.starttime, p.vsize, p.rss);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    proc_stats stats;

    /* Print header */
    printf("%5s %-20s %s\n", "PID", "COMMAND", "STAT  PPID  PGID  SESS  TTYNR TPGID    MINFLT     CMINFLT     MAJFLT     CMAJFLT     UTIME      STIME      CUTIME     CSTIME     PRIORITY   NICE       THREADS    ITREALVAL  STARTTIME  VSIZE      RSS");

    /* Open /proc directory */
    dir = opendir("/proc");
    if (!dir) {
        perror("opendir");
        exit(1);
    }

    /* Loop through entries */
    while ((entry = readdir(dir)) != NULL) {
        /* Check if entry is a directory */
        if (entry->d_type == DT_DIR) {
            /* Check if name is a number */
            if (atoi(entry->d_name) != 0) {
                /* Set pid */
                stats.pid = atoi(entry->d_name);

                /* Read process stats */
                read_proc_stat(&stats);

                /* Print process stats */
                print_proc_stat(stats);
            }
        }
    }

    /* Close /proc directory */
    closedir(dir);

    return 0;
}