//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_PROCESSES 1024
#define MAX_LINE_SIZE 1024

typedef struct {
    int pid;
    char name[MAX_LINE_SIZE];
} process_t;

int main(int argc, char *argv[]) {
    int i, fd, count;
    char path[MAX_LINE_SIZE];
    process_t *processes;

    if (argc!= 2) {
        printf("Usage: %s <procfs_path>\n", argv[0]);
        exit(1);
    }

    strcpy(path, argv[1]);
    strcat(path, "/task");

    fd = open(path, O_RDONLY);
    if (fd == -1) {
        printf("Error opening %s\n", path);
        exit(1);
    }

    processes = malloc(MAX_PROCESSES * sizeof(process_t));
    if (processes == NULL) {
        printf("Error allocating memory\n");
        close(fd);
        exit(1);
    }

    count = 0;
    while (count < MAX_PROCESSES) {
        if (read(fd, &processes[count], sizeof(process_t)) == 0) {
            break;
        }
        count++;
    }

    close(fd);

    printf("PID\tName\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%s\n", processes[i].pid, processes[i].name);
    }

    free(processes);
    return 0;
}