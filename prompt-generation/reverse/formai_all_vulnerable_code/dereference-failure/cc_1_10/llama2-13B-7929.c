//LLAMA2-13B DATASET v1.0 Category: Benchmarking ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define N 100
#define PORT 8080

void *sender(void *arg) {
    int sock = *((int *)arg);
    char buffer[1024];
    struct sockaddr_in server_addr;

    while (1) {
        // Generate a random number and send it to the server
        int random = rand() % N;
        snprintf(buffer, sizeof(buffer), "%d", random);
        send(sock, buffer, strlen(buffer), 0);

        // Sleep for a random amount of time to simulate network latency
        usleep(rand() % 1000000);
    }

    return NULL;
}

void *receiver(void *arg) {
    int sock = *((int *)arg);
    char buffer[1024];
    struct sockaddr_in client_addr;

    while (1) {
        // Receive a number from the client
        recv(sock, buffer, sizeof(buffer), 0);

        // Print the received number
        printf("%d\n", atoi(buffer));

        // Sleep for a random amount of time to simulate network latency
        usleep(rand() % 1000000);
    }

    return NULL;
}

int main(int argc, char **argv) {
    // Create a server socket
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set address and port number for the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    // Bind the server socket to the address and port
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Fork two processes: one to send messages and one to receive them
    pid_t sender_pid = fork();
    if (sender_pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    } else if (sender_pid == 0) {
        // Send messages in a loop
        sender(server_sock);
    } else {
        // Receive messages in a loop
        receiver(server_sock);
    }

    // Close the server socket
    close(server_sock);

    return 0;
}