//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: beginner-friendly
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
#include <signal.h>

#define MAX_PROCESSES 100
#define MAX_COMMAND_LENGTH 1024

typedef struct {
    int pid;
    char command[MAX_COMMAND_LENGTH];
} process_t;

void print_processes(process_t *processes, int count) {
    printf("PID\tCommand\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].command);
    }
}

int find_process(process_t *processes, int count, int pid) {
    for (int i = 0; i < count; i++) {
        if (processes[i].pid == pid) {
            return i;
        }
    }
    return -1;
}

int main() {
    process_t processes[MAX_PROCESSES];
    int count = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (isdigit(ent->d_name[0])) {
                char path[20];
                sprintf(path, "/proc/%s/cmdline", ent->d_name);
                FILE *file = fopen(path, "r");
                if (file!= NULL) {
                    char command[MAX_COMMAND_LENGTH];
                    fgets(command, MAX_COMMAND_LENGTH, file);
                    fclose(file);

                    int pid = atoi(ent->d_name);
                    int index = find_process(processes, count, pid);

                    if (index == -1) {
                        if (count >= MAX_PROCESSES) {
                            break;
                        }
                        processes[count].pid = pid;
                        strcpy(processes[count].command, command);
                        count++;
                    } else {
                        strcpy(processes[index].command, command);
                    }
                }
            }
        }
        closedir(dir);
    }

    if (count == 0) {
        printf("No running processes.\n");
    } else {
        print_processes(processes, count);
    }

    return 0;
}