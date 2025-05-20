//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <IP_Address>\n", argv[0]);
        return 1;
    }

    char ip[INET_ADDRSTRLEN];
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Hostname not found\n");
        exit(1);
    }

    portno = ntohs(server->h_addr_list[0]);
    printf("Server address: %s\n", argv[1]);
    printf("Server port: %d\n", portno);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Connection Failed\n");
        exit(1);
    }

    printf("Connection Established\n");

    char buffer[1024];
    int bytes_received;

    bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    printf("Received data: %s\n", buffer);

    send(sockfd, "Hello, server!", strlen("Hello, server!") + 1, 0);
    printf("Sent data: Hello, server!\n");

    close(sockfd);

    return 0;
}