//Falcon2-11B DATASET v1.0 Category: System boot optimizer ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_PROCESSES 10

struct Process {
    char* name;
    int priority;
    int num_threads;
};

struct Process* read_processes(const char* filename) {
    struct stat sb;
    if (stat(filename, &sb) < 0) {
        perror("stat");
        exit(1);
    }

    if (sb.st_size < sizeof(struct Process)) {
        fprintf(stderr, "Error: file size too small\n");
        exit(1);
    }

    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    struct Process* processes = malloc(sizeof(struct Process) * MAX_PROCESSES);
    int i = 0;
    while (read(fd, &processes[i++], sizeof(struct Process)) > 0) {
    }

    close(fd);
    return processes;
}

void optimize_process(struct Process* process) {
    char command[1024];
    sprintf(command, "nice -n %d %s %d", process->priority, process->name, process->num_threads);
    int status;
    if (system(command) == -1) {
        perror("system");
        exit(1);
    }
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    struct Process* processes = read_processes(argv[1]);
    for (int i = 0; i < MAX_PROCESSES; i++) {
        optimize_process(&processes[i]);
    }

    free(processes);
    return 0;
}