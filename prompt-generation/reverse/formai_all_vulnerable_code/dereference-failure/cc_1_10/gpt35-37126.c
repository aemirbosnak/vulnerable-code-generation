//FormAI DATASET v1.0 Category: Interprocess communication ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <time.h>

#define MSG_SIZE 1024

typedef struct {
    long mtype;             // message type
    char mtext[MSG_SIZE];   // message text
} message_t;

// Function to generate a random integer between min and max (inclusive)
int rand_int(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Generate a random seed
    srand(time(NULL));
    
    // Create a message queue
    key_t key = ftok(".", 'c');
    int msg_id = msgget(key, IPC_CREAT | 0666);
    if (msg_id == -1) {
        perror("msgget");
        exit(1);
    }
    
    // Fork a child process
    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        exit(1);
    }
    
    if (child_pid == 0) {   // Child process
        // Send a message to the parent process
        message_t msg;
        msg.mtype = 1;
        strcpy(msg.mtext, "Hello, parent!");
        if (msgsnd(msg_id, &msg, strlen(msg.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
        
        // Wait for a reply from the parent process
        if (msgrcv(msg_id, &msg, MSG_SIZE, 2, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        
        printf("Child process received a message from the parent: %s\n", msg.mtext);
        
    } else {   // Parent process
        // Wait for a message from the child process
        message_t msg;
        if (msgrcv(msg_id, &msg, MSG_SIZE, 1, 0) == -1) {
            perror("msgrcv");
            exit(1);
        }
        
        printf("Parent process received a message from the child: %s\n", msg.mtext);
        
        // Reply to the child process with a random integer
        int rand_num = rand_int(1, 100);
        char rand_str[10];
        sprintf(rand_str, "%d", rand_num);
        msg.mtype = 2;
        strcpy(msg.mtext, rand_str);
        if (msgsnd(msg_id, &msg, strlen(msg.mtext)+1, 0) == -1) {
            perror("msgsnd");
            exit(1);
        }
    }
    
    // Destroy the message queue
    if (msgctl(msg_id, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(1);
    }
    
    return 0;
}