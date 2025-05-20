//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 5000

#define MAX_PACKET_SIZE 1024

void send_data(int sockfd, const char* data, int len) {
    int sent = 0;
    while (sent < len) {
        sent += send(sockfd, data + sent, len - sent, 0);
    }
}

void* receive_data(int sockfd, char* buffer, int buffer_size) {
    int received = 0;
    while (received < buffer_size) {
        received += recv(sockfd, buffer + received, buffer_size - received, 0);
    }
    return buffer;
}

void handle_client(int sockfd) {
    char buffer[MAX_PACKET_SIZE];
    send_data(sockfd, "Welcome to the server!", 25);
    while (1) {
        char* data = receive_data(sockfd, buffer, MAX_PACKET_SIZE);
        if (data == NULL) {
            break;
        }
        printf("Received: %s\n", data);
        send_data(sockfd, "ACK!", 4);
        free(data);
    }
}

int main(int argc, char* argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent* server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]);
    server = gethostbyname(SERVER_IP);
    if (server == NULL) {
        fprintf(stderr, "Hostname could not be resolved\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    bzero((char*) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    handle_client(sockfd);

    return 0;
}