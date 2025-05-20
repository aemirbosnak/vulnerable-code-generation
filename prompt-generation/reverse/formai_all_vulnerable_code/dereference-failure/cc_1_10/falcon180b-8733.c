//Falcon-180B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SIZE 100

typedef struct {
    int id;
    char name[20];
} person;

int main() {
    int shmid;
    key_t key;
    person *ptr;

    //create shared memory
    key = ftok(".", 'a');
    shmid = shmget(key, SIZE*sizeof(person), IPC_CREAT|0666);

    if(shmid == -1) {
        printf("Shared memory creation failed");
        exit(1);
    }

    //attach shared memory
    ptr = (person *)shmat(shmid, NULL, 0);

    if(ptr == (void*)-1) {
        printf("Shared memory attachment failed");
        exit(1);
    }

    //initialize shared memory
    memset(ptr, 0, SIZE*sizeof(person));

    //create child process
    pid_t pid = fork();

    if(pid < 0) {
        printf("Fork failed");
        exit(1);
    } else if(pid == 0) {
        //child process
        sleep(2);
        for(int i=0; i<SIZE; i++) {
            sprintf(ptr[i].name, "Person %d", i+1);
        }
    } else {
        //parent process
        sleep(1);
        for(int i=0; i<SIZE; i++) {
            printf("Name: %s\nID: %d\n", ptr[i].name, ptr[i].id);
        }
    }

    return 0;
}