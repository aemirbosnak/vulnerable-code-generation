//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// Define key for shared memory
#define SHM_KEY 1234

// Define maximum buffer size for messages
#define BUFFER_SIZE 256

// Define delay time for dialogue
#define DELAY_TIME 1000000

pthread_mutex_t mutex;

// Function for Romeo's thread
void *romeo(void *args)
{
    char message[BUFFER_SIZE];
    int *shared_memory = (int *)args;

    // Romeo sends the first message
    printf("Romeo: Oh Juliet, how sweet thou art!\n");
    strcpy(message, "Oh Juliet, how sweet thou art!");

    // Enter critical section
    pthread_mutex_lock(&mutex);

    // Write message to shared memory
    printf("Romeo: Writing message to shared memory\n");
    strcpy((char *)shared_memory, message);

    //Exit critical section
    pthread_mutex_unlock(&mutex);

    // Wait for Juliet's response
    while(1)
    {
        usleep(DELAY_TIME);

        //Enter critical section
        pthread_mutex_lock(&mutex);

        // Check if Juliet has written a message
        if(strcmp((char *)shared_memory, "empty") != 0)
        {
            // Copy Juliet's message to local variable
            strcpy(message, (char *)shared_memory);

            // Reset shared memory to "empty"
            strcpy((char *)shared_memory, "empty");

            // Print Juliet's message
            printf("Romeo: Juliet says: %s\n", message);

            //If the message contains the word "goodbye", end the conversation
            if(strstr(message, "goodbye") != NULL)
            {
                printf("Romeo: Farewell, my love!\n");
                break;
            }
        }

        // Exit critical section
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

// Function for Juliet's thread
void *juliet(void *args)
{
    char message[BUFFER_SIZE];
    int *shared_memory = (int *)args;

    // Wait for Romeo's message
    while(1)
    {
        usleep(DELAY_TIME);

        //Enter critical section
        pthread_mutex_lock(&mutex);

        // Check if Romeo has written a message
        if(strcmp((char *)shared_memory, "empty") != 0)
        {
            // Copy Romeo's message to local variable
            strcpy(message, (char *)shared_memory);

            // Reset shared memory to "empty"
            strcpy((char *)shared_memory, "empty");

            // Print Romeo's message
            printf("Juliet: Romeo says: %s\n", message);

            //If the message contains the word "goodbye", end the conversation
            if(strstr(message, "goodbye") != NULL)
            {
                printf("Juliet: Farewell, my love!\n");
                break;
            }

            //Compose a response to Romeo's message
            printf("Juliet: Ye speaketh true, my love!\n");
            strcpy(message, "Ye speaketh true, my love!");

            // Write response to shared memory
            printf("Juliet: Writing message to shared memory\n");
            strcpy((char *)shared_memory, message);
        }

        // Exit critical section
        pthread_mutex_unlock(&mutex);
    }

    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    // Initialize shared memory
    int shared_memory_id = shmget(SHM_KEY, BUFFER_SIZE, IPC_CREAT | 0666);
    int *shared_memory = (int *)shmat(shared_memory_id, NULL, 0);

    // Set shared memory to "empty"
    strcpy((char *)shared_memory, "empty");

    // Initialize mutex
    pthread_mutex_init(&mutex, NULL);

    // Create threads for Romeo and Juliet
    pthread_t romeo_thread, juliet_thread;
    pthread_create(&romeo_thread, NULL, romeo, (void *)shared_memory);
    pthread_create(&juliet_thread, NULL, juliet, (void *)shared_memory);

    // Wait for threads to finish
    pthread_join(romeo_thread, NULL);
    pthread_join(juliet_thread, NULL);

    // Clean up mutex and shared memory
    pthread_mutex_destroy(&mutex);
    shmdt(shared_memory);
    shmctl(shared_memory_id, IPC_RMID, NULL);

    return 0;
}