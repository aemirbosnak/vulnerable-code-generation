//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>

#define MAX_LINE_LENGTH 1024

typedef struct {
    char name[MAX_LINE_LENGTH];
    pid_t pid;
} process_t;

void read_processes(process_t *processes, int max_processes) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_LINE_LENGTH];
    int count = 0;

    dir = opendir("/proc");

    if (dir == NULL) {
        fprintf(stderr, "Error: Could not open /proc directory.\n");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (ent->d_type == DT_DIR && count < max_processes) {
            snprintf(path, MAX_LINE_LENGTH, "/proc/%s/cmdline", ent->d_name);
            FILE *file = fopen(path, "r");

            if (file!= NULL) {
                fgets(processes[count].name, MAX_LINE_LENGTH, file);
                fclose(file);

                snprintf(path, MAX_LINE_LENGTH, "/proc/%s/stat", ent->d_name);
                file = fopen(path, "r");

                if (file!= NULL) {
                    fscanf(file, "%d", &processes[count].pid);
                    fclose(file);
                    count++;
                }
            }
        }
    }

    closedir(dir);
}

void print_processes(process_t *processes, int num_processes) {
    for (int i = 0; i < num_processes; i++) {
        printf("%-30s %d\n", processes[i].name, processes[i].pid);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Error: Please provide a maximum number of processes to display.\n");
        return 1;
    }

    int max_processes = atoi(argv[1]);

    process_t processes[max_processes];

    read_processes(processes, max_processes);
    print_processes(processes, max_processes);

    return 0;
}