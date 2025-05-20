//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 4) {
        fprintf(stderr, "Usage: %s server_name server_port message\n", argv[0]);
        exit(1);
    }

    char *server_name = argv[1];
    char *server_port = argv[2];
    char *message = argv[3];

    // Step 1: Get server information
    struct addrinfo hints, *res, *p;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;
    int status = getaddrinfo(server_name, server_port, &hints, &res);
    if(status != 0) {
        fprintf(stderr, "Error: Could not get address information for %s\n", server_name);
        exit(1);
    }

    // Step 2: Create socket and connect to server
    int sockfd;
    for(p = res; p != NULL; p = p->ai_next) {
        sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if(sockfd == -1) {
            fprintf(stderr, "Error: Could not create socket\n");
            continue;
        }

        if(connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            fprintf(stderr, "Error: Could not connect to server\n");
            continue;
        }

        break;
    }

    if(p == NULL) {
        fprintf(stderr, "Error: Could not connect to server\n");
        exit(1);
    }

    freeaddrinfo(res);

    // Step 3: Send message to server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    int message_size = strlen(message);
    snprintf(buffer, BUFFER_SIZE, "From: client@%s\nTo: server@%s\n\n%s", server_name, server_name, message);
    int bytes_sent = send(sockfd, buffer, message_size + 25, 0);
    if(bytes_sent == -1) {
        fprintf(stderr, "Error: Could not send message to server\n");
        exit(1);
    }

    // Step 4: Receive response from server
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if(bytes_received == -1) {
        fprintf(stderr, "Error: Could not receive message from server\n");
        exit(1);
    }

    buffer[bytes_received] = '\0';
    printf("Message received from server:\n%s\n", buffer);

    // Step 5: Close connection to server
    close(sockfd);

    return 0;
}