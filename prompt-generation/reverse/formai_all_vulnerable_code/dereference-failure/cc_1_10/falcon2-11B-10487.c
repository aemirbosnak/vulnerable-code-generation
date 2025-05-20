//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <target ip> <target port>\n", argv[0]);
        return 1;
    }

    char ip[INET6_ADDRSTRLEN];
    char port[INET6_ADDRSTRLEN];
    char host[INET6_ADDRSTRLEN];
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/Address not supported\n");
        return 1;
    }

    portno = atoi(argv[2]);
    if (portno < 0 || portno > 65535) {
        fprintf(stderr, "Invalid port number\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    server = gethostbyaddr((const char *)&serv_addr.sin_addr, sizeof(serv_addr.sin_addr), AF_INET);
    if (server == NULL) {
        fprintf(stderr, "Host not found\n");
        return 1;
    }

    inet_ntop(AF_INET, &(server->h_addr), host, sizeof(host));
    printf("Connected to %s:%d\n", host, ntohs(serv_addr.sin_port));

    // Read from the socket
    char buffer[1024];
    int bytes_read;

    bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received: %s\n", buffer);

    return 0;
}