//Falcon2-11B DATASET v1.0 Category: System administration ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>
#include <signal.h>

void *read_data(void *arg) {
    int child_pid = (int)arg;
    char buffer[100];
    FILE *fp;
    while (1) {
        if ((fp = fopen("/dev/null", "r")) == NULL) {
            perror("fopen");
            exit(1);
        }
        if (fread(buffer, sizeof(char), sizeof(buffer), fp)!= 0) {
            printf("Received data from child process: %s\n", buffer);
            fclose(fp);
            return NULL;
        }
        usleep(1000);
    }
}

void *write_data(void *arg) {
    int child_pid = (int)arg;
    char buffer[100];
    FILE *fp;
    while (1) {
        if ((fp = fopen("/dev/null", "w")) == NULL) {
            perror("fopen");
            exit(1);
        }
        fwrite(buffer, sizeof(char), sizeof(buffer), fp);
        fclose(fp);
        usleep(1000);
    }
}

int main() {
    pid_t child_pid;
    int status;

    pthread_t read_thread;
    pthread_t write_thread;

    int i = 0;
    while (1) {
        child_pid = fork();
        if (child_pid == 0) {
            sleep(2);
            printf("Parent process: I am the child process %d\n", getpid());
            return 0;
        } else if (child_pid > 0) {
            printf("Parent process: Child process %d created\n", child_pid);
        } else {
            printf("Parent process: Fork failed\n");
            exit(1);
        }

        if ((i % 2) == 0) {
            pthread_create(&read_thread, NULL, read_data, (void *)child_pid);
        } else {
            pthread_create(&write_thread, NULL, write_data, (void *)child_pid);
        }

        pthread_join(read_thread, NULL);
        pthread_join(write_thread, NULL);

        i++;
    }

    return 0;
}