//FormAI DATASET v1.0 Category: System process viewer ; Style: recursive
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include<stdlib.h>

typedef struct process_info{
    int pid;
    char cmd[50];
    char state;
    int ppid;
} proc_info;

void print_process_info(proc_info process){
    printf("%-8d %-28s %-12c %-5d\n", process.pid, process.cmd, process.state, process.ppid);
}

void get_process_info(char* pid, proc_info* curr_info){
    char buffer[100];
    FILE* fp;

    sprintf(buffer, "/proc/%s/stat", pid);
    fp = fopen(buffer, "r");

    if(fp){
        fscanf(fp, "%d %s %c %d", &(curr_info->pid), curr_info->cmd, &(curr_info->state), &(curr_info->ppid));
        fclose(fp);
    }
}

void recursive_process_view(char* parent_pid, int depth){
    DIR* proc_dir;
    struct dirent* entry;
    proc_info curr_info;
    char buffer[100];
    int spaces = depth * 2;
    int i;

    proc_dir = opendir("/proc");

    while((entry = readdir(proc_dir))){
        if(entry->d_type == DT_DIR && atoi(entry->d_name)){
            get_process_info(entry->d_name, &curr_info);
            if(curr_info.ppid == atoi(parent_pid)){
                for(i = 0; i < spaces; i++) printf(" ");
                print_process_info(curr_info);
                sprintf(buffer, "/proc/%s", entry->d_name);
                recursive_process_view(entry->d_name, depth + 1);
            }
        }
    }

    closedir(proc_dir);
}


int main(int argc, char** argv){
    printf("%-8s %-28s %-12s %-5s\n", "PID", "CMD", "STATE", "PPID");
    recursive_process_view("0", 0);

    return 0;
}