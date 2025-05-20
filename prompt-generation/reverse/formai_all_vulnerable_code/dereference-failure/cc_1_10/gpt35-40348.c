//FormAI DATASET v1.0 Category: Interprocess communication ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/msg.h>

#define MAX_SIZE 1024

int message_queue_id;
int shared_memory_id;
char* shared_memory_pointer;

struct message_buffer {
    long message_type;
    char message_text[MAX_SIZE];
};

void sigint_handler(int signum) {
    printf("\nGood night, good night! Parting is such sweet sorrow,\n"
           "That I shall say good night till it be morrow.\n");
    msgctl(message_queue_id, IPC_RMID, NULL);
    shmctl(shared_memory_id, IPC_RMID, NULL);
    exit(0);
}

void romeo() {
    printf("Romeo: O, she doth teach the torches to burn bright!\n");
    printf("Romeo: It seems she hangs upon the cheek of night\n");
    printf("       As a rich jewel in an Ethiope’s ear\n");
    printf("Romeo: Good morrow, Juliet!\n");
    
    struct message_buffer buffer;
    buffer.message_type = 1;
    sprintf(buffer.message_text, "Romeo: Go ask his name. -- If he be married.\n"
                                 "         My grave is like to be my wedding bed.\n");
    msgsnd(message_queue_id, &buffer, strlen(buffer.message_text)+1, 0);
    
    while (1) {
        sleep(1);
        if (*shared_memory_pointer) {
            printf("Romeo: By a name\n"
                   "       I know not how to tell thee who I am:\n"
                   "       My name, dear saint, is hateful to myself,\n"
                   "       Because it is an enemy to thee;\n"
                   "       Had I it written, I would tear the word.\n");
            *shared_memory_pointer = 0;
            break;
        }
    }
}

void juliet() {
    printf("Juliet: The brightness of her cheek would shame those stars\n"
           "        As daylight doth a lamp; her eyes in heaven\n"
           "        Would through the airy region stream so bright\n"
           "Juliet: Good evening, Romeo!\n");
    
    while (1) {
        struct message_buffer buffer;
        msgrcv(message_queue_id, &buffer, MAX_SIZE, 1, 0);
        printf("%s\n", buffer.message_text);
        sleep(1);
        if (strcmp(buffer.message_text, "Romeo: Go ask his name. -- If he be married.\n"
                                          "         My grave is like to be my wedding bed.\n") == 0) {
            printf("Juliet: My only love sprung from my only hate!\n"
                   "        Too early seen unknown, and known too late!\n"
                   "        Prodigious birth of love it is to me,\n"
                   "        That I must love a loathèd enemy.\n");
            
            *shared_memory_pointer = 1;
            break;
        }
    }
}

int main() {
    printf("Romeo and Juliet IPC in C.\n"
           "Press Ctrl+C to exit.\n");
  
    signal(SIGINT, sigint_handler);
  
    key_t key = ftok("./", 'R');
    if (key == -1) {
        perror("ftok error");
        exit(1);
    }
  
    message_queue_id = msgget(key, IPC_CREAT | 0666);
    if (message_queue_id == -1) {
        perror("msgget error");
        exit(1);
    }
  
    shared_memory_id = shmget(key, sizeof(int), IPC_CREAT | 0666);
    if (shared_memory_id == -1) {
        perror("shmget error");
        exit(1);
    }
  
    shared_memory_pointer = shmat(shared_memory_id, NULL, 0);
    if (shared_memory_pointer == (char*)-1) {
        perror("shmat error");
        exit(1);
    }
  
    *shared_memory_pointer = 0;
  
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork error");
        exit(1);
    } else if (pid == 0) {
        juliet();
    } else {
        romeo();
        wait(NULL);
    }
  
    return 0;
}