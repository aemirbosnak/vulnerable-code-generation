//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    struct hostent *host_entry;
    struct in_addr *ip_address;
    struct sockaddr_in sock_addr;
    struct hostent *server;
    int sockfd, portno, sent, received;
    char buffer[MAX_BUFFER_SIZE];
    int optval = 1;
    char *ip_address_str;

    ip_address_str = inet_ntoa(*(ip_address));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    bzero((char *) &sock_addr, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = htons(80);
    sock_addr.sin_addr.s_addr = inet_addr(ip_address_str);

    if (connect(sockfd, (struct sockaddr *) &sock_addr, sizeof(sock_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("ERROR setting SO_REUSEADDR option");
        exit(EXIT_FAILURE);
    }

    sent = send(sockfd, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n",
        strlen("GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n"), 0);
    if (sent < 0) {
        perror("ERROR sending data");
        exit(EXIT_FAILURE);
    }

    received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
    if (received < 0) {
        perror("ERROR receiving data");
        exit(EXIT_FAILURE);
    } else {
        printf("Received data: %s\n", buffer);
    }

    close(sockfd);

    return 0;
}