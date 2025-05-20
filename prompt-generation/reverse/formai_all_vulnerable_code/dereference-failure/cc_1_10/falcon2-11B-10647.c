//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <signal.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <pthread.h>

#define BUF_SIZE 1024
#define PORT 50007

int sockfd, portno, chatroom, max_clients;
struct sockaddr_in serv_addr, cli_addr;
char buf[BUF_SIZE], clt_buf[BUF_SIZE];
pthread_t thread_id;

void *client_thread(void *arg) {
    while (1) {
        char *buf;
        int bytes;

        if (read(sockfd, buf, BUF_SIZE) < 0) {
            printf("Error reading from client\n");
            break;
        }

        // Process the message here
        printf("Received message: %s\n", buf);

        write(sockfd, "ACK\n", 4);
        close(sockfd);
    }
}

int main() {
    int listenfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    // Create the socket
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Configure the socket
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(listenfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error on binding");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    listen(listenfd, 5);
    printf("Server listening on port %d\n", PORT);

    // Accept a connection
    while (1) {
        clilen = sizeof(cli_addr);
        newsockfd = accept(listenfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0) {
            perror("Error on accept");
            exit(EXIT_FAILURE);
        }

        printf("Connected to %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

        // Start a new thread for the client
        pthread_create(&thread_id, NULL, client_thread, (void *) newsockfd);
    }

    return 0;
}