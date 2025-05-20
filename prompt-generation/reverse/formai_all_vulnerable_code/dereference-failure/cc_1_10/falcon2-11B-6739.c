//Falcon2-11B DATASET v1.0 Category: Firewall ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    struct sockaddr_in server_addr;
    struct hostent *server;
    struct sockaddr_in client_addr;
    int sockfd, n;
    char buffer[1024];
    char *ip_address;

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <server-ip>\n", argv[0]);
        return 1;
    }

    ip_address = argv[1];

    server = gethostbyname(ip_address);
    if (server == NULL) {
        fprintf(stderr, "Error: Unable to resolve server IP address\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    memcpy((char *) &server_addr.sin_addr.s_addr, (char *) server->h_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Error connecting to server");
        return 1;
    }

    while (1) {
        n = read(sockfd, buffer, sizeof(buffer));
        if (n == -1) {
            perror("Error reading from socket");
            return 1;
        }

        if (n == 0) {
            break;
        }

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        printf("Received: %s\n", buffer);

        if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
            perror("Error sending message to server");
            return 1;
        }
    }

    close(sockfd);

    return 0;
}