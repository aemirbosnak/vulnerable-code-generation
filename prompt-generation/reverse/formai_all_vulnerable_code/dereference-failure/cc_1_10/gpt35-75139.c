//FormAI DATASET v1.0 Category: Interprocess communication ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main(void)
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    printf("Welcome to the IPC chat room!\n");
    printf("Press 'q' to exit the chat room.\n\n");

    // Generate unique key for shmget
    key = 5678;

    // Allocate shared memory segment using the key 
    if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach segment to data space
    if ((shm = shmat(shmid, NULL, 0)) == (char *) -1) {
        perror("shmat");
        exit(1);
    }

    // Start chat loop  
    while(1) {
        // Wait for user input
        printf("You: ");
        scanf("%c", &c);
        getchar(); // consume newline character

        // Exit chat room if user inputs 'q'
        if (c == 'q') {
            break;
        }

        // Write message in shared memory
        s = shm;
        *s = c;
        s++;

        // Print received message
        printf("IPC Buddy: ");
        for (s = shm; *s != 0; s++)
            putchar(*s);
        putchar('\n');
    }

    // Detach memory segment
    if (shmdt(shm) == -1) {
        perror("shmdt");
        exit(1);
    }

    // Remove memory segment
    if (shmctl(shmid, IPC_RMID, 0) == -1) {
        perror("shmctl");
        exit(1);
    }

    printf("Thanks for using IPC chat room. Have a nice day!\n");

    return 0;
}