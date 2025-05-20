//FormAI DATASET v1.0 Category: System process viewer ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>

//structure to hold process information
struct process {
    char pid[10];
    char name[50];
    char state[20];
};

//function to parse the process information from /proc/PID/stat file
void get_process_info(char pid[], struct process *p) {
    FILE *fp;
    char path[50];
    char line[100];
    
    sprintf(path, "/proc/%s/stat", pid);
    fp = fopen(path, "r");
    if(fp) {
        if(fgets(line, sizeof(line), fp)) {
            //parse the first token - pid
            char *token = strtok(line, " ");
            if(token) {
                strcpy(p->pid, token);
            }
            //parse the second token - name
            token = strtok(NULL, " ");
            if(token) {
                //remove the brackets
                token = strtok(token, "(");
                token = strtok(NULL, "(");
                token[strlen(token)-1] = '\0';
                strcpy(p->name, token);
            }
            //parse the third token - state
            token = strtok(NULL, " ");
            if(token) {
                strcpy(p->state, token);
            }
        }
        fclose(fp);
    }
}

int main() {
    DIR *dir;
    struct dirent *entry;
    struct process *processes;
    int num_processes = 0;
    
    //open the /proc directory 
    dir = opendir("/proc");
    if(dir) {
        while((entry = readdir(dir)) != NULL) {
            //check if the directory name is a number (i.e. a process ID)
            if(isdigit(entry->d_name[0])) {
                num_processes++;
            }
        }
        closedir(dir);
    }
    
    //allocate memory for the processes
    processes = (struct process*) malloc(num_processes * sizeof(struct process));
    
    //iterate through the /proc directory again to get process information
    int i = 0;
    dir = opendir("/proc");
    if(dir) {
        while((entry = readdir(dir)) != NULL) {
            if(isdigit(entry->d_name[0])) {
                get_process_info(entry->d_name, &processes[i]);
                i++;
            }
        }
        closedir(dir);
    }
    
    //print the process information
    printf("%-10s %-50s %-20s\n", "PID", "NAME", "STATE");
    for(i=0; i<num_processes; i++) {
        printf("%-10s %-50s %-20s\n", processes[i].pid, processes[i].name, processes[i].state);
    }
    
    free(processes);
    
    return 0;
}