//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_PROCESSES 100
#define MAX_LINE_LENGTH 1024

struct process {
    pid_t pid;
    char name[MAX_LINE_LENGTH];
    char state;
};

int main() {
    int num_processes = 0;
    DIR *dirp;
    struct dirent *direntp;
    char proc_path[MAX_LINE_LENGTH];
    char proc_name[MAX_LINE_LENGTH];
    char proc_state;
    struct process processes[MAX_PROCESSES];
    
    dirp = opendir("/proc");
    if (dirp == NULL) {
        printf("Error: Could not open /proc directory.\n");
        exit(1);
    }
    
    while ((direntp = readdir(dirp))!= NULL) {
        if (direntp->d_type == DT_DIR) {
            sprintf(proc_path, "/proc/%s", direntp->d_name);
            if (access(proc_path, F_OK)!= -1) {
                sprintf(proc_name, "%s", direntp->d_name);
                proc_state = 'R';
                strcat(proc_name, &proc_state);
                strcpy(processes[num_processes].name, proc_name);
                processes[num_processes].pid = atoi(direntp->d_name);
                processes[num_processes].state = proc_state;
                num_processes++;
            }
        }
    }
    
    closedir(dirp);
    
    system("clear");
    printf("Process ID\tName\tState\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%c\n", processes[i].pid, processes[i].name, processes[i].state);
    }
    
    return 0;
}