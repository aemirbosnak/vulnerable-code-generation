//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Ada Lovelace
/*
 * Author: Ada Lovelace
 * Title: Interprocess Communication Example 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

#define SHM_SIZE 1024

void *write_memory(void *);
void *read_memory(void *);

pthread_mutex_t mutex;

int main()
{ 
    int shmid;
    key_t key = 5678;
    char *shm;
    pthread_t tid1, tid2;

    shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666); 
    if(shmid < 0) { 
        perror("shmget error");
        exit(1);
    } 

    shm = (char*) shmat(shmid, NULL, 0); 
    if(shm == (char*) -1) { 
        perror("shmat error");
        exit(1);
    } 

    printf("Memory attached with ID: %d\n", shmid);

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&tid1, NULL, &write_memory, shm);
    pthread_create(&tid2, NULL, &read_memory, shm);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
    
    pthread_mutex_destroy(&mutex);

    shmdt(shm);
    shmctl(shmid, IPC_RMID, 0);

    return 0;
}

void *write_memory(void *ptr)
{
    char * messages[] = { "Hello", "from", "the", "other", "side" };
    char *message;
    int i;

    message = (char *) ptr;

    for(i = 0; i < 5; i++) {
        pthread_mutex_lock(&mutex);
        sprintf(message, "%s", messages[i]);
        printf("Sent message: %s\n", message);
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}

void *read_memory(void *ptr)
{
    char * message;
    message = (char *) ptr;

    while(1) {
        pthread_mutex_lock(&mutex);
        if(*message) {
            printf("Received message: %s\n", message);
            *message = '\0';
        }
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
}