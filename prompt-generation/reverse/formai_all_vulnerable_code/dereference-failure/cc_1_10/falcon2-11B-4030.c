//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to send a message to the server
void send_message(int sockfd, char* message) {
    int sent = 0;
    while (sent < strlen(message)) {
        sent += send(sockfd, message + sent, strlen(message) - sent, 0);
    }
}

// Function to receive a message from the server
void receive_message(int sockfd, char* message) {
    int recv_size = sizeof(message);
    while (recv_size > 0) {
        recv_size = recv(sockfd, message, recv_size, 0);
        if (recv_size == 0) {
            break;
        }
        message += recv_size;
    }
}

// Function to create a socket and connect to the server
int create_and_connect(int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    return sockfd;
}

// Function to run the client program
int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    int sockfd = create_and_connect(port);

    char message[MAX_SIZE];
    while (1) {
        printf("Enter a message to send: ");
        fgets(message, MAX_SIZE, stdin);
        message[strcspn(message, "\n")] = '\0'; // Remove the newline character

        send_message(sockfd, message);

        receive_message(sockfd, message);

        printf("Received: %s\n", message);
    }

    return 0;
}