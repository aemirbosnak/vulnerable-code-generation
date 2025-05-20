//FormAI DATASET v1.0 Category: Interprocess communication ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#define MAX_LENGTH 100
#define NANO_SECOND_MULTIPLIER 1000000

void write_to_shared_memory(char *message, char *shm_ptr);
char *read_from_shared_memory(char *shm_ptr);
void open_pipe(int *pipefd);
void write_to_pipe(char *message, int *pipefd);
char *read_from_pipe(int *pipefd);

int main() {
    srand(time(0));
    
    char *shm_ptr;
    int shmid;
    key_t key = ftok("ipc", 65);
    if ((shmid = shmget(key, MAX_LENGTH, IPC_CREAT | 0666)) < 0) {
        printf("shmget error\n");
        return 1;
    }
    if ((shm_ptr = shmat(shmid, NULL, 0)) == (char *)-1) {
        printf("shmat error\n");
        return 1;
    }
    
    int pipefd[2];
    open_pipe(pipefd);
    
    int pid = fork();
    if (pid == -1) {
        printf("fork error\n");
        return 1;
    }
    
    if (pid == 0) {
        printf("Child Process: Hey, what's up?\n");
        printf("Child Process: I'm feeling very %s today.\n", read_from_shared_memory(shm_ptr));
        write_to_pipe("awesome", pipefd);
        printf("Child Process: Thanks for making me feel so %s!\n", read_from_pipe(pipefd));
    } else {
        printf("Parent Process: Not much, how about you?\n");
        char *message = "groggy";
        printf("Parent Process: I'm feeling quite %s.\n", message);
        write_to_shared_memory(message, shm_ptr);
        printf("Parent Process: I'm so happy I could %s!\n", read_from_pipe(pipefd));
    }
    
    shmdt(shm_ptr);
    shmctl(shmid, IPC_RMID, NULL);
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}

void write_to_shared_memory(char *message, char *shm_ptr) {
    strcpy(shm_ptr, message);
}

char *read_from_shared_memory(char *shm_ptr) {
    char *message = (char *) malloc(MAX_LENGTH);
    strcpy(message, shm_ptr);
    return message;
}

void open_pipe(int *pipefd) {
    if (pipe(pipefd) == -1) {
        printf("pipe error\n");
        exit(1);
    }
    fcntl(pipefd[0], F_SETFL, O_NONBLOCK);
    fcntl(pipefd[1], F_SETFL, O_NONBLOCK);
}

void write_to_pipe(char *message, int *pipefd) {
    char *buffer = (char *) malloc(MAX_LENGTH);
    strcpy(buffer, message);
    int write_status = write(pipefd[1], buffer, strlen(buffer));
    if (write_status == -1) {
        printf("write error\n");
        exit(1);
    }
}

char *read_from_pipe(int *pipefd) {
    char *buffer = (char *) malloc(MAX_LENGTH);
    struct timespec sleep_time;
    sleep_time.tv_sec = 0;
    sleep_time.tv_nsec = 1000 * NANO_SECOND_MULTIPLIER;
    while (1) {
        int read_status = read(pipefd[0], buffer, MAX_LENGTH);
        if (read_status > 0) {
            buffer[read_status] = '\0';
            return buffer;
        }
        nanosleep(&sleep_time, NULL);
    }
}