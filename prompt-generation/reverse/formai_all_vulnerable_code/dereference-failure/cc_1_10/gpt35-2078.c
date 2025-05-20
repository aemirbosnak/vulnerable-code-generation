//FormAI DATASET v1.0 Category: System process viewer ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_DIGITS 5

// function to check if a string is numeric
int is_numeric(char* str){
    int i, len = strlen(str);
    for(i=0; i<len; i++){
        if(!isdigit(str[i]))
            return 0;
    }
    return 1;
}

// function to check if a PID exists
int pid_exists(int pid){
    char path[30];
    sprintf(path, "/proc/%d", pid);
    DIR* dir = opendir(path);
    if(dir == NULL)
        return 0;
    closedir(dir);
    return 1;
}

// function to get the name of a process given its PID
char* get_proc_name(int pid){
    char path[50], buffer[512];
    char* name = NULL;
    FILE* status_file;
    sprintf(path, "/proc/%d/status", pid);
    status_file = fopen(path, "r");
    if(status_file){
        while(fgets(buffer, sizeof(buffer), status_file)){
            if(strncmp(buffer, "Name:", 5) == 0){
                char* p = strchr(buffer, '\t');
                if(p != NULL){
                    name = strdup(++p); // duplicate the string after the tab character
                    strtok(name, "\n"); // remove trailing newline character
                }
                break;
            }
        }
        fclose(status_file);
    }
    return name;
}

// function to print the details of a process given its PID
void print_process_details(int pid){
    char path[30];
    sprintf(path, "/proc/%d/stat", pid);
    FILE* stat_file;
    stat_file = fopen(path, "r");
    if(stat_file){
        char name[50];
        int ppid, pgrp, session, tty_nr, tpgid, flags, minflt, cminflt, majflt, cmajflt, utime, stime, cutime, cstime, priority, nice, num_threads, itrealvalue;
        long unsigned int starttime, vsize;
        fscanf(stat_file, "%d %s %*c %d %d %d %d %d %d %u %lu %lu %lu %lu %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %ld %d %d %lu", 
            &pid, name, &ppid, &pgrp, &session, &tty_nr, &tpgid, &flags, &minflt, &cminflt, &majflt, &cmajflt, &utime, &stime, 
            &cutime, &cstime, &priority, &nice, &num_threads, &itrealvalue, &starttime, &vsize);
        fclose(stat_file);

        char* proc_name = get_proc_name(pid);
        printf("%5d %20s %5d %5d %5d %5d %5d %5d %10lu\n", pid, proc_name != NULL ? proc_name : "", ppid, pgrp, session, tty_nr, 
            tpgid, num_threads, vsize);
        if(proc_name != NULL)
            free(proc_name);
    }
}

int main(){
    printf("PID   Process Name            PPID  PGRP  SESS  TTY   TPGID  Threads  VSize\n");
    DIR* dir = opendir("/proc");
    struct dirent* dp;
    while((dp = readdir(dir)) != NULL){
        if(is_numeric(dp->d_name)){
            int pid = atoi(dp->d_name);
            if(pid_exists(pid))
                print_process_details(pid);
        }
    }
    closedir(dir);
    return 0;
}