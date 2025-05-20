//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main() {
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    // Connect to shared memory
    if ((key = ftok(".", 'R')) == -1) { 
        perror("ftok"); 
        exit(1); 
    }

    // Create shared memory segment
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) == -1) { 
        perror("shmget"); 
        exit(1); 
    }

    // Attach to shared memory segment
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) { 
        perror("shmat"); 
        exit(1); 
    }

    // Write message to shared memory
    s = shm;
    for (c = 'a'; c <= 'z'; c++) {
        *s++ = c;
    }
    *s = '\0';

    // Wait for other process to change first byte of shared memory
    while (*shm != '*') {
        sleep(1);
    }

    // Read message from shared memory and print to console
    for (s = shm + 1; *s != '\0'; s++) {
        putchar(*s);
    }
    putchar('\n');

    // Destroy shared memory segment
    if (shmctl(shmid, IPC_RMID, NULL) == -1) { 
        perror("shmctl"); 
        exit(1); 
    }

    return 0;
}