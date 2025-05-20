//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: decentralized
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define MAX_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, valread, n;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;
    char buffer[MAX_BUFF_SIZE];
    char *ip = "127.0.0.1";
    int port = PORT;

    if (argc > 1) {
        ip = argv[1];
    }

    if (argc > 2) {
        port = atoi(argv[2]);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        return 1;
    }

    server = gethostbyname(ip);
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        return 2;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 3;
    }

    n = recv(sockfd, buffer, MAX_BUFF_SIZE, 0);
    printf("Received message: %s\n", buffer);

    return 0;
}