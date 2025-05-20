//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/* Define a shared memory segment size */
#define SHM_SIZE 256 

/* Define a structure to hold the shared data */
typedef struct {
    int num;
    char data[SHM_SIZE];
} shared_data_t;

/* Create a global shared data variable */
shared_data_t *shared_data;

/* Define the thread function */
void *thread_func(void *arg) {
    char *data = (char *) arg;
    
    /* Write the data to the shared memory segment */
    sprintf(shared_data->data, "%s", data);
    
    /* Increment the num value in the shared memory */
    shared_data->num++;
}

/* Main function */
int main(int argc, char **argv) {
    int shmid;
    pthread_t tid1, tid2;
    key_t key;
    
    /* Generate a unique key for the shared memory segment */
    key = ftok("shared_data", 'R');
    
    /* Create the shared memory segment */
    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    
    /* Attach to the shared memory segment */
    shared_data = shmat(shmid, NULL, 0);
    
    /* Set the initial values in the shared memory */
    shared_data->num = 0;
    strcpy(shared_data->data, "Initial Value");
    
    /* Create the threads */
    pthread_create(&tid1, NULL, thread_func, "Hello World");
    pthread_create(&tid2, NULL, thread_func, "Goodbye World");
    
    /* Wait for the threads to finish */
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    /* Print the final values from the shared memory */
    printf("Final Num Value: %d\n", shared_data->num);
    printf("Final Data Value: %s\n", shared_data->data);
    
    /* Detach from the shared memory */
    shmdt(shared_data);
    
    /* Remove the shared memory segment */
    shmctl(shmid, IPC_RMID, NULL);
    
    return 0;
}