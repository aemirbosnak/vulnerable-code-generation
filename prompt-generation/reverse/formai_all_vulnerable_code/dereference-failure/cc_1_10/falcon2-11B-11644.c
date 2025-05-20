//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <netinet/tcp.h>

#define SERVER_ADDR "localhost"
#define SERVER_PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct hostent *server;
    struct sockaddr_in client_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(SERVER_ADDR);

    if (server == NULL) {
        fprintf(stderr, "ERROR: Unable to resolve server address\n");
        exit(1);
    }

    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "ERROR: Unable to connect to server\n");
        exit(1);
    }

    while (1) {
        n = read(sockfd, &client_addr, sizeof(client_addr));
        if (n < 0) {
            fprintf(stderr, "ERROR: Unable to read from socket\n");
            exit(1);
        }

        printf("Client address: %s\n", inet_ntoa(client_addr.sin_addr));

        if (n == 0) {
            printf("Client disconnected\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}