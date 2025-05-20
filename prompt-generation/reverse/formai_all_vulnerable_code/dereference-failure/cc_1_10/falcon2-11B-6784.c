//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, n, len;
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        return 1;
    }

    // Resolve the server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("gethostbyname failed");
        return 1;
    }

    // Connect to the server
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(12345);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        return 1;
    }

    // Receive and print packets
    while ((n = recv(sockfd, &len, sizeof(len), 0)) > 0) {
        bzero((char *) &cli_addr, sizeof(cli_addr));
        bzero((char *) &len, sizeof(len));

        n = recv(sockfd, (char *) &len, sizeof(len), 0);
        if (n < 0) {
            perror("recv failed");
            return 1;
        }

        n = recv(sockfd, (char *) &cli_addr, sizeof(cli_addr), 0);
        if (n < 0) {
            perror("recv failed");
            return 1;
        }

        printf("Received packet from %s:%u\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
    }

    return 0;
}