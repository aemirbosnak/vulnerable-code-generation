//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 60
#define PORT 80

int main() {
    int sockfd, numbytes;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation error");
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("www.example.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        exit(EXIT_FAILURE);
    }

    char packet[MAX_PACKET_SIZE];
    bzero(packet, MAX_PACKET_SIZE);
    sprintf(packet, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");

    numbytes = send(sockfd, packet, strlen(packet), 0);

    if (numbytes < 0) {
        perror("send error");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_PACKET_SIZE];
    bzero(buffer, MAX_PACKET_SIZE);

    numbytes = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);

    if (numbytes < 0) {
        perror("recv error");
        exit(EXIT_FAILURE);
    }

    printf("Received %s\n", buffer);

    close(sockfd);
    return 0;
}