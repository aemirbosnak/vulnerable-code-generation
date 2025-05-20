//FormAI DATASET v1.0 Category: Interprocess communication ; Style: sophisticated
#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<errno.h>

//Key for shared memory
#define SHM_KEY 0x1234

typedef struct {
    int value;
} shared_memory;

int main() {
    shared_memory *shared_mem;
    int shm_id;
    key_t key = SHM_KEY;
    int i;

    //Creating shared memory segment
    shm_id = shmget(key, sizeof(shared_memory), IPC_CREAT | 0666);
    if(shm_id < 0) {
        printf("Shared Memory segment could not be created.\n");
        exit(1);
    }

    //Attach shared memory segment
    shared_mem = (shared_memory*)shmat(shm_id, NULL, 0);
    if(shared_mem < (shared_memory*)0) {
        printf("Error while attaching shared memory segment.\n");
        exit(1);
    }
    shared_mem->value = 0;
    pid_t process_id = fork();

    if(process_id < 0) { //Error case - fork failed
        printf("Failed to fork process.\n");
        exit(1);
    }

    if(process_id == 0) {//Child process
        for(i = 0; i < 5; i++) {
            sleep(1);
            shared_mem->value = shared_mem->value + 10;
            printf("Child process updated shared memory to %d\n", shared_mem->value);
        }
        shmdt(shared_mem); //Detaching from shared memory segment
    }

    else { //Parent process
        for(i = 0; i < 5; i++) {
            sleep(1);
            shared_mem->value = shared_mem->value + 5;
            printf("Parent process updated shared memory to %d\n", shared_mem->value);
        }
        wait(NULL);
        shmdt(shared_mem); //Detaching from shared memory segment
        shmctl(shm_id, IPC_RMID, NULL); //Deleting shared memory segment
    }
    return 0;
}