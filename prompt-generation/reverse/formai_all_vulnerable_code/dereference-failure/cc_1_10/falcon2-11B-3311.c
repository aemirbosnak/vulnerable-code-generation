//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char* argv[])
{
    int sockfd, bytes_sent, bytes_recv, n;
    struct sockaddr_in server_addr;
    struct hostent* server;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy((char*)&server_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s on port %d\n", inet_ntoa(server_addr.sin_addr), PORT);

    bytes_sent = send(sockfd, "Hello, world!\n", 13, 0);
    if (bytes_sent < 0) {
        perror("send");
        exit(1);
    }

    printf("Sent %d bytes\n", bytes_sent);

    bytes_recv = recv(sockfd, NULL, 0, 0);
    if (bytes_recv < 0) {
        perror("recv");
        exit(1);
    }

    printf("Received %d bytes\n", bytes_recv);

    close(sockfd);

    return 0;
}