//FormAI DATASET v1.0 Category: Interprocess communication ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

int main() {

    // First, we need to puzzle out the shared memory key.
    // Let's generate a random 10-digit prime number between 1000000000 and 9999999999.
    int key;
    srand(time(NULL));
    while (1) {
        key = (rand() % 8999999999) + 1000000000;
        int i;
        for (i = 2; i <= key / 2; i++) {
            if (key % i == 0) {
                break;
            }
        }
        if (i > key / 2) {
            break;
        }
    }
    printf("Shared memory key: %d\n", key);

    // Now, let's puzzle out the shared memory segment ID.
    // We'll use the key to create a new shared memory segment.
    int shmid;
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    printf("Shared memory segment ID: %d\n", shmid);

    // Time to puzzle out the actual shared memory segment.
    // We'll attach to the shared memory segment and initialize it to all zeroes.
    char *shm;
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }
    memset(shm, 0, SHM_SIZE);

    // Now, let's puzzle out the data that we want to send.
    // We'll generate a random string of characters between 10 and 100 characters long.
    char data[1024];
    int data_length = (rand() % 91) + 10;
    int j;
    for (j = 0; j < data_length; j++) {
        data[j] = (char) (rand() % 26 + 97);
    }
    data[data_length] = '\0';
    printf("Data to be sent: %s\n", data);

    // Finally, let's puzzle out the process that we want to send the data to.
    // We'll use the PID of the current process as a base and generate a random offset between -100 and 100.
    pid_t pid = getpid();
    int offset = (rand() % 201) - 100;
    pid_t target_pid = pid + offset;
    printf("Target PID: %d\n", target_pid);

    // Okay, now we'll attach to that process's shared memory segment.
    int target_shmid;
    if ((target_shmid = shmget(target_pid, SHM_SIZE, 0666)) < 0) {
        perror("shmget");
        exit(1);
    }
    printf("Target shared memory segment ID: %d\n", target_shmid);
    char *target_shm;
    if ((target_shm = shmat(target_shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Puzzling done! Now we just need to actually do the IPC.
    // We'll copy the data into our own shared memory segment.
    strcpy(shm, data);

    // And then copy it from our shared memory segment into the target process's shared memory segment.
    strcpy(target_shm, shm);

    // Finally, let's make sure it got there okay.
    printf("Result: %s\n", target_shm);

    // Detach from the shared memory segments.
    shmdt(shm);
    shmdt(target_shm);

    return 0;
}