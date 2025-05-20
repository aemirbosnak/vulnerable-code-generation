//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

typedef struct {
    char message[SIZE];
    int read_count;
    int write_count;
} shared_data;

int main(int argc, char *argv[]) {
    int shmid;
    key_t key;
    shared_data *shared_memory;

    if (argc < 2) {
        printf("Usage: %s [romeo/juliet]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "romeo") == 0) {
        key = 1234;
        shmid = shmget(key, sizeof(shared_data), 0666);
        shared_memory = (shared_data *) shmat(shmid, NULL, 0);
        strcpy(shared_memory->message, "Wherefore art thou, Juliet?");
        shared_memory->read_count = 0;
        shared_memory->write_count = 1;
    } else if (strcmp(argv[1], "juliet") == 0) {
        key = 1234;
        shmid = shmget(key, sizeof(shared_data), 0666);
        shared_memory = (shared_data *) shmat(shmid, NULL, 0);
        while (shared_memory->write_count!= 0) {
            usleep(100000);
        }
        printf("Romeo, Romeo! Wherefore art thou Romeo?\n");
        strcpy(shared_memory->message, "Deny thy father and refuse thy name;\nOr, if thou wilt not, be but sworn my love,\nAnd I'll no longer be a Capulet.\n");
        shared_memory->read_count = 1;
        shared_memory->write_count = 0;
    } else {
        printf("Invalid argument.\n");
        exit(1);
    }

    return 0;
}