//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netdb.h>

#define PORT "12345"
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    struct addrinfo hints, *res;
    int sockfd, status;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    struct timeval timeout;
    timeout.tv_sec = 5; // set timeout to 5 seconds
    timeout.tv_usec = 0;

    // set up hints
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // get address info
    if ((status = getaddrinfo("127.0.0.1", PORT, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(1);
    }

    // create socket
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // set timeout on socket
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    // connect to server
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
        perror("connect");
        exit(1);
    }

    // send message to server
    int bytes_sent;
    char *message = "Hello server!";
    bytes_sent = send(sockfd, message, strlen(message), 0);
    if (bytes_sent == -1) {
        perror("send");
        exit(1);
    }

    // receive response from server
    bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received == -1) {
        fprintf(stderr, "recv error\n");
    }
    else {
        buffer[bytes_received] = '\0';
        printf("Response from server: %s\n", buffer);
    }

    // close socket
    close(sockfd);

    // free address info
    freeaddrinfo(res);

    return 0;
}