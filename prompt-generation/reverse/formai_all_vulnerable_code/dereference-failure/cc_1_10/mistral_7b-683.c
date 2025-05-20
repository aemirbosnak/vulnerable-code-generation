//MISTRAL-7B DATASET v1.0 Category: Automated Fortune Teller ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>
#include <fcntl.h>
#include <sys/types.h>

#define SHM_KEY 1234
#define MSG_KEY 5678
#define SHM_SIZE 1024
#define QUEUE_SIZE 10

struct message_buffer {
    long mtype;
    char mtext[256];
};

int main() {
    key_t shmid, msgid;
    int shmflg = 0;
    char *shm;
    struct message_buffer msg;

    if ((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    if ((shm = shmat(shmid, NULL, 0)) == NULL) {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    if ((msgid = msgget(MSG_KEY, IPC_CREAT | 0666)) < 0) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    if (fork() > 0) { // FortuneTellerServer
        strcpy(shm, "Welcome to the Fortune Teller server!");

        while (1) {
            msgrcv(msgid, &msg, QUEUE_SIZE, 1, 0);

            if (strcmp(msg.mtext, "tell_fortune") == 0) {
                int random_num = rand() % 5;
                snprintf(shm, SHM_SIZE, "Your fortune: Luck %d", random_num);
                msgsnd(msgid, &msg, strlen("Your fortune: Luck ") + random_num + 1, 0);
            }
        }
    } else { // Client
        while (1) {
            wait(NULL);

            if (strcmp(shm, "Welcome to the Fortune Teller server!") != 0) {
                strcpy(msg.mtext, "tell_fortune");
                msgsnd(msgid, &msg, strlen("tell_fortune"), 0);
                printf("%s\n", shm);
                break;
            }
        }

        msgrcv(msgid, &msg, QUEUE_SIZE, 1, 0);
        printf("%s\n", msg.mtext);
    }

    shmdt(shm);
    shmctl(shmid, IPC_RMID, NULL);
    msgctl(msgid, IPC_RMID, NULL);

    return 0;
}