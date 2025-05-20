//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    char hostname[1024];
    strncpy(hostname, argv[1], sizeof(hostname));

    struct addrinfo hints;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    struct addrinfo *result = NULL;
    int gai_error = getaddrinfo(hostname, NULL, &hints, &result);

    if (gai_error!= 0) {
        printf("Error resolving hostname: %s\n", gai_strerror(gai_error));
        return 1;
    }

    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        freeaddrinfo(result);
        return 1;
    }

    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Error connecting to host: %s\n", strerror(errno));
        close(sockfd);
        freeaddrinfo(result);
        return 1;
    }

    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 'A', BUFFER_SIZE);

    int bytes_sent = send(sockfd, send_buffer, BUFFER_SIZE, 0);

    if (bytes_sent == -1) {
        printf("Error sending data: %s\n", strerror(errno));
        close(sockfd);
        freeaddrinfo(result);
        return 1;
    }

    char recv_buffer[BUFFER_SIZE];
    memset(recv_buffer, 0, BUFFER_SIZE);

    int bytes_received = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);

    if (bytes_received == -1) {
        printf("Error receiving data: %s\n", strerror(errno));
        close(sockfd);
        freeaddrinfo(result);
        return 1;
    }

    printf("Sent %d bytes, received %d bytes\n", bytes_sent, bytes_received);

    close(sockfd);
    freeaddrinfo(result);

    return 0;
}