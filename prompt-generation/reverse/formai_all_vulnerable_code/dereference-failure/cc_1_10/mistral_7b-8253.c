//MISTRAL-7B DATASET v1.0 Category: Interprocess communication ; Style: Ken Thompson
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_KEY 1234
#define SIZE 4096

struct Data {
    int id;
    char name[32];
};

int main() {
    int pid, shmid;
    struct Data *data;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    } else if (pid > 0) {
        shmid = shmget(SHM_KEY, SIZE, IPC_CREAT | 0666);
        data = (struct Data *) shmat(shmid, NULL, 0);

        sprintf(data->name, "Parent");
        data->id = getpid();

        waitpid(pid, NULL, 0);

        printf("Parent: Child %d sent data: %s\n", pid, data->name);

        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
    } else {
        shmid = shmget(SHM_KEY, SIZE, 0);
        data = (struct Data *) shmat(shmid, NULL, 0);

        sprintf(data->name, "Child");
        data->id = getpid();

        printf("Child: Created shared memory segment at %p\n", data);
        printf("Child: Sent data to parent: %s\n", data->name);

        exit(0);
    }

    return 0;
}