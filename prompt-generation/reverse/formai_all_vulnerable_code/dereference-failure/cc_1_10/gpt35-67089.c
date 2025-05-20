//FormAI DATASET v1.0 Category: System process viewer ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_COMM 16 // maximum length for command name display
#define MAX_PID_LENGTH 10 // maximum length for pid number
#define MAX_PATH_LENGTH 64 // maximum length for stat file path
#define MAX_TASKS 1024 // maximum number of tasks/processes

// structure for storing process information
typedef struct {
    char pid[MAX_PID_LENGTH];
    char comm[MAX_COMM];
    char state;
    char vmlck;
    long int utime;
    long int stime;
    unsigned long int rss;
} proc_info;

// function for parsing stat file and storing process information
void parse_stat_file(char *pid, proc_info *pinfo) {
    char stat_path[MAX_PATH_LENGTH];
    FILE *fp;
    char buf[1024];
    
    // create path for stat file
    snprintf(stat_path, MAX_PATH_LENGTH, "/proc/%s/stat", pid);
    
    // open stat file for reading
    fp = fopen(stat_path, "r");
    if(fp == NULL) {
        fprintf(stderr, "Failed to open %s\n", stat_path);
        exit(EXIT_FAILURE);
    }
    
    // parse contents of stat file
    fscanf(fp, "%s %s %c %c %*s %*s %*s %*s %*s %*s %*s %*s %*s %*s %ld %ld %*s %*s %ld", 
           pinfo->pid, pinfo->comm, &pinfo->state, &pinfo->vmlck, &pinfo->utime, &pinfo->stime, &pinfo->rss);
    
    // close file stream
    fclose(fp);
}

int main() {
    DIR *dir;
    struct dirent *entry;
    char path[MAX_PATH_LENGTH];
    char *endptr;
    int ntasks = 0;
    proc_info tasks[MAX_TASKS];
    int i, j;
    long int cpu_time = 0;
    unsigned long int rss_total = 0;
    
    // open directory containing process directories
    dir = opendir("/proc");
    if(dir == NULL) {
        fprintf(stderr, "Failed to open /proc\n");
        exit(EXIT_FAILURE);
    }
    
    // iterate through each directory (pid) in /proc
    while((entry = readdir(dir)) != NULL) {
        // check if directory entry is a pid number
        if(isdigit(*entry->d_name)) {
            // create path for stat file
            snprintf(path, MAX_PATH_LENGTH, "/proc/%s/stat", entry->d_name);
            
            // attempt to parse contents of corresponding stat file
            if((endptr = strrchr(entry->d_name, '\0')) != NULL) {
                parse_stat_file(entry->d_name, &tasks[ntasks]);
                ntasks++;
                
                // update total cpu time and rss usage
                cpu_time += tasks[ntasks-1].utime + tasks[ntasks-1].stime;
                rss_total += tasks[ntasks-1].rss;
            }
        }
    }
    
    // print process information table
    printf("%-10s %-16s %-8s %-10s %-10s %-10s\n", "PID", "COMMAND", "STATE", "VMLOCK", "UTIME", "STIME");
    for(i = 0; i < ntasks; i++) {
        printf("%-10s ", tasks[i].pid);
        for(j = 0; j < MAX_COMM; j++) {
            if(tasks[i].comm[j] == '\0')
                break;
            printf("%c", tasks[i].comm[j]);
        }
        printf(" ");
        printf("%-8c %-10c %-10ld %-10ld\n", tasks[i].state, tasks[i].vmlck, tasks[i].utime, tasks[i].stime);
    }
    
    // print cpu time and rss summary
    printf("\nTotal CPU time: %ld\n", cpu_time);
    printf("Total RSS usage: %lu KB\n", rss_total);
    
    // close directory stream
    closedir(dir);

    return 0;
}