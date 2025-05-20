//FormAI DATASET v1.0 Category: System process viewer ; Style: rigorous
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PROC 32768

typedef struct {
    int pid;
    char name[256];
    char state;
    int ppid;
} process;

process* proc_info[MAX_PROC];

int total_procs;

const char* get_proc_state_name(char state) {
    switch (state) {
        case 'R': return "Running";
        case 'S': return "Sleeping";
        case 'D': return "Disk sleep";
        case 'Z': return "Zombie";
        case 'T': return "Stopped";
        case 't': return "Tracing stop";
        case 'X': return "Dead";
        case 'x': return "Dead (child)";
        case 'K': return "Wakekill";
        case 'W': return "Waking";
        default: return "Unknown";
    }
}

void print_procs() {
    printf("%5s %15s %15s %6s\n", "PID", "COMMAND", "STATE", "PPID");
    
    for (int i = 0; i < total_procs; i++) {
        process* p = proc_info[i];
        printf("%5d %15s %15s %6d\n", p->pid, p->name, get_proc_state_name(p->state), p->ppid);
    }
}

void parse_proc_info(char* dir_name) {
    struct dirent *dir_entry;
    char proc_path[256];
    DIR *d = opendir(dir_name);
    bool is_pid = true;
    char *temp_ptr;

    if (d) {
        while ((dir_entry = readdir(d)) != NULL) {
            if (dir_entry->d_name[0] < '0' || dir_entry->d_name[0] > '9') {
                is_pid = false;
                continue;
            }

            if (is_pid) {
                process *p = (process*) malloc(sizeof(process));
                p->pid = atoi(dir_entry->d_name);
                sprintf(proc_path, "%s/%s/status", dir_name, dir_entry->d_name);
                FILE* file = fopen(proc_path, "r");

                if (file) {
                    char line[256];

                    while(fgets(line, sizeof(line) - 1, file) != NULL) {
                        if (strncmp(line, "Name:", 5) == 0) {
                            temp_ptr = strchr(line, '\t');
                            strncpy(p->name, temp_ptr + 1, sizeof(p->name) - 1);
                            p->name[strlen(p->name) - 1] = '\0'; // remove newline
                        } else if (strncmp(line, "State:", 6) == 0) {
                            temp_ptr = strchr(line, '\t');
                            p->state = *(temp_ptr + 1);
                        } else if (strncmp(line, "PPid:", 5) == 0) {
                            temp_ptr = strchr(line, '\t');
                            p->ppid = atoi(temp_ptr + 1);
                        }
                    }

                    fclose(file);

                    proc_info[total_procs] = p;
                    total_procs++;

                    if (total_procs >= MAX_PROC) break;
                }
            }
            is_pid = true;         
        }

        closedir(d);
    }
}

int main() {
    parse_proc_info("/proc");
    print_procs();
    return 0;
}