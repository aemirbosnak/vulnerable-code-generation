//FormAI DATASET v1.0 Category: System process viewer ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>

#define MAX_PID_LENGTH 6
#define MAX_PID_COUNT 1000

typedef struct {
    char pid[MAX_PID_LENGTH];
    char name[255];
    char status;
} process_t;

int is_number(const char *s) {
    while(*s) {
        if(!isdigit(*s)) {
            return 0;
        }
        s++;
    }
    return 1;
}

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tName\tState\n");
    for(int i = 0; i < num_processes; i++) {
        printf("%s\t%s\t%c\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    DIR *proc_dir;
    struct dirent *entry;
    char proc_path[255], status_path[255], line[255];
    int num_processes = 0;
    process_t processes[MAX_PID_COUNT];

    proc_dir = opendir("/proc");
    if(proc_dir == NULL) {
        fprintf(stderr, "Error opening /proc\n");
        exit(1);
    }

    while((entry = readdir(proc_dir)) != NULL) {
        if(is_number(entry->d_name)) {
            snprintf(proc_path, sizeof(proc_path), "/proc/%s", entry->d_name);
            snprintf(status_path, sizeof(status_path), "%s/status", proc_path);
            FILE *status_file = fopen(status_path, "r");
            if(status_file == NULL) {
                continue;
            }

            process_t process;
            strcpy(process.pid, entry->d_name);

            while(fgets(line, sizeof(line), status_file) != NULL) {
                if(strncmp(line, "Name:", 5) == 0) {
                    char *name = strchr(line, '\t') + 1;
                    name[strlen(name) - 1] = '\0';
                    strcpy(process.name, name);
                }
                else if(strncmp(line, "State:", 6) == 0) {
                    process.status = line[7];
                }

                if(process.name[0] != '\0' && process.status != '\0') {
                    break;
                }
            }

            fclose(status_file);

            if(process.name[0] != '\0' && process.status != '\0') {
                processes[num_processes++] = process;
            }
        }
    }

    closedir(proc_dir);

    print_processes(processes, num_processes);

    return 0;
}