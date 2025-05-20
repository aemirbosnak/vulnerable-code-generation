//FormAI DATASET v1.0 Category: System process viewer ; Style: authentic
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

#define MAX_PID_LEN 6
#define MAX_PROC_NAME_LEN 1024
#define MAX_STATE_LEN 2
#define MAX_LINE_LEN 2048
#define MAX_COMMAND_LEN 2048

typedef struct {
    char pid[MAX_PID_LEN];
    char proc_name[MAX_PROC_NAME_LEN];
    char state[MAX_STATE_LEN];
    char command[MAX_COMMAND_LEN];
} process_info;

void print_header() {
    printf("%-10s%-30s%-10s%s\n", "PID", "Process Name", "State", "Command");
    printf("-------------------------------------------------------\n");
}

char* get_proc_name_from_pid(const char* pid) {
    char* proc_name = malloc(MAX_PROC_NAME_LEN*sizeof(char));
    char proc_path[1024];
    sprintf(proc_path, "/proc/%s/comm", pid);
    FILE* fp = fopen(proc_path, "r");
    fgets(proc_name, MAX_PROC_NAME_LEN, fp);
    fclose(fp);
    return proc_name;
}

void get_proc_state_from_pid(const char* pid, char* state) {
    char proc_path[1024];
    sprintf(proc_path, "/proc/%s/status", pid);
    FILE* fp = fopen(proc_path, "r");
    char line[MAX_LINE_LEN];
    while(fgets(line, MAX_LINE_LEN, fp)) {
        char* key = strtok(line, ":\t");
        if (strcmp(key, "State") == 0) {
            char* value = strtok(NULL, ":\t");
            strncpy(state, value, MAX_STATE_LEN);
            break;
        }
    }
    fclose(fp);
}

void get_proc_command_from_pid(const char* pid, char* command) {
    char proc_path[1024];
    sprintf(proc_path, "/proc/%s/cmdline", pid);
    FILE* fp = fopen(proc_path, "r");
    fgets(command, MAX_COMMAND_LEN, fp);
    fclose(fp);
}

void print_process_info(process_info* pi) {
    printf("%-10s%-30s%-10s%s\n", pi->pid, pi->proc_name, pi->state, pi->command);
}

void list_processes() {
    DIR* dir = opendir("/proc/");
    struct dirent* ent;
    while ((ent = readdir(dir)) != NULL) {
        if (isdigit(ent->d_name[0])) {
            process_info pi;
            strncpy(pi.pid, ent->d_name, MAX_PID_LEN);
            char* proc_name = get_proc_name_from_pid(pi.pid);
            strncpy(pi.proc_name, proc_name, MAX_PROC_NAME_LEN);
            free(proc_name);
            get_proc_state_from_pid(pi.pid, pi.state);
            get_proc_command_from_pid(pi.pid, pi.command);
            print_process_info(&pi);
        }
    }
    closedir(dir);
}

int main() {
    print_header();
    list_processes();
    return 0;
}