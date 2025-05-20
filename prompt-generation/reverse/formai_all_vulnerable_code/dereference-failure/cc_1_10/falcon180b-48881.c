//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/wait.h>
#include <errno.h>
#include <ctype.h>

#define MAX_LINE 256

typedef struct {
    pid_t pid;
    char name[MAX_LINE];
} process_t;

void read_processes(process_t *processes, int count) {
    DIR *dir;
    struct dirent *ent;
    char path[MAX_LINE];
    int i = 0;

    snprintf(path, MAX_LINE, "/proc");
    dir = opendir(path);

    if (dir == NULL) {
        perror("opendir");
        exit(1);
    }

    while ((ent = readdir(dir))!= NULL) {
        if (isdigit(ent->d_name[0])) {
            if (i >= count) {
                break;
            }

            snprintf(processes[i].name, MAX_LINE, "%s", ent->d_name);
            processes[i].pid = atoi(ent->d_name);
            i++;
        }
    }

    closedir(dir);
}

void print_processes(process_t *processes, int count) {
    int i;

    for (i = 0; i < count; i++) {
        printf("%-10d %-30s\n", processes[i].pid, processes[i].name);
    }
}

int main(int argc, char *argv[]) {
    int count;
    process_t processes[100];

    if (argc > 1) {
        count = atoi(argv[1]);
    } else {
        count = 10;
    }

    read_processes(processes, count);
    print_processes(processes, count);

    return 0;
}