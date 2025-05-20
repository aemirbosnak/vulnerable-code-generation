//FormAI DATASET v1.0 Category: Interprocess communication ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

// define shared memory key and size
#define SHM_KEY 1234
#define SHM_SIZE 1024

// define message sizes
#define MSG_SIZE 100
#define NUM_MESSAGES 10

// define message struct
typedef struct {
    pid_t sender;
    char content[MSG_SIZE];
} message_t;

// declare functions
void child_process(int, int);
void parent_process(int, int);

int main() {
    // declare variables
    int shm_id, pid, status;
    message_t *shm_data;
    
    // create shared memory segment
    shm_id = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666);
    if(shm_id < 0) {
        perror("Error creating shared memory segment");
        exit(1);
    }
    
    // attach shared memory segment to data pointer
    shm_data = shmat(shm_id, NULL, 0);
    if(shm_data == (void*) -1) {
        perror("Error attaching shared memory segment");
        exit(1);
    }
    
    // initialize shared memory data
    shm_data->sender = 0;
    memset(shm_data->content, 0, MSG_SIZE);
    
    // fork process
    pid = fork();
    if(pid < 0) {
        perror("Error forking process");
        exit(1);
    } else if(pid == 0) {
        // child process
        child_process(shm_id, MSG_SIZE);
    } else {
        // parent process
        parent_process(shm_id, MSG_SIZE);
    }
    
    // wait for child process to complete
    wait(&status);
    
    // detach and remove shared memory segment
    shmdt(shm_data);
    shmctl(shm_id, IPC_RMID, NULL);
    
    return 0;
}

void child_process(int shm_id, int msg_size) {
    // declare variables
    int i;
    message_t msg;
    message_t *shm_data;
    char content[MSG_SIZE];
    
    // attach shared memory segment to data pointer
    shm_data = shmat(shm_id, NULL, 0);
    if(shm_data == (void*) -1) {
        perror("Error attaching shared memory segment");
        exit(1);
    }
    
    // send messages to parent process
    for(i=0;i<NUM_MESSAGES;i++) {
        // populate message
        msg.sender = getpid();
        sprintf(content, "Message %d from child process %d", i+1, getpid());
        strncpy(msg.content, content, msg_size);
        
        // write message to shared memory
        memcpy(shm_data, &msg, sizeof(msg));
        shm_data++;
    }
    
    // detach shared memory segment
    shmdt(shm_data);
    
    exit(0);
}

void parent_process(int shm_id, int msg_size) {
    // declare variables
    int i;
    message_t msg;
    message_t *shm_data;
    
    // attach shared memory segment to data pointer
    shm_data = shmat(shm_id, NULL, 0);
    if(shm_data == (void*) -1) {
        perror("Error attaching shared memory segment");
        exit(1);
    }
    
    // read messages from child process
    for(i=0;i<NUM_MESSAGES;i++) {
        // read message from shared memory
        memcpy(&msg, shm_data, sizeof(msg));
        shm_data++;
        
        // print message
        printf("Received message:\n\tSender: %d\n\tContent: %s\n", msg.sender, msg.content);
    }
    
    // detach shared memory segment
    shmdt(shm_data);
}