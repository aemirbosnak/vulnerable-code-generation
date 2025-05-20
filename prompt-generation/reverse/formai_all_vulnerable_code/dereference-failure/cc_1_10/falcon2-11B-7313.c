//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

// Function to scan a given port
void scanPort(int port) {
    int sockfd, valread;
    struct sockaddr_in server_address;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket failed");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("connect failed");
        exit(1);
    }

    if (send(sockfd, "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n", 42, 0) < 0) {
        perror("send failed");
        exit(1);
    }

    if ((valread = recv(sockfd, NULL, 0, 0)) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Port %d is %s\n", port, valread > 0? "open" : "closed");

    close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    scanPort(atoi(argv[1]));

    return 0;
}