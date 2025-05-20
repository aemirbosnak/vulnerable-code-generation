//MISTRAL-7B DATASET v1.0 Category: System process viewer ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>

#define SHM_SIZE 1024

void print_process_info(int pid) {
    FILE *fp;
    char cmd[128];
    char buffer[128];

    sprintf(cmd, "/usr/bin/ps -p %d -o comm,ppid,pgid,sid,state,%c %d 2>&1", pid, 0, pid);
    fp = popen(cmd, "r");

    if (fp != NULL) {
        if (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("Process Info:\n");
            printf("Name: %s", strtok(buffer, ":") + 8);
            printf("PID: %d\n", pid);
            printf("PPID: %s\n", strtok(buffer, ":") + 4);
            printf("PGID: %s\n", strtok(buffer, ":") + 10);
            printf("SID: %s\n", strtok(buffer, ":") + 15);
            printf("State: %s\n", strtok(buffer, ":") + 19);
            pclose(fp);
        }
    }
}

int main(int argc, char *argv[]) {
    int shmid, pid, i;
    char *shm;

    shmid = shmget(IPC_PRIVATE, SHM_SIZE, 0666 | IPC_CREAT);
    shm = shmat(shmid, NULL, 0);

    if (shm == (void *)-1) {
        perror("Error attaching shared memory");
        exit(EXIT_FAILURE);
    }

    strcpy(shm, "Shape-shifting Process Viewer v1.0\n");

    printf("Shape-shifting Process Viewer v1.0\n");

    while (1) {
        printf("Enter a PID to view its process info (or type 'exit' to quit): ");
        scanf("%d", &pid);

        if (strcmp(shm, "exit") == 0) {
            break;
        }

        print_process_info(pid);
        sleep(1);

        for (i = 0; i < strlen(shm); i++) {
            shm[i] ^= 0x1;
        }
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}