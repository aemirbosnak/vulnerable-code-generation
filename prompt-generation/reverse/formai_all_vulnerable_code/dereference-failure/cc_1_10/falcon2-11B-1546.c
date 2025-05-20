//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_PACKET_SIZE 1500
#define SERVER_IP "192.168.1.1"
#define PORT 80

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_PACKET_SIZE];
    char* server_address;

    if (argc!= 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    server_address = argv[1];
    server = gethostbyname(server_address);

    if (server == NULL) {
        fprintf(stderr, "ERROR: Unknown host\n");
        return 1;
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "ERROR opening socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "ERROR connecting to server\n");
        return 1;
    }

    for (;;) {
        n = recv(sockfd, buffer, MAX_PACKET_SIZE, 0);
        if (n < 0) {
            fprintf(stderr, "ERROR receiving data\n");
            return 1;
        }
        printf("Received: %s\n", buffer);
        if (strcmp(buffer, "Connection closed") == 0)
            break;
    }

    printf("Connection closed\n");
    return 0;
}