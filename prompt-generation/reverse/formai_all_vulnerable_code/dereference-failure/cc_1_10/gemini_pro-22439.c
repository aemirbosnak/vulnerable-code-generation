//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: unmistakable
/*
 * Multithreaded TCP Server
 *
 * This server listens for incoming TCP connections on a specified port and
 * creates a new thread for each connection to handle its communication.
 *
 * Compile: gcc -pthread -o server server.c
 * Run: ./server <port>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} client_info;

void *handle_client(void *arg) {
    client_info *client = (client_info *)arg;

    // Receive and print the message from the client
    char buffer[1024];
    int n = recv(client->sockfd, buffer, sizeof(buffer), 0);
    if (n < 0) {
        perror("recv() failed");
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }
    printf("Received from client: %s\n", buffer);

    // Send a response back to the client
    char *response = "Hello from the server!";
    n = send(client->sockfd, response, strlen(response), 0);
    if (n < 0) {
        perror("send() failed");
        close(client->sockfd);
        free(client);
        pthread_exit(NULL);
    }

    // Close the client socket and free the memory
    close(client->sockfd);
    free(client);
    pthread_exit(NULL);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int port = atoi(argv[1]);

    // Create the server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        return EXIT_FAILURE;
    }

    // Bind the server socket to the specified port and address
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind() failed");
        close(sockfd);
        return EXIT_FAILURE;
    }

    // Define the maximum number of queued connections
    listen(sockfd, 10);

    // Start the server loop
    while (1) {
        // Accept incoming connections
        client_info *client = malloc(sizeof(client_info));
        socklen_t len = sizeof(client->addr);
        client->sockfd = accept(sockfd, (struct sockaddr *)&client->addr, &len);
        if (client->sockfd < 0) {
            perror("accept() failed");
            close(sockfd);
            free(client);
            continue;
        }

        // Create a new thread to handle the client communication
        pthread_t thread;
        if (pthread_create(&thread, NULL, handle_client, client) != 0) {
            perror("pthread_create() failed");
            close(client->sockfd);
            free(client);
            continue;
        }

        // Detach the thread so it can run independently
        if (pthread_detach(thread) != 0) {
            perror("pthread_detach() failed");
            close(client->sockfd);
            free(client);
            continue;
        }
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}