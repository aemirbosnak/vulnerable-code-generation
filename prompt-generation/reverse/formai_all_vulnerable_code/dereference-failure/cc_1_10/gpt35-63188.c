//FormAI DATASET v1.0 Category: System process viewer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_PID_LENGTH 64
#define MAX_PROC_PATH_LENGTH 512
#define MAX_STATUS_PROP_LENGTH 128

struct Process {
    int pid;
    char name[MAX_STATUS_PROP_LENGTH];
    char state[MAX_STATUS_PROP_LENGTH];
    char user[MAX_STATUS_PROP_LENGTH];
};

int get_processes(struct Process* processes, int max_processes) {
    int i = 0;
    DIR* proc_dir = opendir("/proc");
    if (proc_dir == NULL) {
        return -1;
    }
    struct dirent* entry;
    while ((entry = readdir(proc_dir)) != NULL && i < max_processes) {
        int pid = atoi(entry->d_name);
        if (pid == 0) {
            continue;
        }
        char proc_path[MAX_PROC_PATH_LENGTH];
        snprintf(proc_path, MAX_PROC_PATH_LENGTH, "/proc/%d/status", pid);
        int fd = open(proc_path, O_RDONLY);
        if (fd == -1) {
            continue;
        }
        char buf[MAX_STATUS_PROP_LENGTH];
        int j = 0;
        while (read(fd, buf+j, 1) == 1) {
            if (buf[j] == '\n' && j > 0) {
                buf[j] = '\0';
                if (strncmp(buf, "Name:", 5) == 0) {
                    strcpy(processes[i].name, buf+6);
                } else if (strncmp(buf, "State:", 6) == 0) {
                    strcpy(processes[i].state, buf+7);
                } else if (strncmp(buf, "Uid:", 4) == 0) {
                    char* p = strchr(buf, '\t');
                    if (p != NULL) {
                        strcpy(processes[i].user, p+1);
                    }
                }
                j = 0;
            } else {
                ++j;
            }
        }
        close(fd);
        processes[i].pid = pid;
        ++i;
    }
    closedir(proc_dir);
    return i;
}

void print_processes(struct Process* processes, int num_processes) {
    printf("+------+------+----------+----------------+\n");
    printf("| PID  | Name |  State   |      User      |\n");
    printf("+------+------+----------+----------------+\n");
    for (int i = 0; i < num_processes; ++i) {
        printf("|%6d|%6s|%10s|%16s|\n",
               processes[i].pid,
               processes[i].name,
               processes[i].state,
               processes[i].user);
        printf("+------+------+----------+----------------+\n");
    }
}

int main() {
    printf("Welcome to the Futuristic System Process Viewer!\n");
    printf("-----------------------------------------------\n");
    printf("Loading Processes... ");
    fflush(stdout);
    struct Process processes[1024];
    int num_processes = get_processes(processes, 1024);
    if (num_processes == -1) {
        printf("Error loading processes.\n");
        return -1;
    }
    printf("Done!\n");
    printf("Displaying %d processes.\n", num_processes);
    print_processes(processes, num_processes);
    return 0;
}