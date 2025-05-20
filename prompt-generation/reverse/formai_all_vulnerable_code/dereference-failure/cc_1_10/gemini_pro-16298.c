//GEMINI-pro DATASET v1.0 Category: Network Packet Monitoring ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>

#define BUFSIZE 1024

// Thread arguments
typedef struct {
    int sockfd;
    struct sockaddr_in addr;
} thread_args;

// Thread function
void* thread_func(void* args) {
    thread_args* arg = (thread_args*)args;

    // Receive data from the client
    char buf[BUFSIZE];
    int recv_len;
    while ((recv_len = recv(arg->sockfd, buf, BUFSIZE, 0)) > 0) {
        // Process the received data
        printf("Received data from %s:%d: %s\n", inet_ntoa(arg->addr.sin_addr), ntohs(arg->addr.sin_port), buf);

        // Echo the data back to the client
        send(arg->sockfd, buf, recv_len, 0);
    }

    // Close the client socket
    close(arg->sockfd);

    return NULL;
}

int main() {
    // Create a server socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Bind the socket to an address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(sockfd, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        perror("bind");
        return EXIT_FAILURE;
    }

    // Listen for connections
    if (listen(sockfd, 5) == -1) {
        perror("listen");
        return EXIT_FAILURE;
    }

    // Accept connections in a loop
    while (1) {
        // Accept a connection
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int client_sockfd = accept(sockfd, (struct sockaddr*)&client_addr, &client_addr_len);
        if (client_sockfd == -1) {
            perror("accept");
            continue;
        }

        // Create a new thread to handle the connection
        pthread_t thread;
        thread_args args;
        args.sockfd = client_sockfd;
        args.addr = client_addr;
        if (pthread_create(&thread, NULL, thread_func, (void*)&args) != 0) {
            perror("pthread_create");
            close(client_sockfd);
            continue;
        }

        // Detach the thread so that it can run independently
        pthread_detach(thread);
    }

    // Close the server socket
    close(sockfd);

    return EXIT_SUCCESS;
}