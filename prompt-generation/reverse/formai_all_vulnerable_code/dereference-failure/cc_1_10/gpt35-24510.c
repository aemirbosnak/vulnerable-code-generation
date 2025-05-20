//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>

// Define a structure for shared memory
struct shared_mem {
    int number;
    char message[256];
    pthread_mutex_t mutex;
    pthread_cond_t cond;
};

void *child_process(void *arg) {
    struct shared_mem *mem = (struct shared_mem *) arg;

    // Child Process
    printf("Child process is running...\n");
    sleep(1);

    // Acquire Mutex Lock 
    pthread_mutex_lock(&mem->mutex);
    
    // Manipulate Shared Data
    printf("Child process is writing data.\n");
    mem->number = 42;
    sprintf(mem->message, "Hello from child process!");

    // Signal the Parent Process
    pthread_cond_signal(&mem->cond);

    // Release Mutex Lock
    pthread_mutex_unlock(&mem->mutex);

    return NULL;
}

int main() {
    int pid;
    struct shared_mem *mem;

    // Allocate Shared Memory 
    mem = mmap(NULL, sizeof(struct shared_mem), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    pthread_mutex_init(&mem->mutex, NULL);
    pthread_cond_init(&mem->cond, NULL);

    // Parent Process
    printf("Parent process is running...\n");

    // Fork Child Process
    pid = fork();
    if (pid == 0) {
        // Child Process
        return child_process(mem);
    }

    // Acquire Mutex Lock 
    pthread_mutex_lock(&mem->mutex);

    // Wait for child to signal 
    printf("Parent is waiting...\n");
    pthread_cond_wait(&mem->cond, &mem->mutex);

    // Display Shared Data 
    printf("Parent received: %d\n", mem->number);
    printf("Parent received: %s\n", mem->message);

    // Release Mutex Lock 
    pthread_mutex_unlock(&mem->mutex);

    // Wait for Child Process to Complete and Terminate 
    waitpid(pid, NULL, 0);

    return 0;
}