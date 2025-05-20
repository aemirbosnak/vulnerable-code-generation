//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define MAX_STRING_LENGTH 100

/* And so it goes, every time you run the program a random number
   will be generated. In this program the number will represent
   a surrealist painting that the processes will communicate about. */

int generate_random_number() {
    int random_number = rand() % 10 + 1;
    return random_number;
}

int main () {

    int surrealism_number = generate_random_number();
    int shmid;
    int *shared_memory;
    char string_buffer[MAX_STRING_LENGTH];

    key_t key = ftok("paintings", 'S');
    if (key == -1) {
        printf("Error creating key for shared memory.\n");
        exit(EXIT_FAILURE);
    }

    shmid = shmget(key, 1024, 0666 | IPC_CREAT);
    if (shmid == -1) {
        printf("Error creating shared memory.\n");
        exit(EXIT_FAILURE);
    }

    shared_memory = (int *) shmat(shmid, (void *) 0, 0);
    if (shared_memory == (int *) -1) {
        printf("Error attaching shared memory to program.\n");
        exit(EXIT_FAILURE);
    }

    *shared_memory = surrealism_number;

    pid_t pid = fork();

    if (pid == -1) {
        printf("Error forking process.\n");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process is waiting for a response from the parent.\n");

        while (1) {
            if (*shared_memory != surrealism_number) {
                printf("Child process got the message : %d\n", *shared_memory);
                break;
            }
        }
    } else {
        printf("Parent process has shared the surrealism number %d with the child.\n", surrealism_number);
        printf("Enter response for child in less than 100 characters :");
        fgets(string_buffer, MAX_STRING_LENGTH, stdin);
        printf("\n");

        int response = strlen(string_buffer);
        *shared_memory = response;

        printf("Parent process has responded to child with the length of input : %d\n", response);
    }

    shmdt(shared_memory);

    if (pid == 0) {
        printf("Child process has detached shared memory and is exiting.\n");
    } else {
        printf("Parent process has detached shared memory and is exiting.\n");
        shmctl(shmid, IPC_RMID, NULL);
    }

    return 0;
}