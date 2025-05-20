//FormAI DATASET v1.0 Category: Interprocess communication ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024

void* readThread(void* arg);
void* writeThread(void* arg);

int shm_id;
key_t key = 1000;
char* shared_memory;

int main() {
    pthread_t rtid, wtid;
    
    // Create shared memory segment
    shm_id = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if(shm_id < 0) {
        perror("Error creating shared memory");
        exit(1);
    }
    
    // Attach shared memory segment
    shared_memory = shmat(shm_id, NULL, 0);
    if(shared_memory == (char*)-1) {
        perror("Error attaching shared memory");
        exit(1);
    }
    memset(shared_memory, 0, SHM_SIZE);
    
    // Create read and write threads
    pthread_create(&rtid, NULL, readThread, NULL);
    pthread_create(&wtid, NULL, writeThread, NULL);
    
    pthread_join(rtid, NULL);
    pthread_join(wtid, NULL);
    
    // Detach and destroy shared memory
    shmdt(shared_memory);
    shmctl(shm_id, IPC_RMID, NULL);
    
    return 0;
}

void* readThread(void* arg) {
    while(1) {
        // Lock shared memory for reading
        char* read_data = shared_memory;
        while(*read_data == '\0') {
            usleep(1000); // Wait for write thread to write data
            read_data = shared_memory;
        }
        
        // Print data read from shared memory
        printf("Read thread: %s\n", read_data);
        memset(shared_memory, 0, SHM_SIZE);
    }
}

void* writeThread(void* arg) {
    while(1) {
        // Lock shared memory for writing
        char* write_data = shared_memory;
        while(*write_data != '\0') {
            usleep(1000); // Wait for read thread to read data
            write_data = shared_memory;
        }
        
        // Prompt user to enter data
        char data[SHM_SIZE];
        printf("Enter data to write: ");
        fgets(data, sizeof(data), stdin);
        data[strlen(data)-1] = '\0';
        
        // Write data to shared memory
        strcpy(shared_memory, data);
        printf("Write thread: %s\n", data);
    }
}