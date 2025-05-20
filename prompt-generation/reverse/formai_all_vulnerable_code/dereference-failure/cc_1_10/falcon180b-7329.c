//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct hostent *he;
    struct sockaddr_in server_addr;
    char *ip;
    char buffer[BUF_SIZE];
    int port;
    int opt = 1;
    int addrlen;
    char *message = "Hello, world!\n";

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    ip = argv[1];
    port = atoi(argv[2]);

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on the socket
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Get server address
    if ((he = gethostbyname(ip)) == NULL) {
        fprintf(stderr, "No such host: %s\n", ip);
        exit(EXIT_FAILURE);
    }

    // Fill in server address structure
    memcpy(&(server_addr.sin_addr), he->h_addr, he->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    send(sockfd, message, strlen(message), 0);

    // Receive message from server
    addrlen = sizeof(server_addr);
    memset(buffer, 0, BUF_SIZE);
    if ((recv(sockfd, buffer, BUF_SIZE, 0)) < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    printf("Message from server: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}