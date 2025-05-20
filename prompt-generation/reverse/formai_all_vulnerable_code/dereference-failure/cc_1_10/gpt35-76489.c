//FormAI DATASET v1.0 Category: Interprocess communication ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>

typedef struct {
    char message[100];
} love_letter;

/* Declare global variable */

int shmid;
love_letter *shared_letter;

int main() {
    /* Create shared memory segment */
    key_t key = ftok("love_letter.txt", 'B');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }
    shmid = shmget(key, sizeof(love_letter), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    /* Attach shared memory segment */
    shared_letter = (love_letter*) shmat(shmid, NULL, 0);
    if (shared_letter == (void*) -1) {
        perror("shmat");
        exit(1);
    }

    /* Express your love by writing a love letter using IPC */
    printf("My love,\n");
    printf("You are my everything, my sunshine on a cloudy day, my shelter in the midst of a storm.\n");
    printf("I cannot imagine a life without you, without your love, without your beautiful smile.\n");
    printf("I want you to know that I will always cherish you, love you and care for you.\n");
    printf("Please take this letter as a token of my love.\n\n");

    printf("Reflecting on how I love you, I will write only one quick line.\n");
    printf("I love you more than words can express, more than actions can show and more than you can imagine.\n\n");

    printf("With all my love,\n");
    printf("Your devoted partner\n");

    strcpy(shared_letter->message, "You have mail! Check your shared memory segment.\n");

    /* Signal the other process to check their shared memory */
    printf("Sending notification...\n");
    system("echo '\a'");
    sleep(1);

    /* Wait for the other process to signal completion */
    while (strcmp(shared_letter->message, "Love letter received!") != 0) {
        sleep(1);
    }

    /* Detach from shared memory segment */
    if (shmdt(shared_letter) == -1) {
        perror("shmdt");
        exit(1);
    }

    /* Delete shared memory segment */
    if (shmctl(shmid, IPC_RMID, NULL) == -1) {
        perror("shmctl");
        exit(1);
    }

    return 0;
}