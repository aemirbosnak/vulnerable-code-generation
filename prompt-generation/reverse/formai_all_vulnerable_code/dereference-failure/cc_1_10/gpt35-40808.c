//FormAI DATASET v1.0 Category: System process viewer ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <ctype.h>

typedef struct {
    pid_t pid;
    char name[100];
    char status;
    char parent[100];
} process;

void print_header(){
    printf("-----------------------------------------------------------------------\n");
    printf("|%15s |%25s |%10s |%25s  |\n", "PID", "PROCESS NAME", "STATUS", "PARENT");
    printf("-----------------------------------------------------------------------\n");
}

void print_process(process p){
    printf("|%15d |%25s |%10c |%25s  |\n", p.pid, p.name, p.status, p.parent);
}

int is_number(char* str){
    for(int i = 0; i < strlen(str); i++){
        if(!isdigit(str[i])){
            return 0;
        }
    }
    return 1;
}

void get_processes(){
    DIR* proc_dir = opendir("/proc");
    if(proc_dir == NULL){
        printf("Error opening proc directory.\n");
        exit(1);
    }

    struct dirent* entry;
    pid_t pid_list[100];
    int pid_list_index = 0;

    while((entry = readdir(proc_dir)) != NULL){
        if(is_number(entry->d_name)){
            pid_t pid = atoi(entry->d_name);
            pid_list[pid_list_index++] = pid;
        }
    }

    for(int i = 0; i < pid_list_index; i++){
        pid_t pid = pid_list[i];
        char proc_path[1000];
        sprintf(proc_path, "/proc/%d/status", pid);
        FILE* status_file = fopen(proc_path, "r");
        if(status_file != NULL){
            process p;
            p.pid = pid;
            while(!feof(status_file)){
                char line[1000];
                fgets(line, 1000, status_file);
                if(strncmp(line, "Name:", 5) == 0){
                    strcpy(p.name, line + 6);
                    p.name[strlen(p.name) - 1] = '\0';
                }
                if(strncmp(line, "PPid:", 5) == 0){
                    char temp[100];
                    strcpy(temp, line + 6);
                    temp[strlen(temp) - 1] = '\0';
                    pid_t parent_pid = atoi(temp);
                    sprintf(p.parent, "(%d) %s", parent_pid, "unknown");
                }
                if(strncmp(line, "State:", 6) == 0){
                    char* state = line + 7;
                    p.status = state[0];
                }
            }
            print_process(p);
            fclose(status_file);
        }
    }
}

int main(){
    print_header();
    get_processes();
    return 0;
}