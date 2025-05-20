//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Claude Shannon
/*
 * This program demonstrates a unique Interprocess communication using
 * shared memory and a semaphore in C language.
 * 
 * First, the program creates a shared memory segment that can 
 * store a string of maximum 100 characters. Then, it forks a child process, 
 * in which it opens the shared memory segment and waits for a semaphore signal 
 * from the parent process. 
 *
 * When the parent process receives an input string from the user, it copies
 * the string into the shared memory segment. It then signals the 
 * semaphore to wake up the child process, which reads the string from the
 * shared memory segment and displays it.
 * 
 * Written by: [Your Name]
 * Created on: [Date]
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MAX_CHARS 100 // maximum characters in the shared memory

/* struct sembuf contains semaphore properties */
struct sembuf sop_lock = { 0, -1, SEM_UNDO };  // Acquire the semaphore with blocking
struct sembuf sop_unlock = { 0, 1, SEM_UNDO }; // Release the semaphore

/* function to print error message and exit */
void error_exit(const char *msg)
{
    perror(msg);
    exit(EXIT_FAILURE);
}

/* main function */
int main()
{
    key_t shm_key, sem_key; // keys for shared memory and semaphore
    int shm_id, sem_id; // IDs of shared memory and semaphore
    char *shm_ptr; // pointer to shared memory
    int pid; // process ID of child process

    /* create shared memory and semaphore keys */
    if ((shm_key = ftok(".", 'A')) == -1) {
        error_exit("Failed to generate shared memory key");
    }
    if ((sem_key = ftok(".", 'B')) == -1) {
        error_exit("Failed to generate semaphore key");
    }

    /* create shared memory segment */
    if ((shm_id = shmget(shm_key, MAX_CHARS, IPC_CREAT | 0666)) == -1) {
        error_exit("Failed to create shared memory segment");
    }

    /* attach the shared memory segment to the process's address space */
    if ((shm_ptr = shmat(shm_id, NULL, 0)) == (void *) -1) {
        error_exit("Failed to attach shared memory segment");
    }

    /* create semaphore */
    if ((sem_id = semget(sem_key, 1, IPC_CREAT | 0666)) == -1) {
        error_exit("Failed to create semaphore");
    }

    /* initialize semaphore value */
    if (semctl(sem_id, 0, SETVAL, 0) == -1) {
        error_exit("Failed to initialize semaphore value");
    }

    /* fork child process */
    pid = fork();

    /* child process */
    if (pid == 0) {
        printf("Child process: semaphore waiting...\n");
        sleep(1);
        semop(sem_id, &sop_lock, 1); // acquire semaphore

        printf("Child process: message received: %s\n", shm_ptr);

        semop(sem_id, &sop_unlock, 1); // release semaphore
        exit(EXIT_SUCCESS);
    }
    /* parent process */
    else if (pid > 0) {
        char input[MAX_CHARS]; // buffer for input string

        printf("Parent process: enter a message: ");
        fgets(input, MAX_CHARS, stdin);
        input[strlen(input)-1] = '\0'; // remove newline character

        /* copy input string into the shared memory segment */
        strncpy(shm_ptr, input, MAX_CHARS);

        /* signal the semaphore to release the child process */
        semop(sem_id, &sop_unlock, 1); 

        exit(EXIT_SUCCESS);
    }
    /* error */
    else {
        error_exit("Failed to fork child process");
    }

    /* detach and remove shared memory segment */
    if (shmdt(shm_ptr) == -1) {
        error_exit("Failed to detach shared memory segment");
    }
    if (shmctl(shm_id, IPC_RMID, NULL) == -1) {
        error_exit("Failed to remove shared memory segment");
    }

    /* remove semaphore */
    if (semctl(sem_id, 0, IPC_RMID, 0) == -1) {
        error_exit("Failed to remove semaphore");
    }

    return 0;
}