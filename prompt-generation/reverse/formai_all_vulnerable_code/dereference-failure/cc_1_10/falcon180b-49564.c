//Falcon-180B DATASET v1.0 Category: System process viewer ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void print_process_info(char *name, int pid, int ppid, int state) {
    printf("Name: %s\n", name);
    printf("PID: %d\n", pid);
    printf("PPID: %d\n", ppid);
    printf("State: %d\n", state);
    printf("\n");
}

int main(int argc, char **argv) {
    if(argc!= 2) {
        printf("Usage: %s <process_id>\n", argv[0]);
        return 1;
    }

    int target_pid = atoi(argv[1]);

    char path[BUFFER_SIZE];
    snprintf(path, BUFFER_SIZE, "/proc/%d/stat", target_pid);

    int fd = open(path, O_RDONLY);
    if(fd == -1) {
        printf("Error opening file: %s\n", strerror(errno));
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = read(fd, buffer, BUFFER_SIZE);
    if(bytes_read == -1) {
        printf("Error reading file: %s\n", strerror(errno));
        close(fd);
        return 1;
    }

    char *token;
    char name[BUFFER_SIZE];
    int pid, ppid, state;

    token = strtok(buffer, " ");
    while(token!= NULL) {
        if(strcmp(token, "name:") == 0) {
            token = strtok(NULL, " ");
            strncpy(name, token, BUFFER_SIZE);
        } else if(strcmp(token, "pid:") == 0) {
            token = strtok(NULL, " ");
            pid = atoi(token);
        } else if(strcmp(token, "ppid:") == 0) {
            token = strtok(NULL, " ");
            ppid = atoi(token);
        } else if(strcmp(token, "state:") == 0) {
            token = strtok(NULL, " ");
            state = atoi(token);
        }
        token = strtok(NULL, " ");
    }

    close(fd);

    print_process_info(name, pid, ppid, state);

    return 0;
}