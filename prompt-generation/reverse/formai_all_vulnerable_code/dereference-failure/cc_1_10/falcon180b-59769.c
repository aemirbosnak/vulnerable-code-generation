//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>

#define MAX_PROCESSES 50

typedef struct {
    int pid;
    char name[20];
    char state;
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("PID\tName\tState\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%c\n", processes[i].pid, processes[i].name, processes[i].state);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;
    DIR *proc_dir;
    struct dirent *ent;

    proc_dir = opendir("/proc");

    if (proc_dir == NULL) {
        printf("Error opening /proc directory\n");
        exit(1);
    }

    while ((ent = readdir(proc_dir))!= NULL) {
        if (ent->d_type == DT_DIR) {
            char path[100];
            sprintf(path, "/proc/%s/stat", ent->d_name);

            int fd = open(path, O_RDONLY);

            if (fd == -1) {
                printf("Error opening %s\n", path);
                continue;
            }

            char buffer[100];
            int bytes_read = read(fd, buffer, sizeof(buffer));

            close(fd);

            if (bytes_read == -1) {
                printf("Error reading %s\n", path);
                continue;
            }

            process_t process;
            sscanf(buffer, "%d %s %c", &process.pid, process.name, &process.state);

            strcpy(processes[num_processes].name, process.name);
            processes[num_processes].pid = process.pid;
            processes[num_processes].state = process.state;

            num_processes++;
        }
    }

    closedir(proc_dir);

    print_processes(processes, num_processes);

    return 0;
}