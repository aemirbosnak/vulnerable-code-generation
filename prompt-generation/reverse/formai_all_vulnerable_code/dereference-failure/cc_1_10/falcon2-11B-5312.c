//Falcon2-11B DATASET v1.0 Category: Browser Plugin ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to establish a TCP connection to a given IP address and port
int establish_connection(char* ip_address, int port) {
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in server_address;
    struct hostent* server;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    server = gethostbyname(ip_address);
    if (server == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    bytes_sent = send(sockfd, "Hello, world!\n", strlen("Hello, world!\n"), 0);
    if (bytes_sent == -1) {
        perror("send");
        close(sockfd);
        return -1;
    }

    bytes_received = recv(sockfd, "Reply from server:\n", sizeof("Reply from server:\n") - 1, 0);
    if (bytes_received == -1) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    printf("Reply from server: %s\n", "Reply from server:\n");

    close(sockfd);
    return 0;
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip_address> <port>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[2]);
    int result = establish_connection(argv[1], port);

    if (result == 0) {
        return 0;
    } else {
        fprintf(stderr, "Failed to establish connection\n");
        return 1;
    }
}