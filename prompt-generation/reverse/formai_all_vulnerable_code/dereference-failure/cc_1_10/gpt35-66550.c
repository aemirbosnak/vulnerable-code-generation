//FormAI DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define SHM_KEY 123456

typedef struct {
    int num_clients;
    bool is_server_waiting;
} SharedData;

SharedData *shared_data;

void server() {
    printf("Server started.\n");

    int shmid = shmget(SHM_KEY, sizeof(SharedData), 0666 | IPC_CREAT);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    shared_data = (SharedData*) shmat(shmid, NULL, 0);
    if (shared_data == (void*)-1) {
        perror("shmat failed");
        exit(1);
    }

    shared_data->num_clients = 0;
    shared_data->is_server_waiting = false;

    while (true) {
        printf("Waiting for client...\n");
        while (shared_data->num_clients == 0) { // wait until there is a client
            sleep(1);
        }

        printf("Received message from client.\n");

        shared_data->is_server_waiting = true;

        char message[80];
        strcpy(message, "Server received your message.");

        while (shared_data->is_server_waiting) { // wait until client is done
            sleep(1);
        }

        printf("Client has acknowledged.\n");
    }

    shmdt(shared_data);
    shmctl(shmid, IPC_RMID, NULL);
}

void client() {
    printf("Client started.\n");

    int shmid = shmget(SHM_KEY, sizeof(SharedData), 0666);
    if (shmid == -1) {
        perror("shmget failed");
        exit(1);
    }

    shared_data = (SharedData*) shmat(shmid, NULL, 0);
    if (shared_data == (void*)-1) {
        perror("shmat failed");
        exit(1);
    }

    shared_data->num_clients++;

    char message[80];
    printf("Enter message to send to server: ");
    fgets(message, 80, stdin);

    while (shared_data->is_server_waiting) { // wait until server is ready
        sleep(1);
    }

    printf("Sending message to server.\n");

    shared_data->is_server_waiting = true;

    while (shared_data->is_server_waiting) { // wait until server acknowledges
        sleep(1);
    }

    printf("Server acknowledged.\n");

    shmdt(shared_data);
}

int main() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork failed");
        exit(1);
    }

    if (pid > 0) { // parent process is server
        server();
    } else { // child process is client
        client();
    }

    return 0;
}