//FormAI DATASET v1.0 Category: System process viewer ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <string.h>

// A structure to store process information
struct process_info{
    char pid[50];
    char pname[50];
    char pstatus[50];
};

// A function to read the process information from /proc directory
void read_proc_dir(struct process_info *proc_list, int *num_procs){
    DIR *dir;
    struct dirent *entry;
    char path[100];
    *num_procs = 0;

    // Open the /proc directory
    dir = opendir("/proc");

    // Loop through each entry in the /proc directory
    while((entry = readdir(dir)) != NULL){
        // Check if the entry is a directory and if the name is a number
        if(entry->d_type == DT_DIR && atoi(entry->d_name) != 0){
            strcpy(path, "/proc/");
            strcat(path, entry->d_name);

            // Read the process status file to get process information
            FILE *fp = fopen(strcat(path, "/status"), "r");
            if(fp == NULL){
                continue;
            }
            char line[100], pname[50], pstatus[50];
            int pid;

            // Extract process information from the status file
            while(fgets(line, 100, fp)){
                if(sscanf(line, "Name:\t%s", pname) == 1){
                    continue;
                }
                if(sscanf(line, "State:\t%s", pstatus) == 1){
                    continue;
                }
                if(sscanf(line, "Pid:\t%d", &pid) == 1){
                    sprintf(proc_list[*num_procs].pid, "%d", pid);
                    strcpy(proc_list[*num_procs].pname, pname);
                    strcpy(proc_list[*num_procs].pstatus, pstatus);
                    (*num_procs)++;
                    break;
                }
            }
            fclose(fp);
        }
    }
    closedir(dir);
}

// A function to print the process information in a table format
void print_proc_info(struct process_info *procs, int num_procs){
    printf("PID\tProcess Name\tStatus\n");
    printf("-----------------------------------------\n");
    for(int i = 0; i < num_procs; i++){
        printf("%s\t%-15s\t%s\n", procs[i].pid, procs[i].pname, procs[i].pstatus);
    }
}

int main(){
    struct process_info proc_list[100];
    int num_procs;

    // Read process information from /proc directory
    read_proc_dir(proc_list, &num_procs);

    // Print process information
    print_proc_info(proc_list, num_procs);

    return 0;
}