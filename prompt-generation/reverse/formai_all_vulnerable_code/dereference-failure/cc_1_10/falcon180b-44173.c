//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PROCESSES 100

typedef struct {
    char name[16];
    int pid;
    int status;
} process_t;

void print_processes(process_t *processes, int num_processes) {
    printf("Process ID\tName\tStatus\n");
    for (int i = 0; i < num_processes; i++) {
        printf("%d\t%s\t%d\n", processes[i].pid, processes[i].name, processes[i].status);
    }
}

int main() {
    process_t processes[MAX_PROCESSES];
    int num_processes = 0;

    DIR *dir;
    struct dirent *ent;

    if ((dir = opendir("/proc"))!= NULL) {
        while ((ent = readdir(dir))!= NULL) {
            if (ent->d_type == DT_DIR) {
                char path[20];
                sprintf(path, "/proc/%s/stat", ent->d_name);
                FILE *file = fopen(path, "r");

                if (file!= NULL) {
                    char line[100];
                    fgets(line, sizeof(line), file);
                    fclose(file);

                    int pid = atoi(line);
                    strcpy(processes[num_processes].name, ent->d_name);
                    processes[num_processes].pid = pid;
                    processes[num_processes].status = 0;
                    num_processes++;
                }
            }
        }
        closedir(dir);
    }

    print_processes(processes, num_processes);

    return 0;
}