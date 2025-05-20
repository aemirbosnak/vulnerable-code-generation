//FormAI DATASET v1.0 Category: System process viewer ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<dirent.h>
#include<sys/stat.h>

#define MAX_PATH 1024

typedef struct {
    char name[50];
    pid_t pid;
    char state;
} Process;

Process* get_processes(int* size);
void print_processes(Process* processes, int size);
int process_exists(Process process);

int main() {
    int size;
    Process* processes = get_processes(&size);
    print_processes(processes, size);
    free(processes);
    return 0;
}

// get list of all processes
Process* get_processes(int* size) {
    DIR* dir;
    struct dirent* ent;
    char* endptr;
    char buf[MAX_PATH];
    Process* processes = (Process*) malloc(500 * sizeof(Process));
    int index = 0;
    if((dir = opendir("/proc")) == NULL) {
        perror("Error: cannot open /proc");
        exit(EXIT_FAILURE);
    }
    while((ent = readdir(dir)) != NULL) {
        long lpid = strtol(ent->d_name, &endptr, 10);
        if(*endptr != '\0') continue;
        snprintf(buf, MAX_PATH, "/proc/%ld/stat", lpid);
        FILE* fp = fopen(buf, "r");
        if(fp) {
            Process process;
            process.pid = lpid;
            fscanf(fp, "%ld (%[^)]s %c", &lpid, process.name, &process.state);
            if(process_exists(process) == 0) {
                processes[index] = process;
                index++;
            }
            fclose(fp);
        }
    }
    closedir(dir);
    *size = index;
    return processes;
}

// print list of all processes
void print_processes(Process* processes, int size) {
    printf("PID\tSTATE\tNAME\n");
    for(int i = 0; i < size; i++) {
        printf("%d\t%c\t%s\n", processes[i].pid, processes[i].state, processes[i].name);
    }
}

// check if process already exists in array
int process_exists(Process process) {
    DIR* dir;
    struct dirent* ent;
    char* endptr;
    char buf[MAX_PATH];
    int exists = 0;
    if((dir = opendir("/proc")) == NULL) {
        perror("Error: cannot open /proc");
        exit(EXIT_FAILURE);
    }
    while((ent = readdir(dir)) != NULL) {
        long lpid = strtol(ent->d_name, &endptr, 10);
        if(*endptr != '\0') continue;
        if(lpid == process.pid) {
            exists = 1;
            break;
        }
    }
    closedir(dir);
    return exists;
}