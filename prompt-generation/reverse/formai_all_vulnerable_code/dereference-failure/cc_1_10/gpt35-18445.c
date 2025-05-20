//FormAI DATASET v1.0 Category: Interprocess communication ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>
#include <string.h>

#define SHM_KEY 12345
#define MAX_LENGTH 100

volatile sig_atomic_t stop;

void handler(int sig){
    stop = 1;
}

int main(){
    int shm_id, pid, status;
    char *data;
    struct sigaction sa;
    key_t key = ftok("ipc_example.c", 'a');

    if((shm_id = shmget(key, MAX_LENGTH, IPC_CREAT | 0666)) < 0){
        perror("Error in shmget");
        exit(EXIT_FAILURE);
    }

    if((data = (char *)shmat(shm_id, NULL, 0)) == (char *)-1){
        perror("Error in shmat");
        exit(EXIT_FAILURE);
    }

    //Set up the signal handler to catch SIGINT
    memset(&sa, 0, sizeof(struct sigaction));
    sa.sa_handler = &handler;
    sigaction(SIGINT, &sa, NULL);

    pid = fork();
    if(pid < 0){
        perror("Error in fork");
        exit(EXIT_FAILURE);
    } else if(pid == 0){
        //Child process
        while(!stop){
            if(strlen(data) > 0){
                printf("Child received: %s\n", data);
                fflush(stdout);
                //Clear the buffer
                memset(data, '\0', MAX_LENGTH);
            }
            sleep(1);
        }
        printf("Child exiting\n");
        fflush(stdout);
        exit(EXIT_SUCCESS);
    } else {
        //Parent process
        printf("Enter a message to send to the child process (max %d characters):\n", MAX_LENGTH-1);
        fflush(stdout);
        while(!stop){
            fgets(data, MAX_LENGTH, stdin);
            if(strlen(data) > 0 && data[strlen(data)-1] == '\n'){
                //Replace newline character with null terminator
                data[strlen(data)-1] = '\0';
            }
            printf("Parent sent: %s\n", data);
            fflush(stdout);
        }
        printf("Parent exiting\n");
        fflush(stdout);
        kill(pid, SIGTERM);
        waitpid(pid, &status, 0);
    }

    //Detach and remove shared memory segment
    shmdt(data);
    shmctl(shm_id, IPC_RMID, NULL);

    return EXIT_SUCCESS;
}