//LLAMA2-13B DATASET v1.0 Category: Ebook reader ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define MAX_CLIENTS 10

struct client {
    int sock;
    char *name;
    char *email;
    char *message;
};

int main(int argc, char *argv[]) {
    // Create a shared memory segment for client data
    key_t key = IPC_PRIVATE;
    int shmid = shmget(key, sizeof(struct client) * MAX_CLIENTS, IPC_CREAT | 0644);
    if (shmid < 0) {
        perror("shmget");
        exit(1);
    }

    // Create a socket for listening for client connections
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the listen address and backlog
    struct sockaddr_in listen_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = INADDR_ANY
    };
    if (bind(sock, (struct sockaddr *)&listen_addr, sizeof(listen_addr)) < 0) {
        perror("bind");
        exit(1);
    }
    if (listen(sock, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(1);
    }

    // Loop indefinitely, accepting and serving clients
    while (1) {
        // Accept a new client connection
        struct sockaddr_in client_addr;
        socklen_t client_len = sizeof(client_addr);
        int client_sock = accept(sock, (struct sockaddr *)&client_addr, &client_len);
        if (client_sock < 0) {
            perror("accept");
            exit(1);
        }

        // Create a new client struct and store it in shared memory
        struct client *client = (struct client *)shmat(shmid, NULL, 0);
        if (!client) {
            perror("shmat");
            exit(1);
        }
        client->sock = client_sock;
        client->name = malloc(100);
        client->email = malloc(100);
        client->message = malloc(100);

        // Read data from the client
        read(client_sock, client->name, 100);
        read(client_sock, client->email, 100);
        read(client_sock, client->message, 100);

        // Print the client data
        printf("Client: %s %s %s\n", client->name, client->email, client->message);

        // Send a response back to the client
        char *response = "Hello, client!";
        send(client_sock, response, strlen(response), 0);

        // Clean up and free memory
        free(client->name);
        free(client->email);
        free(client->message);
        shmctl(shmid, IPC_RMID, 0);
    }

    return 0;
}