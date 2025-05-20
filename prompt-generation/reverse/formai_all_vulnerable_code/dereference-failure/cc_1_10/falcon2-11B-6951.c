//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: expert-level
#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define MAX_BUFF_SIZE 1000

int main(int argc, char *argv[]) {
    key_t key;
    int shmid;
    char *buff;
    int size;
    int i;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <message>\n", argv[0]);
        return 1;
    }

    key = ftok(argv[0], 'a');
    if (key == -1) {
        perror("ftok");
        return 1;
    }

    shmid = shmget(key, sizeof(char), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        return 1;
    }

    buff = (char*)shmat(shmid, NULL, 0);
    if (buff == (char*)-1) {
        perror("shmat");
        return 1;
    }

    size = strlen(argv[1]);
    if (size > MAX_BUFF_SIZE) {
        fprintf(stderr, "Message too long (%d bytes). Maximum allowed is %d bytes.\n", size, MAX_BUFF_SIZE);
        return 1;
    }

    memcpy(buff, argv[1], size);
    buff[size] = '\0';

    printf("Child process received message: %s\n", buff);

    shmdt(buff);
    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}